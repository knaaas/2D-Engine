CC = g++
INCLUDE = ../src/
CFLAGS = -Wall -c -std=c++0x -g -I$(INCLUDE)
CLIB = -lopengl32 -lglew32 -lglfw3
SOURCES = test.cpp gpu/shader.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = out

	
all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS)  $(CLIB) -o $@
	
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)
	

	
