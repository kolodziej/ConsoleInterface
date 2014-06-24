CXX=g++
CXXFLAGS=-std=c++11 -g -I../headers/	-L../lib/
TARGET=ConsoleInterfaceTest

all: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -lConsoleInterface -o $(TARGET)

clean:
	rm -f $(TARGET)
