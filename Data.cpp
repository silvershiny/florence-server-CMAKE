#include "Data.h"

FLORENCE::FrameworkSpace::ServerSpace::Data::Data(unsigned char* ptr_NumberOfImplementedCores)
{
    this->ptr_new_Input = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input();
    while (this->ptr_new_Input == nullptr) { /* wait untill created */ }
    this->ptr_new_Input->initialise_Control();
    
    this->ptr_new_Output = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output();
    while (this->ptr_new_Output == nullptr) { /* wait untill created */ }
    this->ptr_new_Output->initialise_Control();

    this->ptr_DistributeBuffer = this->ptr_new_Output;
    while (this->ptr_DistributeBuffer == nullptr) { /* wait untill created */ }

    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_InputRefferenceOfCore[3] = {
        this->ptr_new_Input,
        this->ptr_new_Input,
        this->ptr_new_Input
    };//NUMBER OF CONCURRENT CORES
    for (int index = 0; index < *ptr_NumberOfImplementedCores - 1; index++)
    {
        while (this->ptr_InputRefferenceOfCore[index] == nullptr) { /* wait untill created */ }
    }

    this->ptr_InputRefferenceOfCore_Array = this->ptr_InputRefferenceOfCore;
    while (this->ptr_InputRefferenceOfCore_Array == nullptr) { /* wait untill created */ }
    
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* ptr_OutputRefferenceOfCore[3] = {
        this->ptr_new_Output,
        this->ptr_new_Output,
        this->ptr_new_Output
    };//NUMBER OF CONCURRENT CORES
    for (int index = 0; index < *ptr_NumberOfImplementedCores - 1; index++)
    {
        while (this->ptr_OutputRefferenceOfCore[index] == nullptr) { /* wait untill created */ }
    }

    this->ptr_OutputRefferenceOfCore_Array = this->ptr_OutputRefferenceOfCore;
    while (this->ptr_OutputRefferenceOfCore_Array == nullptr) { /* wait untill created */ }

    this->ptr_StackOfInputPraise = new std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>;
    while (this->ptr_StackOfInputPraise == nullptr) { /* wait untill created */ }
    this->ptr_StackOfInputPraise->resize(1);
    this->ptr_StackOfInputPraise->at(0) = this->ptr_new_Input;

    this->ptr_StackOfDistributeBuffer = new std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>;
    while (this->ptr_StackOfDistributeBuffer == nullptr) { /* wait untill created */ }
    this->ptr_StackOfDistributeBuffer->resize(1);
    this->ptr_StackOfDistributeBuffer->at(0) = this->ptr_new_Output;

    this->ptr_PraiseBuffer = this->ptr_new_Input;
    while (this->ptr_PraiseBuffer == nullptr) { /* wait untill created */ }

    //===
    //===
    this->prt_Praise0_Input = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input();
    while (this->prt_Praise0_Input == nullptr) { /* wait untill created */ }
    this->prt_Praise0_Outut = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output();
    while (this->prt_Praise0_Outut == nullptr) { /* wait untill created */ }
    //===
    //===
    delete FLORENCE::FrameworkSpace::ServerSpace::Data::ptr_new_Input;
    delete FLORENCE::FrameworkSpace::ServerSpace::Data::ptr_new_Output;
}

FLORENCE::FrameworkSpace::ServerSpace::Data::~Data()
{
    delete FLORENCE::FrameworkSpace::ServerSpace::Data::ptr_Control_Of_Data;
    delete FLORENCE::FrameworkSpace::ServerSpace::Data::ptr_DistributeBuffer;
    for (int index = 0; index < 3; index++)
    {
        delete FLORENCE::FrameworkSpace::ServerSpace::Data::ptr_InputRefferenceOfCore[index];
        delete FLORENCE::FrameworkSpace::ServerSpace::Data::ptr_OutputRefferenceOfCore[index];
    }
    delete FLORENCE::FrameworkSpace::ServerSpace::Data::ptr_StackOfInputPraise;
    delete FLORENCE::FrameworkSpace::ServerSpace::Data::ptr_StackOfDistributeBuffer;
    delete FLORENCE::FrameworkSpace::ServerSpace::Data::ptr_PraiseBuffer;
}

void FLORENCE::FrameworkSpace::ServerSpace::Data::initialise_Control()
{
    this->ptr_Control_Of_Data = new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Control_Of_Data();
    while (this->ptr_Control_Of_Data == nullptr) { /* wait untill created */ }
}

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Control_Of_Data* FLORENCE::FrameworkSpace::ServerSpace::Data::get_Control_Of_Data()
{
    return this->ptr_Control_Of_Data;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* FLORENCE::FrameworkSpace::ServerSpace::Data::get_DistributeBuffer()
{
    return this->ptr_DistributeBuffer;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* FLORENCE::FrameworkSpace::ServerSpace::Data::get_InputRefferenceOfCore(unsigned char concurrent_coreId)
{
    return this->ptr_InputRefferenceOfCore_Array[concurrent_coreId];
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* FLORENCE::FrameworkSpace::ServerSpace::Data::get_OutputRefferenceOfCore(unsigned char concurrent_coreId)
{
    return this->ptr_OutputRefferenceOfCore_Array[concurrent_coreId];
}

std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* FLORENCE::FrameworkSpace::ServerSpace::Data::get_StackOfInputPraise()
{
    return this->ptr_StackOfInputPraise;
}

std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* FLORENCE::FrameworkSpace::ServerSpace::Data::get_StackOfDistributeBuffer()
{
    return this->ptr_StackOfDistributeBuffer;
}

class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* FLORENCE::FrameworkSpace::ServerSpace::Data::get_PraiseBuffer()
{
    return this->ptr_PraiseBuffer;
}

void FLORENCE::FrameworkSpace::ServerSpace::Data::set_DistributeBuffer(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* value_Output)
{
    this->ptr_DistributeBuffer = value_Output;
}

void FLORENCE::FrameworkSpace::ServerSpace::Data::set_InputRefferenceOfCore(unsigned char concurrent_coreId, class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* value_Input)
{
    this->ptr_InputRefferenceOfCore_Array[concurrent_coreId] = value_Input;
}

void FLORENCE::FrameworkSpace::ServerSpace::Data::set_OutputRefferenceOfCore(unsigned char concurrent_coreId, class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* value_Output)
{
    this->ptr_OutputRefferenceOfCore_Array[concurrent_coreId] = value_Output;
}

void FLORENCE::FrameworkSpace::ServerSpace::Data::set_PraiseBuffer(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* value_Input)
{
    this->ptr_PraiseBuffer = value_Input;
}