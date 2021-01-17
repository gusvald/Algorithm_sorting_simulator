#ifndef ALGORYTMY_LRUFO_H
#define ALGORYTMY_LRUFO_H

#include "CreatorP.h"

class LRUfo {
public:
    explicit LRUfo(CreatorP &object);
    void sorting(CreatorP &object);
    ~LRUfo();
    void moreSort();
private:
    CreatorP &object;

    int minTime();
};


#endif
