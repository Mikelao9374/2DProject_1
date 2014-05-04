CXX= g++
CXXFLAG= -Wall -std=c++11 -g

SRC= $(PWD)

# Include flags
INCLUDE= -I $(PWD)/include
INCLUDE+= $(shell sdl2-config --cflags)

# Libs flags
LIB+= $(shell sdl2-config --libs)

OBJ= main.o

OUT_EXE= game.exe

$(OUT_EXE): $(OBJ)
	@echo "    LD    "$@
	@$(CXX) $(OBJ) $(CXXFLAG) $(LIB) -o $@

%.o: $(PWD)%.cpp
	@echo "    CC    "$@
	@$(CXX) $< $(CXXFLAG) $(INCLUDE) -c

.PHONY: clean
clean:
	rm -frv *.o $(OUT_EXE)
