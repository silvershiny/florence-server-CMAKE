#pragma once
#include "Praise0_Input.h"
#include "Praise0_Output.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace AlgorithmsSpace
            {
                class Praise0_Algorithm
                {
                public:
                    Praise0_Algorithm();
                    virtual ~Praise0_Algorithm();
                    void do_Praise(
                        class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_In_SubSet,
                        class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* ptr_Out_SubSet
                    );

                protected:

                private:

                };
            }
        }
    }
}