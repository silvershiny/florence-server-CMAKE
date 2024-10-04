#include "Control_Of_ListenRespond.h"

bool FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond::flag_IO_ThreadState = false;

FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond::Control_Of_ListenRespond()
{
    ptr_Flag_IO_ThreadState = new bool(true);
}
FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond::~Control_Of_ListenRespond()
{

}

bool FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond::getFlag_IO_ThreadState()
{
    return flag_IO_ThreadState;
}

void FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond::setFlag_IO_ThreadState(bool value)
{
    flag_IO_ThreadState = value;
}