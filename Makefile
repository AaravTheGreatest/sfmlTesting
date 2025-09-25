CXX = g++
CXXFLAGS = -Wall -Werror
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp
OBJ = main.o
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LIBS)

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -c $(SRC) -o $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

