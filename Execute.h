#pragma once
#include <array>
#include "Control_Of_Execute.h"
#include "Framework.h"
#include "Global.h"
#include "LaunchConcurrency.h"
#include "Server.h"
#include <thread>
#include "WriteEnable.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            class Execute
            {
            public:
                Execute(
                    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
                    unsigned char* ptr_MyNumImplementedCores
                );
                virtual ~Execute();
                void initialise_Control(
                    unsigned char* ptr_MyNumImplementedCores,
                    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
                );
                void initialise_Threads();
                class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute* get_Control_Of_Execute();
                class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency* get_LaunchConcurrency();
                class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable* get_WriteEnable();

            protected:

            private:
                class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute* ptr_Control_Of_Execute;
                class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrency* ptr_LaunchConcurrency;
                std::thread* ptr_Thread_WithCoreId[4];//NUMBER OF CORES
                class FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::WriteEnable* ptr_WriteEnable;
            };
        }
    }
}