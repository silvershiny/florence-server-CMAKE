#include "Concurrent.h"

FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent::Concurrent()
{
    this->ptr_Algorithms_Subset = new class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm();//TODO CLASS T
    while (this->ptr_Algorithms_Subset == nullptr) { /* wait untill class constructed */ }
}

FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent::~Concurrent()
{
    delete FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent::ptr_Control_Of_Concurrent;
    delete FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent::ptr_Algorithms_Subset;
}

void FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent::initialise_Control()
{
    this->ptr_Control_Of_Concurrent = new class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ConcurrentSpace::Control_Of_Concurrent();
    while (this->ptr_Control_Of_Concurrent == nullptr) { /* wait untill class constructed */ }
}

void FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent::thread_Concurrency(
    unsigned char concurrent_coreId,
    unsigned char* ptr_MyNumImplementedCores,
    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent* ptr_Concurrent,
    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ConcurrentSpace::Control_Of_Concurrent* prt_Control_Of_Concurrent,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Control_Of_Data* ptr_Control_Of_Data,
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute* ptr_Control_Of_Execute,
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output* ptr_Control_Of_Output,
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnableSpace::Control_Of_WriteEnable* ptr_Control_Of_WriteEnable,
    class FLORENCE::FrameworkSpace::ServerSpace::Data* ptr_Data,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_InputBuffer,
    std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* ptr_InputStack,
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency* ptr_LaunchConcurrency,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* ptr_Output,
    std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* ptr_OutputStack,
    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* ptr_Algorithm_Subset,//TODO CLASS T
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_Input_Subset,//TODO CLASS T
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* ptr_Output_Subset,//TODO CLASS T
    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable* ptr_WriteEnable
)
{
    ptr_Control_Of_Execute->setConditionCodeOfThisThreadedCore(concurrent_coreId);
    while (ptr_Control_Of_Execute->getFlag_SystemInitialised(ptr_MyNumImplementedCores) != false)
    {
        // wait untill thread initalised
    }
    if (ptr_Control_Of_LaunchConcurrency->getFlag_ConcurrentCoreState(&concurrent_coreId) == ptr_Global->getConst_Core_ACTIVE())
    {
        if (ptr_Control_Of_Data->getFlag_InputStackLoaded() == true)
        {
            ptr_WriteEnable->write_Start(
                ptr_Control_Of_WriteEnable,
                &concurrent_coreId,
                ptr_MyNumImplementedCores,
                ptr_Global
            );
            ptr_Control_Of_Data->popFromStackOfInputPraises(
                ptr_Data->get_InputRefferenceOfCore(concurrent_coreId),
                ptr_InputStack
            );
            if (sizeof(ptr_Data->get_StackOfInputPraise()) <= 1)
            {
                ptr_Control_Of_Data->setFlag_InputStackLoaded(false);
            }
            else
            {
                ptr_Control_Of_Data->setFlag_InputStackLoaded(true);
            }

            prt_Control_Of_Concurrent->selectSet_Algorithm_Subset_For_Given_PraiseEventId(
                ptr_Data->get_InputRefferenceOfCore(concurrent_coreId)->getPraiseEventId(),
                concurrent_coreId
            );

            ptr_Control_Of_Output->selectSet_Output_Subset_For_Given_PraiseEventId(
                ptr_Data->get_OutputRefferenceOfCore(concurrent_coreId)->getPraiseEventId(),
                concurrent_coreId
            );

            ptr_WriteEnable->write_End(
                ptr_Control_Of_WriteEnable,
                &concurrent_coreId,
                ptr_MyNumImplementedCores,
                ptr_Global
            );
            
            ptr_Concurrent->do_Concurrent_Algorithm_For_PraiseEventId(
                ptr_Data->get_InputRefferenceOfCore(concurrent_coreId)->getPraiseEventId(),
                ptr_Algorithm_Subset,
                ptr_Input_Subset,
                ptr_Output_Subset
            );
            ptr_WriteEnable->write_Start(
                ptr_Control_Of_WriteEnable,
                &concurrent_coreId,
                ptr_MyNumImplementedCores,
                ptr_Global
            );
            ptr_Control_Of_Data->pushToStackOfOutput(
                ptr_OutputStack,
                ptr_Data->get_OutputRefferenceOfCore(concurrent_coreId)
            );
            if (sizeof(ptr_Data->get_StackOfInputPraise()) < 1)
            {
                ptr_Control_Of_Data->setFlag_InputStackLoaded(false);
            }
            else
            {
                ptr_Control_Of_Data->setFlag_InputStackLoaded(true);
            }
            ptr_LaunchConcurrency->thread_End(
                ptr_Control_Of_LaunchConcurrency,
                &concurrent_coreId,
                ptr_Global
            );
            ptr_WriteEnable->write_End(
                ptr_Control_Of_WriteEnable,
                &concurrent_coreId,
                ptr_MyNumImplementedCores,
                ptr_Global
            );
        }
    }
}

void  FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent::do_Concurrent_Algorithm_For_PraiseEventId(
    int* ptr_praiseEventId,
    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* ptr_Algorithm_Subset,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_Input_Subset,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* ptr_Output_Subset
)
{
    ptr_Algorithm_Subset->do_Praise(
        ptr_Input_Subset,
        ptr_Output_Subset
    );
}
class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent::get_Algorithm_Subset()
{
    return this->ptr_Algorithms_Subset;
}

class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ConcurrentSpace::Control_Of_Concurrent* FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent::get_Control_Of_Concurrent()
{
    return this->ptr_Control_Of_Concurrent;
}

void FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent::set_Algorithm_Subset(class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* value_algorithm)
{
    this->ptr_Algorithms_Subset = value_algorithm;
}