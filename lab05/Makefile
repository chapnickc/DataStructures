BUILDIR=build
INCLUDE=-I../lib/  -I./ -I../shaffer/
# DEPS = 
OBJ = lab05.o 

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
