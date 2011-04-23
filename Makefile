
CC	= g++
CFLAGS	= -Wall -std=gnu++0x
FILES	= $(wildcard example/*.cpp)
TARGETS = $(FILES:.cpp=.jspp)

all: $(TARGETS)

%.jspp: %.cpp
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm $(TARGETS)