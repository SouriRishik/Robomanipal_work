#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main()
{
    char str1[100], str2[100];
    char *str1Ptr, *str2Ptr;
    cout<<"Enter the string: ";
    cin>>str1;
    str1Ptr = &str1[0];
    str2Ptr = &str2[0];
    
    //Manipulation on the pointer impacts the original string as the pointer variable is storing the address
    while(*str1Ptr)
    {
        *str2Ptr = *str1Ptr;
        str1Ptr++;
        str2Ptr++;
    }
    *str2Ptr = '\0';
    cout<<"\nCopied String: "<<str2;
    return 0;
}
