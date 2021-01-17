#include <iostream>
#include <string>
#include <ctime>
#include "Data_generator.h"
#include "S_FIFO.h"
#include "S_LRU.h"

enum algorythmChooser {
    FIFO = 0,
    LRU = 1
};

algorythmChooser whichAlgorythm;

int main() {
    srand( static_cast<unsigned int>(time(nullptr)));

    Data_generator object(1000,5,"R");

    S_FIFO fifo(object);

    S_LRU lru(object);

    for(unsigned long i=0; i<object.Qframe.size(); i++){
        if(object.Qframe.at(i).count != object.pagesList.begin()->count){
        object.Qframe.at(i).count=object.pagesList.begin()->count;
        }
        object.pagesList.erase(object.pagesList.begin());
    }

    object.sFrames();

    for(unsigned long i=0; i<object.Qframe.size(); i++){
        std::cout << "|" << object.Qframe.at(i).count << "|";
    }

    std::cout<<std::endl;

    while(!object.pagesList.empty()) {

        if (whichAlgorythm == FIFO) {
            fifo.sorting(object);
        }
        if (whichAlgorythm == LRU) {
            lru.sorting(object);
        }

        for(unsigned long i=0; i<object.Qframe.size(); i++){
            object.Qframe.at(i).timeWithoutChange++;
        }

        object.sFrames();

        for(unsigned long i=0; i<object.Qframe.size(); i++){
            std::cout << "|" << object.Qframe.at(i).count << "|";
        }

        std::cout<<std::endl;
    }

    object.beginSaving();

    return 0;
}


