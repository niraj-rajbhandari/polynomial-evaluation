# C PreProcessor
CPPFLAGS =

# C Compiler
CC = g++-6

# C Compiler Flags
CFLAGS = -Wall

# C++ Compiler
CXX = g++-6

# C++ Compiler Flags
CXXFLAGS = -Wall -pedantic -ansi -std=c++11

# Extra flags to give to compilers when they are supposed to invoke the linker, 'ld', such as -L. Libraries (-lfoo) should be added to the LDLIBS variable instead.
LDFLAGS = 

# Library flags or names given to compilers when they are supposed to invoke the linker, 'ld'. LOADLIBES is a deprecated (but still supported) alternative to LDLIBS. Non-library linker flags, such as -L, should go in the LDFLAGS variable.
LDLIBS = 




CPP_FILES = main.cpp ComplexNumber.cpp Polynomial.cpp Utility.cpp
OBJ_FILES := $(CPP_FILES:.cpp=.o)
HDR_FILES =ComplexNumber.h Polynomial.h Utility.h

PROG = main

.PHONY : all
all : $(PROG)

ComplexNumber.o:ComplexNumber.cpp

Polynomial.o: Polynomial.cpp ComplexNumber.h

Utility.o: Utility.cpp ComplexNumber.h

main.o: main.cpp

main: main.o Utility.o Polynomial.o ComplexNumber.o



.PHONY : clean
clean:
	$(RM) $(OBJ_FILES)

.PHONY : veryclean
veryclean:
	$(RM) $(PROG) $(OBJ_FILES)

.PHONY : tar
tar:
	tar -czvf src.tar.gz $(HDR_FILES) $(CPP_FILES) Makefile

