#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;
int factorial(int n) {
    if (n>=1)
        return n*factorial(n-1);
    else if(n==0)
        return 1;
    else
        cout<<"doesn't exist";
        exit(0);
}
int main() {
    int n;
    cout<<"Enter a positive integer: ";
    cin>>n;
    cout<<"Factorial of "<<n<< " is "<<factorial(n);
    return 0;
}
