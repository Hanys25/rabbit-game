#ifndef RECEIVER_H
#define RECEIVER_H

#include "sere_interface.h"


class Receiver
{
public:
    Receiver();
    FileUtilities file_utilities;
    void ReceiveFromFile();
    char ReturnValue() {return key;}
    void ShowValue(){ std::cout<<key<<std::endl;}
private:
    char key;
};

#endif // RECEIVER_H
