#ifndef SENDER_H
#define SENDER_H

#include <string>
#include <fstream>
#include "sere_interface.h"

class Sender : public SeRe_Interface {
public:
    Sender();
    void SendToFile(char key);

private:

    char key;
};

#endif // SENDER_H
