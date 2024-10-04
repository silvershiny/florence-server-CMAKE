#pragma once
#include <vector>
#include "Input.h"
#include "Output.h"


namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace DataSpace
            {
                class Control_Of_Data
                {
                public:
                    Control_Of_Data();
                    virtual ~Control_Of_Data();
                    void popFromStackOfInputPraises(
                        class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* referenceForCore,
                        std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* ptr_inputStack
                    );
                    void popFromStackOfOutput(
                        class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* distributeBuffer,
                        std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* ptr_outputStack
                    );
                    void pushToStackOfInputPraises(
                        std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input*>* ptr_InputStack,
                        class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Input* ptr_PraiseBuffer
                    );
                    void pushToStackOfOutput(
                        std::vector<class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output*>* ptr_outputStack,
                        class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Output* ptr_referenceForCore
                    );

                    bool getFlag_InputStackLoaded();
                    bool getFlag_OutputStackLoaded();

                    void setFlag_InputStackLoaded(bool value);
                    void setFlag_OutputStackLoaded(bool value);

                protected:

                private:
                    void load_Input_Subset_For_PraiseEventId(int* ptr_praiseEventId);

                    static bool flag_InputStackLoaded;
                    static bool flag_OutputStackLoaded;
                };
            }
        }
    }
}