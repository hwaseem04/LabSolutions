-- INSERTION
use ex4;
-- Employee table
INSERT INTO employee
VALUES('anil', 'nagpur');

INSERT INTO employee
VALUES('shankar', 'bombay');

INSERT INTO employee
VALUES('jaya', 'chennai');

INSERT INTO employee
VALUES('sunil', 'bombay');

INSERT INTO employee
VALUES('vijay', 'delhi');

INSERT INTO employee
VALUES('prakash', 'calcutta');

INSERT INTO employee
VALUES('ajay', 'nagpur');

-- Emp_company table
INSERT INTO emp_company
VALUES('anil', 'Acc', 1500, '1989-05-01');

INSERT INTO emp_company
VALUES('shankar', 'Tata', 2000, '1990-07-10');

INSERT INTO emp_company
VALUES('jaya', 'CMC', 1800, '1991-06-07');

INSERT INTO emp_company
VALUES('sunil', 'CMC', 1700, '1988-01-01');

INSERT INTO emp_company
VALUES('vijay', 'TATA', 5000, '1988-01-03');

INSERT INTO emp_company
VALUES('prakash', 'TATA', 3000, '1989-05-27');

INSERT INTO emp_company
VALUES('ajay', 'CMC', 8000, '1995-04-30');

INSERT INTO emp_company
VALUES('amol', 'Acc', 1000, '1995-03-17');

INSERT INTO emp_company
VALUES('kiran', 'Hyundai Mobis', 30000, '1998-12-18');

-- Company table
INSERT INTO company
VALUES('Acc', 'chennai');

INSERT INTO company
VALUES('TATA', 'bombay');

INSERT INTO company
VALUES('Acc', 'nagpur');

INSERT INTO company
VALUES('CMC', 'bombay');

INSERT INTO company
VALUES('CMC', 'chennai');

INSERT INTO company
VALUES('TATA', 'chennai');

-- Manager table
INSERT INTO manager
VALUES ('anil', 'ajay');

INSERT INTO manager
VALUES ('shankar', 'vijay');

INSERT INTO manager
VALUES ('jaya', NULL);

INSERT INTO manager
VALUES ('sunil', 'jaya');

INSERT INTO manager
VALUES ('vijay', NULL);

INSERT INTO manager
VALUES ('prakash', 'shankar');

INSERT INTO manager
VALUES ('ajay', NULL);

-- Emp shift table

INSERT INTO emp_shift
VALUES ('anil', 'A');

INSERT INTO emp_shift
VALUES ('sunil', 'B');

INSERT INTO emp_shift
VALUES ('vijay', 'B');

INSERT INTO emp_shift
VALUES ('prakash', 'C');

INSERT INTO emp_shift
VALUES ('kiran', 'E');




