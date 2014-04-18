CXX=g++
CXXOPTS=-c -std=c++11
TARGETDIR=obj
TARGET=ConsoleInterface.o

ConsoleInterface: ConsoleInterface.cpp
	$(CXX) $(CXXOPTS) ConsoleInterface.cpp -o $(TARGETDIR)/$(TARGET)

all: ConsoleInterface

clean:
	rm -rf $(TARGETDIR)
