set serveroutput on 

delete from temp;

DECLARE
vname emp.ename%type;
vsalaire emp.sal%type;
vempno emp.empno%type;
vcomm emp.comm%type;
vmgr emp.mgr%type;
vempnowait emp.empno%type;

Cursor c IS select empno,sal,ename into vempno,vsalaire,vname FROM emp where empno=vmgr; 

BEGIN
	vempnowait:=7902;
	SELECT sal, MGR INTO vsalaire,vmgr FROM emp WHERE empno=vempnowait;
	dbms_output.put_line(vsalaire||vmgr) ;
END;
/
