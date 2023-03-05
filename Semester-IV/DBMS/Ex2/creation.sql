use ex2;

CREATE TABLE Department(
DeptId int PRIMARY KEY,
Name varchar(25),
HoD int,
Phone bigint
);

CREATE TABLE Professor(
EmpId int PRIMARY KEY,
Name varchar(25),
Sex varchar(2),
StartYear date,
DeptNo int,
Phone bigint
);

CREATE TABLE Student(
RollNo int PRIMARY KEY,
Name varchar(25),
Degree varchar(30),
Year date,
Sex varchar(2),
DeptNo int,
Advisor int
);


CREATE TABLE Course(
CourseId char(5) PRIMARY KEY,
CourseName varchar(25),
Credits int,
DeptNo int REFERENCES Department(DeptId) 
);


CREATE TABLE Enrollment(
RollNo int REFERENCES Student(RollNo),
CourseId char(5) REFERENCES Course(CourseId),
Sem int,
Year int,
Grade varchar(2)
);


CREATE TABLE Teaching(
EmpId int REFERENCES Professor(EmpId),
CourseId char(5) REFERENCES Course(CourseId),
Sem int,
Year int,
ClassRoom char(4)
);

CREATE TABLE Prerequisite(
Prereqcourse char(5) REFERENCES Course(CourseId),
CourseId char(5) REFERENCES Course(CourseId)
);



