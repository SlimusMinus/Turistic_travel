#include "Travel.h"
string country, food, stars, rating, name_additional = "";
short familyKey;
string Country::A_country()
{
	short key;
	do
	{
		try
		{
			cout << "�������� ������ � ������� ������ ��������:" << endl;
			cout << "1 - �������, 2 - �������, 3 - ������, 4 - ���������, 5 - ������" << endl;
			cin >> key;
			if (key < 1 || key > 5)
				throw exception("����� ������ � ����� �������� ���, ��������� ������� ������ ������");
		}
		catch (exception& str)
		{
			system("cls");
			cout << str.what() << endl;
		}
	} while (key < 1 || key > 5);
	switch (key)
	{
	case 1:
		return country = "�������";
		break;
	case 2:
		return country = "�������";
		break;
	case 3:
		return country = "������";
		break;
	case 4:
		return country = "���������";
		break;
	case 5:
		return country = "������";
		break;
	default:
		cout << "����� ������ � ����� ����������� ���" << endl;
		break;
	}
}

string Food::A_food()
{
	short key;
	system("cls");
	do
	{
		try
		{
			cout << "�������� ��� �������:" << endl;
			cout << "1 - ��� ��������, 2 - ������ ��������" << endl;
			cin >> key;
			if (key < 1 || key > 2)
				throw exception("����� ��� ������� ���� �������� �� ����������, ��������� ������� ������ ���");
		}
		catch (exception& str)
		{
			system("cls");
			cout << str.what() << endl;
		}

	} while (key < 1 || key > 2);

	switch (key)
	{
	case 1:
		return food = "��� ��������";
		break;
	case 2:
		return food = "������ ��������";
		break;
	default:
		cout << "������ ���� ������� �� ������������" << endl;
		break;
	}
}

string Rating::A_rating()
{
	system("cls");
	short key;
	do
	{
		try
		{
			cout << "������� �������� ������� ����� (�� 5 �� 10)" << endl;
			cin >> key;
			if (key < 5 || key > 10)
				throw exception("����� ������ � ����� �������� ���, ��������� ������� ������ ������");
		}
		catch (exception& str)
		{
			system("cls");
			cout << str.what() << endl;
		}
	} while (key < 5 || key > 10);

	switch (key)
	{
	case 10:
		return rating = "10";
		break;
	case 9:
		return rating = "9";
		break;
	case 8:
		return rating = "8";
		break;
	case 7:
		return rating = "7";
		break;
	case 6:
		return rating = "6";
		break;
	case 5:
		return rating = "5";
		break;
	default:
		cout << "������ � ����� ��������� �� �� �������������" << endl;
		break;
	}
}

string Stars::A_stars()
{
	system("cls");
	short key;
	do
	{
		try
		{
			cout << "�������� ���������� ����� � ����� ����� (�� 1 �� 5)" << endl;
			cin >> key;
			if (key < 1 || key > 5)
				throw exception("������ � ����� ����������� ����� � ����� �������� ���, ��������� ������� ������ �������");
		}
		catch (exception& str)
		{
			system("cls");
			cout << str.what() << endl;
		}
	} while (key < 1 || key > 5);

	switch (key)
	{
	case 1:
		return stars = "*";
		break;
	case 2:
		return stars = "**";
		break;
	case 3:
		return stars = "***";
		break;
	case 4:
		return stars = "****";
		break;
	case 5:
		return stars = "*****";
		break;
	default:
		cout << "������ ���������� ����� � ������ ������ ����������� ���" << endl;
		break;
	}
}

void Vaucher::vaucher()
{
	int i;
	for (i = 0; i < cntr.size(); i++)
		ctr = cntr[i].A_country();
	for (i = 0; i < fd.size(); i++)
		fd[i].A_food();
	for (i = 0; i < st.size(); i++)
		st[i].A_stars();
	for (i = 0; i < rtng.size(); i++)
		rtng[i].A_rating();
}

int Money::price(string position)
{
	if (position == "�������")
		return 550;
	else if (position == "�������")
		return 670;
	else if (position == "������")
		return 490;
	else if (position == "���������")
		return 400;
	else if (position == "������")
		return 500;
	else if (position == "��� ��������")
		return 150;
	else if (position == "������ ��������")
		return 40;
	else if (position == "*****")
		return 200;
	else if (position == "****")
		return 150;
	else if (position == "***")
		return 100;
	else if (position == "**")
		return 50;
	else if (position == "*")
		return 20;
}

float Money::convert()
{
	float one_dollar = 75.44;
	return one_dollar;
}

void Just_fly::Print()
{
	system("cls");
	Product* prod = new Adapter(new Money);
	cout << "�� ������� ����� ������ �������:" << endl;
	cout << "������ �������� " << country << ", ����� ����� ������ " << prod->convert_rub(1, price(country)) << " ������" << endl;
	delete prod;
}

void FlyAndLive::Print()
{
	system("cls");
	Product* prod = new Adapter(new Money);
	cout << "�� ������� ����� ������� � ����������:" << endl;
	cout << "������ �������� - " << country << ", ���������� � " << stars << " ����� " << "� ��������� " << rating << endl;
	cout << "��������� ������ �������������� ������� �� ���� ���� c������� " << price(country) + price(stars) << " $" << endl;
	cout << "������� �������� ���������� ���� ���������� � " << stars << " �����: ";
	cin >> day;
	cout << "������� �� " << day << " ���� " << "����� ������ " << prod->convert_rub(day, price(stars)) + prod->convert_rub(1, price(country)) << " ������" << endl;
	prices = prod->convert_rub(1, price(stars) * day + price(country));
	system("pause");
	FamilyTur(prices);
	delete prod;
}

void FlyAndLive::FamilyTur(float prices)
{
	system("cls");
	cout << "���� �� ������ ���������� �������� ���, ��������� ��������� ������� ������" << endl;
	cout << "��� ���������� ��� ������ �������� ��������� ������ 5 % �� �������, �� �� ����� 15 %" << endl;
	cout << "���� �� ������ �������� �������� ������� 1, ���� ��� �� 0" << endl;
	cin >> familyKey;
	if (familyKey == 0)
	{
		cout << "��������� ������� � ������ " << country << " � ����������� � " << stars
			<< " ����� " << "� ��������� " << rating << " �������� " << prices << " ������" << endl;
		Additionaly(prices);
	}
	else
	{
		cout << "������� ���������� ����� ������� ������ ��������: ";
		cin >> familyKey;
		if (familyKey == 1)
		{
			prices = prices * 2 - (prices * 2 / 100 * 5);
			cout << "��������� ������� �� " << familyKey + 1 << " ������� " << "� ������ " << country << " � ����������� � " << stars
				<< " ����� " << "� ��������� " << rating << " �������� " << prices << " ������" << endl;
		}

		else if (familyKey == 2)
		{
			prices = prices * 2 - (prices * 2 / 100 * 10);
			cout << "��������� ������� �� " << familyKey + 1 << " �������" << " � ������ " << country << " � ����������� � " << stars
				<< " ����� " << "� ��������� " << rating << " �������� " << prices << " ������" << endl;
		}

		else if (familyKey > 2)
		{
			prices = prices * 2 - (prices * 2 / 100 * 15);
			cout << "��������� ������� �� " << familyKey + 1 << " �������" << " � ������ " << country << " � ����������� � " << stars
				<< " ����� " << "� ��������� " << rating << " �������� " << prices << " ������" << endl;
		}
		Additionaly(prices);
	}
}

void Allinclusive::Print()
{
	system("cls");
	Product* prod = new Adapter(new Money);
	cout << "�� ������� ����� ��� ��������:" << endl;
	cout << "������ �������� - " << country << " ���������� � " << stars << " ����� " << "� ��������� " << rating << " ��� ������� - " << food << endl;
	cout << "��������� ������ �������������� ������� �� ���� ���� c������� " << price(country) + price(stars) + price(food) << " $" << endl;
	cout << "������� �������� ���������� ���� ���������� � " << stars << " �����: ";
	cin >> day;
	cout << "������� �� " << day << " ���� " << "����� ������ " << prod->convert_rub(day, price(stars)) + prod->convert_rub(day, price(food)) + prod->convert_rub(1, price(country)) << " ������" << endl;
	system("pause"); 
	prices = prod->convert_rub(1, (price(stars)*day + price(food)) * day + price(country));
	FamilyTur(prices);
	delete prod;
}

void Allinclusive::FamilyTur(float prices)
{
	system("cls");
	cout << "���� �� ������ ���������� �������� ���, ��������� ��������� ������� ������" << endl;
	cout << "��� ���������� ��� ������ �������� ��������� ������ 5 % �� �������, �� �� ����� 15 %" << endl;
	cout << "���� �� ������ �������� ����� ������� ����� ������ �������� �� 0, ���� �� ������ ������� 0 " << endl;
	cin >> familyKey;
	if (familyKey == 0)
	{
		cout << "��������� ������� � ������ " << country << " � ����������� � " << stars
			<< " ����� " << "� ��������� " << rating << " � ����� ������� - " << food << " �������� " << prices << " ������" << endl;
		Additionaly(prices);
	}
	else
	{
		cout << "������� ���������� ����� ������� ������ ��������: ";
		cin >> familyKey;
		if (familyKey == 1)
		{
			prices = prices * 2 - (prices * 2 / 100 * 5);
			cout << "��������� ������� �� " << familyKey + 1 << " ������� " << "� ������ " << country << " � ����������� � " << stars
				<< " ����� " << "� ��������� " << rating << " � ����� ������� - " << food << " �������� " << prices << " ������" << endl;
		}
		else if (familyKey == 2)
		{
			prices = prices * 2 - (prices * 2 / 100 * 10);
			cout << "��������� ������� �� " << familyKey + 1 << " ������� " << " � ������ " << country << " � ����������� � " << stars
				<< " ����� " << "� ��������� " << rating << " � ����� ������� - " << food << " �������� " << prices << " ������" << endl;
		}
		else if (familyKey > 2)
		{
			prices = prices * 2 - (prices * 2 / 100 * 15);
			cout << "��������� ������� �� " << familyKey + 1 << " ������� " << " � ������ " << country << " � ����������� � " << stars
				<< " ����� " << "� ��������� " << rating << " � ����� ������� - " << food << " �������� " << prices << " ������" << endl;
		}
		Additionaly(prices);
	}
}

float Adapter::convert_rub(int quantity, float price)
{
	return (dol->convert() * quantity * price);
}

void Money::Additionaly(float prices)
{
	Servis* exc = new Ecursions();
	Servis* trancf = new Trancfer();
	Servis* insur = new Insurance();
	exc->SetSuccessor(trancf);
	trancf->SetSuccessor(insur);
	Cash start(prices);
	exc->Process(start, prices, name_additional);
}

void Ecursions::Process(Cash& request, float money, string add)
{
	system("pause");
	system("cls");
	cout << "���� �� ������ �������� ��������� � ��������� ������� ������� 1, ���� ���, �� 0" << endl;
	cin >> change;
	if (change == 1)
	{
		name_additional.append(add_excurs);
		//name_additional = name_additional + add_excurs;
		money += 10000;
		pServis->Process(request, money, name_additional);
	}
	else
		pServis->Process(request, money, name_additional);
}

void Trancfer::Process(Cash& request, float money, string add)
{
	cout << "���� �� ������ �������� �������� � ��������� ������� ������� 1, ���� ���, �� 0" << endl;
	cin >> change;
	if (change == 1)
	{
		name_additional.append(add_transf);
		//name_additional += add_transf;
		money += 1500;
		pServis->Process(request, money, name_additional);
	}
	else
		pServis->Process(request, money, name_additional);
}

void Insurance::Process(Cash& request, float money, string add)
{
	Product* prod = new Adapter(new Money);
	cout << "���� �� ������ �������� ��������� � ��������� ������� ������� 1, ���� ���, �� 0" << endl;
	cin >> change;
	if (change == 1)
	{
		name_additional.append(add_insur);
		//name_additional += add_insur;
		money += 5500;
	}		
	system("cls");
	cout << "�� �������:\n������� �� " << familyKey + 1 << " �������\n" << "� ������ " << country << "\n���������� � " << stars
		<< " �����\n" << "������� " << rating << "\n��� ������� - " << food << "\n���. ������ - " << name_additional << endl;
	cout << "������������� ��������� ������� �������� " << money << " ������" << endl;
}


void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}

void show_menu()
{
	system("cls");
	cout << "������ ������" << endl;
	cout << "������ � ����������" << endl;
	cout << "�� ��������" << endl;
	cout << "=====================" << endl;
	cout << "Press ESC to exit" << endl;
}
