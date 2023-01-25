# A line starting with a hashtag is a comment, we'll build up
# the below example

TARGET = A2
SRC_FILES = main.cpp ppm_functions.cpp

# DO NOT EDIT BELOW HERE
CXX = g++
CFLAGS = -Wall -g -std=c++11
OBJECTS = $(SRC_FILES:.cpp=.o) # names all files from SRC_FILES that have a .cpp with a .o
ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

# DEPENDENCIES
main.o: main.cpp ppm_functions.h
ppm_functions.o: ppm_functions.cpp ppm_functions.h