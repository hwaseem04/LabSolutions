
INSERT INTO Department
VALUES(3, 'CSE', NULL, 1212);

INSERT INTO Professor
VALUES(1, 'Waseem', 'm', '2017-01-01', 3, 9988776656);

UPDATE Department SET HoD=1
WHERE DeptID=3;

INSERT INTO Student
VALUES(21110088, 'Prathosh', 'Btech', '2021-07-01', 'M', 3, 1);

INSERT INTO Course
VALUES('CS101', 'Artificial Intelligence', 4, 3);

INSERT INTO Enrollment
VALUES(21110088, 'CS101', 1, 1, 'O');

INSERT INTO Teaching
VALUES(1, 'CS101', 1, 1, 'CS-1');

INSERT INTO Prerequisite
VALUES(NULL, 'CS101');