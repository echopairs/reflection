#include "src/Message1.h"

int main()
{
	auto ps = AutoFactory::ProduceShared("message1");
	if (ps == nullptr)
	{
		std::cout << "register message" << std::endl;
		return 0;
	}
	ps->show();
}
