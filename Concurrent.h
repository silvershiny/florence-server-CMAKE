#pragma once
#include "Concurrent.h"
#include "Control_Of_Concurrent.h"
#include "Control_Of_Data.h"
#include "Control_Of_Execute.h"
#include "Control_Of_LaunchConcurrency.h"
#include "Control_Of_Output.h"
#include "Control_Of_WriteEnable.h"
#include "Data.h"
#include "Global.h"
#include "Input.h"
#include "LaunchConcurrency.h"
#include "Output.h"
#include "user_files/Praise0_Algorithm.h"
#include "user_files/Praise0_Input.h"
#include "user_files/Praise0_Output.h"
#include "WriteEnable.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace AlgorithmsSpace
            {
                class Concurrent
                {
                public:
                    Concurrent();
                    virtual ~Concurrent();
                    void initialise_Control();
                    static void thread_Concurrency(
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
                        class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* ptr_Algorithm_Subset,
                        class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_Input_Subset,
                        class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* ptr_Output_Subset,
                        class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable* ptr_WriteEnable
                    );

                    void do_Concurrent_Algorithm_For_PraiseEventId(
                        int* ptr_praiseEventId,
                        class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* ptr_Algorithm_Subset,
                        class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_Input_Subset,
                        class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* ptr_Output_Subset
                    );
                    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* get_Algorithm_Subset();//TODO CLASS T
                    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ConcurrentSpace::Control_Of_Concurrent* get_Control_Of_Concurrent();

                    void set_Algorithm_Subset(class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* value_algorithm);//TODO CLASS T

                protected:

                private:
                    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ConcurrentSpace::Control_Of_Concurrent* ptr_Control_Of_Concurrent;
                    class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* ptr_Algorithms_Subset;//TODO CLASS T

                };
            }
        }
    }
}