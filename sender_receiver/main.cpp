#include "sender.h"
#include "receiver.h"

int main()
{

Sender a;
Receiver b;
SeRe_Interface * interface = new SeRe_Interface;
char character='p';

interface->ClearFile();

a.SendToFile(character);
b.ReceiveFromFile();
b.ShowValue();

interface->CloseFile();
std::cout<<a.CloseFile()<<std::endl;
    return 0;
}

