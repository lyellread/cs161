

#include <iostream>
#include <sys/time.h>
#include <cstdlib>


using namespace std;


int fib (int &a, int &b, int n, int r) {
	if (n == 0) return (a + b); r = (a+b), a=b, b=r;
	return fib(a,b,--n, r);
}

int main () {
	int iteration;
	cout << "ITERATIONS:";
	cin >> iteration;
	int result;
	
	int a = 0;
	int b = 1;
	
	typedef struct timeval time; 
	time stop, start;
	gettimeofday(&start,NULL);
	result=fib (a,b,iteration-1, 0);
	gettimeofday(&stop, NULL);
	if(stop.tv_sec > start.tv_sec)
		cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
	else
		cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;
	cout << "RESULT: " <<  result << endl;
}
