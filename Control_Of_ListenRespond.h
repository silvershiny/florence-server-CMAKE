#pragma once

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            namespace AlgorithmsSpace
            {
                namespace ListenRespondSpace
                {
                    class Control_Of_ListenRespond
                    {
                    public:
                        Control_Of_ListenRespond();
                        ~Control_Of_ListenRespond();
                        bool getFlag_IO_ThreadState();
                        void setFlag_IO_ThreadState(bool value);

                    protected:

                    private:
                        static bool flag_IO_ThreadState;
                    };
                }
            }
        }
    }
}
