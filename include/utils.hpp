#ifndef _UTILS_H_
#define _UTILS_H_

#include "miniaudio.hpp"
#include <iostream>
#include <string>

char intensityToASCII(int intensity);

void show_usage(std::string programName);

bool check_input(int &argc, char **&argv);

void data_callback(ma_device *pDevice, void *pOutput, const void *pInput, ma_uint32 frameCount);

#endif