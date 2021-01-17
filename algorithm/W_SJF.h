#ifndef ALGORYTMY_W_SJF_H
#define ALGORYTMY_W_SJF_H
#include "Creator.h"

class W_SJF {
    public:
        explicit W_SJF(Creator &object);
        void sort(Creator &object);
        ~W_SJF();
    private:
        Creator &object;
};
#endif
