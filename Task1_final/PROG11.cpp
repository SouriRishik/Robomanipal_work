#include <iostream>
using namespace std;
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
	int n,ele,location=0,index;
	cout<<"Enter the size of the array: ";
	cin>>n;
	int a[n];
    cout << "Enter the array Elements: ";
    for(int i=0; i<n; i++)
        cin>>a[i];
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
