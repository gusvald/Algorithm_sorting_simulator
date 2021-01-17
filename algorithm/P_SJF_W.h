#ifndef ALGORYTMY_P_SJF_W_H
#define ALGORYTMY_P_SJF_W_H

#include "Data_generator.h"

class P_SJF_W {
    public:
        explicit P_SJF_W(Data_generator &stack);
        void sort(Data_generator &stack);
        ~P_SJF_W();
    private:
        Data_generator &stack;
};


#endif
