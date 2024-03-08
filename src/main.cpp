#include <iostream>
#include <ncurses.h>
#include <chrono>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "../include/utils.hpp"
#include "../include/audio.hpp"
#define MINIAUDIO_IMPLEMENTATION
#include "../include/miniaudio.hpp"
#include <chrono>

int main(int argc, char *argv[])
{
    if (!check_input(argc, argv))
    {
        return -1;
    }

    // std::string density = "@%*+=-. '~^_:;,<ix+-?10|tfjrxnuvM@$0ZNTIt;:";
    // std::string density = " .:-=+*#%@";
    std::string density = "@%#*+=-:. ";
    // std::string density = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,^`. ";

    cv::VideoCapture cap(argv[1]);
    double fps = cap.get(cv::CAP_PROP_FPS);
    cv::Mat frame;
    int videoHeight = 0, videoWidth = 0;
    int colorBlue = 0, colorGreen = 0, colorRed = 0;
    int index = 0, avgColor = 0;

    // Initialise screen
    initscr();

    // Disable input buffering
    cbreak();

    // Capture of special keys (like F1, F2, etc)
    keypad(stdscr, TRUE);

    // Don't display pressed keys
    noecho();

    nodelay(stdscr, TRUE);

    // Initialise of colors
    if (has_colors())
    {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLACK);
        attron(COLOR_PAIR(1));
    }

    // Program logic
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    move(0, 0);

    int input = '\0';

    Audio *audio = nullptr;

    try
    {
        audio = new Audio("./resources/audios/gta_vi.mp3");
    }
    catch (std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
    audio->play();

    while (true)
    {
        auto initTime = std::chrono::high_resolution_clock::now();
        cap >> frame;
        if (frame.empty())
        {
            std::cout << "End of the video" << std::endl;
            break;
        }
        cv::resize(frame, frame, cv::Size(xMax, yMax));
        cv::Size sz = frame.size();
        videoWidth = sz.width;
        videoHeight = sz.height;
        for (int i = 0; i < videoHeight; ++i)
        {
            for (int j = 0; j < videoWidth; ++j)
            {
                colorBlue = frame.at<cv::Vec3b>(i, j)[0];
                colorGreen = frame.at<cv::Vec3b>(i, j)[1];
                colorRed = frame.at<cv::Vec3b>(i, j)[2];
                avgColor = (colorBlue + colorGreen + colorRed) / 3;
                index = floor(avgColor / (255 / density.size()));
                if (index >= static_cast<int>(density.size()))
                    index = density.size() - 1;
                addch(density.at(index));
                index = 0;
            }
            move(i + 1, 0);
        }
        refresh();
        auto finalTime = std::chrono::high_resolution_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::milliseconds>(finalTime - initTime);
        napms(1000 / fps - time_span.count());
        input = getch();
        if (input == 'q' || input == 'Q')
            break;
    }
    delete audio;
    cap.release();
    getch();

    // End ncurses
    endwin();
}
