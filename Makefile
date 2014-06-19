CXX=g++
CXXOPTS=-c -std=c++11 -I./headers
TARGET=lib/libConsoleInterface.a

ConsoleInterface: src/ConsoleInterface.cpp
	$(CXX) $(CXXOPTS) src/ConsoleInterface.cpp -o $(TARGET)

all: ConsoleInterface

clean:
	rm -f $(TARGET)
