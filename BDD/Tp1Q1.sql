set serveroutput on
DECLARE 
vname emp.ename%type;
vsalaire emp.sal%type;
vcommission emp.comm%type;
vdepart dept.dname%type;

/* Question 1 */
begin
SELECT ENAME,SAL,COMM,DNAME into vname,vsalaire,vcommission,vdepart
FROM EMP join DEPT on EMP.DEPTNO=DEPT.DEPTNO
WHERE ENAME='MILLER';
dbms_output.put_line(' nom ' || vname || ' salaire ' || vsalaire || ' commision ' || vcommission || ' departement ' || vdepart) ;
end;
/

