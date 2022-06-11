FROM debian:10.10

ARG CERTS_
RUN apt-get update && apt-get install -y nginx \
                        ca-certificates \
                        gettext-base 

COPY ./requirements/nginx/conf/default.conf.template /
COPY ${CERTS_} /etc/nginx/certs/self-signed

RUN ln -sf /dev/stdout /var/log/nginx/access.log \
    && ln -sf /dev/stderr /var/log/nginx/error.log

EXPOSE 80 443

COPY ./requirements/nginx/tools/nginx-entrypoint.sh /
ENTRYPOINT ["/nginx-entrypoint.sh"]
