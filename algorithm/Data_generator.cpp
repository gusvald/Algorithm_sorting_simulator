#include "Data_generator.h"

Data_generator::Data_generator(int quantityProcesses,int average,int deviation,int lowBorder,int highBorder, bool read):quantityProcesses(quantityProcesses),
average(average),deviation(deviation),lowBorder(lowBorder),highBorder(highBorder),read(read) {

    if(read){
        loadData();
        initialSort();
    }
    if(!read){
        generator();
        saveInitialData();
        initialSort();
    }
}
void Data_generator::generator(){
    Process process;
    std::stringstream ss;
    std::string str;
    int buffer1=(average+deviation);
    int buffer2=(average-deviation);
    int buffer3=((buffer1-buffer2)+1);
    int bufferTimeArrival=highBorder-lowBorder;

    process.name="P0";
    process.timeExecution= rand()%buffer3+buffer2;
    process.timeArrival=lowBorder;
    all.push_back(process);

    for(int i=1;i<quantityProcesses; i++){

        str = std::to_string(i);
        process.name="P"+str;
        process.timeExecution= rand()%buffer3+buffer2;
        process.timeArrival= rand()%bufferTimeArrival+(lowBorder+1);
        all.push_back(process);
    }
}
void Data_generator::saveInitialData() {
    std::fstream file1;
    std::fstream file2;

    file1.open("../timeExecution.txt", std::ios::out);
    file2.open("../timeArrival.txt", std::ios::out);

    for (unsigned int i = 0; i < all.size(); i++) {
        file1 << all.at(i).timeExecution << std::endl;
        file2 << all.at(i).timeArrival << std::endl;
    }
    file1.close();
    file2.close();
}

void Data_generator::loadData(){
    int processNumber=0;
    std::fstream file1;
    std::fstream file2;
    std::fstream file3;
    std::fstream file4;
    Process process;
    std::string line1;
    std::string line2;
    std::string line3;
    std::string line4;
    int countFile1=0;
    int countFile2=0;
    file1.open("../timeExecution.txt", std::ios::in);
    file2.open("../timeArrival.txt", std::ios::in);
    file3.open("../timeExecution.txt", std::ios::in);
    file4.open("../timeArrival.txt", std::ios::in);
    if (file1.good() && file2.good()) {

        while(getline(file1, line1)){
            countFile1++;
        }
        while(getline(file2, line2)){
            countFile2++;
        }
        if(countFile1 != countFile2){
            std::cout<<"Nierówna ilość danych w plikach"<<std::endl;
            std::cerr << strerror(errno) <<std::endl;
            abort();
        }
        for(int i=0; i<countFile1; i++) {

            getline(file3, line3);
            getline(file4, line4);

            process.name = "P" + std::to_string(processNumber);
            process.timeExecution = std::stoi(line3);
            process.timeArrival = std::stoi(line4);

            all.push_back(process);
            processNumber++;
        }
    }
    file1.close();
    file2.close();
}
void Data_generator::initialSort(){
    for(unsigned long i=0; i<all.size();i++){
        for(unsigned long j=0; j<all.size()-1;j++) {
            if (all.at(j).timeArrival > all.at(j+1).timeArrival) {
                std::swap(all.at(j), all.at(j+1));
            }
        }
    }
    Process process;
    process.name="END";
    process.timeArrival=-1;
    process.timeExecution=-1;
    process.timeEnd=-1;
    all.push_back(process);
}
void Data_generator::saveData(){
    std::fstream file1;
    std::fstream file2;
    std::fstream file3;
    std::fstream file4;
    file1.open("../Results/timeExecutionResult.txt", std::ios::out);
    file2.open("../Results/timeArrivalResult.txt", std::ios::out);
    file3.open("../Results/timeEndResult.txt", std::ios::out);
    file4.open("../Results/collectiveResult.txt", std::ios::out);
    file4 << "number of process" << "           " << "timeExecution" << "      " << "timeArrival" << "      " << "timeEnd" <<  std::endl;
    for (unsigned int i = 0; i < sorted.size(); i++) {
        file1 << sorted.at(i).timeExecution << std::endl;
        file2 << sorted.at(i).timeArrival << std::endl;
        file3 << sorted.at(i).timeEnd << std::endl;
        file4 << sorted.at(i).name << "                     " << sorted.at(i).timeExecution << "                         " << sorted.at(i).timeArrival << "              " << sorted.at(i).timeEnd <<  std::endl;
    }
    file1.close();
    file2.close();
    file3.close();
    file4.close();
}

Data_generator::~Data_generator() {

}

void Data_generator::initSaveData() {
    saveData();
}


