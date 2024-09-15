#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
bool checkHillNumber(int n)
{
	int a[100],p=0,i;
	//seperating each digit and storing in an array
	while(n!=0)
	{
		a[p++]=n%10;
		n=n/10;
	}
	//checking for the first condition
	for(i=p-1;i>=0;i--)
	{
		if(a[i]>a[i-1])
			break;
	}
	
	//for end cases
	if(i==p || i==0)
		return false;
		
	//checking for the second condition	
	for(;i>0;i--)
	{
		if(a[i-1]>a[i])
			break;
	}
	
	return i==0;
}
int main()
{
	int n;
	cout<<"Enter a number to check whether it is a hill number or not: ";
	cin>>n;
	bool isHill=checkHillNumber(n);
	if(isHill)
	{
		cout<<"It is a hill number";
	}
	else
		cout<<"It is not a hill number";
	return 0;
}

