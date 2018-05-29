
CXX_FLAGS=-std=c++11 -O0 -W -Wall -fpic  -g
CXX=g++
INC= -I. -I ./timer
all: 
	cd timer && make
	${CXX} -c ${CXX_FLAGS} ${INC} ${LIB} ${LPATH} Runner.cc
	${CXX} -o Runner Runner.o ./timer/libMultiPointTimer.a -ldl -lpthread 

	cd plugins && make



test : 
	g++ ${INC} test.cc -o test_timer ${LPATH} ${LIB}
	gcc ${INC} test.c -o test_timer_c ${LPATH} ${LIB} -lstdc++ -ldl


clean:
	rm -rf *.o  *.so *.a Runner
	cd plugins && make clean 
