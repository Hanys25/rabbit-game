#include "sender.h"

Sender::Sender(){

}

void Sender::SendToFile(char key){
    if(OpenFile(false)){
         file << key;
    }
}
