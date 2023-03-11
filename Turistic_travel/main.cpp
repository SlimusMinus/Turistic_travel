#include "Travel.h"


int main()
{
	setlocale(LC_ALL, "ru");
	Director direct;
	Just_fly jf;
	Allinclusive all;
	FlyAndLive FL;
	Vaucher* vch_all = direct.buy_turistic_vaucher(all);
	Vaucher* vch = direct.buy_turistic_vaucher(jf);
	Vaucher* vch_FL = direct.buy_turistic_vaucher(FL);

	system("color F0");
	const int num_menu = 3;
	int ch = 0, active_menu = 0;
	bool q;
	do
	{
		bool exit = false;
		while (!exit)
		{

			show_menu();
			gotoxy(0, active_menu);
			ch = _getch();
			if (ch == 224) ch = _getch();
			switch (ch)
			{

			case 27: exit = true; break;
			case 72: active_menu--; break;
			case 80: active_menu++; break;
			case 13:

				if (active_menu == 0)
				{
					system("cls");
					vch->vaucher();
					jf.Print();
					system("pause");
				}
				else if (active_menu == 1)
				{
					system("cls");
					vch_FL->vaucher();
					FL.Print();
					system("pause");

				}
				else if (active_menu == 2)
				{
					system("cls");
					vch_all->vaucher();
					all.Print();
					system("pause");

				}
				break;
			}
			if (active_menu < 0) active_menu = num_menu - 1;
			if (active_menu > num_menu - 1) active_menu = 0;

		}
		system("cls");
		cout << "If you wanna continue press 1, no 0" << endl;
		cin >> q;
		system("cls");
	} while (q == 1);
	system("cls");

	return 0;

}