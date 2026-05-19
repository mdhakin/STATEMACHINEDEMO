CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

SRC = src/main.cpp \
      src/StateMachine.cpp \
      src/CommandParser.cpp

TARGET = statemachine

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)