use ex7;

-- Table creation
CREATE TABLE feespaid(
rollno int,
feelspaiddate date,
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
refcode int
);


-- Table insertion
INSERT INTO feespaid VALUES
(10001, '1998-07-25', 12345, '', '',20000),
(10002, '2015-07-27', 12789, '', '', 25000),
(10003, '2016-10-02', 13456, '', '', 35000);

INSERT INTO enquiry VALUES
(1100011, 'anil', 10, 'ramnagar', 'nagpur', '1998-07-01', 1001),
(1100012, 'achin', 20, 'gandhinagar', 'nagpur', '1999-09-01', 1002);

-- Questions
-- Q1
use delimiter //
CREATE TRIGGER check_code BEFORE INSERT ON enquiry FOR EACH ROW
BEGIN
	IF new.coursecode > 10 AND new.coursecode < 99 THEN
		set new.coursecode = new.coursecode;
	ELSE 
		SIGNAL SQLSTATE '70715';
	END IF;
END //

-- Q2
use delimiter //
CREATE TRIGGER dont_change_student1 BEFORE UPDATE ON enquiry FOR EACH ROW
BEGIN
	IF old.name = 'student1' THEN
		SIGNAL SQLSTATE '70715';
	END IF;
END //

use delimiter //
CREATE TRIGGER dont_change_student1_del BEFORE DELETE ON enquiry FOR EACH ROW
BEGIN
	IF old.name = 'student1' THEN
		SIGNAL SQLSTATE '70715';
	END IF;
END //

-- Q3
use delimiter //
CREATE TRIGGER check_fee BEFORE INSERT ON feespaid FOR EACH ROW
BEGIN
	IF new.amount < 10000 THEN
		SIGNAL SQLSTATE '70715';
	END IF;
END //

-- Q4
use delimiter //
CREATE TRIGGER check_enquiry_date1 BEFORE INSERT ON enquiry FOR EACH ROW
BEGIN
	IF new.enquirydate > '2017-08-25' THEN
		SIGNAL SQLSTATE '70715';
	END IF;
END //

-- Q5
use delimiter //
CREATE TRIGGER not_equal BEFORE UPDATE ON enquiry FOR EACH ROW
BEGIN
	IF old.enquiryno = new.enquiryno AND old.name = new.name AND old.coursecode = new.coursecode AND old.street = new.street AND old.city = new.city AND old.enquirydate = new.enquirydate AND old.refcode = new.refcode THEN
		SIGNAL SQLSTATE '70715';
	END IF;
END //

-- Q6
use delimiter //
CREATE TRIGGER check_average_1 AFTER INSERT ON feespaid FOR EACH ROW
BEGIN
	IF  (SELECT AVG(amount) FROM feespaid) > 50000 THEN
		SIGNAL SQLSTATE '70715';
	END IF;
END //


