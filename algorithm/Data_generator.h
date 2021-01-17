#ifndef ALGORYTMY_DATA_GENERATOR_H
#define ALGORYTMY_DATA_GENERATOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstring>
#include "Process.h"


class Data_generator {
public:
    Data_generator(int quantityProcesses,int average,int deviation,int lowBorder,int highBorder,bool read);
    std::vector < Process > queue;
    std::vector < Process > all;
    std::vector < Process > sorted;

    void initSaveData();

    ~Data_generator();
private:
    int quantityProcesses;

    int average;

    int deviation;

    int lowBorder;

    int highBorder;

    bool read;

    void loadData();

    void generator();

    void saveInitialData();

    void saveData();

    void initialSort();
};


#endif
