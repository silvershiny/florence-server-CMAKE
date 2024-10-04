#pragma once
#include "Control_Of_LaunchConcurrency.h"
#include "Global.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace ExecuteSpace
            {
                class LaunchConcurrency
                {
                public:
                    LaunchConcurrency();
                    virtual ~LaunchConcurrency();

                    void concurrent_Thread_Start(
                        class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
                        unsigned char* ptr_concurrent_CoreId,
                        class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
                        unsigned char* ptr_NumImplementedCores

                    );
                    void initialise_Control(
                        class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
                        unsigned char* ptr_MyNumImplementedCores
                    );
                    void thread_End(
                        class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency,
                        unsigned char* ptr_concurrent_CoreId,
                        class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
                    );
                    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* get_Control_Of_LaunchConcurrency();

                protected:

                private:
                    class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency* ptr_Control_Of_LaunchConcurrency;
                };
            }
        }
    }
}