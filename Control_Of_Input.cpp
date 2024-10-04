#include "Control_Of_Input.h"

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input::Control_Of_Input()
{

}
FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input::~Control_Of_Input()
{

}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::InputSpace::Control_Of_Input::selectSet_Input_Subset_For_Given_PraiseEventId(
	int* ptr_praiseEventId
)
{
	class FLORENCE::FrameworkSpace::Server* server = FLORENCE::Framework::get_Server();
	switch (*ptr_praiseEventId)
	{
//===
//===
	case 0:
		server->get_Data()->get_PraiseBuffer()->set_InputBuffer_SubSet(new class FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input());
		break;

	case 1:

		break;
//===
//===

	}
}


