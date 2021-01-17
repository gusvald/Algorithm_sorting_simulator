#ifndef ALGORYTMY_NW_SJF_H
#define ALGORYTMY_NW_SJF_H
#include "Creator.h"

class NW_SJF {
    public:
        explicit NW_SJF(Creator &object);
        void sort(Creator &object);
        ~NW_SJF();
    private:
        Creator &object;
};

#endif
