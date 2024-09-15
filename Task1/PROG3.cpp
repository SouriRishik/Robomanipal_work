#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
#include<process.h>
using namespace std;
class matrix
{
	public:
		int i,j,m,n,a[100][100],c,r;
		void getdata();
		void calculate();
		void display();
};
void matrix::getdata()
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
}
void matrix::calculate()
{
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==0)
			{
				for(c=0;c<m;c++)
				{
					if(a[c][j] == 0 && c!=i){
						a[c][j] = 0;
					}
					else{
						a[c][j]=-1;
					}
				}
				for(r=0;r<n;r++)
				{
					if(a[i][r] == 0 && r!=j){
						a[i][r]=0;
					}
					else{
						a[i][r]=-1;
					}
				}		
			}
		}
	}
}
void matrix::display()
{
	cout<<"\nThe changed array is: "<<endl;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==-1)
			{
				a[i][j]=0;
			}
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}	
}
int main()
{
	system("cls");
	matrix M;
	M.getdata();
	M.calculate();
	M.display();
	return 0;
}
