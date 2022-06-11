
build:
	sudo mkdir -p /home/njacques/data/wordpress_db
	sudo mkdir -p /home/njacques/data/wordpress
	cd srcs && \
	sudo docker-compose up -d --build

stop:
	sudo docker-compose -f srcs/docker-compose.yml down

clean: stop
	sudo rm -rf /home/njacques/data
	sudo docker system prune -f