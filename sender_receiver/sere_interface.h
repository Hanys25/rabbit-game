#ifndef SERE_INTERFACE_H
#define SERE_INTERFACE_H

#include <iostream>
#include <string>
#include <fstream>

class SeRe_Interface{
public:
    SeRe_Interface();
    bool OpenFile(bool overwrite);
    bool CloseFile() ;
    void ClearFile() ;

protected:
    std::fstream file;
    std::string sciezka = "/home/spod/RABBIT/rabbit-game/sender_receiver/plik.txt";
};

#endif // SERE_INTERFACE_H
