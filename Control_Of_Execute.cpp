#include "Control_Of_Execute.h"

bool FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute::flag_SystemInitialised = bool(true);
bool FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute::flag_ThreadInitialised[4] = { bool(true), bool(true), bool(true), bool(true) };//NUMBER OF CORES

FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute::Control_Of_Execute(unsigned char* ptr_MyNumImplementedCores)
{
	bool flag_SystemInitialised = bool(true);
	bool flag_ThreadInitialised[4] = { true, true, true, true };//NUMBER OF CORES
}

FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute::~Control_Of_Execute()
{

}

bool FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute::getFlag_SystemInitialised(unsigned char* ptr_MyNumImplementedCores)
{
	for (int index = 0; index < *ptr_MyNumImplementedCores; index++)
	{
		flag_SystemInitialised = false;
		if (flag_ThreadInitialised[index] == true)
		{
			flag_SystemInitialised = true;
		}
	}
	return flag_SystemInitialised;
}

bool FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute::getFlag_ThreadInitialised(unsigned char coreId)
{
	return flag_ThreadInitialised[coreId];
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute::setConditionCodeOfThisThreadedCore(unsigned char coreId)
{
	//Todo
	setFlag_ThreadInitialised(coreId);
}

void FLORENCE::FrameworkSpace::ServerSpace::ExecuteSpace::Control_Of_Execute::setFlag_ThreadInitialised(unsigned char coreId)
{
	flag_ThreadInitialised[coreId] = false;
}