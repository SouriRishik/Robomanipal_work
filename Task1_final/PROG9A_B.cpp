#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string.h>
using namespace std;

void rearrangeletter(char str[])
{
	int x,i,j;
	x=strlen(str);
	
	char temp;
	for(i=0;i<x;i++)
	{
		for(j=i+1;j<x;j++){
			if(str[i]>str[j])
			{
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	}
	
	cout<<str<<endl;
}


int main()
{
	int n,i,j;
	cout<<"Enter the number of words: ";
	cin>>n;
	std::string str[n],temp;
	cout<<"Enter the words:";
	for(i=0;i<n;i++)
	{
		cin>>str[i];
	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(str[i].length() > str[j].length()){
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	}
	cout<<"The Sorted order of names: "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<str[i]<<"\n";
	}
	
	cout<<"The string alphabetically is: "<<endl;
	for(i=0;i<n;i++)
	{ 
		//converting string to character array using inbuilt function c_str()
	    char* charWord = new char[n + 1];
		strcpy(charWord, str[i].c_str()); 
		rearrangeletter(charWord);
	}
		
	return 0;	
}
