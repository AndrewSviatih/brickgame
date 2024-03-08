CC = gcc
CFLAGS = -Wall -Werror -Wextra
C11 = -std=c11

CPP = cppcheck --enable=all --suppress=missingIncludeSystem

MAIN = main.c

BUILD_STR = build
CFILES_STR_LIB = $(wildcard s21_bricks_lib/*.c)
OBJS_STR_LIB = $(CFILES_STR_LIB:.c=.o)
OBJS_STR_LIB_DONE = $(addprefix $(BUILD_STR)/,$(CFILES_STR_LIB:.c=.o))

CHECK_LIBS = -lcheck -lsubunit -lm
MY_LIB = s21_bricks.a

all: s21_bricks

s21_bricks: s21_bricks.a tests main final

s21_bricks.a: $(OBJS_STR_LIB)
		ar rcs $(MY_LIB) $(OBJS_STR_LIB_DONE)

main:
		$(CC) -c $(MAIN) -o build/main.o

final:
		$(CC) $(CFLAGS) $(C11) build/main.o $(OBJS_TESTS_DONE) -o s21_bricks -L. $(MY_LIB) $(CHECK_LIBS)

gcov_report:
		$(CC) --coverage $(CFLAGS) $(CFILES_STR_LIB) $(CFILES_TESTS) main.c -o test -lcheck -lsubunit -lm
		./test
		lcov -t "test" -o test.info -c -d ./
		genhtml -o report test.info

cppcheck:
		$(CPP) $(CFILES)

clang_check:
		find -name "*.c" -o -name "*.h" | xargs clang-format -n

clean:
		rm -f s21_bricks $(OBJS_STR_LIB_DONE) $(OBJS_TESTS_DONE) build/main.o $(MY_LIB)
		rm -rf *.gcda
		rm -rf *.gcno
		rm -rf *.info
		rm -rf test
		rm -rf report/*

rebuild: clean s21_bricks

$(OBJS_STR_LIB): %.o: %.c
		$(CC) $(CFLAGS) $(C11) -c $< -o build/$@

valgrind: rebuild
	valgrind --tool=memcheck --leak-check=yes ./s21_bricks