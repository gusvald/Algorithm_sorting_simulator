#include "S_LRU.h"

S_LRU::S_LRU(Data_generator &stack):stack(stack) {

}

void S_LRU::sort(Data_generator &stack) {

    for(unsigned long j=0;j<stack.frames.size();j++){
        if(stack.frames.at(j).count==stack.pagesList.at(0).count){
            stack.frames.at(j).timeWithoutChange=0;
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
int S_LRU::minTime() {
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

S_LRU::~S_LRU() {

}
