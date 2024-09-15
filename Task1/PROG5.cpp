#include<iostream>
#include<conio.h>
#include<iomanip>
#include<math.h>
using namespace std;
void binary(int n){
	int binaryno[100],i,j;
    while (n > 0) {
        binaryno[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (j = i - 1; j >= 0; j--)
        cout << binaryno[j];
}
void octal(int n){
	int octalno[100],i,j;
    while (n > 0) {
        octalno[i] = n % 8;
        n = n / 8;
        i++;
    }
    for (j = i - 1; j >= 0; j--)
        cout << octalno[j];
}
void hexadecimal(int n){
	char hex[100];
	int i,j,temp=0;
	while(n>0){
		temp=n%16;
		if(temp<10)
			hex[i++]=temp+48;
		else
			hex[i++]=temp+55;
		n=n/16;
	}
	for (j = i - 1; j >= 0; j--)
        cout << hex[j];
}
int main()
{
	int n;
	cout<<"Enter a number: ";
	cin>>n;
	cout<<"Binary conversion: ";binary(n);
	cout<<"\nOctal conversion: ";octal(n);
	cout<<"\nHexadecimal conversion: ";hexadecimal(n);
	return 0;
}
