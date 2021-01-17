#ifndef ALGORYTMY_NW_FCFS_H
#define ALGORYTMY_NW_FCFS_H
#include "Creator.h"


class NW_FCFS {
public:
explicit NW_FCFS(Creator &object);
~NW_FCFS();
void sort(Creator &object);
private:
    Creator &object;
};
#endif
