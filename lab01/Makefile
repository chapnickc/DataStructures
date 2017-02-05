BUILDIR=build
CXX= g++ -std=c++11
CXXFLAGS = -Wall
DEPS = VectorND.h Vector3D.h main.h
OBJ = VectorND.o Vector3D.o  main.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

go: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm *.o
