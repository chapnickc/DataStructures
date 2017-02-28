BUILDIR=build
INCLUDE=-I../lib/  -I./
# DEPS = 
OBJ = lab04.o 

CXX= g++ 
CXXFLAGS= -std=c++0x  -Wall -Wno-unused-variable


%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

go: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm *.o 
	rm go
	echo Clean done
