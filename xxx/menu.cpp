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
	cout << "*** 1.��˾�û� ***" << endl;
	cout << "*** 2.�����û� ***" << endl;
	cout << "*** 0.�˳�ϵͳ ***" << endl;
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
		cout << "��ӭ�´�ʹ�ã�" << endl;
		exit(0);
		break;
	default:
		cout << "��Ч������������" << endl;
		mainmenu();
		break;
	}
}

void Company_Login_Menu()
{
	system("cls");
	system("color b1");
	cout << "***************" << endl;
	cout << "**** 1.��¼ ***" << endl;
	cout << "**** 2.ע�� ***" << endl;
	cout << "**** 3.���� ***" << endl;
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
		cout << "����ˣ�����������" << endl;
		system("pause");
		system("cls");
		Company_Login_Menu();
		break;
	}
}

void Company_Login()
{
	cout << "�����빫˾���룺";
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
	int input_time = 0; // �����������Ĵ�
	if (c_is_in && input_time <= 5)
	{
		while (input_time <= 5)
		{
			cout << endl
				<< "���������룺";
			string pswd_;
			cin >> pswd_;
			input_time++;
			if (p->company.getPassword() == pswd_)
			{
				cout << endl
					<< "��¼�ɹ�" << endl;
				Company_Check_Menu(code_);
				break;
			}
			cout << endl
				<< "�����������������";
		}
	}
	else
	{
		cout << endl
			<< "���������빫˾����" << endl;
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
	cout << "****** 1.�޸����� ********" << endl;
	cout << "*** 2.������һ������� ***" << endl;
	cout << "******  3.�˳���¼   *****" << endl;
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
			cout << "����ˣ�����������" << endl;
			system("pause");
			system("cls");
			Company_Check_Menu(code);
			break;
	}
}

//�û�����Ŀ¼ 

void User_Login_Menu()
{
	flag = 0;
	system("cls");
	system("color b1");
	cout << "***************" << endl;
	cout << "**** 1.��¼ ***" << endl;
	cout << "**** 2.ע�� ***" << endl;
	cout << "**** 3.���� ***" << endl;
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
		cout << "����ˣ�����������" << endl;
		system("pause");
		system("cls");
		User_Login_Menu();
		break;
	}
}


void User_Check_Menu() {
	system("cls");
	cout << "**************************" << endl;
	cout << "*****  1.������˾��Ϣ ****" << endl;
	cout << "*****  2.�鿴���й�˾ ****" << endl;
	cout << "*****    3.�������� ******" << endl;
	cout << "******   4.�˳���¼  *****" << endl;
	cout << "**************************" << endl;
	int select2 = 0;
	cin >> select2;
	if(!company_list&&(select2==2||select2==1)){
		cout<<"���޹�˾��Ϣ"<<endl;
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
		cout << "����ˣ�����������" << endl;
		system("pause");
		system("cls");
		User_Check_Menu();
		break;
	}
}

void User_Search_Option_Menu() {
	system("cls");
	cout << "*************************" << endl;
	cout << "***** 1.���������� ******" << endl;
	cout << "***** 2.����ֵ���� ******" << endl;
	cout << "***** 3.���۸����� ******" << endl;
	cout << "***** 4.��Earning���� ***" << endl;
	cout << "***** 5.��P/E���� *******" << endl;
	cout << "*************************" << endl;
	int select3=0;
	cin>>select3;
	if(!company_list){
		cout<<"���޹�˾��Ϣ"<<endl;
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
		cout << "����ˣ�����������" << endl;
		system("pause");
		system("cls");
		User_Search_Option_Menu();
		break;
	} 
}

