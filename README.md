CREATE TABLE users(
	user_id INT NOT NULL,
	login VARCHAR(40),
	reg_dttm TIMESTAMP,
	PRIMARY KEY(user_id)
);

CREATE TABLE payments(
	payment_id INT NOT NULL,
	user_id INT,
	payment_sum DOUBLE,
	payment_dttm TIMESTAMP,
	PRIMARY KEY(payment_id),
	FOREIGN KEY (user_id) REFERENCES users(user_id)
);

CREATE TABLE sessions(
	session_id INT NOT NULL,
	user_id INT,
	begin_dttm TIMESTAMP,
	end_dttm TIMESTAMP,
	PRIMARY KEY(session_id),
	FOREIGN KEY (user_id) REFERENCES users(user_id)
);

show tables;

LOAD DATA INFILE '/var/lib/mysql-files/users.csv'
INTO TABLE users
FIELDS TERMINATED BY ','
LINES TERMINATED BY '\n';

LOAD DATA INFILE '/var/lib/mysql-files/payments.csv'
INTO TABLE payments
FIELDS TERMINATED BY ','
LINES TERMINATED BY '\n';

LOAD DATA INFILE '/var/lib/mysql-files/sessions.csv'
INTO TABLE sessions
FIELDS TERMINATED BY ','
LINES TERMINATED BY '\n';
