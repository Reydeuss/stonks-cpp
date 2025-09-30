COMPILER=clang++
TARGET=build/main
FLAGS=-Wall -std=c++20

all:
	$(COMPILER) $(FLAGS) -o $(TARGET) ./*.cc

run:
	./$(TARGET)
