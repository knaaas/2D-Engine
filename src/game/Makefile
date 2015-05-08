CC = g++
INCLUDE = ../src/
CFLAGS = -Wall -c -std=c++0x -g -I$(INCLUDE)
CLIB = -lopengl32 -lglew32 -lglfw3
SOURCES = main.cpp state/stack.cpp game/main_state.cpp game/run_state.cpp gui/menu.cpp game/game.cpp ../engine/gpu/shader.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = game.out

ifdef SystemRoot 
#Windows assumed
	RM = del /Q/F
	FixPath = $(subst /,\,$1)
else 
#OS X or Linux assumed
	RM = rm -f
	FixPath = $1
endif

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS)  $(CLIB) -o $@
	
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(call FixPath,$(OBJECTS))