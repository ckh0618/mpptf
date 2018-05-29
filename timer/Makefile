
#CXX_FLAGS=-std=c++11 -g -O0 -W -Wall
CXX_FLAGS=-std=c++11 -O2 -W -Wall 
INC= -I.  
LIB=-lMultiPointTimer
LPATH= -L.
all: 
	g++ -fpic -c ${CXX_FLAGS} ${INC} ${LIB} ${LPATH} MultiPointTimer.cc
	g++ -fpic -c ${CXX_FLAGS} ${INC} ${LIB} ${LPATH} MultiPointTimerC.cc

	gcc -shared -o libMultiPointTimer.so MultiPointTimerC.o  MultiPointTimer.o
	ar rcs libMultiPointTimer.a MultiPointTimerC.o MultiPointTimer.o


test : 
	g++ ${INC} test.cc -o test_timer ${LPATH} ${LIB}
	gcc ${INC} test.c -o test_timer_c ${LPATH} ${LIB} -lstdc++


clean:
	rm -rf *.o test_timer *.so test_timer_c *.a
