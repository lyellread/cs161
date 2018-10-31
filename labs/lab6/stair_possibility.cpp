

#include <iostream>
#include <sys/time.h>
#include <cstdlib>


using namespace std;


int fib (int &a, int &b, int n, int r) {
	if (n == 0) return (a + b);	
	r = (a+b), a=b, b=r;
	return fib(a,b,--n, r);
}

int main () {

	cout << "How many stairs:" << endl;
	int count;
	cin >> count;

	int a=0;
	int b=1;

	int result;
	result = fib(a, b, count-1, 0);
	
	cout << result << endl;	

}
