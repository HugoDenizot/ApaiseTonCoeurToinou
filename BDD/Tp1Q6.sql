set serveroutput on 

delete from temp;

DECLARE
vname emp.ename%type;
vsalaire emp.sal%type;
vempno emp.empno%type;
vcomm emp.comm%type;
vmgr emp.mgr%type;
vempnowait emp.empno%type;

Cursor c IS select empno,sal,ename,mgr FROM emp where empno=vempnowait; 

BEGIN
	SELECT sal,mgr,ename INTO vsalaire, vmgr,vname FROM emp where empno=7902;
	if vsalaire>4000 then
		INSERT INTO temp VALUES(7902,vsalaire,vname);
	else
		OPEN c;
		loop
			vempnowait:=vmgr;
			fetch c into vempno,vsalaire,vname,vmgr;
			EXIT WHEN( vsalaire > 4000 );		
			if vsalaire>4000 then
				INSERT INTO temp VALUES(vempno,vsalaire,vname);
			end if;
		end loop;
		close c;
	end if;
		
END;
/
