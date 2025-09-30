COMPILER=clang++
TARGET=build/main
FLAGS=-Wall -std=c++20

build:
	$(COMPILER) $(FLAGS) -o $(TARGET) ./*.cc

run: build
	./$(TARGET)
