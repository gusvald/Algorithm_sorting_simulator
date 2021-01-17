#include <iostream>
#include <string>
#include <ctime>
#include "Creator.h"
#include "NW_FCFS.h"
#include "NW_SJF.h"
#include "W_SJF.h"
enum algorythmChooser {
    FCFS = 0,
    SJFNW = 1,
    SJFW =2
};

algorythmChooser whichAlgorythm;
int main() {
    srand( static_cast<unsigned int>(time(nullptr)));
    Creator object(100, 19, 4, 1, 1500, "R");//int ilość procesów, int średnia, int odchylenie, int Dolna granica czasów przyjścia, int górna granica czasów przyjscia, tryb czytanie / generuj nowe dane R/G
    NW_FCFS fcfsNW(object);
    NW_SJF sjfNW(object);
    W_SJF sjfW(object);
    whichAlgorythm = SJFW;

if(whichAlgorythm==SJFNW)
{sjfNW.sort(object);}
if(whichAlgorythm==SJFW)
{sjfW.sort(object);}
if(whichAlgorythm==FCFS)
{fcfsNW.sort(object);}


    return 0;
}



