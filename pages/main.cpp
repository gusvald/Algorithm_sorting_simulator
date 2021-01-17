#include <iostream>
#include <string>
#include <ctime>
#include "CreatorP.h"
#include "FIFOfo.h"
#include "LRUfo.h"

enum algorythmChooser {
    FIFO = 0,
    LRU = 1
};

algorythmChooser whichAlgorythm = LRU;

int main() {
    srand( static_cast<unsigned int>(time(nullptr)));

    CreatorP object(100, 3, 0, "R");

    FIFOfo P_Fifo(object);

    LRUfo P_Lru(object);

    if (whichAlgorythm == FIFO) {
        P_Fifo.sorting();
    }
    if (whichAlgorythm == LRU) {
        P_Lru.sorting(object);
    }


    object.beginSaving();


    return 0;
}


