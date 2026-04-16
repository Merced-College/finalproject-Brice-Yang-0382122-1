CXX = g++
CXXFLAGS = -std=c++11
TARGET = finalproject
SRC_DIR = chooseyourownadventure
SOURCES = $(addprefix $(SRC_DIR)/, main.cpp LinkedList.cpp Room.cpp Enemy.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	cd $(SRC_DIR) && ../$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all run clean
