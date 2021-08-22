CC := g++
CFLAGS := -std=c++11 -D TEST_MAIN_ *.cpp
TARGET := test
SRCS := $(wildcard *.cpp)
# OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(TARGET) *.o
run: ${TARGET}
	./$(test)

