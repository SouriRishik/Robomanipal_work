#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string.h>
using namespace std;
class sorting
{
	public:
		int n,i,j;
		char str[];
		void getdata();
		void calculate();
		void display();	
};
void sorting::getdata()
{
	cout<<"Enter a string:";
	cin>>str;
}
void sorting::calculate()
{
	n=strlen(str);
	int temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(str[i]>str[j])
			{
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	}
}
void sorting::display()
{
	cout<<"The Sorted string is: "<<str<<endl;
}
int main()
{
	sorting s;
	s.getdata();
	s.calculate();
	s.display();
	return 0;
}
