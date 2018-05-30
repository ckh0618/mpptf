
CXX_FLAGS=-std=c++11 -O2 -W -Wall -fpic 
CXX=g++
INC= -I. -I ./timer
all: 
	cd timer && make
	${CXX} -c ${CXX_FLAGS} ${INC} ${LIB} ${LPATH} Runner.cc
	${CXX} -o Runner Runner.o ./timer/libMultiPointTimer.a -ldl -lpthread 

	cd plugins && make

clean:
	rm -rf *.o  *.so *.a Runner
	cd plugins && make clean 
	cd timer && make clean
