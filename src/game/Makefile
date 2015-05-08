CC = g++
INCLUDE = ../src/
CFLAGS = -Wall -c -std=c++0x -g -I$(INCLUDE)
CLIB = 
SOURCES = main.cpp state/stack.cpp game/main_state.cpp game/run_state.cpp gui/menu.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = game.out
	
all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS)  $(CLIB) -o $@
	
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)
