FROM ubuntu

ENV TZ=Europe/Moscow 
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone 
RUN apt-get update 
RUN apt-get install qt5-default -y 
RUN apt-get install qtbase5-dev -y 
RUN apt-get install qt5-qmake 
RUN apt-get install build-essential -y 
#RUN apt-get -y install gcc-snapshot g++-11
# RUN apt-get install -y qt-devel qt-create
 
WORKDIR /root/
RUN mkdir server
WORKDIR /root/server/
COPY Server/*.cpp /root/server/
COPY Server/*.h /root/server/
COPY Server/*.pro /root/server/
 

RUN qmake echoServer.pro
RUN make 

ENTRYPOINT ["./echoServer"]
