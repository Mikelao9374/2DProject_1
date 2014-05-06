# Choose which compiler to use
CXX= g++

# Setup the compiler flags
# -Wall: mean "Turn on all the warrning"
# -std=c++11: use c++11 standard
# -g: add gdb debug symbol into binary file, may increase the size a little
CXXFLAG= -Wall -std=c++11 -g

# Include flags
INCLUDE+= $(shell sdl2-config --cflags)

# Libs flags
LIB+= $(shell sdl2-config --libs)

OBJ= main.o

OUT_EXE= game.exe

# Basic pattern of Makefile:
# Target: dependencies ...
# 	command
#
# note that the indent using for command is TAB!
#
# After choosing a target, GNU make will check if dependencies need to be updated or not exist.
# Then keep finding in this Makefile for the target that can make these dependencies, and so on, untill your target is done or some error occur.
$(OUT_EXE): $(OBJ)
	@echo "    LD    "$@
	@$(CXX) $(OBJ) $(CXXFLAG) $(LIB) -o $@

%.o: %.cpp
	@echo "    CC    "$@
	@$(CXX) $< $(CXXFLAG) $(INCLUDE) -c

.PHONY: clean
clean:
	rm -frv *.o $(OUT_EXE)
