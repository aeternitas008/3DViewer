CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 
LDFLAGS=-L/usr/local/lib
GCOV_FLAGS=-fprofile-arcs -ftest-coverage

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    CHECK_FLAGS = -lcheck -lm -lpthread -lsubunit -lrt
    OPEN_CMD = xdg-open
else ifeq ($(UNAME_S),Darwin)
    CHECK_FLAGS = -lcheck -lm -lpthread
    OPEN_CMD = open
endif


LIBRARY_SOURCES = qt/parser.c \
				  qt/affine_transformations.c


LIBRARY_OBJECTS = parser.o\
				  affine_transformations.o

TEST_SOURCES =  tests/s21_parser.c \
				tests/test.c \
				tests/s21_affin_rotate_test.c \
				tests/s21_affin_shift_test.c \
				tests/s21_affin_scale_test.c \
				


all: install

build: install

rebuild: clean build

install:
	cd qt && qmake && make
	cd qt && make clean && rm Makefile && rm .qmake.stash

uninstall:
	@rm -rf bin/

clean: uninstall
	@rm -rf Documentation
	@rm -rf *.o *.out *.a
	@rm -rf *.gcda *.gcno *.info gcov_report

dist:
	tar -cvzf archive.tgz qt/

# dvi:
# 	touch readme.md

dvi:
	@rm -rf Documentation
	@doxygen
	@open Documentation/html/index.html

test: clean
	$(CC) $(CFLAGS) $(TEST_SOURCES) -o tests.out ${LIBRARY_SOURCES} $(CHECK_FLAGS) $(GCOV_FLAGS)
	./tests.out

gcov_report: test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	@if command -v $(OPEN_CMD) > /dev/null; then \
        $(OPEN_CMD) ./gcov_report/index.html; \
    else \
        echo "Please open ./gcov_report/index.html manually"; \
    fi