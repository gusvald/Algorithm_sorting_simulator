#ifndef ALGORYTMY_CREATOR_H
#define ALGORYTMY_CREATOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstring>
#include "Process_S.h"

class Creator {
public:
    Creator(int quantityProcesses, int average, int deviation, int lowBorder, int highBorder, std::string read);
    std::vector < Process_S > working;
    std::vector < Process_S > each_process;
    std::vector < Process_S > results;
    void beginSaving();
    ~Creator();
private:
    int how_m_process;
    int average;
    int interval;
    int lBorder;
    int hBorder;
    std::string mode;
    void lData();
    void generate();
    void beginSave();
    void sData();
    void sortInit();
};


#endif
