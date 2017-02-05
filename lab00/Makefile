BUILDIR=build
CXX= g++
CFLAGS = -Wall
DEPS = Vector3D.h
OBJ = main.o Vector3D.o

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

go: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
