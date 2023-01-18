#include <iostream>
#include <fstream>
#include <string>

void addLinenumbers(const std::string& filename){
    std::ifstream infile;
    infile.open(filename, std::ios::in);
    char nextchar = ' ';
    infile >> nextchar;
    std::cout << nextchar << std::endl;
    std::string currentline;
    std::cout << infile.eof() << std::endl;
    std::cout << infile.bad() << std::endl;
    std::cout << infile.fail() << std::endl;
    while (infile.good()){
        std::getline(infile, currentline);
        std::cout << currentline << std::endl;
    }
    infile.close();
}

int main(){
    addLinenumbers("BeispielDatei.txt");
}