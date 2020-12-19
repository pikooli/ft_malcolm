docker rm malcolm
docker rmi malcolm
docker build . -t malcolm
docker run -ti -p 9002:9002 --name malcolm malcolm	
docker inspect -f '{{range.NetworkSettings.Networks}}{{.IPAddress}}{{end}}' malcolm
