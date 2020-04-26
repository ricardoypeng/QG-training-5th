#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include "./head/tool.h"
using namespace std;
void error_()
{
	cout<<endl<<"错误输入，请检查后重新输入"<<endl;
	system("PAUSE");
	return;
}
int SHURU(int *n)
{
	string gg;
	bool zf=0;
	int x,b,z=0;
	cin>>gg;
	x=gg.length();
	if(gg[0]=='-')
	{
		if(x>11)
		{
			return 1;
		}
		for(int i=1;i<x;i++)
		{
			if(gg[i]<'0'||gg[i]>'9')
				return 1;
			z+=gg[i]-'0';
			if(i!=x-1)
				z*=10;
		}
		*n=-z;
		return 0;
	}
	else
	{
		if(x>10)
		{
			return 1;
		}
		for(int i=0;i<x;i++)
		{
			if(gg[i]<'0'||gg[i]>'9')
				return 1;
			z+=gg[i]-'0';
			if(i!=x-1)
				z*=10;
		}
		*n=z;
		return 0;
	}
}
char jiami(char c)
{
	if (c >= '0' && c <= '9')
	{
		return '9' - c + '0';
	}
	if (c >= 'a' && c <= 'z')
	{
		return 'a' - c + 'z';
	}
	if (c >= 'A' && c <= 'Z')
	{
		return 'A' - c + 'Z';
	}
	return c;
} 

