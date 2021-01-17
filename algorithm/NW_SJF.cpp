#include "NW_SJF.h"

NW_SJF::NW_SJF(Creator &object): object(object) {
}

void NW_SJF::sort(Creator &object) {
    for (int i = 0; i < object.working.size() - 1; i++) {
        for (int j = 1; j < object.working.size() - 1; j++) {
            if (object.working.at(j).timeExecution > object.working.at(j + 1).timeExecution) {
                std::swap(object.working.at(j), object.working.at(j + 1));
            }
        }
    }
}

NW_SJF::~NW_SJF() {
}

