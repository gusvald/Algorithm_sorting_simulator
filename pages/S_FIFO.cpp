#include "S_FIFO.h"



S_FIFO::S_FIFO(Data_generator &object): object(object) {}

void S_FIFO::sorting(Data_generator &object) {

    for(unsigned long j=0; j < object.Qframe.size(); j++){
    if(object.Qframe.at(j).count == object.pagesList.at(0).count){
    object.pagesList.erase(object.pagesList.begin());
    return;
    }
    }
    int sign = mTime();

    object.Qframe.at(sign).count=object.pagesList.begin()->count;
    object.Qframe.at(sign).timeWithoutChange=0;
    object.pagesList.erase(object.pagesList.begin());
    object.how_m_changes++;

}
int S_FIFO::mTime() {
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

S_FIFO::~S_FIFO() {

}


