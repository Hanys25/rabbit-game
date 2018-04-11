#ifndef SENDER_H
#define SENDER_H

#include <string>
#include <fstream>
#include "sere_interface.h"

class Sender{
public:

    Sender();
    FileUtilities file_utilities;
    void SendToFile(char key);
private:
    char key;
};

#endif // SENDER_H
