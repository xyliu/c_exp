PROG = cpuid
CFLAGS= -g
all: $(PROG)

%.o: %.cpp
	g++ -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(PROG)
