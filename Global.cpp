#include "Global.h"

bool FLORENCE::FrameworkSpace::ServerSpace::Global::flag_write_IDLE[2] = { false, false };
bool FLORENCE::FrameworkSpace::ServerSpace::Global::flag_write_WAIT[2] = { false, false };
bool FLORENCE::FrameworkSpace::ServerSpace::Global::flag_write_WRITE[2] = { false, false };
bool FLORENCE::FrameworkSpace::ServerSpace::Global::flag_core_IDLE = false;
bool FLORENCE::FrameworkSpace::ServerSpace::Global::flag_core_ACTIVE = false;
unsigned char* FLORENCE::FrameworkSpace::ServerSpace::Global::ptr_num_Implemented_Cores = nullptr;

FLORENCE::FrameworkSpace::ServerSpace::Global::Global()
{
    bool false_core_ACTIVE = new bool(true);
    bool false_core_IDLE = new bool(false);
    unsigned char* ptr_num_Implemented_Cores = new unsigned char(4);//NUMBER OF CORES
    bool false_write_IDLE[2] = { bool(false), bool(false) };
    bool false_write_WAIT[2] = { bool(false), bool(true) };
    bool false_write_WRITE[2] = { bool(true), bool(false) };
}

FLORENCE::FrameworkSpace::ServerSpace::Global::~Global()
{
    delete FLORENCE::FrameworkSpace::ServerSpace::Global::ptr_num_Implemented_Cores;
}

bool FLORENCE::FrameworkSpace::ServerSpace::Global::getConst_Core_ACTIVE()
{
    return flag_core_ACTIVE;
}
bool FLORENCE::FrameworkSpace::ServerSpace::Global::getConst_Core_IDLE()
{
    return flag_core_IDLE;
}
unsigned char* FLORENCE::FrameworkSpace::ServerSpace::Global::get_NumCores()
{
    return ptr_num_Implemented_Cores;
}
bool FLORENCE::FrameworkSpace::ServerSpace::Global::getConst_Write_IDLE(unsigned char index)
{
    return flag_write_IDLE[index];
}
bool FLORENCE::FrameworkSpace::ServerSpace::Global::getConst_Write_WAIT(unsigned char index)
{
    return flag_write_WAIT[index];
}
bool FLORENCE::FrameworkSpace::ServerSpace::Global::getConst_Write_WRITE(unsigned char index)
{
    return flag_write_WRITE[index];
}