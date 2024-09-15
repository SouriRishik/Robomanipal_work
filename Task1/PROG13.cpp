#include<iostream>
#include<conio.h>
#include<iomanip>
#include<process.h>
using namespace std;
int Sum(int n) 
{ 
    if (n == 0) 
    return 0; 
    return (n % 10 + Sum(n / 10)); 
}
int SUM(int n)
{
	int S=0;
	while(n!=0)
	{
		S=S+n%10;
		n=n/10;
	}
	return S;	
}
int main() 
{ 
    int num,temp;
	cout<<"Enter a number:";
	cin>>num;
	cout<<"Enter 1 to find sum of digits by recursion otherwise enter 2: ";
	cin>>temp;
	if(temp!=1&&temp!=2){
		cout<<"Input invalid";
		exit(0);
	}
	else
		if(temp==1)
		{
    		int s = Sum(num); 
    		cout << "Sum of digits in "<<num<<" is "<<s<< endl;
		}
	else
		if(temp==2)
		{
			int r= SUM(num);
    		cout << "Sum of digits in "<<num<<" is "<<r<< endl;	
		}	
    return 0; 
} 
