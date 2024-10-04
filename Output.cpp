#include "Output.h"

int* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::ptr_out_PraiseEventId = nullptr;

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::Output()
{
    this->praiseOutputBuffer_Subset = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output();//ToDo CLASS T
    while (this->praiseOutputBuffer_Subset == nullptr) { /* wait untill created */ }
    int* ptr_out_PraiseEventId = new int(0);
    while (this->ptr_out_PraiseEventId == nullptr) { /* wait untill created */ }
}

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::~Output()
{
    delete FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::ptr_Control_Of_Output;
    delete FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::praiseOutputBuffer_Subset;
    delete FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::ptr_out_PraiseEventId;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::initialise_Control()
{
    this->ptr_Control_Of_Output = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output();
    while (this->ptr_Control_Of_Output == nullptr) { /* wait untill created */ }
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::get_Control_Of_Output()
{
    return this->ptr_Control_Of_Output;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::get_OutputBuffer_Subset()
{
    return this->praiseOutputBuffer_Subset;
}


int* FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::getPraiseEventId()
{
    return this->ptr_out_PraiseEventId;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::set_OutputBuffer_Subset(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* value)
{
    this->praiseOutputBuffer_Subset = value;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output::setPraiseEventId(int value)
{
    this->ptr_out_PraiseEventId = &value;
}

