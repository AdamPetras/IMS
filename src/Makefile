CXX=g++
CXXFLAGS=-Wall -Wextra --std=c++11 -g
LDLIBS=-lm -lsimlib

.PHONY: clean

all: ims

OBJS=main.o auto_spekani.o baleni.o mazani.o orezavani.o peceni.o\
     spekani.o sypani.o vazeni.o vlhceni.o utils.o

ims: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)
clean:
	-rm -f *.o ims *.tgz *.zip

#################################################

auto_spekani.o: auto_spekani.cpp auto_spekani.h
baleni.o: baleni.cpp baleni.h utils.h
main.o: main.cpp
mazani.o: mazani.cpp mazani.h orezavani.h vazeni.h utils.h baleni.h
orezavani.o: orezavani.cpp orezavani.h vazeni.h utils.h baleni.h
peceni.o: peceni.cpp peceni.h vlhceni.h mazani.h orezavani.h vazeni.h \
 utils.h baleni.h
spekani.o: spekani.cpp spekani.h utils.h vazeni.h baleni.h
sypani.o: sypani.cpp sypani.h utils.h spekani.h vazeni.h baleni.h
utils.o: utils.cpp utils.h
vazeni.o: vazeni.cpp vazeni.h utils.h baleni.h
vlhceni.o: vlhceni.cpp vlhceni.h
