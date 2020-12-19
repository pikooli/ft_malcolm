FROM debian:buster 

RUN apt update -y
RUN apt install build-essential vim net-tools -y
ADD . malcolm
WORKDIR malcolm
CMD sh 
