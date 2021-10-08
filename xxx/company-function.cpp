#include "stock.h"

extern UList* user_list;
extern CList* company_list;
extern User Current_User;

//��˾���У�ע��֮�� 
void Company::ipo()
{
	cout << "������룺";
	string c_;
	cin >> c_;
	code = c_;
	
	cout << endl << "�������룺";
	string p_;
	cin >> p_;
	password = p_;

	cout << endl << "���빫˾���ƣ�";
	string n_;
	cin >> n_;
	name = n_;

	cout << endl << "������ֵ��";
	double ev_;
	cin >> ev_;
	ev = ev_;

	cout << endl << "������ͨ������";
	int s_;
	cin >> s_;
	shares_out = s_;

	cout << endl << "��������";
	double ea_;
	cin >> ea_;
	earning = ea_;

	cout << endl << "�ɹ�����" << endl;
	price = ev / shares_out;
	pe = price / (earning / shares_out);
	cout << "�ɼۣ�" << price << endl;
	cout << "PE��" << pe << endl;
}

//�������� 
void Company::setPassword()
{
    cout << "���������룺";
    string pswd;
    cin >> pswd;
    password = pswd;
    cout << endl << "���" << endl;
}

// ����Earnings
void Company::updateEarning()
{
	cout << "������һ������" << endl;
	double earn;
	cin >> earn;
	earning = earn;
	ev += earning;

	cout << "�������" << endl;
	cout << "����ֵ��" << ev << endl;
	system("pause");
}

void Company_Update_Earning(string code){
	CList* tmp=company_list;
	while(tmp){
		if(tmp->company.getCode()==code) break;
		tmp=tmp->next;
	}
	tmp->company.updateEarning();
}

// ֻʵ����ջ�Ĳ��빦��
bool pushC(CList* &clist, Company c_)
{
    CList* n;
    n->company = c_;
    clist->next=n->next;
    clist->next = n;
    return true;
}

bool popC(CList* &clist, string c_)
{
    CList *p = clist;
    while (p){
        if (p->company.getCode() == c_){
            p->next = p->next->next;
            return true;
        }
        p = p->next;
    }
    return false;
}

int getLengthC(CList* clist)
{
    CList *p=clist;
    int i = 0;
    while (p){
        ++i;
        p = p->next;
    }
    return i;
}

