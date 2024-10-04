#include "Algorithms.h"

FLORENCE::FrameworkSpace::ServerSpace::Algorithms::Algorithms(unsigned char* ptr_NumberOfImplementedCores)
{
    this->ptr_New_Concurrent = new FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent();
    this->ptr_New_Concurrent->initialise_Control();

    FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent* ptr_Concurrent[3] = {
        this->ptr_New_Concurrent,
        this->ptr_New_Concurrent,
        this->ptr_New_Concurrent
    };//NUMBER OF CONCURRENT CORES
    delete this->ptr_New_Concurrent;

    this->ptr_Concurrent_Array = this->ptr_Concurrent;
    while (this->ptr_Concurrent_Array == nullptr) { /* wait untill class constructed */ }

    this->ptr_ListenRespond = new class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond();
    while (this->ptr_ListenRespond == nullptr) { /* wait untill class constructed */ }
    this->ptr_ListenRespond->initialise_Control();
//===
//===
    this->ptr_Praise0_Algorithms = new class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm();
    while (this->ptr_Praise0_Algorithms == nullptr) { /* wait untill class constructed */ }
//===
//===
}

FLORENCE::FrameworkSpace::ServerSpace::Algorithms::~Algorithms()
{
    for (int index = 0; index < 3; index++)//NUMBER OF CONCURRENT CORES
    {
        delete FLORENCE::FrameworkSpace::ServerSpace::Algorithms::ptr_Concurrent[index];
    }
    delete FLORENCE::FrameworkSpace::ServerSpace::Algorithms::ptr_Concurrent_Array;
    delete FLORENCE::FrameworkSpace::ServerSpace::Algorithms::ptr_ListenRespond;
    delete FLORENCE::FrameworkSpace::ServerSpace::Algorithms::ptr_Praise0_Algorithms;
}

class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Concurrent* FLORENCE::FrameworkSpace::ServerSpace::Algorithms::get_Concurren_Array(unsigned char concurrent_coreId)
{
    return this->ptr_Concurrent[concurrent_coreId];
}

class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::ListenRespond* FLORENCE::FrameworkSpace::ServerSpace::Algorithms::get_ListenRespond()
{
    return this->ptr_ListenRespond;
}

//===
//===
class FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm* FLORENCE::FrameworkSpace::ServerSpace::Algorithms::get_Praise0_Algorithm()
{
    return this->ptr_Praise0_Algorithms;
}
//===
//===