#!/bin/sh

sed -i '/listen = /c\listen = 9000'  /etc/php/7.3/fpm/pool.d/www.conf
mkdir -p /run/php

if [ ! -e wp-config.php ]; then
    sed -i "/define( 'DB_NAME', 'database_name_here' )/c\define( 'DB_NAME', '$WORDPRESS_DB_NAME' );"  ./wp-config-sample.php 
    sed -i "/define( 'DB_USER', 'username_here' )/c\define( 'DB_USER', '$WORDPRESS_DB_USER' );"  ./wp-config-sample.php
    sed -i "/define( 'DB_PASSWORD', 'password_here' )/c\define( 'DB_PASSWORD', '$WORDPRESS_DB_PASSWORD' );"  ./wp-config-sample.php
    sed -i "/define( 'DB_HOST', 'localhost' );/c\define( 'DB_HOST', '$WORDPRESS_DB_HOST' );"  ./wp-config-sample.php
    mv wp-config-sample.php wp-config.php 

    wp core install \
    --url=njacques.42.fr --title=Example \
    --admin_user=$WP_ADMIN \
    --admin_password=$WP_ADMIN_PASSWORD \
    --admin_email=$WP_ADMIN_EMAIL --allow-root 

    wp user create $WP_USER $WP_USER_EMAIL \
    --user_pass=$WP_USER_PASSWORD \
    --role=subscriber --allow-root 

    wp post create \
    --post_content="Hello to the school of future" \
    --comment_status=open \
    --post_name=commentpage \
    --post_status=publish --allow-root
fi

/usr/sbin/php-fpm7.3 -R -F
