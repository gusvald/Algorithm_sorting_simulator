#include "W_SJF.h"
W_SJF::W_SJF(Creator &object): object(object) {
}

void W_SJF::sort(Creator &object) {
    for (unsigned long i = 0; i < object.working.size() - 1; i++) {
        for (unsigned long j = 0; j < object.working.size() - 1; j++) {
            if (object.working.at(j).timeExecution > object.working.at(j + 1).timeExecution) {
                std::swap(object.working.at(j), object.working.at(j + 1));
            }
        }
    }
}

W_SJF::~W_SJF() {
}

