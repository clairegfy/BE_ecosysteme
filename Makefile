X11_PREFIX ?= /opt/X11

CXX = g++
CXXFLAGS = -Wall -std=c++11 -I . -I$(X11_PREFIX)/include
LDFLAGS  = -L$(X11_PREFIX)/lib
LDLIBS   = -lX11 -lpthread

OBJS = Aquarium.o Bestiole.o Milieu.o Gregaire.o Peureuse.o Kamikaze.o Prevoyante.o MultiPersonnalite.o Yeux.o Oreilles.o Nageoires.o Carapace.o Camouflage.o SimMemento.o SimulationAnalyser.o

main: main.cpp $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

Aquarium.o: Aquarium.cpp Aquarium.h
	$(CXX) $(CXXFLAGS) -c Aquarium.cpp

Bestiole.o: Bestiole.cpp Bestiole.h
	$(CXX) $(CXXFLAGS) -c Bestiole.cpp

Milieu.o: Milieu.cpp Milieu.h
	$(CXX) $(CXXFLAGS) -c Milieu.cpp

Gregaire.o: Gregaire.cpp Gregaire.h
	$(CXX) $(CXXFLAGS) -c Gregaire.cpp

Peureuse.o: Peureuse.cpp Peureuse.h
	$(CXX) $(CXXFLAGS) -c Peureuse.cpp

Kamikaze.o: Kamikaze.cpp Kamikaze.h
	$(CXX) $(CXXFLAGS) -c Kamikaze.cpp

Prevoyante.o: Prevoyante.cpp Prevoyante.h
	$(CXX) $(CXXFLAGS) -c Prevoyante.cpp

MultiPersonnalite.o: MultiPersonnalite.cpp MultiPersonnalite.h
	$(CXX) $(CXXFLAGS) -c MultiPersonnalite.cpp

Yeux.o: Yeux.cpp Yeux.h
	$(CXX) $(CXXFLAGS) -c Yeux.cpp

Oreilles.o: Oreilles.cpp Oreilles.h
	$(CXX) $(CXXFLAGS) -c Oreilles.cpp

Nageoires.o: Nageoires.cpp Nageoires.h
	$(CXX) $(CXXFLAGS) -c Nageoires.cpp

Carapace.o: Carapace.cpp Carapace.h
	$(CXX) $(CXXFLAGS) -c Carapace.cpp

Camouflage.o: Camouflage.cpp Camouflage.h
	$(CXX) $(CXXFLAGS) -c Camouflage.cpp

SimMemento.o: SimMemento.cpp SimMemento.h
	$(CXX) $(CXXFLAGS) -c SimMemento.cpp

SimulationAnalyser.o: SimulationAnalyser.cpp SimulationAnalyser.h
	$(CXX) $(CXXFLAGS) -c SimulationAnalyser.cpp

clean:
	rm -f *.o main