#include "Praise0_Input.h"

bool FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input::a = false;
bool FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input::b = false;

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input::Praise0_Input()
{
	bool a = bool(false);
	bool b = bool(false);
}

FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input::~Praise0_Input()
{
}

bool FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input::get_A()
{
	return a;
}

bool FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input::get_B()
{
	return b;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input::set_A(bool value)
{
	a = value;
}

void FLORENCE::FrameworkSpace::ServerSpace::DataSpace::Praise0_Input::set_B(bool value)
{
	b = value;
}
