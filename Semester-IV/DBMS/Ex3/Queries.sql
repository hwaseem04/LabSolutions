-- Ex 3

-- Q1
SELECT  empid, name 
FROM  professor 
WHERE StartYear = (SELECT min(Startyear) FROM professor);

-- Q2
SELECT RollNo, s.Name 
FROM Student s, Professor p 
WHERE s.Advisor = p.EmpId AND s.sex = p.sex;

-- Q3
SELECT EmpId, Name 
FROM Professor 
WHERE EmpId IN 
	(SELECT Advisor 
    FROM Student 
    WHERE sex='f' 
    GROUP BY advisor 
    HAVING COUNT(Advisor) >= 1);

-- Q4
SELECT DeptId, Name 
FROM department 
WHERE DeptId NOT IN 
	(SELECT DISTINCT(DeptNo) 
    FROM course 
    WHERE Credits=4);

-- Q5
SELECT RollNo 
FROM Enrollment 
WHERE CourseId IN 
	(SELECT CourseId 
    FROM teaching 
    WHERE EmpId=5) 
GROUP BY RollNo 
HAVING Count(RollNo)=
	(SELECT COUNT(CourseId) 
	FROM teaching 
	WHERE EmpId = 5);

-- Q6
SELECT RollNo 
FROM enrollment 
WHERE CourseId IN 
	(SELECT Prereqcourse 
    FROM Prerequisite 
    WHERE CourseId='CS789')
AND Grade IN ('S' ,'A') 
GROUP BY RollNo 
HAVING COUNT(RollNo)=
	(SELECT Count(Prereqcourse) 
    FROM prerequisite 
    WHERE courseID='CS789');

-- Q7
SELECT Name, Phone 
FROM department;

-- Q8
SELECT RollNo 
FROM enrollment 
WHERE CourseId IN ('CS232', 'CS230') 
GROUP BY RollNo 
HAVING COUNT(RollNo)=1 ;

-- Q9
SELECT RollNo 
FROM enrollment 
WHERE CourseId IN ('CS232', 'CS230') 
GROUP BY RollNo 
HAVING COUNT(RollNo)=2;

-- Q10
SELECT DISTINCT(RollNo) 
FROM enrollment 
WHERE RollNo NOT IN 
    (SELECT RollNo 
    FROM enrollment 
    WHERE CourseId='CS230');
