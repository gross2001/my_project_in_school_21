#!/bin/sh

mkdir -p /var/www/html

export KEY_NAME=$(ls /etc/nginx/certs/self-signed | grep .key)
export CERT_NAME=$(ls /etc/nginx/certs/self-signed | grep .cert)

envsubst '${DOMAIN_NAME} $KEY_NAME $CERT_NAME' < /default.conf.template > /etc/nginx//conf.d/default.conf

nginx -g 'daemon off;'