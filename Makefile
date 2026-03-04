X11_PREFIX ?= /opt/X11

CXX = g++
CXXFLAGS = -Wall -std=c++11 -I . -I$(X11_PREFIX)/include
LDFLAGS  = -L$(X11_PREFIX)/lib
LDLIBS   = -lX11 -lpthread

OBJS = Aquarium.o Bestiole.o Milieu.o

main: main.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

Aquarium.o: Aquarium.cpp Aquarium.h
	$(CXX) $(CXXFLAGS) -c $<

Bestiole.o: Bestiole.cpp Bestiole.h
	$(CXX) $(CXXFLAGS) -c $<

Milieu.o: Milieu.cpp Milieu.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o main