#pragma once
#include <array>
#include "Concurrent.h"
#include "ListenRespond.h"
#include "user_files/Praise0_Algorithm.h"

namespace FLORENCE
{
    namespace FrameworkSpace
    {
        namespace ServerSpace
        {
            class Algorithms
            {
            public:
                Algorithms(unsigned char* ptr_NumberOfImplementedCores);
                virtual ~Algorithms();
                class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent* get_Concurren_Array(unsigned char concurrent_coreId);
                class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond* get_ListenRespond();

                //===
//===
                class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* get_Praise0_Algorithm();
                //===
                //===

            protected:

            private:
                class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent** ptr_Concurrent_Array;
                class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent* ptr_Concurrent[3];
                class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond* ptr_ListenRespond;
                class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent* ptr_New_Concurrent;
                //===
//===
                class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* ptr_Praise0_Algorithms;
                //===
                //===



            };
        }
    }
}