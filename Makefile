CXX := g++
CXXFLAGS := -Wall -Wextra -pedantic -std=c++17 -march=native -O3 -Wno-stringop-overflow -Wno-deprecated-enum-enum-conversion
NCURSES_LIBS := -lncurses
OPENCV_LIBS := `pkg-config --cflags --libs opencv`
MINIAUDIO_LIBS := -ldl -lpthread -lm

TARGET := video-player

SRC := src/main.cpp src/utils.cpp src/audio.cpp
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(NCURSES_LIBS) $(OPENCV_LIBS) $(MINIAUDIO_LIBS)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(OPENCV_LIBS) $(MINIAUDIO_LIBS)

format:
	clang-format -style=Microsoft -i src/*.cpp

clean:
	rm -f $(TARGET) $(OBJ)

