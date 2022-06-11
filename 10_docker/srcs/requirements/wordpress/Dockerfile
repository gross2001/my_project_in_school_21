FROM debian:10.10

RUN apt-get update \
&& apt-get install -y php php-fpm php-mysql \
&& ln -sf /dev/stderr /var/log/php7.3-fpm.log

WORKDIR /var/www/html
RUN apt-get install -y wget \
&& wget http://wordpress.org/latest.tar.gz \
&& tar xzvf latest.tar.gz \
&& mv wordpress/* . \
&& rm -f latest.tar.gz

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
&& chmod +x wp-cli.phar \
&& mv wp-cli.phar /usr/local/bin/wp

COPY ./tools/wordpress-entrypoint.sh /

EXPOSE 9000

ENTRYPOINT ["sh", "/wordpress-entrypoint.sh"]

