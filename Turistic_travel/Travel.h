#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

class Money
{
protected:
	int day;
	float prices;
	float money;
	string add_excurs = " экскурсии";
	string add_insur = " страховка";
	string add_transf = " трансфер";
public:
	int price(string position);
	float convert();
	void Additionaly(float prices);
};

class Cash
{
	int quantity;
public:
	Cash(int f = 0) :quantity(f) {	}
	int Getquantity() const { return quantity; }
};


class Servis : public Money
{
protected:
	Servis* pServis;
public:
	void SetSuccessor(Servis* ptrServis) { pServis = ptrServis; }
	virtual void Process(Cash& request, float money, string add) = 0;
};


class Ecursions : public Servis
{
private:
	int change;
public:
	void Process(Cash& request, float money, string add);
};

class Trancfer : public Servis
{
private:
	int change;
public:
	void Process(Cash& request, float money, string add);
};

class Insurance : public Servis
{
private:
	int change;
public:
	void Process(Cash& request, float money, string add);
};

class Price_Service : public Ecursions, public Trancfer, public Insurance
{
	Servis* exc = new Ecursions();
	Servis* trancf = new Trancfer();
	Servis* insur = new Insurance();
};

class Product
{
public:
	virtual float convert_rub(int quantity, float price) = 0;
};

class Adapter : public Product
{
private:
	Money* dol;
public:
	Adapter(Money* dollar) { dol = dollar; }
	float convert_rub(int quantity, float price) override;
};

class Country
{
public:
	string A_country();
};
class Food
{
public:
	string A_food();
};

class Rating
{
public:
	string A_rating();
};

class Stars
{
public:
	string A_stars();
};

class Vaucher
{
public:
	string ctr;
	vector <Country> cntr;
	vector <Food> fd;
	vector <Rating> rtng;
	vector <Stars> st;
	void vaucher();
};

class BuilderVaucher
{
public:
	Vaucher* vch;
	BuilderVaucher() : vch(0) {}
	virtual void buy_vaucher() {}
	virtual void buy_country() {}
	virtual void buy_food() {}
	virtual void look_rating() {}
	virtual void buy_stars() {}
	virtual Vaucher* Get_vaucher() { return vch; }
};


class Director
{
public:
	Vaucher* buy_turistic_vaucher(BuilderVaucher& buy)
	{
		buy.buy_vaucher();
		buy.buy_country();
		buy.buy_food();
		buy.buy_stars();
		buy.look_rating();
		return (buy.Get_vaucher());
	}
};

class Just_fly : public BuilderVaucher, public Money
{

public:
	void buy_vaucher() { vch = new Vaucher; }
	void buy_country() { vch->cntr.push_back(Country()); }
	void Print();
};

class FlyAndLive : public BuilderVaucher, public Money
{

public:
	void buy_vaucher() { vch = new Vaucher; }
	void buy_country() { vch->cntr.push_back(Country()); }
	void look_rating() { vch->rtng.push_back(Rating()); }
	void buy_stars() { vch->st.push_back(Stars()); }
	void Print();
	void FamilyTur(float prices);
};

class Allinclusive : public BuilderVaucher, public Money
{
public:
	void buy_vaucher() { vch = new Vaucher; }
	void buy_country() { vch->cntr.push_back(Country()); }
	void buy_food() { vch->fd.push_back(Food()); }
	void look_rating() { vch->rtng.push_back(Rating()); }
	void buy_stars() { vch->st.push_back(Stars()); }
	void Print();
	void FamilyTur(float prices);
};

void gotoxy(short x, short y);

void show_menu();
