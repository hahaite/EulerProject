CFLAGS += -W -Wall
CFLAGS += -Wno-unused-variable
CFLAGS += -Wno-unused-parameter

main : main.cpp bigInt.cpp
	g++ -g -o $@ $^ $(CFLAGS)

clean :
	rm -rf main *.o
