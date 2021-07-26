
#include "MainUpdate.h"

int main(void)
{

	system("Double_Side");
	system("mode con:cols=120 lines=30");

	srand((ULONG)GetTickCount64());

	MainUpdate Main;
	Main.Initialize();

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			Main.Update();
			Main.Render();

		}
	}

	return 0;
}

