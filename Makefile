CXX=g++
CXXOPTS=-c -std=c++11
TARGET=ConsoleInterface.o

ConsoleInterface: ConsoleInterface.cpp
	$(CXX) $(CXXOPTS) ConsoleInterface.cpp -o $(TARGET)

all: ConsoleInterface

clean:
	rm -f $(TARGET)
