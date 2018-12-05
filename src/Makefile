CXX=g++
CXXFLAGS=-Wall -Wextra --std=c++11 -g
LDLIBS=-lm -lsimlib

.PHONY: clean

all: ims

OBJS=main.o auto_spekani.o baleni.o mazani.o orezavani.o peceni.o\
     spekani.o sypani.o vazeni.o vlhceni.o

ims: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)
clean:
	-rm -f *.o ims *.tgz *.zip

#################################################

auto_spekani.o: auto_spekani.cpp auto_spekani.h
baleni.o: baleni.cpp baleni.h
main.o: main.cpp
mazani.o: mazani.cpp mazani.h
orezavani.o: orezavani.cpp orezavani.h
peceni.o: peceni.cpp peceni.h
spekani.o: spekani.cpp spekani.h
sypani.o: sypani.cpp sypani.h
vazeni.o: vazeni.cpp vazeni.h
vlhceni.o: vlhceni.cpp vlhceni.h
