INCLUDE= -I./ \
		 -I../lib \
		 -I../lib/json/src 

DEPS=graph_utils.o

CXX= g++ 
CXXFLAGS= -std=c++11 -Wall -Wno-unused-variable -o run

all: $(DEPS) dijk0 dijk1 dijk2 dijk3

dijk0: graphl_dijk0.o
	$(CXX) $(CXXFLAGS) -o $@ $^

dijk1: graphl_dijk1.o
	$(CXX) $(CXXFLAGS) -o $@ $^

dijk2: graphm_dijk2.o
	$(CXX) $(CXXFLAGS) -o $@ $^

dijk3: graphm_dijk3.o
	$(CXX) $(CXXFLAGS) -o $@ $^

run:
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	rm *.o
	rm ./dijk*

