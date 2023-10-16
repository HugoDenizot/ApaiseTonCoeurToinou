set serveroutput on 
DECLARE
vname emp.ename%type;
vsalaire emp.sal%type;
vempno emp.empno%type;

Cursor c IS SELECT empno,ename,sal FROM Emp ORDER BY sal DESC; 

BEGIN
	OPEN c;
	for i in 1..5 loop
		FETCH c into vempno,vname,vsalaire;
		INSERT INTO Temp VALUES(vempno,vsalaire,vname); 
	END LOOP;
	CLOSE c;
END;
/

