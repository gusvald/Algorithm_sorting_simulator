#ifndef ALGORYTMY_S_FIFO_H
#define ALGORYTMY_S_FIFO_H

#include "Data_generator.h"

class S_FIFO {
public:
    explicit S_FIFO(Data_generator &object);
    void sorting(Data_generator &object);
    ~S_FIFO();
private:
    Data_generator &object;

    int mTime();
};


#endif
