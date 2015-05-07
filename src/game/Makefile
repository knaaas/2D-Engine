CC = g++
CFLAGS = -c -g -Wall -std=c++11 
LDFLAGS =
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = game.out

all: $(SOURCES) $(EXECUTABLE)
	    
$(EXECUTABLE): $(OBJECTS) 
	    $(CC) $(OBJECTS) -o $@

.cpp.o:
	    $(CC) $(LDFLAGS) $(CFLAGS) $< -o $@
clean:
	rm -r *.o
