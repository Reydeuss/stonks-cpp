CXX = clang++
TARGET = build/main
CXXFLAGS = -Wall -std=c++20

all:
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

run:
	./$(TARGET)
