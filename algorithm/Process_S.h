#ifndef ALGORYTMY_PROCESS_S_H
#define ALGORYTMY_PROCESS_S_H
#include <string>

struct Process_S {
    std::string name;
    int timeExecution = 0;
    int timeArrival= 0;
    int timeEnd=0;
};
#endif
