# ASCII Video Player

[![License](https://shields.io/badge/License-GNU%20General%20Public%20License%20v3.0-green)](LICENSE)
[![SFML](https://img.shields.io/badge/OpenCV-4.8.0-brightgreen.svg)](https://opencv.org/)
[![nCurses](https://img.shields.io/badge/nCurses-6.4-red.svg)](https://en.wikipedia.org/wiki/Ncurses/)
[![Linux](https://img.shields.io/badge/Platform-Linux-blue.svg)](https://www.linux.org/)

## Overview

This C++ application uses OpenCV to play a video file in ASCII characters.

[![Video Player](https://img.youtube.com/vi/d23n-RNRGtk/0.jpg)](https://www.youtube.com/watch?v=d23n-RNRGtk)

## Requirements

- C++ compiler
- OpenCV 4.0 or later ([OpenCV Get Started](https://opencv.org/get-started/))
- nCurses

## Getting Started

1. Clone the repository
```bash
git clone https://github.com/ignabelitzky/ascii-video-player.git
cd ascii-video-player
```
2. Build the project using the Makefile
```bash
make
```
3. Run the executable
```bash
./video-player <path-video-file> <path-audio-file>
```

## License

This project is licensed under the [GNU General Public License v3.0](LICENSE). You can find the full text of the license here [LICENSE](LICENSE).
