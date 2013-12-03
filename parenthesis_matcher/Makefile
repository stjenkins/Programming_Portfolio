# Makefile for parens

CPP = g++
OPTS = -c -Wall -Werror
PROG = parens
OBJS = parens.o Stack.o

$(PROG): $(OBJS)
	$(CPP) $(OBJS) -o $(PROG)

parens.o: parens.cpp Stack.h
	$(CPP) $(OPTS) parens.cpp -o parens.o

Stack.o: Stack.cpp Stack.h
	$(CPP) $(OPTS) Stack.cpp -o Stack.o

clean:
	rm *.o parens

test: $(PROG)
	./$(PROG) strings.txt



