CC=g++
CFLAGS=-c -g -O0 -std=c++11 -Wall
LDFLAGS=
SOURCES=proj7.cpp priorityqueue.h card.cpp card.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=proj7

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f core $(EXECUTABLE) $(OBJECTS)
