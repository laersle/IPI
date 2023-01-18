#include <iostream>
#include <fstream>
#include <string>

void addLinenumbers(const std::string& filename){
    std::string filenameadditionin = ".txt";
    std::string filenameadditionout = "-a.txt";

    std::ifstream infile;
    std::ofstream outfile;
    infile.open(filename+filenameadditionin, std::ios::in);                       //open file <filename>.txt in reading mode
    outfile.open(filename+filenameadditionout, std::ios::out);                    //open file <filename>-a.txt in writing mode
    if (!infile.good()){    throw std::runtime_error("Error opening Input File!");    }     //check that files have been opened correctly
    if (!outfile.good()){    throw std::runtime_error("Error opening Output File!");   }

    std::string currentline;
    int linecount = 1;
    std::string newline;
    std::string colon = ": ";

    while (infile.good()){                                                             //exits when eof-flag is true
        std::getline(infile, currentline);                                      //save line in string currentline
        std::string newline = std::to_string(linecount) + colon + currentline;    //add linenumber and colon to it
        outfile << newline << std::endl;                                               //write newline
        linecount++;
    }

    infile.close();
    outfile.close();
}

int main(){
    std::cout << "Hinweis: Dateiname muss von der Form <Dateiname>.txt sein, aber ohne Endung eingegeben werden.\nDie Datei muss im selben Ordner liegen oder der filepath muss angegeben werden.\n" << std::endl;
    std::cout << "Gib den Dateiname der Datei ein, die mit Zeilennummern versehen werden soll (Beispieldatei enthält Lorem Ipsum): ";
    std::string filename;
    std::cin >> filename;
    std::cout << std::endl;
    addLinenumbers(filename);
}