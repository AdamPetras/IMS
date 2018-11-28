CXX=g++
CXXFLAGS=-Wall -Wextra --std=c++11 -g
.PHONY: clean

all: ims
#OBJS=xxx.o

ims: main.o $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lsimlib -lm
clean:
	-rm -f *.o ims *.tgz *.zip
zip:
	-zip xpetra19_xpitko00.zip *.cpp *.h Makefile


#################################################

main.o: main.cpp