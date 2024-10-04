#include "Execute.h"

FLORENCE::FrameworkSpace::ServerSpace::Execute::Execute(
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
    unsigned char* ptr_MyNumImplementedCores
)
{
    this->ptr_LaunchConcurrency = new class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency();
    while (this->ptr_LaunchConcurrency == nullptr) { /* wait untill created */ }
    this->ptr_LaunchConcurrency->initialise_Control(ptr_Global, ptr_MyNumImplementedCores);

    this->ptr_WriteEnable = new class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable();
    while (this->ptr_WriteEnable == nullptr) { /* wait untill created */ }
    this->ptr_WriteEnable->initialise_Control(ptr_Global, ptr_MyNumImplementedCores);
}

FLORENCE::FrameworkSpace::ServerSpace::Execute::~Execute()
{
    delete FLORENCE::FrameworkSpace::ServerSpace::Execute::ptr_Control_Of_Execute;
    delete FLORENCE::FrameworkSpace::ServerSpace::Execute::ptr_LaunchConcurrency;
    delete FLORENCE::FrameworkSpace::ServerSpace::Execute::ptr_WriteEnable;
    for (int index = 0; index < 4; index++)
    {
        delete FLORENCE::FrameworkSpace::ServerSpace::Execute::ptr_Thread_WithCoreId[index];
    }//NUMBER OF CORES
}

void FLORENCE::FrameworkSpace::ServerSpace::Execute::initialise_Threads()
{
    ptr_Thread_WithCoreId[0] = new std::thread(
        FLORENCE::Framework::get_Server()->get_Algorithms()->get_ListenRespond()->thread_IO_ListenDistribute,
        unsigned char(0),
        FLORENCE::Framework::get_Server()->get_Global()->get_NumCores(),
        FLORENCE::Framework::get_Server()->get_Execute()->get_Control_Of_Execute(),
        FLORENCE::Framework::get_Server()->get_Data()->get_Control_Of_Data(),
        FLORENCE::Framework::get_Server()->get_Execute()->get_LaunchConcurrency(),
        FLORENCE::Framework::get_Server()->get_Algorithms()->get_ListenRespond()->get_Control_Of_ListenRespond(),
        FLORENCE::Framework::get_Server()->get_Execute()->get_WriteEnable(),
        FLORENCE::Framework::get_Server()->get_Data(),
        FLORENCE::Framework::get_Server()->get_Global(),
        FLORENCE::Framework::get_Server()->get_Data()->get_StackOfInputPraise(),
        FLORENCE::Framework::get_Server()->get_Execute()->get_LaunchConcurrency(),
        FLORENCE::Framework::get_Server()->get_Data()->get_StackOfDistributeBuffer(),
        FLORENCE::Framework::get_Server()->get_Data()->get_PraiseBuffer(),
        FLORENCE::Framework::get_Server()->get_Data()->get_PraiseBuffer()->get_InputBufferSubset(),
        FLORENCE::Framework::get_Server()->get_Execute()->get_WriteEnable()
    );
    for (unsigned char index = 1; index <= *FLORENCE::Framework::get_Server()->get_Global()->get_NumCores(); index++)
    {
        ptr_Thread_WithCoreId[index] = new std::thread(
            FLORENCE::Framework::get_Server()->get_Algorithms()->get_Concurren_Array(index)->thread_Concurrency,
            unsigned char(index),
            FLORENCE::Framework::get_Server()->get_Global()->get_NumCores(),
            FLORENCE::Framework::get_Server()->get_Algorithms()->get_Concurren_Array(index),
            FLORENCE::Framework::get_Server()->get_Algorithms()->get_Concurren_Array(index)->get_Control_Of_Concurrent(),
            FLORENCE::Framework::get_Server()->get_Data()->get_Control_Of_Data(),
            FLORENCE::Framework::get_Server()->get_Execute()->get_Control_Of_Execute(),
            FLORENCE::Framework::get_Server()->get_Execute()->get_LaunchConcurrency(),
            FLORENCE::Framework::get_Server()->get_Execute()->get_WriteEnable(),
            FLORENCE::Framework::get_Server()->get_Data(),
            FLORENCE::Framework::get_Server()->get_Global(),
            FLORENCE::Framework::get_Server()->get_Data()->get_PraiseBuffer(),
            FLORENCE::Framework::get_Server()->get_Data()->get_StackOfInputPraise(),
            FLORENCE::Framework::get_Server()->get_Execute()->get_LaunchConcurrency(),
            FLORENCE::Framework::get_Server()->get_Data()->get_DistributeBuffer(),
            FLORENCE::Framework::get_Server()->get_Data()->get_StackOfDistributeBuffer(),
            FLORENCE::Framework::get_Server()->get_Algorithms()->get_Concurren_Array(index)->get_Algorithm_Subset(),
            FLORENCE::Framework::get_Server()->get_Data()->get_PraiseBuffer()->get_InputBufferSubset(),
            FLORENCE::Framework::get_Server()->get_Data()->get_DistributeBuffer()->get_OutputBuffer_Subset(),
            FLORENCE::Framework::get_Server()->get_Execute()->get_WriteEnable()
        );
    }
    while (FLORENCE::Framework::get_Server()->get_Execute()->get_Control_Of_Execute()->getFlag_SystemInitialised(FLORENCE::Framework::get_Server()->get_Global()->get_NumCores()) != false)
    {

    }
}

void FLORENCE::FrameworkSpace::ServerSpace::Execute::initialise_Control(
    unsigned char* ptr_MyNumImplementedCores,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
)
{
    this->ptr_Control_Of_Execute = new class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute(ptr_MyNumImplementedCores);
    while (this->ptr_Control_Of_Execute == nullptr) { /* wait untill created */ }
}

class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute* FLORENCE::FrameworkSpace::ServerSpace::Execute::get_Control_Of_Execute()
{
    return this->ptr_Control_Of_Execute;
}

class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency* FLORENCE::FrameworkSpace::ServerSpace::Execute::get_LaunchConcurrency()
{
    return this->ptr_LaunchConcurrency;
}

class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable* FLORENCE::FrameworkSpace::ServerSpace::Execute::get_WriteEnable()
{
    return this->ptr_WriteEnable;
}
