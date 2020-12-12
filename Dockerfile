FROM debian:buster 

RUN apt update -y
RUN apt install build-essential -y
ADD . ft_malcolm

CMD sh 
