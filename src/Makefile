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

auto_spekani.o: auto_spekani.cpp auto_spekani.h vazeni.h baleni.h \
 vlhceni.h sypani.h spekani.h
baleni.o: baleni.cpp baleni.h
main.o: main.cpp peceni.h vlhceni.h auto_spekani.h vazeni.h baleni.h \
 sypani.h spekani.h mazani.h orezavani.h
mazani.o: mazani.cpp mazani.h orezavani.h vazeni.h baleni.h
orezavani.o: orezavani.cpp orezavani.h vazeni.h baleni.h
peceni.o: peceni.cpp peceni.h vlhceni.h auto_spekani.h vazeni.h baleni.h \
 sypani.h spekani.h mazani.h orezavani.h
spekani.o: spekani.cpp spekani.h vazeni.h baleni.h
sypani.o: sypani.cpp sypani.h spekani.h vazeni.h baleni.h vlhceni.h \
 auto_spekani.h
vazeni.o: vazeni.cpp vazeni.h baleni.h
vlhceni.o: vlhceni.cpp vlhceni.h auto_spekani.h vazeni.h baleni.h \
 sypani.h spekani.h
