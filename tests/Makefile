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



LIBRARY_SOURCES = ../src/parcer.c


LIBRARY_OBJECTS = parser.o 

TEST_SOURCES =  s21_parcer.c \
				test.c \

all: test gcov_report

compile_objects:
	$(CC) $(CFLAGS) -c ${LIBRARY_SOURCES}

s21_parser.a: compile_objects
	ar -rc s21_parser.a ${LIBRARY_OBJECTS}
	#ranlib s21_parser.a
	rm -f *.o


build: s21_parser.a

rebuild: clean build

test: clean
	$(CC) $(CFLAGS) $(TEST_SOURCES) -o tests.out ${LIBRARY_SOURCES} $(CHECK_FLAGS) $(GCOV_FLAGS)
	./tests.out
test_valgrind: rebuild
	$(CC) $(CFLAGS) $(LDFLAGS) -o tests.out $(TEST_SOURCES) s21_parser.a $(CHECK_FLAGS) $(GCOV_FLAGS)
	valgrind --log-file=valgrind.log --leak-check=full --track-origins=yes ./tests.out

gcov_report: test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	@if command -v $(OPEN_CMD) > /dev/null; then \
        $(OPEN_CMD) ./gcov_report/index.html; \
    else \
        echo "Please open ./gcov_report/index.html manually"; \
    fi

clean:
	@rm -rf ../src/*.o ../*/*.out ./*/*.a ../src/*.a
	@rm -rf *.gcda *.gcno *.info gcov_report
style:
	cp ../materials/linters/.clang-format .
	find .. -name "*.c" -exec clang-format -i {} \;
	find .. -name "*.h" -exec clang-format -i {} \;
	rm -rf .clang-format

style_test:
	cp ../materials/linters/.clang-format .
	find .. -name "*.c" -exec clang-format -n {} \;
	find .. -name "*.h" -exec clang-format -n {} \;
	rm -rf .clang-format

test_manual: rebuild
	$(CC) $(CFLAGS) ../tests/main.c s21_parser.a -o main_test.out
	./main_test.out
