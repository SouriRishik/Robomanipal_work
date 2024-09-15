#include<iostream>
#include<conio.h>
#include<iomanip>
#include<process.h>
using namespace std;
void bubble(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		if(a[j]>a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;		
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
int binarySearch(int a[], int beg, int end, int ele)
{
    while(beg<=end)
    {
        int mid=(beg+end)/2;
        if(a[mid]==ele)
        {
            return mid;
        }
        else if(a[mid]<ele)
        {
            return binarySearch(a,mid+1,end,ele);
        }
        else
        {
         	return binarySearch(a,beg,mid-1,ele);
        }
    }
    return -1;
}
int main()
{
	int n,i,temp,ele,location=0,index;
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
    cout << "\nEnter an element to Search ";
    cin >> ele;
    index = binarySearch(a, 0, n - 1, ele);
    if(index>=0)
	{
		location=index+1;
    	cout << "\nElement is present at the location: " <<location;
    }
    else
    {
      cout << "\nElement is not present in array";
    }
	return 0;
}
