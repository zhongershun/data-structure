#include "stock.h"
#include "company-function.cpp"
#include "menu.cpp"
#include "user-function.cpp"

UList *user_list = NULL;
CList *company_list = NULL;

int main()
{
	while(1){
		mainmenu();
	}
	return 0;
}
