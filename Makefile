TEST_PROGRAM=test-simple
GTEST_PROGRAM=gtest
all: $(TEST_PROGRAM) ${GTEST_PROGRAM}
SOURCE_FILES = $(abspath test-simple.cpp log.cpp parser.cpp)
SOURCE_FILES_GTEST = $(abspath gtest.cpp log.cpp parser.cpp)

INCLUDE_FLAGS = -I../include -Igoogletest/googletest/include

CPPFLAGS += $(INCLUDE_FLAGS)
CFLAGS += -Wall -Werror -Wextra
CXXFLAGS += -std=c++17 -Wall -Wall -Werror
LDFLAGS += -lstdc++

OBJ_FILES = $(filter %.o, $(SOURCE_FILES:.cpp=.o) $(SOURCE_FILES:.c=.o))
OBJ_FILES_GTEST = $(filter %.o, $(SOURCE_FILES_GTEST:.cpp=.o) $(SOURCE_FILES_GTEST:.c=.o))

$(TEST_PROGRAM): $(OBJ_FILES)
	g++ $(LDFLAGS) -o $(TEST_PROGRAM) $(OBJ_FILES)

$(GTEST_PROGRAM): $(OBJ_FILES_GTEST)
	g++ $(LDFLAGS) -o $(GTEST_PROGRAM) $(OBJ_FILES_GTEST) -Lgoogletest/build/lib -lgtest -lpthread

clean:
	rm -f $(OBJ_FILES) $(OBJ_FILES_GTEST) $(TEST_PROGRAM) $(GTEST_PROGRAM)

.PHONY: clean all test gtest
