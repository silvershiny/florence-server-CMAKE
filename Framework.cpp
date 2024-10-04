#include <iostream>
#include "Framework.h"

//class FLORENCE::FrameworkSpace::Server* FLORENCE::Framework::FLORENCE::Framework::get_Server();

FLORENCE::Framework::Framework()
{
    System.Console.WriteLine("FLORENCE: Framework");
    this->ptr_Server = new class FLORENCE::FrameworkSpace::Server();
	while (this->ptr_Server == nullptr) { /* wait untill created */ }
    
    System.Console.WriteLine("        ,     \\      /      ,");
    System.Console.WriteLine("       / \\    )\\ __ /(     / \\ ");
    System.Console.WriteLine("      /   \\   (_\\  /_)    /   \\ ");
    System.Console.WriteLine("____ / ____\\__ \\@  @/ ___/_____\\_____");
    System.Console.WriteLine("|              |\\../|               |");
    System.Console.WriteLine("|               \\VV/                |");
    System.Console.WriteLine("|  FLORANCE - FULL STACK DEVELOPMENT |");
    System.Console.WriteLine("|        DEVELOPERS TEMPLATE        |");
    System.Console.WriteLine("|___________________________________|");
    System.Console.WriteLine("|    / \\ /        \\\\        \\ /\\    |");
    System.Console.WriteLine("|  /    V          ))        V   \\  |");
    System.Console.WriteLine("|/                //               \\| ");
    System.Console.WriteLine("`                 V                 '");
}

FLORENCE::Framework::~Framework()
{
	delete FLORENCE::Framework::ptr_Server;
}

class FLORENCE::FrameworkSpace::Server* FLORENCE::Framework::get_Server()
{
	return this->ptr_Server;
}
