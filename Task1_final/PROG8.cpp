#include<iostream>
#include<conio.h>
#include<iomanip>
#include<process.h>
using namespace std;
void getmatrix(int a[100][100],int m ,int n)
{
    int i,j;
    cout<<"Enter the elements of the matrix:";
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
}

void multiply(int a[][100],int b[][100], int c[][100], int m,int n,int p,int q)
{
	int i,j,k;
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
void transpose(int a[100][100],int p,int q,int tr[100][100])
{
    int i,j;
    for(i=0;i<q;i++)
        {for(j=0;j<p;j++)
           {
              tr[i][j]=a[j][i];
           }
        }
}
int main()
{
    int a[100][100],r1,c1,b[100][100],r2,c2,c[100][100],trA[100][100],trB[100][100],trAB[100][100],trResult[100][100],i,j;

    cout<<"Enter the dimensions of A martix:";
    cin>>r1>>c1;


    cout<<"Enter the dimensions of B matrix:";
    cin>>r2>>c2;


    if(c1!=r2)
       {
          cout<<"Not compatible";
          exit(0);
       }
    else
    {
         getmatrix(a,r1,c1);
         cout<<"\nThe Array A is: "<<endl;
		for(i=0;i<r1;i++)
		{
			for(j=0;j<c1;j++)
			{
				cout<<a[i][j]<<"\t";
			}
			cout<<"\n";
		}
         getmatrix(b,r2,c2);
         cout<<"\nThe Array B is: "<<endl;
		for(i=0;i<r2;i++)
		{
			for(j=0;j<c2;j++)
			{
				cout<<b[i][j]<<"\t";
			}
			cout<<"\n";
		}
         multiply(a,b,c,r1,c1,r2,c2);

         cout<<"Multiplied matrix AB:"<<endl;
         for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                cout<<c[i][j]<<"\t";
            }
            cout<<"\n";

        }
        transpose(c,r1,c2,trAB);
        cout<<"Transpose of matrix AB= (A.B)':"<<endl;
        for(i=0;i<c2;i++)
        {
            for(j=0;j<r1;j++)
            {
                cout<<trAB[i][j]<<"\t";
            }
            cout<<"\n";
        }

        transpose(b,r2,c2,trB);
        cout<<"Transpose of matrix B= B':"<<endl;
        for(i=0;i<c2;i++)
        {
            for(j=0;j<r2;j++)
            {
                cout<<trB[i][j]<<"\t";
            }
            cout<<"\n";
        }
        transpose(a,r1,c1,trA);
        cout<<"Transpose of matrix A= A':"<<endl;
        for(i=0;i<c1;i++)
        {
            for(j=0;j<r1;j++)
            {
                cout<<trA[i][j]<<"\t";
            }
            cout<<"\n";
        }
        multiply(trB,trA,trResult,c2,r2,r1,c1);
            cout<<"Multiplication of transposed matrices B'. A':"<<endl;
            for(i=0;i<c2;i++)
        {
            for(j=0;j<r1;j++)
            {
                cout<<trAB[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }
    return 0;
}
