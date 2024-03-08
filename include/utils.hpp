#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>
#include <iostream>
#include "miniaudio.hpp"

void show_usage(std::string programName);

bool check_input(int& argc, char**& argv);

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount);

#endif