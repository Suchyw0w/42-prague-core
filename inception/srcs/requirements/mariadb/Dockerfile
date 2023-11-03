FROM debian:buster

RUN apt update
RUN apt -y install mariadb-server
EXPOSE 3306

COPY ./config/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./config/init.sql /var/www/

RUN service mysql start && mysql < /var/www/init.sql && rm -f /var/www/init.sql;

CMD [ "mysqld" ]
