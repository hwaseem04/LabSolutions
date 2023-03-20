-- Creation of new manager table and other prior tasks
use ex4;
-- (i)
DROP TABLE manager;
CREATE TABLE manager(
ename varchar(15),
mname varchar(15),
city varchar(15)
);
INSERT INTO manager VALUES('anil', 'ajay', 'nagpur');
INSERT INTO manager VALUES('shankar', 'vijay', 'chennai');
INSERT INTO manager VALUES('jaya', 'kiran', 'calcutta');
INSERT INTO manager VALUES('sunil', 'jaya', 'bombay');
INSERT INTO manager VALUES('vijay', 'rakesh', 'calcutta');
INSERT INTO manager VALUES('prakash', 'shankar', 'nagpur');
INSERT INTO manager VALUES('ajay', 'sanjay', 'coimbatore');

-- (ii)
INSERT INTO employee VALUES('suresh', NULL);

-- (iii)
INSERT INTO emp_company VALUES('suresh', 'Acc', 8000, '1985-07-12'); 


-- Join Queries
-- Q1
SELECT employee.ename, city, cname, salary, jDate 
FROM employee NATURAL JOIN emp_company;

-- Q2
SELECT * FROM manager
CROSS JOIN employee;

-- Q3
SELECT emp_company.ename, mname, salary 
FROM emp_company, manager
WHERE salary > 3000 AND emp_company.ename=manager.ename; 

-- Q4
SELECT e.ename, mname, salary
FROM emp_company e INNER JOIN manager m ON e.ename=m.ename
WHERE salary > 3000;

-- Q5
SELECT DISTINCT(ename) 
FROM employee 
INNER JOIN company ON employee.city=company.city;

-- Q6
SELECT employee.ename
FROM employee 
INNER JOIN emp_company ON employee.ename=emp_company.ename
WHERE city='chennai' AND salary BETWEEN 1500 AND 10000;

-- Q7
SELECT employee.ename, cname, salary
FROM employee 
INNER JOIN emp_company ON employee.ename=emp_company.ename
WHERE city IS NULL ;

-- Q8
SELECT emp_shift.ename, shift, mname 
FROM emp_shift 
LEFT OUTER JOIN manager ON emp_shift.ename = manager.ename;

-- Q9
SELECT e.city
FROM company c
RIGHT OUTER JOIN employee e 
ON e.city=c.city 
WHERE c.city IS NULL AND e.city IS NOT NULL;


-- Q10
SELECT emp_shift.ename, shift, mname 
FROM emp_shift 
LEFT JOIN manager ON emp_shift.ename = manager.ename
UNION
SELECT emp_shift.ename, shift, mname 
FROM emp_shift 
RIGHT JOIN manager ON emp_shift.ename = manager.ename;

-- Q11
SELECT employee.ename, employee.city
FROM employee INNER JOIN manager 
ON employee.ename = manager.ename 
WHERE employee.city=manager.city;

-- Q12
SELECT employee.ename 
FROM employee
INNER JOIN manager
ON employee.ename=manager.ename
ORDER BY employee.ename ASC;
