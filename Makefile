CXX := g++
CXXFLAGS := -Wall -Werror -Wextra -pedantic -std=c++17 -march=native -O2
NCURSES_LIBS := -lncurses
OPENCV_LIBS := `pkg-config --cflags --libs opencv`

TARGET := video-player

SRC := main.cpp utils.cpp
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(NCURSES_LIBS) $(OPENCV_LIBS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(OPENCV_LIBS)

clean:
	rm -f $(TARGET) $(OBJ)

