CC = g++
INCLUDE = ../src/
CFLAGS = -Wall -c -std=c++0x -g -I$(INCLUDE)
CLIB = -lopengl32 -lglew32 -lglfw3
SOURCES = test.cpp ../gpu/shader.cpp ../scene/camera.cpp ../scene/instance.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = out

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