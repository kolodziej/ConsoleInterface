CXX=g++
CXXOPTS=-c -std=c++11
TARGET=libConsoleInterface.a

ConsoleInterface: ConsoleInterface.cpp
	$(CXX) $(CXXOPTS) ConsoleInterface.cpp -o $(TARGET)

all: ConsoleInterface

clean:
	rm -f $(TARGET)
	rm -f *.o
	rm -f *.a
