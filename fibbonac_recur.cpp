#include <iostream>
using namespace std;

int fibo(int n)
{
	if(n == 0 || n == 1) return n;
	return fibo(n-1)+fibo(n-2);
}

int fibo_iter(int n)
{
	if(n == 0 || n == 1) return n;

	int f0 = 0, f1 = 1, f2;
	for(int i = 2; i <= n; i++) {
		f2 = f0 + f1;
		f0 = f1;
		f1 = f2;
	}
	return f2;
}

int fibo_dynamic(int n)
{
        static int saved[100] = {0};

	if(saved[n] != 0) return saved[n];

	if(n == 0 || n == 1) {
		saved[n] = n;
		return saved[n];
	}

	saved[n] = fibo_dynamic(n-1)+fibo_dynamic(n-2);

	return saved[n];
}

int main()
{
	int i;
	int n = 15;
	cout << "recursive Fibonacci " << endl;
	for(i = 0; i < n; i++) 
		cout <<  fibo(i) << " ";
	cout << endl;

	cout << "iterative Fibonacci " << endl;
	for(i = 0; i < n; i++) 
		cout <<  fibo_iter(i) << " ";
	cout << endl;

	cout << "dynamic Fibonacci " << endl;
	for(i = 0; i < n; i++) 
		cout <<  fibo_dynamic(i) << " ";
	cout << endl;

	return 0;
}
 