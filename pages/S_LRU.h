#ifndef ALGORYTMY_S_LRU_H
#define ALGORYTMY_S_LRU_H

#include "Data_generator.h"

class S_LRU {
public:
    explicit S_LRU(Data_generator &object);
    void sorting(Data_generator &object);
    ~S_LRU();
private:
    Data_generator &object;

    int minTime();
};


#endif
