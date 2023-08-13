FROM gcc:latest
COPY . /app
WORKDIR /app
RUN ldconfig
RUN apt update
RUN apt-get install libmicrohttpd12
RUN /bin/bash -c ./make.sh
RUN /bin/bash -c ./build.sh
EXPOSE 8080
CMD [ "./run.sh" ]