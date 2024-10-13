

all: install

build: install

rebuild: clean build

install:
	cd qt && qmake && make
	cd qt && make clean && rm Makefile && rm .qmake.stash

uninstall:
	rm -r bin

clean:
	uninstall 

dist:
	tar -cvzf archive.tgz qt/

dvi:
	touch readme.md