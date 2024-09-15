#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
#include<process.h>
using namespace std;
class multiply
{
	public:
		int i,j,k,m,n,p,q,a[100][100],b[100][100],c[100][100];
		void getdata();
		void calculate();
		void display();
};
void multiply::getdata()
{
	cout<<"Enter dimensions of first array A: ";
	cin>>m>>n;
	cout<<"\nEnter the array elements for A:";
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<"\nThe Array A is: "<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\nEnter dimensions of first array B: ";
	cin>>p>>q;
	cout<<"\nEnter the array elements for B:";
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			cin>>b[i][j];
		}
	}
	cout<<"\nThe Array B is: "<<endl;
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			cout<<b[i][j]<<"\t";
		}
		cout<<"\n";
	}
}
void multiply::calculate()
{
	if(n!=p)
	{
		cout<<"Martices cannot be multiplied"<<endl;
		exit(0);
	}
	else
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<q;j++)
			{
				c[i][j]=0;
				for(k=0;k<n;k++)
				{
					c[i][j]+=a[i][k]*b[k][j];		
				}			
			}	
		}	
	}
}
void multiply::display()
{
	cout<<"\nThe Multiplied array is: "<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			cout<<c[i][j]<<"\t";
		}
		cout<<"\n";
	}	
}
int main()
{
	multiply M;
	M.getdata();
	M.calculate();
	M.display();
	return 0;
}
