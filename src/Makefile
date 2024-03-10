CC = gcc
CFLAGS = -Wall -Werror -Wextra
C11 = -std=c11

CPP = cppcheck --enable=all --suppress=missingIncludeSystem

MAIN = main.c

BUILD_BRICKS = build

CFILES_BRICKS_LIB = $(wildcard brickgame/tetris/*.c)
OBJS_BRICKS_LIB = $(CFILES_BRICKS_LIB:.c=.o)
OBJS_BRICKS_LIB_DONE = $(addprefix $(BUILD_BRICKS)/,$(CFILES_BRICKS_LIB:.c=.o))

CFILES_GUI_LIB = $(wildcard gui/sli/*.c)
OBJS_GUI_LIB = $(CFILES_GUI_LIB:.c=.o)
OBJS_GUI_LIB_DONE = $(addprefix $(BUILD_BRICKS)/,$(CFILES_GUI_LIB:.c=.o))

CHECK_LIBS = -lcheck -lsubunit -lm -lncurses
MY_LIB = s21_bricks.a

all: s21_bricks

s21_bricks: s21_bricks.a gui_lib final

s21_bricks.a: $(OBJS_BRICKS_LIB)
	ar rcs $(MY_LIB) $(OBJS_BRICKS_LIB_DONE)

gui_lib: $(OBJS_GUI_LIB)
	ar rcs gui_bricks.a $(OBJS_GUI_LIB_DONE)

final:
		$(CC) $(CFLAGS) $(C11) main.c $(OBJS_TESTS_DONE) -o s21_bricks -L. $(MY_LIB) gui_bricks.a $(CHECK_LIBS)

gcov_report:
		$(CC) --coverage $(CFLAGS) $(CFILES_BRICKS_LIB) $(CFILES_TESTS) main.c -o test -lcheck -lsubunit -lm
		./test
		lcov -t "test" -o test.info -c -d ./
		genhtml -o report test.info

cppcheck:
		$(CPP) $(CFILES)

clang_check:
		find -name "*.c" -o -name "*.h" | xargs clang-format -n

clean:
		rm -f s21_bricks $(OBJS_BRICKS_LIB_DONE) $(OBJS_TESTS_DONE) build/main.o $(MY_LIB)
		rm -rf *.gcda
		rm -rf *.gcno
		rm -rf *.info
		rm -rf test
		rm -rf report/*
		rm -rf *.out

rebuild: clean s21_bricks

$(OBJS_BRICKS_LIB): %.o: %.c
		$(CC) $(CFLAGS) $(C11) -c $< -o build/$@

$(OBJS_GUI_LIB): %.o: %.c
		$(CC) $(CFLAGS) $(C11) -c $< -o build/$@

valgrind: rebuild
	valgrind --tool=memcheck --leak-check=yes ./s21_bricks