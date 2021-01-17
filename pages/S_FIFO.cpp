#include "S_FIFO.h"



S_FIFO::S_FIFO(Data_generator &stack): stack(stack) {}

void S_FIFO::sort(Data_generator &stack) {

    for(unsigned long j=0;j<stack.frames.size();j++){
    if(stack.frames.at(j).count==stack.pagesList.at(0).count){
    stack.pagesList.erase(stack.pagesList.begin());
    return;
    }
    }
    int sign = minTime();

    stack.frames.at(sign).count=stack.pagesList.begin()->count;
    stack.frames.at(sign).timeWithoutChange=0;
    stack.pagesList.erase(stack.pagesList.begin());
    stack.changes++;

}
int S_FIFO::minTime() {
    int time=0;
    int sign=0;
    for (unsigned long i = 0; i < stack.frames.size(); i++) {
        if (stack.frames.at(i).timeWithoutChange > time) {
            time = stack.frames.at(i).timeWithoutChange;
            sign = i;
        }
    }
    return sign;
}

S_FIFO::~S_FIFO() {

}


