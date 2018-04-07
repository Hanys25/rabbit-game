#include "sender.hpp"

void Sender::SendToFile(const char key)
{
    file_utilities.SaveToFile(key);
    file_utilities.RemoveFile(); // TODO - probably no here
}
