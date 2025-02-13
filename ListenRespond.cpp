#include "ListenRespond.h"

FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond::ListenRespond()
{

}

FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond::~ListenRespond()
{
    delete FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond::ptr_Control_Of_ListenRespond;
}

void FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond::initialise_Control()
{
    this->ptr_Control_Of_ListenRespond = new class ListenRespondSpace::Control_Of_ListenRespond();
    while (this->ptr_Control_Of_ListenRespond == nullptr) { /* wait untill class constructed */ }
}

void FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond::thread_IO_ListenDistribute(
    unsigned char coreId,
    unsigned char* ptr_MyNumImplementedCores,
    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent* ptr_Concurrent,
    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ConcurrentSpace::Control_Of_Concurrent* ptr_Control_Of_Concurrent,
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute* ptr_Control_Of_Execute,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Control_Of_Data* ptr_Control_Of_Data,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input* ptr_Control_Of_Input,
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond* ptr_Control_Of_ListenRespond,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output* ptr_Control_Of_Output,
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
    class FLORENCE::FrameworkSpace::ServerSpace::Data* ptr_Data,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
    std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* ptr_InputStack,
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency* ptr_LaunchConcurrency,
    std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* ptr_OutputStack,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_PraiseBuffer,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_PraiseBuffer_Subset,
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable* ptr_WriteEnable
)
{
    ptr_Control_Of_Execute->setConditionCodeOfThisThreadedCore(coreId);
    while (ptr_Control_Of_Execute->getFlag_SystemInitialised(ptr_MyNumImplementedCores) != false)
    {
        // wait untill ALL threads initalised in preperation of system init.
    }
    if (ptr_Control_Of_ListenRespond->getFlag_IO_ThreadState() == true)
    {
        ptr_WriteEnable->write_Start(
            ptr_Control_Of_WriteEnable,
            &coreId,
            ptr_MyNumImplementedCores,
            ptr_Global
        );
        
        //TODO> client praise networking accepted and captured
        ptr_Data->get_PraiseBuffer()->setPraiseEventId(0);//NETWORKING TODO
        ptr_Control_Of_Input->selectSet_Input_Subset_For_Given_PraiseEventId(
            ptr_Data->get_PraiseBuffer()->getPraiseEventId(),
            ptr_Data->get_PraiseBuffer()
        );
        ptr_PraiseBuffer_Subset->set_A(new bool(false));
        ptr_PraiseBuffer_Subset->set_B(new bool(false));
        //END TODO> client praise networking accepted and captured

        ptr_Control_Of_Data->pushToStackOfInputPraises(
            ptr_InputStack,
            ptr_PraiseBuffer
        );

        ptr_Control_Of_Data->setFlag_InputStackLoaded(true);

        while ( ptr_Control_Of_LaunchConcurrency->getFlag_ConcurrentCoreState( ptr_Control_Of_LaunchConcurrency->get_coreId_To_Launch() ) == ptr_Global->getConst_Core_ACTIVE() ) {/* wait untill a core is free */ }
        ptr_LaunchConcurrency->concurrent_Thread_Start(
            ptr_Control_Of_LaunchConcurrency,
            ptr_Control_Of_LaunchConcurrency->get_coreId_To_Launch(),
            ptr_Global,
            ptr_MyNumImplementedCores
        );//Dynamic Launch

        ptr_WriteEnable->write_End(
            ptr_Control_Of_WriteEnable,
            &coreId,
            ptr_MyNumImplementedCores,
            ptr_Global
        );

        ptr_Control_Of_ListenRespond->setFlag_IO_ThreadState(false);//DISTRIBUTE=FALSE
    }
    else if (ptr_Control_Of_ListenRespond->getFlag_IO_ThreadState() == false)
    {
        if (ptr_Control_Of_Data->getFlag_OutputStackLoaded() == true)
        {
            ptr_WriteEnable->write_Start(
                ptr_Control_Of_WriteEnable,
                &coreId,
                ptr_MyNumImplementedCores,
                ptr_Global
            );
            ptr_Control_Of_Data->popFromStackOfOutput(
                ptr_Data->get_DistributeBuffer(),
                ptr_OutputStack
            );
            if (sizeof(ptr_Data->get_StackOfDistributeBuffer()) < 1)
            {
                ptr_Control_Of_Data->setFlag_OutputStackLoaded(false);
            }
            else
            {
                ptr_Control_Of_Data->setFlag_OutputStackLoaded(true);
            }
            //TODO> server distribute networking
            /*
            *  send registers in distribute buffer
            *  set ACK distribute sent to equal TRUE
            */
            ptr_WriteEnable->write_End(
                ptr_Control_Of_WriteEnable,
                &coreId,
                ptr_MyNumImplementedCores,
                ptr_Global
            );
        }
        ptr_Control_Of_ListenRespond->setFlag_IO_ThreadState(true);//LISTEN=TRUE
    }
}

class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespondSpace::Control_Of_ListenRespond* FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond::get_Control_Of_ListenRespond()
{
    return this->ptr_Control_Of_ListenRespond;
}

