########################
###
### Unity Configuration
###
########################
#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -rf
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -rf
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=Unity

CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition
#CFLAGS += -Wfatal-errors

TARGET_BASE1=all_tests
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
UNITY_SRC_FILES=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  test/TestSort.c \
  test/test_runners/Test_Runner.c \
  test/test_runners/all_tests.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src
SYMBOLS=

########################
###
### END Unity Configuration
###
########################


SRC = 	src/sort.c \
	src/array.c \
	src/get_opt.c
TEST_MAIN = test/TestMain.c
MAIN = src/main.c
CPPCHECK_FLAGS = --enable=all --suppress=missingIncludeSystem
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all
SANITIZER_FLAGS = -fsanitize=address
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
OUT = sort

all: clean cppcheck valgrind sanitizers test
cppcheck: run-cppcheck
valgrind: compile-test-main run-valgrind
sanitizers: run-sanitizers run-sort
test: compile-unity-tests run-unity-tests

sort:
	$(C_COMPILER) $(CFLAGS) -o $(OUT) $(SRC)

compile-test-main:
	$(C_COMPILER) $(CFLAGS) -o $(OUT) $(SRC) $(TEST_MAIN)

run-cppcheck:
	cppcheck $(CPPCHECK_FLAGS) $(SRC) $(MAIN)

run-valgrind:
	valgrind $(VALGRIND_FLAGS) ./$(OUT) $(ARGS)
	
run-sanitizers:
	$(C_COMPILER) $(CFLAGS) $(SANITIZER_FLAGS) -o $(OUT) $(SRC) $(TEST_MAIN)
	
run-sort:
	- ./$(OUT) $(ARGS)

# Unity tests
compile-unity-tests:
	$(C_COMPILER) $(CFLAGS) $(GCOV_FLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC) $(UNITY_SRC_FILES) -o $(TARGET1)

run-unity-tests:
	- ./$(TARGET1) -v

# Clean up all
clean:
	$(CLEANUP) $(ALL) $(TARGET1) $(OUT) *.o cov* *.dSYM *.gcda *.gcno *.gcov
