CREATE OR REPLACE procedure createdpt_hudenizot(numero_dept IN dept.deptno%type, dept_name in dept.dname%type, localisation in dept.loc%type)
IS
	cpt dept.deptno%type;
BEGIN
	select count(numero_dept) into cpt FROM Dept Where deptno=numero_dept;
	if cpt=0 then
	 INSERT INTO Dept Values(numero_dept,dept_name,localisation);
	end if;
END createdpt_hudenizot;
/

exec procedure createdpt_hudenizot(12,'BDD','Clermont');

CREATE OR REPLACE function salok_hudenizot(jobs IN SalIntervalle_hudenizot.job%type, salaire in SalIntervalle_hudenizot.lsal%type)
RETURN number
IS
	retour number;
	salairemin SalIntervalle_hudenizot.lsal%type;
	salairemax SalIntervalle_hudenizot.hsal%type;
	
BEGIN
	select lsal,hsal into salairemin,salairemax FROM SalIntervalle_hudenizot Where job=jobs;
	if salaire>salairemin and salaire<salairemax then
		retour:=1;
	else
		retour:=0;
	end if;
	return(retour);
END salok_hudenizot;
/

create table SalIntervalle_hudenizot (job varchar2(9), lsal number(7,2), hsal number(7,2));
insert into SalIntervalle_hudenizot values ('ANALYST', 2500, 3000) ;
insert into SalIntervalle_hudenizot values ('CLERK', 900, 1300) ;
insert into SalIntervalle_hudenizot values ('MANAGER', 2400, 3000) ;
insert into SalIntervalle_hudenizot values ('PRESIDENT', 4500, 4900) ;
insert into SalIntervalle_hudenizot values ('SALESMAN', 1200, 1700) ;

select salok_hudenizot('MANAGER',2100) from dual;

set serveroutput on
CREATE OR REPLACE procedure raisesalary_hudenizot(emp_id IN emp.empno%type, amount in emp.sal%type)
IS
	retour number;
	nom_job emp.job%type;
	sal_actuelle emp.sal%type;
	futur_sal emp.sal%type;
	
BEGIN
	select job,sal into nom_job,sal_actuelle from emp where empno=emp_id;
	if nom_job is not null then
		futur_sal:=sal_actuelle+amount;
		select salok_hudenizot(nom_job,futur_sal) into retour from dual;
		if retour=1 then
			UPDATE emp SET sal=sal_actuelle+amount Where empno=emp_id ;
		else
			dbms_output.put_line('Le salaire ne sera plus dans l''intervale');
		end if;
	end if;
END raisesalary_hudenizot;
/

set serveroutput on
DECLARE
	cpt number;
	nom_nouveau_table user_tables.table_name%type;
	nom_table user_tables.table_name%type;
	Cursor c IS SELECT table_name FROM user_tables where table_name NOT LIKE '%%_OLD' ; 
	req user_tables.table_name%type;
	req1 user_tables.table_name%type;
BEGIN
	Open c;
	loop
		FETCH c into nom_table;
		EXIT WHEN(c%NOTFOUND);
		select count(*) into cpt from user_tables where table_name=nom_table||'_OLD';
		nom_nouveau_table:=nom_table||'_OLD';
		if cpt>0 then
			req:='DROP TABLE '||nom_nouveau_table;
			execute immediate req;
		end if;
		req1:='Create table '||nom_nouveau_table||' as Select * from '||nom_table;
		dbms_output.put_line(req);
		execute immediate req1;
	END LOOP;
	CLOSE c;
END;
/

