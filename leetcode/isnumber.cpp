#include<iostream>
#include<string>
using namespace std;

bool isnumber(string s)
{
    int len=s.length();
    int fulen=0;
    for (int i = 0; i < len; i++)
    {
        char temp;
        temp=s[i];
        if (temp<'0'||temp>'9')
        {
            fulen++;
        }
        else
        {
            break;
        }
    }
    for (int i = fulen; i < len; i++)
    {
        char temp;
        temp=s[i];
        if (temp<'0'||temp>'9')
        {
            s[i]=s[fulen];
            s[fulen]=temp;
            fulen++;        
        }
    }
    
    int counte;
    int countd;
    for (int i = 0; i < fulen; i++)
    {
        if (s[i]=='e'||s[i]=='E')
        {
            counte++;
        }
        
    }
    
    
    for (int i = 0; i < len; i++)
    {
        cout<<s[i];
    }
    return true;
}



int main()
{
    string s="+8241.3e123";
    isnumber(s);
}