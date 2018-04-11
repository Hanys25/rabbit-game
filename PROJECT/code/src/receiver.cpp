#include "receiver.h"

Receiver::Receiver()
{

}

void Receiver::ReceiveFromFile(){
    if(file_utilities.OpenFile(false)){
         file_utilities.file >> key;
         file_utilities.CloseFile();
    }
}
