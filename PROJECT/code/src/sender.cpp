#include "sender.h"

Sender::Sender(){

}

void Sender::SendToFile(char key){
    if(file_utilities.OpenFile(false)){
         file_utilities.file << key;
         file_utilities.CloseFile();
    }
}
