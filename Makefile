COMPILER=clang++
TARGET=build/main
FLAGS=-Wall -std=c++20
SRC_FOLDER=src

build:
	$(COMPILER) $(FLAGS) -o $(TARGET) $(src)/*.cc

run: build
	./$(TARGET)
