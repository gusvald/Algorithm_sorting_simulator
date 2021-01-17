#ifndef ALGORYTMY_S_FIFO_H
#define ALGORYTMY_S_FIFO_H

#include "Data_generator.h"

class S_FIFO {
public:
    explicit S_FIFO(Data_generator &stack);
    void sort(Data_generator &stack);
    ~S_FIFO();
private:
    Data_generator &stack;

    int minTime();
};


#endif
