CREATE DATABASE IF NOT EXISTS wordpress;

ALTER USER 'root'@'localhost' IDENTIFIED BY '42prague';

CREATE USER IF NOT EXISTS 'suchy'@'%' IDENTIFIED BY '42prague';
GRANT ALL PRIVILEGES ON wordpress.* TO 'suchy'@'%';
FLUSH PRIVILEGES;
