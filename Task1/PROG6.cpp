#include<iostream>
#include<conio.h>
#include<iomanip>
#include<math.h>
using namespace std;
 
int main()
{
    int n,m,sum=0,sum2=0;
    cout<<"Enter two numbers to check whether they are amicable or not: ";
    cin>>n>>m;
    for (int i=1; i<=n/2; i++)
    {
        if (n%i == 0)
            sum += i;
    }
    for (int i=1; i<=m/2; i++)
    {
        if (m%i == 0)
            sum2 += i;
    }
	if(m==sum && n==sum2)
		cout<<"They are amicable numbers"<<endl;
	else
		cout<<"They are not amicable numbers"<<endl;
	return 0;
}
