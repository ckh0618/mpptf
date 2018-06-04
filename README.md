
# MPPTF 

Multi Purpose Performance Testing Framework. 

# 개념 및 목적 

MPPTF는 성능 및 Latency 측정을 반복적인 개발없이 수행할 수 있도록 만든 일종의 프레임워크이다. 사용자는 성능테스트를 위한 모듈을 Shared Library 형태로 만들고 이를 Runner 라는 프로그램에서 호출함으로 수행되며, 다음과 같은 반복적인 일들을 자동화 해준다. 

* Thread 를 통한 Throughput 측정 
* 각각의 Thread간의 Latency 측정 

다음은 MPPTF 를 사용했을때 Output 이다. 

```
$ ./Runner -t 8 -l ./plugins/Sample/libSample.so -c 1000 
Thread[    0] MinLat[  1118.97] AvgLat[  2210.17] MaxLat[  8737.08] 99 Pct[  2640.72] 99.9 Pct[  7503.91] Ops[   452.45]
Thread[    1] MinLat[  1100.56] AvgLat[  2206.16] MaxLat[ 13504.11] 99 Pct[  2625.50] 99.9 Pct[  5093.25] Ops[   453.28]
Thread[    2] MinLat[  1197.55] AvgLat[  2199.76] MaxLat[  8612.68] 99 Pct[  2566.66] 99.9 Pct[  7261.22] Ops[   454.59]
Thread[    3] MinLat[  1165.14] AvgLat[  2212.54] MaxLat[ 11868.77] 99 Pct[  2660.76] 99.9 Pct[  6222.46] Ops[   451.97]
Thread[    4] MinLat[  1138.72] AvgLat[  2212.10] MaxLat[  8127.30] 99 Pct[  2715.90] 99.9 Pct[  7378.87] Ops[   452.06]
Thread[    5] MinLat[  1132.95] AvgLat[  2217.64] MaxLat[ 12039.87] 99 Pct[  2704.85] 99.9 Pct[  5555.14] Ops[   450.93]
Thread[    6] MinLat[  1109.37] AvgLat[  2206.88] MaxLat[  8757.55] 99 Pct[  2629.53] 99.9 Pct[  6485.44] Ops[   453.13]
Thread[    7] MinLat[  1161.77] AvgLat[  2207.48] MaxLat[  8263.16] 99 Pct[  2663.70] 99.9 Pct[  6986.12] Ops[   453.01]
------------------------------------------------------------------------------------------------------------------------
                                                                                                    Total Ops[  3621.42]
```

# 예제 

Runner는 다음과 같은 인자를 받는다. 

 * t : Thread 갯수 
 * l : shared library 
 * c : 각각 Thread가 수행할 횟수 

# 테스트 대상 공유 라이브러리 구현 방법 

C 로 개발할떄는 ITask.h 파일을 구현하고, C++로 구현할때는 ITask.hpp 에 정의된 ITask Interface 의 구현체를 만든 후 ITask.h 의 형태로 C API 를 노출한다. 이는 dlopen 등의 함수가 C API 만을 사용할 수 있기 때문이다. 

ITask Interface의 대한 설명은 다음과 같다. 

* Initalize ( int aThreadIndex, int aTotalCount ) : 초기화를 위한 함수. aThreadIndex는 각각의 Thread 의 고유번호이고 0부터 시작. , aTotalCount는 각각의 Thread 가 수행할 수행횟수 
* Run ( int aIndex ) : 실제 Thread 안에서 호출되는 함수. aIndex는 수행번호 ( 0 부터 aTotalCount - 1 까지  )
* Finalize () : 테스트 종료 후 자원정리등을 위한 함수 

자세한 예제는 SimpleInserter / SimpleSelectTask 를 통해서 확인한다. 

