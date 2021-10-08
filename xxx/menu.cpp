#include "stock.h"

extern UList* user_list;
extern CList* company_list;
extern UList* current_user_list;
extern int flag;

void mainmenu()
{
	system("cls");
	system("color e3");
	cout << "******************" << endl;
	cout << "*** 1.公司用户 ***" << endl;
	cout << "*** 2.个人用户 ***" << endl;
	cout << "*** 0.退出系统 ***" << endl;
	cout << "******************" << endl;
	int select;
	cin >> select;
	switch (select)
	{
	case 1:
		system("cls");
		Company_Login_Menu();
		break;
	case 2:
		system("cls");
		User_Login_Menu();
		break;
	case 0:
		system("cls");
		cout << "欢迎下次使用！" << endl;
		exit(0);
		break;
	default:
		cout << "无效，请重新输入" << endl;
		mainmenu();
		break;
	}
}

void Company_Login_Menu()
{
	system("cls");
	system("color b1");
	cout << "***************" << endl;
	cout << "**** 1.登录 ***" << endl;
	cout << "**** 2.注册 ***" << endl;
	cout << "**** 3.返回 ***" << endl;
	cout << "***************" << endl;
	int select;
	cin >> select;
	switch (select)
	{
	case 1:
		Company_Login();
		break;
	case 2:
		Company_Register();
		system("pause");
		Company_Login_Menu();
		break;
	case 3:
		mainmenu();
		break;
	default:
		cout << "输错了，请重新输入" << endl;
		system("pause");
		system("cls");
		Company_Login_Menu();
		break;
	}
}

void Company_Login()
{
	cout << "请输入公司代码：";
	string code_;
	cin >> code_;
	bool c_is_in = false;
	CList *p = company_list;
	while (p)
	{
		if (p->company.getCode() == code_)
		{
			c_is_in = true;
			break;
		}
		p = p->next;
	}
	int input_time = 0; // 最多允许输错四次
	if (c_is_in && input_time <= 5)
	{
		while (input_time <= 5)
		{
			cout << endl
				<< "请输入密码：";
			string pswd_;
			cin >> pswd_;
			input_time++;
			if (p->company.getPassword() == pswd_)
			{
				cout << endl
					<< "登录成功" << endl;
				Company_Check_Menu(code_);
				break;
			}
			cout << endl
				<< "密码错误，请重新输入";
		}
	}
	else
	{
		cout << endl
			<< "请重新输入公司代码" << endl;
		Company_Login_Menu();
	}
}

void Company_Register()
{
	CList *tmp = new CList;
	tmp->company.ipo();
	tmp->next = NULL;
	if (!company_list)
		company_list = tmp;
	else
	{
		CList *p = company_list;
		while (p->next)
			p = p->next;
		p->next = tmp;
	}
}

void Company_Check_Menu(string code){
	system("cls");
	cout << "**************************" << endl;
	cout << "****** 1.修改密码 ********" << endl;
	cout << "*** 2.新增新一年的利润 ***" << endl;
	cout << "******  3.退出登录   *****" << endl;
	cout << "**************************" << endl;
	int select=0;
	cin>>select;
	switch(select){
		case 1:
			company_list->company.setPassword();
			break;
		case 2:
			Company_Update_Earning(code);
			Company_Check_Menu(code);
			break;
		case 3:
			Company_Login_Menu();
			break;
		default:
			cout << "输错了，请重新输入" << endl;
			system("pause");
			system("cls");
			Company_Check_Menu(code);
			break;
	}
}

//用户二级目录 

void User_Login_Menu()
{
	flag = 0;
	system("cls");
	system("color b1");
	cout << "***************" << endl;
	cout << "**** 1.登录 ***" << endl;
	cout << "**** 2.注册 ***" << endl;
	cout << "**** 3.返回 ***" << endl;
	cout << "***************" << endl;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		User_Login();
		break;
	case 2:
		User_Register();
		system("pause");
		User_Login_Menu();
		break;
	case 3:
		mainmenu();
		break;
	default:
		cout << "输错了，请重新输入" << endl;
		system("pause");
		system("cls");
		User_Login_Menu();
		break;
	}
}


void User_Check_Menu() {
	system("cls");
	cout << "**************************" << endl;
	cout << "*****  1.搜索公司信息 ****" << endl;
	cout << "*****  2.查看所有公司 ****" << endl;
	cout << "*****    3.更改密码 ******" << endl;
	cout << "******   4.退出登录  *****" << endl;
	cout << "**************************" << endl;
	int select2 = 0;
	cin >> select2;
	if(!company_list&&(select2==2||select2==1)){
		cout<<"暂无公司信息"<<endl;
		system("pause");
		User_Check_Menu();
	}
	
	switch (select2)
	{
	case 1:
		User_Search_Option_Menu();
		system("pause");
		User_Check_Menu(); 
		break;
	case 2:	
		Check_Companys();
		system("pause");
		User_Check_Menu();
		break;
	case 3:
		current_user_list->user.setPassword();
		break;
	case 4:
		system("cls");
		system("color e3");
		User_Login_Menu();
		break;
	default:
		cout << "输错了，请重新输入" << endl;
		system("pause");
		system("cls");
		User_Check_Menu();
		break;
	}
}

void User_Search_Option_Menu() {
	system("cls");
	cout << "*************************" << endl;
	cout << "***** 1.按代码排列 ******" << endl;
	cout << "***** 2.按市值排列 ******" << endl;
	cout << "***** 3.按价格排列 ******" << endl;
	cout << "***** 4.按Earning排列 ***" << endl;
	cout << "***** 5.按P/E排列 *******" << endl;
	cout << "*************************" << endl;
	int select3=0;
	cin>>select3;
	if(!company_list){
		cout<<"暂无公司信息"<<endl;
		system("pause");
		User_Search_Option_Menu();
	} 
	switch(select3){
	case 1:
		ListByCode(company_list);
		break;
	case 2:
		ListByEV(company_list);
		break;
	case 3:
		ListByPrice(company_list);
		break;
	case 4:
		ListByEarning(company_list);
		break;
	case 5:
		ListByPE(company_list);
		break;
	default:
		cout << "输错了，请重新输入" << endl;
		system("pause");
		system("cls");
		User_Search_Option_Menu();
		break;
	} 
}

