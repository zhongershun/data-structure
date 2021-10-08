#include "stock.h"
#include <algorithm>

UList* current_user_list=NULL; 
extern UList* user_list;
extern CList* company_list;

void User::initial(){
	UList *p = user_list;
	string Email;
	string Password;
	cout << "请输入邮箱： " << endl;
	cin >> Email;
	while (p) {
		if (p->user.getEmail() == Email) {
			cout << "对不起，这个邮箱已经注册过了，请重新注册" << endl;
			system("pause");
			User_Login_Menu();
		}
		p = p->next;
	}
	cout << "请输入密码： " << endl;
	cin >> Password;
	email=Email;
	password=Password;
}

int flag;
void User_Login()
{
	
	system("cls");
	system("color f9");
	UList* tmp=user_list;
	string email;
	string password;
	cout << "请输入邮箱： " << endl;
	cin >> email;
	cout << "请输入密码： " << endl;
	cin >> password;
	if (user_list == NULL)
	{
		cout << "请先注册" << endl;
		system("pause");
		User_Login_Menu();
	}
	else
	{
		while (email != tmp->user.getEmail() && tmp->next != NULL) tmp = tmp->next;
		if (email == tmp->user.getEmail())
		{
			if (password == tmp->user.getPassword())
			{
				cout << "登陆成功！" << endl;
				current_user_list=tmp;
				User_Check_Menu();
			}
			else
			{
				cout << "密码错误！" << endl;
				system("pause");
				User_Login_Menu();
			}
		}
		else
		{
			cout << "账号不存在，请重新输入！还有" << 5 - flag - 1 << "次机会" << endl;
			flag++;
			if (flag == 5)
			{
				cout << "输错次数过多，请重新登入" << endl;
				User_Login_Menu();
			}
			system("pause");
			User_Login();
		}

		system("pause");
	}
}

void User_Register() {
	system("cls");
	system("color f9");
	UList *p = user_list;
	UList *tmp = new UList;
	tmp->next = NULL;	
	tmp->user.initial();
	if (!user_list) 
		user_list = tmp;
	else {
		while (p->next) p = p->next;
		p->next = tmp;
	}
}

//更改密码 
void User::setPassword()
{
    cout << "输入新密码：";
    string pswd;
    cin >> pswd;
    password = pswd;
    cout << endl << "完成" << endl;
}

void Company_Search(){
	string code;
	cout<<"请输入公司代号"<<endl;
	cin>>code;
	CList *tmp=company_list;
	while(tmp){
		if(tmp->company.getCode()==code){
			tmp->company.show();
			system("pause");
			User_Check_Menu();
		}
		tmp=tmp->next;
	}
	
}

// 一键查看信息
void Company::show()
{
	cout <<"公司代号: " <<code << " 公司名称: " << name << endl;
	cout << "股价：" << price << endl;
	cout << "PE：" << pe << endl;
	cout << "市值：" << ev << endl;
	cout << "流通股数：" << shares_out << endl;
	cout << "利润：" << earning << endl;
	cout << endl;
}
void Check_Companys(){
	CList *tmp=company_list;
	if(tmp==NULL){
	cout<<"暂无上市公司！"<<endl;
	system("pause"); 
	User_Check_Menu();
	}
	else{
		while(tmp){
			tmp->company.show();
			tmp=tmp->next;
		}
	}
}

// 搜索功能
// show第一个搜索到的公司
bool searchC_Code(CList* clist, string c_)
{
    CList *p=clist;
    while (p){
        if (p->company.getCode() == c_){
            p->company.show();
            return true;
        }
        p = p->next;
    }
    return false;
}

bool searchC_Name(CList* clist, string n_)
{
    CList *p ;
    while (p){
        if (p->company.getName() == n_){
            p->company.show();
            return true;
        }
        p = p->next;
    }
    return false;
}

// show全部符合条件的公司，用户不能直接调用以下几个search函数
bool searchC_EV(CList* clist, double ev_)
{
    CList *p=clist ;
    while (p){
        if (p->company.getEV() == ev_){
            p->company.show();
        }
        p = p->next;
    }
    return true;
}

bool searchC_Price(CList* clist, double p_)
{
    CList *p=clist ;
    while (p){
        if (p->company.getPrice() == p_){
            p->company.show();
        }
        p = p->next;
    }
    return true;
}

bool searchC_Earning(CList* clist, double ea_)
{
    CList *p=clist;
    while (p){
        if (p->company.getEarning() == ea_){
            p->company.show();
        }
        p = p->next;
    }
    return true;
}

bool searchC_PE(CList* clist, double pe_)
{
    CList *p=clist;
    while (p){
        if (p->company.getPE() == pe_){
            p->company.show();
        }
        p = p->next;
    }
    return true;
}

// 排序展示功能
void ListByCode(CList* clist)
{
    int n = getLengthC(clist);
    string codelist[n];
    CList *p=clist;
    for (int i = 0; i < n; i++){
        codelist[i] = p->company.getCode();
        p = p->next;
    }
    sort(codelist, codelist+n);
    for (int i = 0; i < n; i++){
        searchC_Code(clist, codelist[i]);
        
    }
}

void ListByEV(CList* clist)
{
    int n = getLengthC(clist);
    double evlist[n];
    CList *p=clist;
    for (int i = 0; i < n; i++){
        evlist[i] = p->company.getEV();
        p = p->next;
    }
    sort(evlist, evlist+n);

    // 删除重复元素，因为该search会show所有符合条件的公司
    double newlist[n];
    int i=0, j=0;
    for (i; i < n; i++){
        if (evlist[i] == newlist[j]) continue;
        newlist[j] = evlist[i];
        j++;
    }

    // 遍历查询
    for (int i = 0; i < n; i++){
        searchC_EV(clist, newlist[i]);
    }
}

void ListByPrice(CList* clist)
{
    int n = getLengthC(clist);
    double pricelist[n];
    CList *p=clist;
    for (int i = 0; i < n; i++){
        pricelist[i] = p->company.getEV();
        p = p->next;
    }
    sort(pricelist, pricelist+n);

    // 删除重复元素，因为该search会show所有符合条件的公司
    double newlist[n];
    int i=0, j=0;
    for (i; i < n; i++){
        if (pricelist[i] == newlist[j]) continue;
        newlist[j] = pricelist[i];
        j++;
    }

    // 遍历查询
    for (int i = 0; i < n; i++){
        searchC_Price(clist, newlist[i]);
    }
}

void ListByEarning(CList* clist)
{
    int n = getLengthC(clist);
    double earnlist[n];
    CList *p=clist;
    for (int i = 0; i < n; i++){
        earnlist[i] = p->company.getEV();
        p = p->next;
    }
    sort(earnlist, earnlist+n);

    // 删除重复元素，因为该search会show所有符合条件的公司
    double newlist[n];
    int i=0, j=0;
    for (i; i < n; i++){
        if (earnlist[i] == newlist[j]) continue;
        newlist[j] = earnlist[i];
        j++;
    }

    // 遍历查询
    for (int i = 0; i < n; i++){
        searchC_Earning(clist, newlist[i]);
    }
}

void ListByPE(CList* clist)
{
    int n = getLengthC(clist);
    double pelist[n];
    CList *p=clist ;
    for (int i = 0; i < n; i++){
        pelist[i] = p->company.getEV();
        p = p->next;
    }
    sort(pelist, pelist+n);

    // 删除重复元素，因为该search会show所有符合条件的公司
    double newlist[n];
    int i=0, j=0;
    for (i; i < n; i++){
        if (pelist[i] == newlist[j]) continue;
        newlist[j] = pelist[i];
        j++;
    }

    // 遍历查询
    for (int i = 0; i < n; i++){
        searchC_PE(clist, newlist[i]);
    }
}

// 只实现了栈的插入功能
bool pushU(UList* &ulist, User u_)
{
    UList* n;
    n->user = u_;
    ulist->next=n->next;
    ulist->next = n;
    return true;
}

bool popU(UList* &ulist, string email_)
{
    UList *p=ulist;
    while (p){
        if (p->user.getEmail() == email_){
            p->next = p->next->next;
            return true;
        }
        p = p->next;
    }
    return false;
}

int getLengthU(UList* ulist)
{
    UList *p=ulist;
    int i = 0;
    while (p){
        ++i;
        p = p->next;
    }
    return i;
}
