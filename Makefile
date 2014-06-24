CXX=g++
CXXOPTS=-c -std=c++11 -I./headers
LIBTARGET=lib/libConsoleInterface.a
TARGET=libConsoleInterface.o


Application.o: src/Application.cpp
	$(CXX) $(CXXOPTS) src/Application.cpp -o Application.o

ConsoleInterface: Application.o
	ar rcvs $(LIBTARGET) Application.o

all: delete ConsoleInterface cleanup

cleanup:
	rm -f *.o

delete:
	rm -f *.o
	rm -f $(TARGET)
	rm -f $(LIBTARGET)
