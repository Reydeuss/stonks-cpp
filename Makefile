COMPILER=clang++
TARGET=build/main
FLAGS=-Wall -Wextra -std=c++20 -Iinclude
SRC_FOLDER=src

build:
	$(COMPILER) $(FLAGS) -o $(TARGET) $(src)/*.cc

run: build
	./$(TARGET)
