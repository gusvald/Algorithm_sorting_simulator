#include "P_SJF_NW.h"

P_SJF_NW::P_SJF_NW(Data_generator &stack): stack(stack) {

}

void P_SJF_NW::sort(Data_generator &stack) {
    for (unsigned long i = 0; i < stack.queue.size()-1; i++) {
        for (unsigned long j = 1; j < stack.queue.size()-1; j++) {
            if (stack.queue.at(j).timeExecution > stack.queue.at(j+1).timeExecution) {
                std::swap(stack.queue.at(j), stack.queue.at(j+1));
            }
        }
    }
}

P_SJF_NW::~P_SJF_NW() {

}

