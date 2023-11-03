FROM debian:buster

RUN apt update

RUN apt -y install php7.3 wget php-mysqli php-fpm

COPY ./config/wp_start.sh /var/www/
COPY ./config/wp-config.php /var/www/
COPY ./config/www.conf /etc/php/7.3/fpm/pool.d

EXPOSE 9000

RUN chmod +x /var/www/wp_start.sh

ENTRYPOINT [ "/var/www/wp_start.sh" ]

CMD [ "/usr/sbin/php-fpm7.3", "--nodaemonize"]