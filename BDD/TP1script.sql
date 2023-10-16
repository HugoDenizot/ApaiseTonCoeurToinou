drop table emp ;
drop Table Dept ;


create table dept(
	deptno NUMBER(2) primary key, 
	dname VARCHAR2(14), 
	loc VARCHAR2(13));

create table emp(
    empno      number(4) primary key,
    ename      varchar2(10),
    job        varchar2(9),
    mgr        number(4),
    hiredate   date,
    sal        number(7,2),
    comm       number(7,2),
    deptno     number(2) references dept) ;

drop table temp ;

create table temp(
    num_col1   number(9,4),
    num_col2   number(9,4),
    char_col   char(55)) ;


insert into dept values
(10,'ACCOUNTING', 'NEW YORK') ;

insert into dept values
(20, 'RESEARCH','DALLAS');
insert into dept values
(30,'SALES','CHICAGO');


insert into emp values
(7369,'SMITH','CLERK',7902,to_date('17-12-1980','dd-mm-yyyy'),800,NULL,20) ;

insert into emp values
(7499,'ALLEN','SALESMAN',7698,to_date('20-02-1981','dd-mm-yyyy'),1600,300,30) ;

insert into emp values
(7521,'WARD','SALESMAN',7698,to_date('22-02-1981','dd-mm-yyyy'),1250,500,30) ;

insert into emp values
(7566,'JONES','MANAGER',7839,to_date('02-04-1981','dd-mm-yyyy'),2975,NULL,20) ;

insert into emp values
(7654,'MARTIN','SALESMAN',7698,to_date('28-09-1981','dd-mm-yyyy'),1250,1400,30) ;


insert into emp values
(7698,'BLAKE','MANAGER',7839,to_date('01-05-1981','dd-mm-yyyy'),2850,NULL,30) ;

insert into emp values
(7782,'CLARK','MANAGER',7839,to_date('09-06-1981','dd-mm-yyyy'),2450,NULL,10) ;

insert into emp values
(7788,'SCOTT','ANALYST',7566,to_date('13-7-1987','dd-mm-yyyy'),3000,NULL,20) ;

insert into emp values
(7839,'KING','PRESIDENT',NULL,to_date('17-11-1981','dd-mm-yyyy'),5000,NULL,10) ;

insert into emp values
(7844,'TURNER','SALESMAN',7698,to_date('08-09-1981','dd-mm-yyyy'),1500,0,30) ;

insert into emp values
(7876,'ADAMS','CLERK',7788,to_date('13-07-1987','dd-mm-yyyy'),1100,NULL,20) ;

insert into emp values
(7900,'JAMES','CLERK',7698,to_date('03-12-1981','dd-mm-yyyy'),950,NULL,30) ;

insert into emp values
(7902,'FORD','ANALYST',7566,to_date('03-12-1981','dd-mm-yyyy'),3000,NULL,20) ;

insert into emp values
(7934,'MILLER','CLERK',7782,to_date('23-01-1982','dd-mm-yyyy'),1300,NULL,10) ;

commit;
insert into emp values (7000,'NSIRI','SALESMAN',7566,to_date('17-12-1980','dd-mm-yyyy'),3500,NULL,20)
commit;
