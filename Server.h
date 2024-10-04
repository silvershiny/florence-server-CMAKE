#pragma once
#include "Algorithms.h"
#include "Data.h"
#include "Execute.h"
#include "Global.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        class Server
        {
        public:
            Server();
            virtual ~Server();
            class FLORENCE::FrameworkSpace::ServerSpace::Algorithms* get_Algorithms();
            class FLORENCE::FrameworkSpace::ServerSpace::Data* get_Data();
            class FLORENCE::FrameworkSpace::ServerSpace::Execute* get_Execute();
            class FLORENCE::FrameworkSpace::ServerSpace::Global* get_Global();

        protected:

        private:
            class FLORENCE::FrameworkSpace::ServerSpace::Algorithms* ptr_Algorithms;
            class FLORENCE::FrameworkSpace::ServerSpace::Data* ptr_Data;
            class FLORENCE::FrameworkSpace::ServerSpace::Execute* ptr_Execute;
            class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global;
        };
    }
}