#ifndef ALGORYTMY_P_FCFS_H
#define ALGORYTMY_P_FCFS_H

#include "Data_generator.h"

class P_FCFS {
public:
explicit P_FCFS(Data_generator &stack);
~P_FCFS();
void sort(Data_generator &stack);
private:
    Data_generator &stack;
};


#endif
