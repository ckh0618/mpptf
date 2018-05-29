
CXX_FLAGS=-std=c++11 -O0 -W -Wall -fpic  -g
CXX=g++
INC= -I. -I.. -I${GOLDILOCKS_HOME}/include
all: 
	gpec SimpleSelectTask.gc -o SimpleSelectTask.cc
	${CXX} -c ${CXX_FLAGS} ${INC} ${LIB} ${LPATH} SimpleSelectTask.cc
	${CXX} -c ${CXX_FLAGS} ${INC} ${LIB} ${LPATH} SimpleSelectTask.c -o SimpleSelectSelectInterface.o
	gcc -shared -o libSimpleSelectTask.so SimpleSelectTask.o SimpleSelectSelectInterface.o -lgoldilocksesqls -L${GOLDILOCKS_HOME}/lib -lgoldilockscs-ul64

clean:
	rm -rf *.o test_timer *.so test_timer_c *.a SimpleSelectTask.cc
