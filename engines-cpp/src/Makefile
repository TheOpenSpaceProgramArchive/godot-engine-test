CC=g++
CXXFLAGS=-I../include -g -fPIC -L../lib -lgodot_cpp_bindings -lgodot_cpp_core -std=c++14
OBJS=ThrustProducer.o Engine.o Part.o PartModule.o ResourceManager.o StandardResources.o ResourceContainer.o
BIN=../lib/libosp.so

all: $(OBJS)
	$(CC) $(CXXFLAGS) -shared -o $(BIN) $(OBJS)

clean:
	rm -f $(BIN) $(OBJS)
