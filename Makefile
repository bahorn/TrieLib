SRC=./example.cpp
BIN="./trieExample"
CXXFLAGS=--std=c++11
CXX=`which c++`

build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(BIN)

clean:
	rm $(BIN)
