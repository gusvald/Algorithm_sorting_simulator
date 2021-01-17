#ifndef ALGORYTMY_CREATORP_H
#define ALGORYTMY_CREATORP_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstring>
#include "Page_P.h"


class CreatorP {
public:
    CreatorP(int quantityPages, int quantityFrames,int how_m_changes, std::string mode);
    std::vector < Page_P > pagesList;
    std::vector < Page_P > Qframe;
    std::vector <std::string> results;

    int how_m_changes;

    void beginSaving();

    void sFrames();

    ~CreatorP();
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
