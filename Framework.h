#pragma once
#include "Server.h"

namespace FLORENCE
{
	class Framework
	{
	public:
		Framework();
		virtual ~Framework();
		class FLORENCE::FrameworkSpace::Server* get_Server();

	protected:

	private:
		class FLORENCE::FrameworkSpace::Server* ptr_Server;
	};
}
