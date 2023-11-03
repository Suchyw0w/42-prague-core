FROM debian:buster

RUN apt update
RUN apt -y install nginx openssl

EXPOSE 443

COPY ./config/ng.conf /etc/nginx/sites-enabled/default

RUN openssl req -x509 -nodes -newkey rsa:4096 \
    -keyout /etc/ssl/private/nginx.key \
    -out /etc/ssl/certs/nginx.crt \
    -subj "/C=CZ/ST=Prague/L=Prague/O=42 Prague/CN=osuchane"

CMD [ "nginx", "-g", "daemon off;" ]
