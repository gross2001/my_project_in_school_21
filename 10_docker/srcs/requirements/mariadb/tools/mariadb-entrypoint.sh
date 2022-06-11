#!/bin/sh

printf "\n[mysqld]\nskip-networking=0\nskip-bind-address\n" >> /etc/mysql/my.cnf

CONTAINER_ALREADY_STARTED="CONTAINER_ALREADY_STARTED_PLACEHOLDER"
if [ ! -e /var/lib/mysql/$CONTAINER_ALREADY_STARTED ]; then
    touch /var/lib/mysql/$CONTAINER_ALREADY_STARTED
    echo "-- First container startup --"
    service mysql start
    chown -R mysql:mysql /run/mysqld  
    mysql -u root -Be \
    "create database if not exists $MYSQL_DATABASE;\
    CREATE USER $MYSQL_USER@'%' IDENTIFIED BY '$MYSQL_PASSWORD';\
    GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO $MYSQL_USER@'%' IDENTIFIED BY '$MYSQL_PASSWORD';\
    FLUSH PRIVILEGES;"
    mysqladmin -u root password $(echo $MYSQL_ROOT_PASSWORD)
    service mysql stop
fi

mysqld_safe
