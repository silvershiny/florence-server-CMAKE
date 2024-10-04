#include "Input.h"

int* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::ptr_in_praiseEventId = nullptr;

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::Input()
{
    this->ptr_praiseInputBuffer_Subset = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input();//TODO CLASS T
    while (this->ptr_praiseInputBuffer_Subset == nullptr) { /* wait untill created */ }
    int* ptr_in_praiseEventId = new int(0);
    while (this->ptr_in_praiseEventId == nullptr) { /* wait untill created */ }
}

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::~Input()
{
    delete FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::ptr_Control_Of_Input;
    delete FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::ptr_praiseInputBuffer_Subset;
    delete FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::ptr_in_praiseEventId;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::initialise_Control()
{
    this->ptr_Control_Of_Input = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input();
    while (this->ptr_Control_Of_Input == nullptr) { /* wait untill created */ }
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::get_Control_Of_Input()
{
    return this->ptr_Control_Of_Input;
}

int* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::getPraiseEventId()
{
    return this->ptr_in_praiseEventId;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::get_InputBufferSubset()
{
    return this->ptr_praiseInputBuffer_Subset;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::set_InputBuffer_SubSet(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* value)
{
    this->ptr_praiseInputBuffer_Subset = value;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input::setPraiseEventId(int value)
{
    this->ptr_in_praiseEventId = &value;
}