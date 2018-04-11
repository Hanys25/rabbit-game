#include "sender.h"
#include "receiver.h"

int main()
{

Sender a;
Receiver b;


char character='p';

a.SendToFile(character);
b.ReceiveFromFile();
b.ShowValue();


return 0;
}

