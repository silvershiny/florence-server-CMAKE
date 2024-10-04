#include "Praise0_Algorithm.h"

FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm::Praise0_Algorithm()
{
}

FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm::~Praise0_Algorithm()
{
}

void FLORENCE::FrameworkSpace::ServerSpace::AlgorithmsSpace::Praise0_Algorithm::do_Praise(
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input* ptr_In_SubSet,
    class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output* ptr_Out_SubSet
)
{
    bool result = false;
    if (ptr_In_SubSet->get_A() == true && ptr_In_SubSet->get_B() == true)
    {
        ptr_Out_SubSet->setResultForPraise_0(true);
    }
    else if (ptr_In_SubSet->get_A() == true && ptr_In_SubSet->get_B() == false)
    {
        ptr_Out_SubSet->setResultForPraise_0(false);
    }
    else if (ptr_In_SubSet->get_A() == false && ptr_In_SubSet->get_B() == true)
    {
        ptr_Out_SubSet->setResultForPraise_0(false);
    }
    else if (ptr_In_SubSet->get_A() == false && ptr_In_SubSet->get_B() == false)
    {
        ptr_Out_SubSet->setResultForPraise_0(false);
    }
}
