//https://www.codechef.com/viewsolution/16560913  (https://www.codechef.com/problems/VILTRIBE)
#include <iostream>
#include<string>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>s;
		int a=0,b=0,last=0,check=0,rep=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='A')
			{
				a++;
				if(last==1 && check==1)
					a+=rep;
				last = 1;
				check=0;
			}
			else if(s[i]=='B')
			{
				b++;
				if(last==2 && check==1)
					b+=rep;
				last = 2;
				check=0;
			}
			else
				if(check==0)
				{
					check = 1;
					rep=1;
				}
				else
					rep++;
		}
		cout<<a<<" "<<b<<endl;
	}
	return 0;
} 