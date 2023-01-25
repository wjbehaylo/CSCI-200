TARGET = A6
SRC_FILES = main.cpp Triangle.cpp ScaleneTriangle.cpp IsocelesTriangle.cpp EquilateralTriangle.cpp

CXX = g++
CFLAGS = -Wall -g -std=c++11

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(OS),Windows_NT)
	TARGET := $(TARGET).exe
	DEL = del

	INC_PATH = Z:/CSCI200/include/
	LIB_PATH = Z:/CSCI200/lib/

	ARCH = 
else
	DEL = rm

	INC_PATH = /usr/local/include/
	LIB_PATH = /usr/local/lib/

	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		CCFLAGS += -D LINUX
	endif
	ifeq ($(UNAME_S),Darwin)
		TARGET_MAKEFILE = Makefile.osx
		CCFLAGS += -D OSX
	endif

	UNAME_P := $(shell uname -p)
	ifeq ($(UNAME_P),x86_64)
		ARCH = 
	endif
	ifneq ($(filter %86,$(UNAME_P)),)
		ARCH = 
	endif
	ifneq ($(filter arm%,$(UNAME_P)),)
		ARCH = -arch x86_64
	endif
endif

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(ARCH) -o $@ $^ -L$(LIB_PATH) $(LIBS)

.cpp.o:
	$(CXX) $(CFLAGS) $(ARCH) -o $@ -c $< -I$(INC_PATH)

clean:
	$(DEL) $(TARGET) $(OBJECTS)

# DEPENDENCIES
main.o: main.cpp Triangle.cpp ScaleneTriangle.cpp IsocelesTriangle.cpp EquilateralTriangle.cpp
Triangle.o: Triangle.cpp Triangle.h
ScaleneTriangle.o: Triangle.cpp Triangle.h ScaleneTriangle.cpp ScaleneTriangle.h
IsocelesTriangle.o: Triangle.cpp Triangle.h IsocelesTriangle.cpp IsocelesTriangle.h
EquilateralTriangle.o: Triangle.cpp Triangle.h EquilateralTriangle.cpp EquilateralTriangle.h

.PHONY: all clean