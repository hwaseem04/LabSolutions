-- Q1
SELECT DISTINCT(city) 
FROM company 
WHERE cname IN ('Acc', 'TATA');

-- Q2
SELECT city FROM company WHERE cname='Acc' 
INTERSECT
SELECT city FROM company WHERE cname='Tata';

-- Q3
SELECT city FROM company 
EXCEPT 
SELECT city FROM company WHERE cname='Tata';

-- Q4
SELECT ename FROM employee WHERE city='nagpur' 
INTERSECT
SELECT ename FROM emp_company WHERE cname='Acc';

-- Q5
SELECT ename FROM employee WHERE city='nagpur' 
EXCEPT  
SELECT ename FROM emp_company WHERE cname='Acc';

-- Q6
SELECT ename FROM employee WHERE city='bombay' 
INTERSECT 
SELECT ename FROM emp_company WHERE salary>1500;

-- Q7
SELECT ename FROM employee WHERE city='chennai'
INTERSECT
SELECT ename FROM emp_company WHERE cname='CMC';

-- Q8
SELECT ename FROM employee WHERE city='nagpur'
INTERSECT
SELECT ename FROM emp_company WHERE cname='Acc'
INTERSECT
SELECT ename FROM emp_shift WHERE shift='A';

-- Q9
SELECT ename FROM employee WHERE city='nagpur'
INTERSECT
SELECT ename FROM emp_company WHERE cname='Acc'
EXCEPT
SELECT ename FROM emp_shift WHERE shift='B';

-- Q10
SELECT ename FROM employee WHERE city='nagpur'
UNION
SELECT ename FROM employee WHERE city='bombay';

-- Q11
SELECT ename FROM employee
UNION ALL
SELECT ename FROM emp_company;

SELECT ename FROM employee
UNION 
SELECT ename FROM emp_company;
    
-- Q12
SELECT ename FROM emp_company WHERE jDate='1998-12-18'
INTERSECT
SELECT ename FROM emp_shift WHERE shift='E';

-- Q13
SELECT ename FROM employee WHERE city IN (SELECT city FROM employee WHERE ename='sunil');

-- Q14
SELECT ename FROM employee WHERE city='bombay' 
INTERSECT 
SELECT ename FROM emp_company e, company c WHERE c.cname = e.cname AND c.city='delhi';

-- Q15
SELECT ename FROM employee WHERE city IN (SELECT city FROM employee WHERE ename='ajay');


-- CREATE view vew_name
-- AS 
-- SELECT 
--  Allowed to make changes if you dont have groupby, subquery, distinct keyword