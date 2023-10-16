set serveroutput on 
declare 
p char(9);

begin 
for i in 1..100 loop
	if mod(i,2)=0 then 
		p := 'pair';
	else 
		p := 'impair';
	end if; 
	insert into temp values ( i , i*100 ,  i || ' est '  || p );
end loop;
end;
/
