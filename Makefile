# CC := g++
# CFLAGS := -std=c++11 -D TEST_MAIN_ *.cpp
# TARGET := test

# # $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
# SRCS := $(wildcard *.cpp)
# # $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
# OBJS := $(patsubst %.cpp,%.o,$(SRCS))

# all: $(TARGET)
# $(TARGET): $(OBJS)
# 	$(CC) -o $@ $^
# %.o: %.cpp
# 	$(CC) $(CFLAGS) -c $<
# clean:
# 	rm -rf $(TARGET) *.o
# run: ${TARGET}
# 	./$(test)
# # .PHONY: all clean run
