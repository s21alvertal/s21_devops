CC = gcc
#CC = clang
CFLAGS = -Wall -std=c11 `pkg-config --cflags --libs gtk4`
ifeq ($(O), 1)
    CFLAGS += -O2 -march=native -pipe
endif
ifeq ($(VG), 1)
    CFLAGS += -g
endif
TESTSFLAGS = -lcheck
ifeq ($(shell uname), Linux)
    CFLAGS += -lm
    TESTSFLAGS += -lpthread -lrt -lsubunit
endif

SOURCES = $(wildcard *.c)
OBJECTS = $(addprefix obj/,$(SOURCES:.c=.o))
TESTS = 
TESTSOBJ = $(addprefix obj/,$(TESTS:.c=.o))
TESTSSRC = $(addprefix tests/,$(TESTS))
APP = s21_smartcalc.app

all: install

obj/%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

install: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o build/$(APP)

uninstall:
	rm -f build/$(APP)

$(TESTOBJ): $(TESTSSRC)
	$(CC) $(CFLAGS) -c $^ -o $@

test: $(TESTSOBJ) $(LIBNAME)
	$(CC) $(CFLAGS) $(TESTSFLAGS) $^ -o $@
	./$@

gcov_report: $(TESTSSRC) $(SOURCES)
	$(CC) $(CFLAGS) $(TESTSFLAGS) --coverage $^ -o $@
	-./$@
	lcov -t $@ -o $@.info -c -d .
	genhtml -o report $@.info
	open ./report/index.html

style:
	-clang-format -i --style=Google *.c *.h */*.c */*.h

rebuild: clean all

clean:
	rm -rf */*.o report test gcov_report *.a *.gcda *gcno *.gcov *.info

