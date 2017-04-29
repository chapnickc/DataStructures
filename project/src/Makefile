INCLUDE= -I./ \
		 -I../lib \
		 -I../lib/json/src 


TARGET=graphl_dijk2.cpp 
OBJ = graphl_dijk2.o 

CXX= g++ 
CXXFLAGS= -std=c++11 -Wall -Wno-unused-variable -o run

all: run

dijk3: graphl_dijk3.o
	$(CXX) $(CXXFLAGS) -o $@ $^

run: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<



clean:
	rm *.o

