#include "Framework/Framework.h"

int main()
{
	Framework timberFramework;

	timberFramework.Init(1280, 720, "Timber!");

	return timberFramework.Run();
}