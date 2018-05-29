
CXX_FLAGS=-std=c++11 -O0 -W -Wall -fpic  -g
CXX=g++
INC= -I. -I.. -I${GOLDILOCKS_HOME}/include
all: 
	gpec SimpleInserter.gc -o SimpleInserter.cc
	${CXX} -c ${CXX_FLAGS} ${INC} ${LIB} ${LPATH} SimpleInserter.cc
	${CXX} -c ${CXX_FLAGS} ${INC} ${LIB} ${LPATH} SimpleInserter.c -o SimpleInserterC.o
	gcc -shared -o libSimpleInserter.so SimpleInserter.o SimpleInserterC.o -lgoldilocksesqls -L${GOLDILOCKS_HOME}/lib -lgoldilockscs-ul64

clean:
	rm -rf *.o  *.so  *.a SimpleInserter.cc
