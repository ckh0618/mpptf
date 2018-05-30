
CXX_FLAGS=-std=c++11 -O0 -W -Wall -fpic  -g
CXX=g++
INC= -I. -I.. -I${GOLDILOCKS_HOME}/include
all: 
	gpec PCRF.gc -o PCRF.cc
	${CXX} -c ${CXX_FLAGS} ${INC} ${LIB} ${LPATH} PCRF.cc
	${CXX} -c ${CXX_FLAGS} ${INC} ${LIB} ${LPATH} PCRF.c -o PCRFC.o
	gcc -shared -o libPCRF.so PCRF.o PCRFC.o -lgoldilocksesqls -L${GOLDILOCKS_HOME}/lib -lgoldilockscs-ul64

clean:
	rm -rf *.o  *.so  *.a PCRF.cc
