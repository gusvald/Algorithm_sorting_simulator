#ifndef ALGORYTMY_DATA_GENERATOR_H
#define ALGORYTMY_DATA_GENERATOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include "Page.h"


class Data_generator {
public:
    Data_generator(int quantityPages,int quantityFrames,bool read);
    std::vector < Page > pagesList;
    std::vector < Page > frames;
    std::vector <std::string> sorted;

    int changes;

    void initSaveData();

    void saveFrames();

    ~Data_generator();
private:
    int quantityPages;

    int quantityFrames;

    bool read;

    void loadData();

    void generator();

    void saveInitialData();

    void saveData();

    void initFrames();
};


#endif
