#include "Framework/Framework.h"

int main()
{
	Framework timberFramework;

	timberFramework.Init(1920, 1080, "Timber!");

	return timberFramework.Run();
}