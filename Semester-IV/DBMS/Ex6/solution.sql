-- Ex 6
use ex6;
-- Creation
CREATE TABLE course(
coursecode int,
coursename varchar(25),
syllabus varchar(25),
lastno int
);

CREATE TABLE feespaid(
rollno int,
feespaiddate date,
chequeno int,
bankname varchar(25),
remarks varchar(25),
amount int
);

CREATE TABLE enquiry(
enquiryno int,
name varchar(25),
coursecode int,
street varchar(25),
city varchar(25),
enquirydate date,
refcode int,
salary int,
advercode varchar(10)
);

CREATE TABLE enrollment(
rollno int,
enquiryno int,
batchcode int,
enrollmentdate date
);

-- INSERTION
INSERT INTO course 
VALUES
(10, 'oracle', 'sql', 2),
(20, 'java', 'java servlets', 2);

INSERT INTO feespaid
VALUES
(10001, '1998-07-25', 12345, '', '', 20000),
(10002, '2015-07-27', 12789, '', '', 25000),
(10003, '2016-10-02', 13456, '', '', 35000);


INSERT INTO enquiry
VALUES
(1100011, 'anil', 10, 'ramnagar', 'nagpur', '1998-07-01', 1001, 8000, 'adv1'),
(1100012, 'achin', 20, 'gandhinagar', 'nagar', '1999-09-01', 1002, 3000, 'adv2');

INSERT INTO enrollment
VALUES
(20002001, 10001, 200200, '1998-07-01'),
(20002003, 10002, 200202, '2017-08-03'),
(20002001, 10003, 200203, '1999-09-02');

-- Questions
-- Q1
use ex6;
delimiter //
CREATE PROCEDURE p1()
BEGIN
	DECLARE k INT;
	SET k := (SELECT salary FROM enquiry WHERE name='anil');
	IF k > 7000 THEN
		SELECT 'A' as 'grade';
	ELSEIF k > 4000 THEN
		SELECT 'B' as 'grade';
	ELSEIF k > 3000 THEN
		SELECT 'C' as 'grade' ;
	ELSEIF k > 2000 THEN
		SELECT 'D' as 'grade';
	END IF;
END//

-- Q2
delimiter //
CREATE PROCEDURE p2(code int)
BEGIN
	SELECT coursename FROM course WHERE coursecode=code;
END//

-- Q3
delimiter //
CREATE PROCEDURE p3(code int)
BEGIN
    DECLARE k varchar(25);
    SET k := (SELECT coursename FROM course WHERE coursecode=code);
    IF k IS NULL THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'coursecode is not found';
    ELSE
        SELECT k;
    END IF;
END//


-- Q4
delimiter //
CREATE procedure p4()
BEGIN
	DECLARE k int;
    SET k := (SELECT SUM(amount) FROM feespaid);
    SELECT k as 'Total Amount';
END//

-- Q5
delimiter //
CREATE procedure p5(code varchar(4))
BEGIN
	SELECT COUNT(enquiryno) FROM enquiry WHERE advercode=code;
END//

-- Q6
delimiter //
CREATE procedure p6(roll int)
BEGIN
	DECLARE k int;
    SET k := (SELECT SUM(amount) FROM feespaid WHERE rollno=roll);
    SELECT k as 'Total Amount Paid by student ';
END//

