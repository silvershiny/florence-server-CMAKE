#pragma once
#include <array>
#include "Control_Of_Data.h"
#include "Input.h"
#include "Output.h"
#include "user_files/Praise0_Input.h"
#include "user_files/Praise0_Output.h"
#include <vector>

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            class Data
            {
            public:
                Data(unsigned char* ptr_NumberOfImplementedCores);
                virtual ~Data();
                void initialise_Control();
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Control_Of_Data* get_Control_Of_Data();
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* get_DistributeBuffer();
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* get_InputRefferenceOfCore(unsigned char concurrent_coreId);
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* get_OutputRefferenceOfCore(unsigned char concurrent_coreId);
                std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* get_StackOfInputPraise();
                std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* get_StackOfDistributeBuffer();
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* get_PraiseBuffer();

                void set_DistributeBuffer(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* value_Output);
                void set_InputRefferenceOfCore(unsigned char concurrent_coreId, class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* value_Input);
                void set_OutputRefferenceOfCore(unsigned char concurrent_coreId, class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* value_Output);
                void set_PraiseBuffer(class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* value_Input);

            protected:

            private:
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Control_Of_Data* ptr_Control_Of_Data;
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_PraiseBuffer;
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* ptr_DistributeBuffer;
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_InputRefferenceOfCore[3];//NUMBER OF CONCURRENT CORES
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input** ptr_InputRefferenceOfCore_Array;
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_new_Input;
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* ptr_new_Output;
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* ptr_OutputRefferenceOfCore[3];//NUMBER OF CONCURRENT CORES
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output** ptr_OutputRefferenceOfCore_Array;
                std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* ptr_StackOfInputPraise;
                std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* ptr_StackOfDistributeBuffer;
                //===
                //===
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* prt_Praise0_Input;
                class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* prt_Praise0_Outut;
                //===
                //===

            };
        }
    }
}