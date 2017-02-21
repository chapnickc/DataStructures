BUILDIR=build
CXX= g++ -std=c++11
CXXFLAGS = -Wall -Wno-unused-variable
INCLUDE=-I../lib/ -I../shaffer/book.h 
OBJ = main.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

go: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm *.o
	rm go
