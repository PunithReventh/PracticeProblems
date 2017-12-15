//https://www.codechef.com/problems/CPLAY

#include <iostream>
#include<cstdio>
#include<string>
using namespace std;

int main() {
	string s;
	while(cin>>s)
	{
		int a=0,b=0,A=0,B=0,c=0,i,arem=5,brem=5,ln=0;
		for(i=0;i<10;i++)
		{
			if(i%2==0 )
			{
			    if(s[i]=='1')
			        a++;
			    arem--;
			}    
			else     
			{
			    if(s[i]=='1')
			        b++;
			    brem--;
			}    
			if(a+arem<b)
		    {
		        ln = i+1;
		        break;
		    }
		    if(b+brem<a)
		    {
		        ln = i+1;
		        break;
		    }
		}	     
		if(a>b)
		   A=1;
		else if(b>a)
		   B=1;
		else
		{
			ln=10;
			while(c<5)
			{
				if(s[i]=='1' && s[i+1]=='0')
				{
					A=1;
					ln = ln+2;
					break;
				}	
				else if(s[i]=='0' && s[i+1]=='1')
				{
					B=1;
					ln+=2;
					break;
				}	
				else
				{
					ln+=2;
					i+=2;
					c++;
				}
			}
		}
		if(c==5 && A==0 && B==0)
			printf("TIE\n");
		else if(A==1 && B==0)
			printf("TEAM-A %d\n",ln);
		else if(B==1 && A==0)
			printf("TEAM-B %d\n",ln);
	}
	return 0;
}