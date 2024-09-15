#include<iostream>
#include<conio.h>
#include<iomanip>
#include<process.h>
using namespace std;
void bubble(int a[],int n)
{
	int i,temp;
	for(i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;		
			bubble(a,n);
		}
	}
}
void selection(int a[],int n)
{
	int i,j,temp,pos,small;
	for(i = 0; i < n-1; i++)
	{
		pos = i; small = a[i];
		for(j=i+1; j<n; j++) 
		{
			if(small > a[j])
			{
				pos = j;
				small = a[j];
			}	
		}
	a[pos] = a[i];
	a[i] = small;
	}
}
void printing(int a[], int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
int main()
{
	int n,i,temp;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
	cout<<"Enter the array elements: ";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter (1) for bubble sort or (2) for selection sort: ";
	cin>>temp;
	if(temp == 1){
		bubble(a,n);
	}
	else if(temp == 2){
		selection(a,n);
	}
	else{
		cout<<"Invalid input";
		exit(0);
	}
	cout<<"The Sorted array is: "<<endl;
	printing(a,n);
	return 0;
}
