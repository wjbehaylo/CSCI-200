# A line starting with a has is a comment, we'll build up
# the below example

TARGET = L3A
SRC_FILES = main.cpp test_suite.cpp string_functions.cpp

# DO NOT EDIT BELOW HERE
CXX = g++
CFLAGS = -Wall -g -std=c++11
OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

# DEPENDENCIES
test_suite.o: test_suite.cpp test_suite.h string_functions.h
string_functions.o: string_functions.cpp string_functions.h
main.o: main.cpp test_suite.h
