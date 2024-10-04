#include "Control_Of_LaunchConcurrency.h"

unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::ptr_concurrent_CoreId_Index = nullptr;
int* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::ptr_count_LaunchActive_For[3] = { nullptr, nullptr, nullptr };//NUMBER OF CONCURNT CORES
int* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::ptr_count_LaunchIdle_For[3] = { nullptr, nullptr, nullptr };//NUMBER OF CONCURNT CORES
bool FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::flag_ConcurrentCoreState[3] = { false, false, false };//NUMBER OF CONCURRENT CORES
unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::ptr_new_concurrent_CoreId_Index = nullptr;
bool FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::flag_praisingLaunch = false;
unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::ptr_que_CoreToLaunch[3] = { nullptr, nullptr, nullptr };//NUMBER OF CONCURRENT CORES

FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::Control_Of_LaunchConcurrency(
    FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
    unsigned char* ptr_NumImplementedCores
)
{
    unsigned char* ptr_concurrent_CoreId_Index = new unsigned char(0);
    int* ptr_count_LaunchActive_For[3] = { new int(0), new int(0), new int(0) };//NUMBER OF CONCURNT CORES
    int* ptr_count_LaunchIdle_For[3] = { new int(0), new int(0), new int(0) };//NUMBER OF CONCURNT CORES
    bool flag_ConcurrentCoreState[3] = { bool(false), bool(false), bool(false) };//NUMBER OF CONCURNT CORES
    unsigned char* ptr_new_concurrent_CoreId_Index = new unsigned char(0);
    bool flag_praisingLaunch = false;
    unsigned char* ptr_que_CoreToLaunch[3] = { new unsigned char(0), new unsigned char(0), new unsigned char(0) };//NUMBER OF CONCURNT CORES
}

FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::~Control_Of_LaunchConcurrency()
{
    delete FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::ptr_concurrent_CoreId_Index;
    for (int index = 0; index < 3; index++)
    {
        delete FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::ptr_count_LaunchActive_For[index];
        delete FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::ptr_count_LaunchIdle_For[index];
        delete FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::ptr_que_CoreToLaunch[index];
    }//NUMBER OF CONCURRENT CORES
    delete FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::ptr_new_concurrent_CoreId_Index;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::launchEnable_Activate(
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
)
{
    setFlag_ConcurrentCoreState(getFlag_CoreId_Of_CoreToLaunch(), ptr_Global->getConst_Core_ACTIVE());
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::launchEnable_Request(
    unsigned char* concurrent_CoreId,
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global
)
{
    while (getFlag_ConcurrentCoreState(getFlag_CoreId_Of_CoreToLaunch()) != ptr_Global->getConst_Core_IDLE())
    {

    }
    while (getFlag_PraisingLaunch() == true)
    {
        dynamicStagger(concurrent_CoreId);
    }
    setFlag_PraisingLaunch(true);
    set_concurrent_CoreId_Index(*get_new_concurrent_CoreId_Index());
    if (*get_concurrent_CoreId_Index() == *concurrent_CoreId)
    {

    }
    else
    {
        set_new_concurrent_CoreId_Index(*get_concurrent_CoreId_Index() + 1);
        if (*get_concurrent_CoreId_Index() == 3)
        {
            set_new_concurrent_CoreId_Index(0);
        }
        setFlag_PraisingLaunch(false);
        launchEnable_Request(
            concurrent_CoreId,
            ptr_Global
        );
    }
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::launchEnable_SortQue(
    class FLORENCE::FrameworkSpace::ServerSpace::Global* ptr_Global,
    unsigned char* ptr_NumImplementedCores
)
{
    for (unsigned char index_A = 0; index_A < *ptr_NumImplementedCores - 2; index_A++)
    {
        for (unsigned char index_B = index_A + 1; index_B < *ptr_NumImplementedCores - 1; index_B++)
        {
            if (getFlag_ConcurrentCoreState(get_que_CoreToLaunch(&index_A)) == ptr_Global->getConst_Core_ACTIVE())
            {
                if (getFlag_ConcurrentCoreState(get_que_CoreToLaunch(&index_B)) == ptr_Global->getConst_Core_IDLE())
                {
                    launchEnable_ShiftQueValues(&index_A, &index_B);
                }
                else if (getFlag_ConcurrentCoreState(get_que_CoreToLaunch(&index_B)) == ptr_Global->getConst_Core_ACTIVE())
                {
                    if (get_count_LaunchActive_For(&index_A) > get_count_LaunchActive_For(&index_B))
                    {
                        launchEnable_ShiftQueValues(&index_A, &index_B);
                    }
                }
            }
            else if (getFlag_ConcurrentCoreState(get_que_CoreToLaunch(&index_A)) == ptr_Global->getConst_Core_IDLE())

                if (getFlag_ConcurrentCoreState(get_que_CoreToLaunch(&index_B)) == ptr_Global->getConst_Core_IDLE())
                {
                    if (get_count_LaunchIdle_For(&index_A) < get_count_LaunchIdle_For(&index_B))
                    {
                        launchEnable_ShiftQueValues(&index_A, &index_B);
                    }
                }
        }
    }
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::launchQue_Update(
    unsigned char* ptr_NumImplementedCores
)
{
    for (unsigned char index = 0; index < *ptr_NumImplementedCores; index++)
    {
        switch (getFlag_ConcurrentCoreState(&index))
        {
        case false:
        {
            set_count_LaunchActive_For(&index, 0);
            set_count_LaunchIdle_For(&index, *get_count_LaunchIdle_For(&index) + 1);
            break;
        }
        case true:
        {
            set_count_LaunchActive_For(&index, *get_count_LaunchActive_For(&index) + 1);
            set_count_LaunchIdle_For(&index, 0);
            break;
        }
        }
    }
}

unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::get_concurrent_CoreId_Index()
{
    return ptr_concurrent_CoreId_Index;
}

unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::get_coreId_To_Launch()
{
    return ptr_que_CoreToLaunch[0];
}

bool FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::getFlag_ConcurrentCoreState(unsigned char* concurrent_CoreId)
{
    return flag_ConcurrentCoreState[*concurrent_CoreId];
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::setFlag_PraisingLaunch(bool value)
{
    flag_praisingLaunch = value;
}

unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::get_new_concurrent_CoreId_Index()
{
    return ptr_new_concurrent_CoreId_Index;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::set_concurrent_CoreId_Index(unsigned char value)
{
    ptr_concurrent_CoreId_Index = &value;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::setFlag_ConcurrentCoreState(unsigned char* concurrent_CoreId, bool value)
{
    flag_ConcurrentCoreState[*concurrent_CoreId] = &value;
}


bool FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::getFlag_PraisingLaunch()
{
    return flag_praisingLaunch;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::set_new_concurrent_CoreId_Index(unsigned char value)
{
    ptr_new_concurrent_CoreId_Index = &value;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::dynamicStagger(
    unsigned char* ptr_coreId
)
{
    if (*get_concurrent_CoreId_Index() == *ptr_coreId)
    {
        //exit early
    }
    else
    {
        int* ptr_count = new int(0);
        while (*ptr_count < 20)//todo time till flag change
        {

            ptr_count = ptr_count + 1;
        }
        delete ptr_count;
    }
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::launchEnable_ShiftQueValues(
    unsigned char* concurrent_CoreId_A,
    unsigned char* concurrent_CoreId_B
)
{
    ptr_temp_Int = new int(0);
    ptr_temp_Int = get_count_LaunchActive_For(concurrent_CoreId_A);
    set_count_LaunchActive_For(concurrent_CoreId_A, *get_count_LaunchActive_For(concurrent_CoreId_B));
    set_count_LaunchActive_For(concurrent_CoreId_B, *ptr_temp_Int);

    ptr_temp_Int = get_count_LaunchIdle_For(concurrent_CoreId_A);
    set_count_LaunchIdle_For(concurrent_CoreId_A, *get_count_LaunchIdle_For(concurrent_CoreId_B));
    set_count_LaunchIdle_For(concurrent_CoreId_B, *ptr_temp_Int);
    delete ptr_temp_Int;

    ptr_temp_UnnsignedChar = new unsigned char(0);
    ptr_temp_UnnsignedChar = get_que_CoreToLaunch(concurrent_CoreId_A);
    set_que_CoreToLaunch(concurrent_CoreId_A, *get_que_CoreToLaunch(concurrent_CoreId_B));
    set_que_CoreToLaunch(concurrent_CoreId_B, *ptr_temp_UnnsignedChar);
    delete ptr_temp_UnnsignedChar;
}

int* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::get_count_LaunchActive_For(unsigned char* concurrent_CoreId)
{
    return ptr_count_LaunchActive_For[*concurrent_CoreId];
}

int* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::get_count_LaunchIdle_For(unsigned char* concurrent_CoreId)
{
    return ptr_count_LaunchIdle_For[*concurrent_CoreId];
}

unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::getFlag_CoreId_Of_CoreToLaunch()
{
    return ptr_que_CoreToLaunch[0];
}

unsigned char* FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::get_que_CoreToLaunch(unsigned char* index)
{
    return ptr_que_CoreToLaunch[*index];
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::set_count_LaunchActive_For(unsigned char* concurrent_CoreId, int value)
{
    ptr_count_LaunchActive_For[*concurrent_CoreId] = &value;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::set_count_LaunchIdle_For(unsigned char* concurrent_CoreId, int value)
{
    ptr_count_LaunchIdle_For[*concurrent_CoreId] = &value;
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::LaunchConcurrencySpace::Control_Of_LaunchConcurrency::set_que_CoreToLaunch(unsigned char* concurrent_CoreId, unsigned char value)
{
    ptr_que_CoreToLaunch[*concurrent_CoreId] = &value;
}