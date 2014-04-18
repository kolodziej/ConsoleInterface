CXX=g++
CXXFLAGS=-std=c++11 -g
TARGET=ConsoleInterfaceTest

all: main.cpp ../ConsoleInterface.cpp
	$(CXX) -c $(CXXFLAGS) ../ConsoleInterface.cpp -o ../libConsoleInterface.a
	$(CXX) $(CXXFLAGS) -I.. -L.. -lConsoleInterface main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)
