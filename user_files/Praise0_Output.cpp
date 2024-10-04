#include "Praise0_Output.h"

bool FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output::praise0_Result = false;

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output::Praise0_Output()
{
	bool praise0_Result = bool(false);
}
FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output::~Praise0_Output()
{

}

bool FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output::getResultForPraise_0()
{
	return praise0_Result;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output::setResultForPraise_0(bool value)
{
	praise0_Result = value;
}