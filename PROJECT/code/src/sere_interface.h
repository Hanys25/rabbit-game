#ifndef FILEUTILITIES_H
#define FILEUTILITIES_H

#include <iostream>
#include <string>
#include <fstream>

class FileUtilities{
    friend class Sender;
    friend class Receiver;
public:
    FileUtilities();
    bool OpenFile(bool overwrite);
    bool CloseFile() ;
    void ClearFile() ;
private:
    std::fstream file;
    std::string sciezka = "/home/spod/RABBIT/rabbit-game/sender_receiver/plik.txt";
};

#endif // FILEUTILITIES_H
