.PHONY: all clean s21_affin.a test gcov_report clang

GCC = gcc -Wall -Werror -Wextra

all: s21_affin.a

s21_affin.a:
	@$(GCC) -c affine_transformations.c parcer.c -lm
	@ar rcs affine_transformations.a *.o
	@ranlib affine_transformations.a
	@rm -rf *.o

test :
	@$(GCC) tests/*.c affine_transformations.a -lcheck -lrt -lpthread -lsubunit -lm -o s21_test
	@./s21_test

clean :
	@rm -rf *.o *.a
