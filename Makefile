# A line starting with a has is a comment, we'll build up
# the below example

TARGET = ChessPostions
SRC_FILES = main.cpp DisplayBoard.cpp Piece.cpp Board.cpp

# DO NOT EDIT BELOW HERE
CXX = g++
CFLAGS = -Wall -g -std=c++17
OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

# DEPENDENCIES
DisplayBoard.o: DisplayBoard.cpp DisplayBoard.hpp
Piece.o: Piece.hpp Piece.cpp Board.hpp Board.cpp
Board.o: Board.cpp Board.hpp Piece.cpp Piece.hpp
main.o: main.cpp DisplayBoard.cpp Piece.cpp Board.cpp Board.hpp Piece.hpp DisplayBoard.hpp
