CXX = clang++
CXXFLAGS = -std=c++20 -Iinc

SRC = src/compiler.cpp src/linker.cpp src/scanner.cpp src/service.cpp src/utils.cpp mycompiler.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = mycompiler

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
