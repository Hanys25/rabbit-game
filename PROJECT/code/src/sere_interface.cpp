#include "sere_interface.h"

FileUtilities::FileUtilities()
{

}

bool FileUtilities::OpenFile(bool overwrite){
    if(!overwrite) file.open(sciezka, std::ios::in | std::ios::out|std::ios::app); //dopisywanie znakow
    if(overwrite) file.open(sciezka, std::ios::out|std::ios::trunc); // do wyczyszczenia pliku
    if(file.good()) return 1;
    else return 0;
}

bool FileUtilities::CloseFile(){
file.close();
if(!file.is_open()) return 1;
else return 0;
}


void FileUtilities::ClearFile(){
    OpenFile(true);
    CloseFile();
}

