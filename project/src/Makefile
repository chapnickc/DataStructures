
TARGET=grdijkl1.cpp 
INCLUDE= -I./ \
		 -I../lib \
		 -I../lib/json/src 

OBJ = grdijkl1.o 


CXX= g++ 
CXXFLAGS= -std=c++11  -Wall -Wno-unused-variable -o go

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

go: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm *.o

