#include "sere_interface.h"

SeRe_Interface::SeRe_Interface()
{

}

bool SeRe_Interface::OpenFile(bool overwrite){
    if(!overwrite) file.open(sciezka, std::ios::in | std::ios::out|std::ios::app); //dopisywanie znakow
    if(overwrite) file.open(sciezka, std::ios::out|std::ios::trunc); // do wyczyszczenia pliku
    if(file.good()) return 1;
    else return 0;
}

bool SeRe_Interface::CloseFile(){
file.close();
if(!file.is_open()) return 1;
else return 0;
}


void SeRe_Interface::ClearFile(){
    OpenFile(true);
    CloseFile();    // MASZ KRÓTKIE FUNKCJE <333
}

