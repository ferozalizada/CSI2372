FROM gcc:latest
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN g++ -std=c++11 -D TEST_MAIN_ *.cpp
CMD ["./a.out"]