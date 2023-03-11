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
			cout << "Выберите страну в которую хотите полететь:" << endl;
			cout << "1 - Франция, 2 - Испания, 3 - Италия, 4 - Финляндия, 5 - Греция" << endl;
			cin >> key;
			if (key < 1 || key > 5)
				throw exception("Такой страны в нашем агенстве нет, поробуйте выбрать другую страну");
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
		return country = "Франция";
		break;
	case 2:
		return country = "Испания";
		break;
	case 3:
		return country = "Италия";
		break;
	case 4:
		return country = "Финляндия";
		break;
	case 5:
		return country = "Греция";
		break;
	default:
		cout << "Такой страны в нашем турагенстве нет" << endl;
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
			cout << "Выберите тип питания:" << endl;
			cout << "1 - все включено, 2 - только завтраки" << endl;
			cin >> key;
			if (key < 1 || key > 2)
				throw exception("Такой тип питания наше агенство не предлагает, поробуйте выбрать другой тип");
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
		return food = "все включено";
		break;
	case 2:
		return food = "только завтраки";
		break;
	default:
		cout << "Такого типа питания не предлагается" << endl;
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
			cout << "Введите желаемый рейтинг отеля (от 5 до 10)" << endl;
			cin >> key;
			if (key < 5 || key > 10)
				throw exception("Такой страны в нашем агенстве нет, поробуйте выбрать другую страну");
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
		cout << "Отелей с таким рейтенгом мы не предоставляем" << endl;
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
			cout << "Выберите количество звезд в вашем отеле (от 1 до 5)" << endl;
			cin >> key;
			if (key < 1 || key > 5)
				throw exception("Отелей с таким количеством звезд в нашем агенстве нет, поробуйте выбрать другой рейтинг");
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
		cout << "Такого количества звезд в отелях нашего турагенстве нет" << endl;
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
	if (position == "Франция")
		return 550;
	else if (position == "Испания")
		return 670;
	else if (position == "Италия")
		return 490;
	else if (position == "Финляндия")
		return 400;
	else if (position == "Греция")
		return 500;
	else if (position == "все включено")
		return 150;
	else if (position == "только завтраки")
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
	cout << "Вы выбрали тариф только перелет:" << endl;
	cout << "Страна перелета " << country << ", билет будет стоить " << prod->convert_rub(1, price(country)) << " рублей" << endl;
	delete prod;
}

void FlyAndLive::Print()
{
	system("cls");
	Product* prod = new Adapter(new Money);
	cout << "Вы выбрали тариф перелет и проживание:" << endl;
	cout << "Страна перелета - " << country << ", проживание в " << stars << " отеле " << "с рейтингом " << rating << endl;
	cout << "Стоимость данной туриситической путевки на один день cоставит " << price(country) + price(stars) << " $" << endl;
	cout << "Введите желаемое количество дней пребывания в " << stars << " отеле: ";
	cin >> day;
	cout << "Путевка на " << day << " дней " << "будет стоить " << prod->convert_rub(day, price(stars)) + prod->convert_rub(1, price(country)) << " рублей" << endl;
	prices = prod->convert_rub(1, price(stars) * day + price(country));
	system("pause");
	FamilyTur(prices);
	delete prod;
}

void FlyAndLive::FamilyTur(float prices)
{
	system("cls");
	cout << "Если вы хотите приобрести семейный тур, действует следующая система скидок" << endl;
	cout << "При добавлении еще одного человека действует скидка 5 % за каждого, но не более 15 %" << endl;
	cout << "Если вы хотите добавить человека нажмите 1, если нет то 0" << endl;
	cin >> familyKey;
	if (familyKey == 0)
	{
		cout << "Стоимость путевки в страну " << country << " с проживанием в " << stars
			<< " отеле " << "с рейтингом " << rating << " составит " << prices << " рублей" << endl;
		Additionaly(prices);
	}
	else
	{
		cout << "Введите количество людей которые хотите добавить: ";
		cin >> familyKey;
		if (familyKey == 1)
		{
			prices = prices * 2 - (prices * 2 / 100 * 5);
			cout << "Стоимость путевки на " << familyKey + 1 << " человек " << "в страну " << country << " с проживанием в " << stars
				<< " отеле " << "с рейтингом " << rating << " составит " << prices << " рублей" << endl;
		}

		else if (familyKey == 2)
		{
			prices = prices * 2 - (prices * 2 / 100 * 10);
			cout << "Стоимость путевки на " << familyKey + 1 << " человек" << " в страну " << country << " с проживанием в " << stars
				<< " отеле " << "с рейтингом " << rating << " составит " << prices << " рублей" << endl;
		}

		else if (familyKey > 2)
		{
			prices = prices * 2 - (prices * 2 / 100 * 15);
			cout << "Стоимость путевки на " << familyKey + 1 << " человек" << " в страну " << country << " с проживанием в " << stars
				<< " отеле " << "с рейтингом " << rating << " составит " << prices << " рублей" << endl;
		}
		Additionaly(prices);
	}
}

void Allinclusive::Print()
{
	system("cls");
	Product* prod = new Adapter(new Money);
	cout << "Вы выбрали тариф все включено:" << endl;
	cout << "Страна перелета - " << country << " проживание в " << stars << " отеле " << "с рейтингом " << rating << " тип питания - " << food << endl;
	cout << "Стоимость данной туриситической путевки на один день cоставит " << price(country) + price(stars) + price(food) << " $" << endl;
	cout << "Введите желаемое количество дней пребывания в " << stars << " отеле: ";
	cin >> day;
	cout << "Путевка на " << day << " дней " << "будет стоить " << prod->convert_rub(day, price(stars)) + prod->convert_rub(day, price(food)) + prod->convert_rub(1, price(country)) << " рублей" << endl;
	system("pause"); 
	prices = prod->convert_rub(1, (price(stars)*day + price(food)) * day + price(country));
	FamilyTur(prices);
	delete prod;
}

void Allinclusive::FamilyTur(float prices)
{
	system("cls");
	cout << "Если вы хотите приобрести семейный тур, действует следующая система скидок" << endl;
	cout << "При добавлении еще одного человека действует скидка 5 % за каждого, но не более 15 %" << endl;
	cout << "Если вы хотите добавить людей нажмите любую кнопку отличную от 0, если не хотите нажмите 0 " << endl;
	cin >> familyKey;
	if (familyKey == 0)
	{
		cout << "Стоимость путевки в страну " << country << " с проживанием в " << stars
			<< " отеле " << "с рейтингом " << rating << " и типом питания - " << food << " составит " << prices << " рублей" << endl;
		Additionaly(prices);
	}
	else
	{
		cout << "Введите количество людей которые хотите добавить: ";
		cin >> familyKey;
		if (familyKey == 1)
		{
			prices = prices * 2 - (prices * 2 / 100 * 5);
			cout << "Стоимость путевки на " << familyKey + 1 << " человек " << "в страну " << country << " с проживанием в " << stars
				<< " отеле " << "с рейтингом " << rating << " и типом питания - " << food << " составит " << prices << " рублей" << endl;
		}
		else if (familyKey == 2)
		{
			prices = prices * 2 - (prices * 2 / 100 * 10);
			cout << "Стоимость путевки на " << familyKey + 1 << " человек " << " в страну " << country << " с проживанием в " << stars
				<< " отеле " << "с рейтингом " << rating << " и типом питания - " << food << " составит " << prices << " рублей" << endl;
		}
		else if (familyKey > 2)
		{
			prices = prices * 2 - (prices * 2 / 100 * 15);
			cout << "Стоимость путевки на " << familyKey + 1 << " человек " << " в страну " << country << " с проживанием в " << stars
				<< " отеле " << "с рейтингом " << rating << " и типом питания - " << food << " составит " << prices << " рублей" << endl;
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
	cout << "Если вы хотите включить экскурсии в стоимость путевки нажмите 1, если нет, то 0" << endl;
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
	cout << "Если вы хотите включить трансфер в стоимость путевки нажмите 1, если нет, то 0" << endl;
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
	cout << "Если вы хотите включить страховку в стоимость путевки нажмите 1, если нет, то 0" << endl;
	cin >> change;
	if (change == 1)
	{
		name_additional.append(add_insur);
		//name_additional += add_insur;
		money += 5500;
	}		
	system("cls");
	cout << "Вы выбрали:\nПутевку на " << familyKey + 1 << " человек\n" << "В страну " << country << "\nПроживание в " << stars
		<< " отеле\n" << "Рейтинг " << rating << "\nТип питания - " << food << "\nДоп. услуги - " << name_additional << endl;
	cout << "Окончательная стоимость путевки составит " << money << " рублей" << endl;
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
	cout << "Только перелёт" << endl;
	cout << "Перелёт и проживание" << endl;
	cout << "Всё включено" << endl;
	cout << "=====================" << endl;
	cout << "Press ESC to exit" << endl;
}
