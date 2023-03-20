-- Table creation

CREATE TABLE employee(
ename varchar(20),
city varchar(25)
);

CREATE TABLE emp_company(
ename varchar(20),
Cname varchar(20) REFERENCES company(cname),
Salary int,
Jdate date
);

CREATE TABLE company(
cname varchar(20),
city varchar(20)
);

CREATE TABLE manager(
ename varchar(20) ,
mname varchar(20)
);

CREATE TABLE emp_shift(
ename varchar(20),
shift char(1)
);
