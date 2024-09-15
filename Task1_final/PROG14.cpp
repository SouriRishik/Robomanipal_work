#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
int gcd(int n1,int n2)
{
	if(n1==0)
	{
		return n2;
	}
	return gcd(n2%n1,n1);
}
int main()
{
	int n1,n2;
	cout<<"Enter two numbers to find the GCD among them: ";
	cin>>n1>>n2;
	cout<<"The GCD of the two numbers is: "<<gcd(n1,n2);
	return 0;
}
