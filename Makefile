CXX=g++
CXXOPTS=-c -g -std=c++11 -I./headers
LIBTARGET=lib/libConsoleInterface.a
TARGET=libConsoleInterface.o


Application.o: src/Application.cpp
	$(CXX) $(CXXOPTS) src/Application.cpp -o Application.o

Option.o: src/Option.cpp
	$(CXX) $(CXXOPTS) src/Option.cpp -o Option.o

ConsoleInterface: Application.o Option.o
	ar rcvs $(LIBTARGET) Application.o Option.o

all: delete ConsoleInterface cleanup

cleanup:
	rm -f *.o

delete:
	rm -f *.o
	rm -f $(TARGET)
	rm -f $(LIBTARGET)
