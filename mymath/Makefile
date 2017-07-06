SRC = main.cpp mymath.cpp

CFLAGS += -W -Wall
CFLAGS += -Wno-unused-variable
CFLAGS += -Wno-unused-parameter
CFLAGS += -Wno-sign-compare
CFLAGS += -Wno-format

main : $(SRC)
	g++ -o $@ $^ $(CFLAGS)

clean :
	rm -rf main *.o
