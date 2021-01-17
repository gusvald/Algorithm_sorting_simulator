#include "LRUfo.h"

LRUfo::LRUfo(CreatorP &object): object(object) {

}

void LRUfo::sorting(CreatorP &object) {
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

        moreSort();

        for(unsigned long i=0; i<object.Qframe.size(); i++){
            object.Qframe.at(i).timeWithoutChange++;
        }

        object.sFrames();

        for(unsigned long i=0; i<object.Qframe.size(); i++){
            std::cout << "|" << object.Qframe.at(i).count << "|";
        }

        std::cout<<std::endl;
    }
}

int LRUfo::minTime() {
    int time=0;
    int sign=0;
    for (unsigned long i = 0; i < object.Qframe.size(); i++) {
        if (object.Qframe.at(i).timeWithoutChange > time) {
            time = object.Qframe.at(i).timeWithoutChange;
            sign = i;
        }
    }
    return sign;
}

void LRUfo::moreSort() {
    for(unsigned long j=0; j < object.Qframe.size(); j++){
        if(object.Qframe.at(j).count == object.pagesList.at(0).count){
            object.Qframe.at(j).timeWithoutChange=0;
            object.pagesList.erase(object.pagesList.begin());
            return;
        }
    }
    int sign = minTime();

    object.Qframe.at(sign).count=object.pagesList.begin()->count;
    object.Qframe.at(sign).timeWithoutChange=0;
    object.pagesList.erase(object.pagesList.begin());
    object.how_m_changes++;
}

LRUfo::~LRUfo() {

}