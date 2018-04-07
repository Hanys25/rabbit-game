#include "receiver.h"

Receiver::Receiver()
{

}

void Receiver::ReceiveFromFile(){
    if(OpenFile(false)){
         file >> key;
    }
}
