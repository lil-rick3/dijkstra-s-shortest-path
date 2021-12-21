CC      = /usr/bin/g++
CFLAGS  = -Wall
LDFLAGS = 

BUILDDIR = build
SOURCEDIR = src
HEADERDIR = src

SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

NAME = dijkstra
BINARY = $(BUILDDIR)/$(NAME).bin

ECHO = echo
RM = rm -rf
MKDIR = mkdir

.PHONY: all clean setup

all: $(BINARY)

$(BINARY): $(BUILDDIR)/$(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(HEADERDIR) -I$(SOURCEDIR) $(OBJECTS) -o $(BINARY) 


$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -I$(HEADERDIR) -I$(SOURCEDIR) -c $< -o $@

setup:
	$(MKDIR) -p $(BUILDDIR)

clean:
	$(RM) $(BINARY) $(OBJECTS)

test: $(BINARY)
	./$< 
