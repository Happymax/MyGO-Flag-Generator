CFLAGS=-O3

# Detect if is on ARM Mac, and set to use Rosetta 2
OSFLAG :=
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		UNAME_P := $(shell uname -p)
		ifneq ($(filter arm%,$(UNAME_P)),)
			OSFLAG += arch -arch x86_64
		endif
	endif

.PHONY: run clean install uninstall

all:	flag

run:	flag
	./flag

install:	flag
	sudo cp ./flag /usr/local/bin/flag

uninstall:
	sudo rm /usr/local/bin/flag

flag:	flag.c
	$(CC) $(CFLAGS) -o $@ $^

# Creates x86 binary on arm Mac
# For Linux this is the same as flag, but binary is called flagintel
flagintel:	flag.c
	$(OSFLAG) $(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f flag
	rm -f flagintel
