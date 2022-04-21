#include "Framework/Framework.h"

int main()
{
	Framework fw;
	
	fw.Init(); //초기화

	while (fw.windowIsOpen()) //게임루프
	{
		fw.Update();
		fw.Draw(); 
	}

	return 0;
}