ALTER TABLE Student
ADD CONSTRAINT c1 FOREIGN KEY(DeptNo) REFERENCES Department(DeptId);

ALTER TABLE Student
ADD CONSTRAINT c2 FOREIGN KEY(Advisor) REFERENCES Professor(EmpId);

ALTER TABLE Department
ADD CONSTRAINT c3 FOREIGN KEY(HoD) REFERENCES Professor(EmpId);

ALTER TABLE Professor
ADD CONSTRAINT c4 FOREIGN KEY(DeptNo) REFERENCES Department(DeptId);


-- ALTER TABLE Enrollment
-- ADD (CONSTRAINT check_pre
-- CHECK ((SELECT Prereqcourse FROM Prerequisite WHERE NEW.courseId=Prerequisite.courseId) 
-- 		IN (SELECT Enrollment.CourseId where Enrollent.RollNo=New.RollNo)
--         )
-- );