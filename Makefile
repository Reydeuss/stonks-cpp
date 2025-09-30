COMPILER=clang++
TARGET=build/main
FLAGS=-Wall -Wextra -std=c++20 -Iinclude
SRC_FOLDER=src
SRC=$(wildcard $(SRC_FOLDER)/*.cc)

build: $(TARGET)

$(TARGET): $(SRC)
		@mkdir -p $(dir $@)
		$(COMPILER) $(FLAGS) -o $@ $^

run: build
	./$(TARGET)

clean:
	rm -rf build
