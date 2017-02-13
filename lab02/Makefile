BUILDIR=build
CXX= g++ -std=c++11
CXXFLAGS = -Wall
INCLUDE=-I../shaffer/
OBJ = main.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

go: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm *.o
