

all: install clean

install:
	cd qt && qmake && make

uninstall:
	rm -r bin

clean:
	cd qt && make clean && rm Makefile && rm .qmake.stash
	