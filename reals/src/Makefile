CXX=g++
CXXFLAGS=-lgmp -lmpfr -L../lib -I../include -lgodot_cpp_bindings -lgodot_cpp_core -fPIC -Wall -g
OBJS=TestScript.o
BIN=../lib/libreals-test.so

all: $(OBJS)
	$(CXX) $(CXXFLAGS) -shared -o $(BIN) $(OBJS)