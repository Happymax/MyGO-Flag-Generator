CFLAGS=-O0

OSFLAG=arch -arch x86_64

all:	flag

run:	flag
	./flag

flag:	flag.c
	$(CC) $(CFLAGS) -o $@ $^

flagintel:	flag.c
	$(OSFLAG) $(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f flag
	rm -f flagintel
