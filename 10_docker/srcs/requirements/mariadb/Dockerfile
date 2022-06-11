FROM debian:10.10

RUN apt-get update \
&& apt-get install -y systemd mariadb-server

COPY ./tools/mariadb-entrypoint.sh /

EXPOSE 3306

ENTRYPOINT ["sh", "/mariadb-entrypoint.sh"]