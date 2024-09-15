#include <iostream>
using namespace std;
int fibonacci(int n)
{
    if (n <= 1){ 
        return n;
	}
	else{
		int num=fibonacci(n-1)+fibonacci(n-2);
		return num;
	}
}

int main() {
    for (int i = 0; i < 40; i++) 
	{
    	cout << fibonacci(i) << " ";
    }
    return 0;
}
