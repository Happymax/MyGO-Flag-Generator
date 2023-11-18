CFLAGS=-O0

# Detect if is on ARM Mac, and set to use Rosetta 2
OSFLAG :=
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		UNAME_P := $(shell uname -p)
		ifneq ($(filter arm%,$(UNAME_P)),)
			OSFLAG += arch -arch x86_64
		endif
	endif

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
