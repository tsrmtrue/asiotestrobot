#include "ae_log.h"


INSTANCE_SINGLETON(AELogger);

bool AELogger::InitStart()
{
    std::thread* client_thread = new std::thread([this]()
    {
        try
        {
            this->Worker(); 
        }
        catch (std::exception& e)
        {
            std::printf("Exception: %s\n", e.what());
        }
    });
    return true;
}





