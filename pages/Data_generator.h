#ifndef ALGORYTMY_DATA_GENERATOR_H
#define ALGORYTMY_DATA_GENERATOR_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstring>
#include "Page.h"


class Data_generator {
public:
    Data_generator(int quantityPages,int quantityFrames,std::string mode);
    std::vector < Page > pagesList;
    std::vector < Page > Qframe;
    std::vector <std::string> results;

    int how_m_changes;

    void beginSaving();

    void sFrames();

    ~Data_generator();
private:
    int how_m_pages;

    int how_m_frames;

    std::string mode;

    void lData();

    void creator();

    void sIData();

    void sData();

    void iFrames();
};


#endif
