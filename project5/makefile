CC=g++
CFLAGS=-c -g -O0 -std=c++11 -Wall
LDFLAGS=
SOURCES=proj5.cpp maze.h maze.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=proj5

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f core $(EXECUTABLE) $(OBJECTS)
