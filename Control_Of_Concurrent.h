#pragma once
#include "Framework.h"
#include "user_files/Praise0_Algorithm.h"
#include "user_files/Praise0_Input.h"
#include "user_files/Praise0_Output.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace AlgorithmsSpace
            {
                namespace ConcurrentSpace
                {
                    class Control_Of_Concurrent
                    {
                    public:
                        Control_Of_Concurrent();
                        virtual ~Control_Of_Concurrent();
                        void selectSet_Algorithm_Subset_For_Given_PraiseEventId(
                            int* ptr_praiseEventId,
                            unsigned char concurrent_coreId
                        );

                    protected:

                    private:

                    };
                }
            }
        }
    }
}