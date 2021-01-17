#include "CreatorP.h"

CreatorP::CreatorP(int quantityPages, int quantityFrames,int how_m_changes, std::string mode ): how_m_pages(quantityPages), how_m_frames(quantityFrames),how_m_changes(how_m_changes), mode(mode){

    if(mode == "R"){
        lData();
        iFrames();
    }
    if(mode == "G"){
        creator();
        sIData();
        iFrames();
    }
}
void CreatorP::creator(){
    Page_P page;

    for(int i=0; i < how_m_pages; i++){
        page.count= rand()%9+1;
        pagesList.push_back(page);
    }
}
void CreatorP::iFrames(){
    Page_P frame;
    for(int j=how_m_frames; j > 0; j--){
        frame.timeWithoutChange=j;
        Qframe.push_back(frame);
    }
}
void CreatorP::sIData() {
    std::fstream file1;

    file1.open("../pagesList.txt", std::ios::out);

    for (unsigned int i = 0; i < pagesList.size(); i++) {
        file1 << pagesList.at(i).count << std::endl;
    }
    file1.close();
}
void CreatorP::lData(){
    std::fstream file1;
    std::fstream file2;
    Page_P page;
    std::string line1;
    std::string line2;
    int countFile1=0;
    file1.open("../pagesList.txt", std::ios::in);
    file2.open("../pagesList.txt", std::ios::in);
    if (file1.good() && file2.good()) {

        while(getline(file1, line1)){
            countFile1++;
        }
        if(countFile1 == 0){
            std::cout<<"Brak danych w pliku!"<<std::endl;
            std::cerr << strerror(errno) <<std::endl;
            abort();
        }
        for(int i=0; i<countFile1; i++) {

            getline(file2, line2);
            page.count = std::stoi(line2);

            pagesList.push_back(page);
        }
    }
    file1.close();
    file2.close();
}

void CreatorP::sData(){
    unsigned long countFile1=0;
    std::fstream file1;
    std::fstream file2;
    std::fstream result;
    std::string line1;
    std::string line2;

    file1.open("../pagesList.txt", std::ios::in);
    file2.open("../pagesList.txt", std::ios::in);
    result.open("../result.txt", std::ios::out);

    while(getline(file1, line1)){
        countFile1++;
    }
    result << "Lista odwołań: ";
    for(unsigned long i=0; i<countFile1; i++) {
        getline(file2, line2);
        result << std::stoi(line2);
    }
    result << std::endl << std::endl;

    for(unsigned long i=0; i < results.size(); i++){
        result << results.at(i) << std::endl;
    }
    result<<std::endl;
std::cout<<how_m_changes;
    result << "Zmiany: " << how_m_changes;

    result.close();
}

void CreatorP::beginSaving() {
    sData();
}

void CreatorP::sFrames() {
    std::string frame;
    for(unsigned long i=0; i < Qframe.size(); i++){
        frame += "|" + std::to_string(Qframe.at(i).count) + "|";
    }
    results.push_back(frame);
}

CreatorP::~CreatorP() {

}



