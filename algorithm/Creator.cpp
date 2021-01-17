#include "Creator.h"

Creator::Creator(int quantityProcesses, int average, int deviation, int lowBorder, int highBorder, std::string read): how_m_process(quantityProcesses),
                                                                                                                      average(average), interval(deviation), lBorder(lowBorder), hBorder(highBorder), mode(read) {
    if(read=="R"){
        lData();
        sortInit();
    }
    if(read=="G"){
        generate();
        beginSave();
        sortInit();
    }
}

void Creator::generate(){
    Process_S workflow;
    std::stringstream sstring;
    std::string s;
    int b=(average + interval);
    int bu=(average - interval);
    int buff=((b - bu) + 1);
    int buffT= hBorder - lBorder;
    workflow.name="P0";
    workflow.timeExecution= rand() % buff + bu;
    workflow.timeArrival=lBorder;
    each_process.push_back(workflow);

    for(int i=1; i < how_m_process; i++){
        s = std::to_string(i);
        workflow.name= "P" + s;
        workflow.timeExecution= rand() % buff + bu;
        workflow.timeArrival= rand() % buffT + (lBorder + 1);
        each_process.push_back(workflow);
    }
}

void Creator::beginSave() {
    std::fstream file1;
    std::fstream file2;
    file1.open("../timeExecution.txt", std::ios::out);
    file2.open("../timeArrival.txt", std::ios::out);

    for (unsigned int i = 0; i < each_process.size(); i++) {
        file1 << each_process.at(i).timeExecution << std::endl;
        file2 << each_process.at(i).timeArrival << std::endl;
    }

    file1.close();
    file2.close();
}

void Creator::lData(){
    int processNumber=0;
    std::fstream file1;
    std::fstream file2;
    std::fstream file3;
    std::fstream file4;
    Process_S work;
    std::string string1;
    std::string string2;
    std::string string3;
    std::string string4;
    int number1=0;
    int number2=0;

    file1.open("../timeExecution.txt", std::ios::in);
    file2.open("../timeArrival.txt", std::ios::in);
    file3.open("../timeExecution.txt", std::ios::in);
    file4.open("../timeArrival.txt", std::ios::in);

    if (file1.good() && file2.good()) {
        while(getline(file1, string1)){
            number1++;
        }

        while(getline(file2, string2)){
            number2++;
        }

        if(number1 != number2){
            std::cout<<"Not equal data in files"<<std::endl;
            std::cerr << strerror(errno) <<std::endl;
            abort();
        }

        for(int i=0; i < number1; i++) {

            getline(file3, string3);
            getline(file4, string4);

            work.name = "P" + std::to_string(processNumber);
            work.timeExecution = std::stoi(string3);
            work.timeArrival = std::stoi(string4);

            each_process.push_back(work);
            processNumber++;
        }
    }
    file1.close();
    file2.close();
}

void Creator::sortInit(){
    for(unsigned long i=0; i < each_process.size(); i++){
        for(unsigned long j=0; j < each_process.size() - 1; j++) {
            if (each_process.at(j).timeArrival > each_process.at(j + 1).timeArrival) {
                std::swap(each_process.at(j), each_process.at(j + 1));
            }
        }
    }
    Process_S work;
    work.name="END";
    work.timeArrival=-1;
    work.timeExecution=-1;
    work.timeEnd=-1;
    each_process.push_back(work);
}

void Creator::sData(){
    std::fstream file1;
    std::fstream file2;
    std::fstream file3;
    std::fstream file4;
    file1.open("../Results/timeExecutionResult.txt", std::ios::out);
    file2.open("../Results/timeArrivalResult.txt", std::ios::out);
    file3.open("../Results/timeEndResult.txt", std::ios::out);
    file4.open("../Results/collectiveResult.txt", std::ios::out);
    file4 << "number of process" << "           " << "timeExecution" << "      " << "timeArrival" << "      " << "timeEnd" <<  std::endl;
    for (unsigned int i = 0; i < results.size(); i++) {
        file1 << results.at(i).timeExecution << std::endl;
        file2 << results.at(i).timeArrival << std::endl;
        file3 << results.at(i).timeEnd << std::endl;
        file4 << results.at(i).name << "                     " << results.at(i).timeExecution << "                         " << results.at(i).timeArrival << "              " << results.at(i).timeEnd << std::endl;
    }
    file1.close();
    file2.close();
    file3.close();
    file4.close();
}

void Creator::beginSaving() {
sData();
}

Creator::~Creator() {

}