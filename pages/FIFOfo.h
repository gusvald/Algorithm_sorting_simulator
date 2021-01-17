#ifndef ALGORYTMY_FIFOFO_H
#define ALGORYTMY_FIFOFO_H

#include "CreatorP.h"

class FIFOfo {
public:
    explicit FIFOfo(CreatorP &object);
    void sorting();
    ~FIFOfo();

private:
    CreatorP &object;
    void moreSort();
    int mTime();
};


#endif
