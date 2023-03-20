-- Q1
CREATE OR REPLACE VIEW view1 AS
SELECT t1.ename, t2.cname, t2.salary, t2.jDate, t1.city, t3.cities
FROM employee t1, emp_company t2, company t3 
WHERE t1.ename=t2.ename AND t2.cname=t3.cname AND t1.city=t3.cities;

SELECT * FROM view1;

-- Q2
-- View with single table is updateable. But the changes reflect on original table as well.
UPDATE view1 SET jdate='1999-12-10'
WHERE ename='anil';

SELECT * FROM view1;

-- Q3
CREATE OR REPLACE view v1 AS
SELECT ename, salary, cname FROM emp_company
WHERE cname='ACC';

-- Q4
INSERT INTO emp_company VALUES('Ashok', 'Acc', 1200, NULL);

-- Q5
SELECT * FROM v1;

-- Q6
CREATE OR REPLACE view v2 AS
SELECT ename, salary, cname FROM emp_company
WHERE cname='ACC'
WITH CHECK OPTION;

-- Q7
CREATE OR REPLACE VIEW view2 AS
SELECT cname, AVG(salary), MAX(salary), MIN(salary) 
FROM emp_company 
GROUP BY cname;

SELECT * FROM view2;

-- Q8
CREATE OR REPLACE VIEW view4 AS 
SELECT CONCAT(ename,'-' ,cname) AS 'Employee Company_Name', salary 
FROM emp_company WHERE jDate>'1998-02-01';

SELECT * FROM view4;

-- Q9
CREATE OR REPLACE VIEW view3 AS 
SELECT e.ename, c.salary, e.city 
FROM employee e, emp_company c 
WHERE e.ename=c.ename;

SELECT * FROM view3;

-- Q10
 SELECT e.ename, e.salary 
 FROM (SELECT ename, salary FROM emp_company ORDER BY salary DESC LIMIT 5) e;

-- Q11
SELECT * FROM emp_company 
ORDER BY jDate DESC LIMIT 5;


