CC=g++
CFLAGS=-std=c++11

# Add source files to your project
SOURCES=$(wildcard src/*.cpp)
MAIN=main.cpp

# Generate object file names
OBJECTS=$(SOURCES:.cpp=.o)
MAIN_OBJECT=$(MAIN:.cpp=.o)

# Generate final executable name
EXECUTABLE=Maze

# Add header file directories
INCLUDES=-Iinclude

all: $(SOURCES) $(MAIN) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(MAIN_OBJECT)
	$(CC) $(CFLAGS) $(OBJECTS) $(MAIN_OBJECT) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS) $(MAIN_OBJECT)

