#include "stock.h"

extern UList* user_list;
extern CList* company_list;
extern User Current_User;

//公司上市（注册之后） 
void Company::ipo()
{
	cout << "输入代码：";
	string c_;
	cin >> c_;
	code = c_;
	
	cout << endl << "输入密码：";
	string p_;
	cin >> p_;
	password = p_;

	cout << endl << "输入公司名称：";
	string n_;
	cin >> n_;
	name = n_;

	cout << endl << "输入市值：";
	double ev_;
	cin >> ev_;
	ev = ev_;

	cout << endl << "输入流通股数：";
	int s_;
	cin >> s_;
	shares_out = s_;

	cout << endl << "输入利润：";
	double ea_;
	cin >> ea_;
	earning = ea_;

	cout << endl << "成功上市" << endl;
	price = ev / shares_out;
	pe = price / (earning / shares_out);
	cout << "股价：" << price << endl;
	cout << "PE：" << pe << endl;
}

//更改密码 
void Company::setPassword()
{
    cout << "输入新密码：";
    string pswd;
    cin >> pswd;
    password = pswd;
    cout << endl << "完成" << endl;
}

// 更新Earnings
void Company::updateEarning()
{
	cout << "输入新一年利润：" << endl;
	double earn;
	cin >> earn;
	earning = earn;
	ev += earning;

	cout << "更新完成" << endl;
	cout << "新市值：" << ev << endl;
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

// 只实现了栈的插入功能
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

