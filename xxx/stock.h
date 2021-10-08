#ifndef _STOCK_H_
#define _STOCK_H_

#include <iostream>
#include <string>
#include<stdlib.h>

using namespace std;

class User
{
private:
	string email;
	string password;

public:
	string getEmail()
	{
		return email;
	}
	string getPassword()
	{
		return password;
	}
	void initial();
    void setPassword();
};

class Company
{
private:
	string code;
	string password;
	string name;
	double ev; // enterprise value
	int shares_out;
	double price;
	double earning;
	double pe; // PE ratio
public:
	string getCode()
	{
		return code;
	}
	string getPassword()
	{
		return password;
	}

	string getName()
	{
		return name;
	}
	double getEV()
	{
		return ev;
	}
	int getSO()
	{
		return shares_out;
	}
	double getPrice()
	{
		return price;
	}
	double getEarning()
	{
		return earning;
	}
	double getPE()
	{
		return pe;
	}
	void ipo();
	void updateEarning();
	void setPassword();
	void show();
};

struct CList
{
	Company company;
	struct CList *next;
};

struct UList
{
	User user;
	struct UList *next;
};

extern UList* user_list;
extern CList* company_list;
extern UList* current_user_list;
extern int flag;

//菜单 
void mainmenu();
void Company_Login_Menu();
void User_Login_Menu();
void Company_Check_Menu(string code);
void User_Check_Menu();

//公司注册-登录-更新-修改功能 
void Company_Register();
void Company_Login();
void Company_Update_Earning(string code);
void Company_Modify(string code);

// 公司表
bool pushC(CList* &clist, Company c_); 
bool popC(CList* &clist, string c_);
int getLengthC(CList* clist);

//用户注册-登录-检索-查看功能 
void User_Register();
void User_Login();
void Company_Search();
void Check_Companys();

// 用户-搜索功能
void User_Search_Option_Menu();
bool searchC_Code(CList* clist, string c_);
bool searchC_Name(CList* clist, string n_);

// 用户-排序展示功能
void ListByCode(CList* clist);
void ListByEV(CList* clist);
void ListByPrice(CList* clist);
void ListByEarning(CList* clist);
void ListByPE(CList* clist);

// 用户表
bool pushU(UList* &ulist, User u_); 
bool popU(UList* &ulist, string email_);
int getLengthU(UList ulist);

#endif
