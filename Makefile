CXX=g++
CXXOPTS=-c -std=c++11 -I./headers
LIBTARGET_RELEASE=lib/Release/libConsoleInterface.a
LIBTARGET_DEBUG=lib/Debug/libConsoleInterface.a
TARGET=libConsoleInterface.o
OBJS=src/Application.o src/Option.o


$(OBJS): %.o: %.cpp
	$(CXX) $(CXXOPTS) $< -o $@

debug: CXXOPTS += -DDEBUG -g
debug: $(OBJS)
	ar rcvs $(LIBTARGET_DEBUG) $(OBJS)

release: $(OBJS)
	ar rcvs $(LIBTARGET_RELEASE) $(OBJS)
	
all_release: delete release cleanup
all_debug: delete debug cleanup

all: all_release

cleanup:
	rm -f *.o

delete:
	rm -f *.o
	rm -f $(TARGET)
	rm -f $(LIBTARGET)
