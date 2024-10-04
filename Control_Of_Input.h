#pragma once
#include "Framework.h"
#include "Input.h"
#include "user_files/Praise0_Input.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace DataSpace
            {
                namespace InputSpace
                {
                    class Control_Of_Input
                    {
                    public:
                        Control_Of_Input();
                        virtual ~Control_Of_Input();
                        void selectSet_Input_Subset_For_Given_PraiseEventId(
                            int* ptr_praiseEventId
                        );

                    protected:

                    private:

                    };
                }
            }
        }
    }
}