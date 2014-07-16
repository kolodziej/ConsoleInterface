CXX=g++
CXXOPTS=-c -std=c++11 -I./headers
LIBTARGET_RELEASE=lib/Release/libConsoleInterface.a
LIBTARGET_DEBUG=lib/Debug/libConsoleInterface.a
TARGET=libConsoleInterface.o
OBJS=src/Application.o src/Option.o src/Exception.o


$(OBJS): %.o: %.cpp
	$(CXX) $(CXXOPTS) $< -o $@

debug: CXXOPTS += -DDEBUG -g
debug: $(OBJS)
	ar rcvs $(LIBTARGET_DEBUG) $(OBJS)

release: $(OBJS)
	ar rcvs $(LIBTARGET_RELEASE) $(OBJS)
	
all_release: release cleanup
all_debug: debug cleanup

all: all_release

cleanup:
	rm -f src/*.o

delete:
	rm -f $(LIBTARGET_DEBUG) $(LIBTARGET_RELEASE) $(TARGET) src/*.o
