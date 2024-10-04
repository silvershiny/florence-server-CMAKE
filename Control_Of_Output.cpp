#include "Control_Of_Output.h"

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output::Control_Of_Output()
{

}
FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output::~Control_Of_Output()
{

}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::OutputSpace::Control_Of_Output::selectSet_Output_Subset_For_Given_PraiseEventId(
	int* ptr_praiseEventId,
	unsigned char concurrent_coreId
)
{
	class FLORENCE::FrameworkSpace::Server* server = FLORENCE::Framework::get_Server();
	switch (*ptr_praiseEventId)
	{
		//===
		//===
	case 0:
		server->get_Data()->get_OutputRefferenceOfCore(concurrent_coreId)->set_OutputBuffer_Subset(new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Output());
		break;

	case 1:

		break;
		//===
		//===
	}
}