CXX = g++

CXXFLAGS = -O2 -Wall
LDFLAGS = -shared -static -static-libgcc -static-libstdc++ -s

SatinArmor.dll: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
