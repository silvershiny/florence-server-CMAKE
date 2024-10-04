#include "Server.h"

FLORENCE::FrameworkSpace::Server::Server()
{
    this->ptr_Global = new class FLORENCE::FrameworkSpace::ServerSpace::Global();
    while (this->ptr_Global == nullptr) { /* wait untill created */ }
    
    this->ptr_Algorithms = new class FLORENCE::FrameworkSpace::ServerSpace::Algorithms(ptr_Global->get_NumCores());
    while (this->ptr_Algorithms == nullptr) { /* wait untill created */ }

    this->ptr_Data = new class FLORENCE::FrameworkSpace::ServerSpace::Data(ptr_Global->get_NumCores());
    while (this->ptr_Data == nullptr) { /* wait untill created */ }
    this->ptr_Data->initialise_Control();

    this->ptr_Execute = new class FLORENCE::FrameworkSpace::ServerSpace::Execute(ptr_Global, ptr_Global->get_NumCores());
    while (this->ptr_Execute == nullptr) { /* wait untill created */ }
    this->ptr_Execute->initialise_Control(ptr_Global->get_NumCores(), ptr_Global);
}
FLORENCE::FrameworkSpace::Server::~Server()
{
    delete FLORENCE::FrameworkSpace::Server::ptr_Global;
    delete FLORENCE::FrameworkSpace::Server::ptr_Algorithms;
    delete FLORENCE::FrameworkSpace::Server::ptr_Data;
    delete FLORENCE::FrameworkSpace::Server::ptr_Execute;
}

class FLORENCE::FrameworkSpace::ServerSpace::Algorithms* FLORENCE::FrameworkSpace::Server::get_Algorithms()
{
    return this->ptr_Algorithms;
}

class FLORENCE::FrameworkSpace::ServerSpace::Data* FLORENCE::FrameworkSpace::Server::get_Data()
{
    return this->ptr_Data;
}

class FLORENCE::FrameworkSpace::ServerSpace::Execute* FLORENCE::FrameworkSpace::Server::get_Execute()
{
    return this->ptr_Execute;
}

class FLORENCE::FrameworkSpace::ServerSpace::Global* FLORENCE::FrameworkSpace::Server::get_Global()
{
    return this->ptr_Global;
}

