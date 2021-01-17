#ifndef ALGORYTMY_PROCESS_H
#define ALGORYTMY_PROCESS_H

#include <string>

struct Process {
    std::string name;
    int timeExecution = 0;
    int timeArrival= 0;
    int timeEnd=0;

};

#endif
