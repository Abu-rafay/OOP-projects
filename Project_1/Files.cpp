#include <iostream>
#include "Files.h"
#include <fstream>
#include <sstream>
// Shafin Awal
void read(IntArray &data){
    std::ifstream file("data.csv");
    std::string line;
    
    while(std::getline(file,line)){
        std::string token;
        std::stringstream parser(line);
    
        while(std::getline(parser, token, ',')){
            int num = stoi(token);
            data.push_back(num);
        }
    }
    file.close();
}

