CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic -g
TARGET = student_data
OBJS = main.o address.o date.o student.o

.PHONY: all run debug clean valgrind
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
main.o: main.cpp address.h date.h student.h
	$(CXX) $(CXXFLAGS) -c main.cpp
address.o: address.cpp address.h
	$(CXX) $(CXXFLAGS) -c address.cpp
date.o: date.cpp date.h
	$(CXX) $(CXXFLAGS) -c date.cpp
student.o: student.cpp student.h address.h date.h
	$(CXX) $(CXXFLAGS) -c student.cpp
run: $(TARGET)
	./$(TARGET)
debug: $(TARGET)
	gdb ./$(TARGET)
clean:
	rm -f $(TARGET) $(OBJS)
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./$(TARGET)
