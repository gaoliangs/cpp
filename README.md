# cpp


g++ -std=c++11 -o main main.cpp data.cpp topo.cpp symbol.cpp symbolic.cpp matrix.cpp func.cpp output.cpp util.cpp

./main

cd output

g++ -std=c++11 -o treescore treescore.cpp 

treescore
