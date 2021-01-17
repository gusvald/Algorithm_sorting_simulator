#include <iostream>
#include <string>
#include <ctime>
#include "Data_generator.h"
#include "S_FIFO.h"
#include "S_LRU.h"
#include <locale.h>

enum algorythmChooser {
    FIFO = 0,
    LRU = 1
};

algorythmChooser whichAlgorythm;

Data_generator menu();

int main() {
    srand( static_cast<unsigned int>(time(nullptr)));
    setlocale(LC_CTYPE, "Polish");

    Data_generator stack=menu();

    S_FIFO fifo(stack);

    S_LRU lru(stack);

    for(unsigned long i=0; i<stack.frames.size(); i++){
        if(stack.frames.at(i).count!=stack.pagesList.begin()->count){
        stack.frames.at(i).count=stack.pagesList.begin()->count;
        }
        stack.pagesList.erase(stack.pagesList.begin());
    }

    stack.saveFrames();

    for(unsigned long i=0; i<stack.frames.size(); i++){
        std::cout<<"|"<<stack.frames.at(i).count<<"|";
    }

    std::cout<<std::endl;

    while(!stack.pagesList.empty()) {

        if (whichAlgorythm == FIFO) {
            fifo.sort(stack);
        }
        if (whichAlgorythm == LRU) {
            lru.sort(stack);
        }

        for(unsigned long i=0; i<stack.frames.size(); i++){
            stack.frames.at(i).timeWithoutChange++;
        }

        stack.saveFrames();

        for(unsigned long i=0; i<stack.frames.size(); i++){
            std::cout<<"|"<<stack.frames.at(i).count<<"|";
        }

        std::cout<<std::endl;
    }

    stack.initSaveData();

    return 0;

}

Data_generator menu(){
    bool status;
    std::string g;
    std::string a;
    int counter_pages=0;
    int counter_frames=0;

    while(g != "R" && g != "G")  {
        std::cout << ""<<std::endl;
        std::cout << "Czy chcesz dokonać wczytania danych z pliku czy je wygenerować?" << std::endl;
        std::cout << "Wpisz R jeśli chcesz wczytać, G jeśli chcesz wygenerować nowe dane." << std::endl;
        std::cin >> g;
    }
    if(g == "G"){
        status=false;
        std::cout << "Wpisz liczbę odwołań które chcesz wygenerować:" << std::endl;
        std::cin >> counter_pages;
        std::cout << "Wpisz liczbę ramek z których mają korzystać dane:" << std::endl;
        std::cin >> counter_frames;
    }
    if(g == "R"){
        status=true;
        std::cout << "Wpisz liczbę ramek z których mają korzystać dane:" << std::endl;
        std::cin >> counter_frames;
    }
    while( a != "F" && a != "L"){
        std::cout << "Którym z algorytmów chcesz zastępować strony?" << std::endl;
        std::cout << "Wpisz F jeśli FIFO, L jeśli LRU" << std::endl;
        std::cin >> a;
    }
    if(a == "F"){
        whichAlgorythm=FIFO;
    }
    if(a == "L"){
        whichAlgorythm=LRU;
    }

    Data_generator stack(counter_pages,counter_frames,status);
    return stack;
}

