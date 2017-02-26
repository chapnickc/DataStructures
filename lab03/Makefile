BUILDIR=build
INCLUDE=-I../lib/  -I./
DEPS = Deque.h
OBJ = deque_test.o 

CXX= g++ 
CXXFLAGS= -std=c++11  -Wall -Wno-unused-variable


%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

go: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm *.o 
	rm go
	echo Clean done
