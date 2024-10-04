#pragma once

namespace FLORENCE
{
	namespace FrameworkSpace
	{
		namespace ServerSpace
		{
			namespace DataSpace
			{
				class Praise0_Input
				{
				public:
					Praise0_Input();
					virtual ~Praise0_Input();
					bool get_A();
					bool get_B();
					void set_A(bool value);
					void set_B(bool value);

				protected:

				private:
					static bool a;
					static bool b;
				};
			}
		}
	}
}