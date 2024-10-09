C = gcc
CC = gcc -std=c11 -c
ARCR= ar cr
RLIB = ranlib
RM = rm
GENHTML = genhtml
SOURCE = s21_*.c
TESTS = test.c
OBJ = *.o
ARCHIVE = s21_calc.a
ALL_EX = $(OBJ) $(ARCHIVE) a.out *.gch *.gcno *.info *.gcda report
EXGCOVREP = a.out *.gcno *.info *.gcda

RUN_OUT = ./a.out

WFLAGS = -Wall -Werror -Wextra
LFLAGS = -lm -lpthread -lcheck

ifeq ($(shell uname), Linux)
LFLAGS = -lcheck -lsubunit -lm -lrt -lpthread
endif

DFLAGS = -fprofile-arcs -ftest-coverage
VALGRIND_FLAGS = --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose

INSTALL_DIR = ../build/Qt_Calc
ARCHIVE_DIR = ../Archive

ifeq ($(shell uname), Darwin)
	EXPLORER = open
	APP = Qt_Calc.app
else
	EXPLORER = xdg-open
	APP = Qt_Calc
endif

all: dvi install

install: uninstall
	mkdir $(INSTALL_DIR)
	cd ../Qt_Calc && qmake Qt_Calc.pro -o $(INSTALL_DIR)/Makefile && make -C $(INSTALL_DIR)/
	chmod +rwx $(INSTALL_DIR)
	chmod +rwx $(INSTALL_DIR)/$(APP)
	rm -f $(INSTALL_DIR)/*.o
	$(EXPLORER) ../Manual.md

uninstall:
	rm -rf $(INSTALL_DIR)

dvi:
	$(EXPLORER) ../Manual.md
	
dist: install
	rm -rf $(ARCHIVE_DIR)
	mkdir $(ARCHIVE_DIR)
	mkdir $(ARCHIVE_DIR)/Calculator_v1.0
	cp -r $(INSTALL_DIR)/$(APP) $(ARCHIVE_DIR)/Calculator_v1.0
	cp -r ../Manual.md $(ARCHIVE_DIR)/Calculator_v1.0
	cd $(ARCHIVE_DIR) && tar cvzf Archive_SmartCalc_v1.0.tgz Calculator_v1.0 && rm -rf Calculator_v1.0

s21_calc.a:
	$(CC) $(WFLAGS) $(SOURCE)
	$(ARCR) $(ARCHIVE) $(OBJ)
	$(RLIB) $(ARCHIVE)
	$(RM) $(OBJ)

test: s21_calc.a
	$(CC) $(TESTS)
	$(C) $(OBJ) -L. $(ARCHIVE) $(LFLAGS)
	$(RM) $(OBJ)
	$(RUN_OUT)

gcov_report: s21_calc.a
	$(C) $(DFLAGS) $(SOURCE) $(TESTS) $(LFLAGS)
	$(RUN_OUT)
	lcov -t "test" -o *.info -c -d .
	$(GENHTML) -o report/ *info
	open ./report/index.html
	$(RM) $(EXGCOVREP)
	
clean:
	$(RM) -rf $(ALL_EX)
	$(RM) -rf $(INSTALL_DIR)
	rm -rf $(ARCHIVE_DIR)

clean_a:
	$(RM) $(ARCHIVE)

valgrind: valgrind_build
valgrind_build: s21_calc.a
	$(CC) $(TESTS)
	$(C) $(OBJ) -L. $(ARCHIVE) $(LFLAGS)
	$(RM) $(OBJ)
	CK_FORK=no valgrind $(VALGRIND_FLAGS) --log-file=RESULT_VALGRIND.txt ./a.out

style:
	cp ../../materials/linters/.clang-format .
	cp ../../materials/linters/.clang-format ./test
	clang-format -n *.c
	clang-format -n *.h
	clang-format -n ../Credit/*.c
	clang-format -n ../Credit/*.h
	rm ./.clang-format
	rm ./test

install_lcov_for_brew:
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

leak: test
	CK_FORK=no leaks --atExit -- ./a.out

rebuild: clean install
