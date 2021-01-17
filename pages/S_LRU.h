#ifndef ALGORYTMY_S_LRU_H
#define ALGORYTMY_S_LRU_H

#include "Data_generator.h"

class S_LRU {
public:
    explicit S_LRU(Data_generator &stack);
    void sort(Data_generator &stack);
    ~S_LRU();
private:
    Data_generator &stack;

    int minTime();
};


#endif