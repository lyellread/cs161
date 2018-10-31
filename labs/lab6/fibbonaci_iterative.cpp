

#include <iostream>
#include <sys/time.h>
#include <cstdlib>


using namespace std;


int fib (int a, int b, int n, int temp) {
	while (n>-1) temp = a + b, a = b, b = temp, n= n-1;
	return b;
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
