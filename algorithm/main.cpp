#include <iostream>
#include <string>
#include <ctime>
#include "Data_generator.h"
#include "P_FCFS.h"
#include "P_SJF_NW.h"
#include "P_SJF_W.h"

enum algorythmChooser {
    FCFS = 0,
    SJFNW = 1,
    SJFW =2
};

algorythmChooser whichAlgorythm;

Data_generator menu();

int main() {
    srand( static_cast<unsigned int>(time(nullptr)));
    bool isDone=true;
    int timer=0;

    Data_generator stack=menu();

    P_FCFS fcfs(stack);

    P_SJF_NW sjfNW(stack);

    P_SJF_W sjfW(stack);

    stack.queue.push_back(stack.all.at(0));
    stack.all.erase(stack.all.begin());
    int numberOfProcess = 1;
    int time=0;
    timer=timer+stack.queue.begin()->timeArrival;
    //stack.sorted.push_back(stack.queue.at(0));

    while(stack.queue.begin()->name!="END") {
        if (stack.queue.empty() && stack.all.at(0).timeArrival!=timer) {
            timer++;
            std::cout << timer << std::endl;
        }
        else {
            if (!stack.all.empty()) {
                if (stack.all.begin()->name == "END" && isDone) {
                    stack.queue.push_back(stack.all.at(0));
                    isDone = false;
                }
                while (stack.all.at(0).timeArrival == timer) {
                    std::string name = "P" + std::to_string(numberOfProcess);
                    stack.queue.push_back({name, stack.all.at(0).timeExecution, timer});
                    stack.all.erase(stack.all.begin());
                    numberOfProcess++;
                    if (whichAlgorythm == FCFS) {
                        fcfs.sort(stack);
                    }
                    if (whichAlgorythm == SJFNW) {
                        sjfNW.sort(stack);
                    }
                    if (whichAlgorythm == SJFW) {
                        sjfW.sort(stack);
                    }
                }
            }
            if (stack.queue[0].timeExecution == 0) {
                if (!stack.queue.empty()) {
                    stack.sorted.push_back({stack.queue.at(0).name,time,stack.queue.at(0).timeArrival,timer});
                    time=0;
                }
                //stack.sorted.at(stack.sorted.size() - 1).timeEnd = timer;
                stack.queue.erase(stack.queue.begin());
            }
            if (!stack.queue.empty()) {
                for (auto &i : stack.queue) {
                    if (i.name != "END") {
                        std::cout << "|" << i.name << " " << i.timeExecution << " "
                                  << i.timeArrival
                                  << "|";
                    }
                }
                if(stack.queue.begin()->name!="END") {
                    std::cout << std::endl;
                    std::cout << "aktualnie wykonywany proces: " << stack.queue[0].name << " Pozostały czas: "
                              << stack.queue[0].timeExecution << std::endl;
                }
                stack.queue[0].timeExecution--;
                time++;
            }
            timer++;
            std::cout << timer << std::endl;
        }
    }
    //stack.sorted.erase(stack.sorted.end()-1);
    stack.initSaveData();

    return 0;

}


Data_generator menu(){
    bool status;
    std::string g;
    std::string a;
    int countProcesses=0;
    int averageTimeExecution=0;
    int deviationTimeExecution=0;
    int lowBorderTimeArrival=0;
    int highBorderTimeArrival=0;


    while(g != "R" && g != "G")  {
        std::cout << ""<<std::endl;
        std::cout << "Czy chcesz dokonać wczytania danych z pliku czy je wygenerować?" << std::endl;
        std::cout << "Wpisz R jeśli chcesz wczytać, G jeśli chcesz wygenerować nowe dane." << std::endl;
        std::cin >> g;
    }
    if(g == "G"){
        status=false;
        std::cout << "Wpisz liczbę procesów które chcesz wygenerować:" << std::endl;
        std::cin >> countProcesses;
        std::cout << "Wpisz średni czas wykonywania:" << std::endl;
        std::cin >> averageTimeExecution;
        std::cout << "Wpisz odchylenie standardowe czasów wykonywania:" << std::endl;
        std::cin >> deviationTimeExecution;
        std::cout << "Wpisz dolną granicę czasów przyjścia:" << std::endl;
        std::cin >> lowBorderTimeArrival;
        std::cout << "Wpisz górną granicę czasów przyjścia:" << std::endl;
        std::cin >> highBorderTimeArrival;
    }
    while( a != "F" && a != "N" && a != "W"){
        std::cout << "Którym z algorytmów chcesz posortować dane?" << std::endl;
        std::cout << "Wpisz F jeśli FCFS, N jeśli SJF nie wywłaszczeniowy, W jeśli SJF wywłaszczeniowy" << std::endl;
        std::cin >> a;
    }
    if(a == "F"){
        whichAlgorythm=FCFS;
    }
    if(a == "N"){
        whichAlgorythm=SJFNW;
    }
    if(a == "W"){
        whichAlgorythm=SJFW;
    }
    if(g == "R"){
        status=true;
    }

    Data_generator stack(countProcesses,averageTimeExecution,deviationTimeExecution,lowBorderTimeArrival,highBorderTimeArrival,status);
    return stack;
}

