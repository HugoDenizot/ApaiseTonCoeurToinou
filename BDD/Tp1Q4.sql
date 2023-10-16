set serveroutput on 

delete from temp;

DECLARE
vname emp.ename%type;
vsalaire emp.sal%type;
vempno emp.empno%type;
vcomm emp.comm%type;

Cursor c IS SELECT empno,ename,sal,comm FROM Emp; 

BEGIN
	OPEN c;
	loop
		FETCH c into vempno,vname,vsalaire,vcomm;
		EXIT WHEN(c%NOTFOUND);
		if vcomm IS NULL then
			vcomm:=0;
		end if;
		if (vcomm+vsalaire)>2000 then
			INSERT INTO Temp VALUES(vempno,vsalaire,vname); 
		end if;
		
	END LOOP;
	CLOSE c;
END;
/

