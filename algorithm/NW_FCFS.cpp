#include "NW_FCFS.h"

NW_FCFS::NW_FCFS(Creator &object): object(object) {}

void NW_FCFS::sort(Creator &object) {
    bool temporary=true;
    int timer=0;
    object.working.push_back(object.each_process.at(0));
    object.each_process.erase(object.each_process.begin());
    int numberOfProcess = 1;
    int time=0;
    timer= timer + object.working.begin()->timeArrival;
    while(object.working.begin()->name != "END") {
        if (object.working.empty() && object.each_process.at(0).timeArrival != timer) {
            timer++;
        }
        else {
            if (!object.each_process.empty()) {
                if (object.each_process.begin()->name == "END" && temporary) {
                    object.working.push_back(object.each_process.at(0));
                    temporary = false;
                }
                while (object.each_process.at(0).timeArrival == timer) {
                    std::string name = "P" + std::to_string(numberOfProcess);
                    object.working.push_back({name, object.each_process.at(0).timeExecution, timer});
                    object.each_process.erase(object.each_process.begin());
                    numberOfProcess++;
                }
            }

            if (object.working[0].timeExecution == 0) {
                if (!object.working.empty()) {
                    object.results.push_back(object.working.at(0));
                    object.results.at(object.results.size() - 1).timeEnd = timer;
                    object.results.at(object.results.size() - 1).timeExecution = time;
                    object.results.at(object.results.size() - 1).timeArrival = object.working.at(0).timeArrival;
                    time=0;
                }
                object.working.erase(object.working.begin());
            }

            if (!object.working.empty()) {
                for (auto &i : object.working) {
                    if (i.name != "END") {
                        std::cout << "|" << i.name << " " << i.timeExecution << " "
                                  << i.timeArrival
                                  << "|";
                    }
                }
                if(object.working.begin()->name != "END") {
                    std::cout << std::endl;
                    std::cout << "Working on process:  " << object.working[0].name << " Remaining time: "<< object.working[0].timeExecution << std::endl;
                }
                object.working[0].timeExecution--;
                time++;
            }
            timer++;
        }
    }
    object.beginSaving();
}
NW_FCFS::~NW_FCFS() {}
