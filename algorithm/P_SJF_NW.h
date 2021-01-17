#ifndef ALGORYTMY_P_SJF_NW_H
#define ALGORYTMY_P_SJF_NW_H

#include "Data_generator.h"

class P_SJF_NW {
    public:
        explicit P_SJF_NW(Data_generator &stack);
        void sort(Data_generator &stack);
        ~P_SJF_NW();
    private:
        Data_generator &stack;
};


#endif
