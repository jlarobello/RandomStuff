#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

/* prototypes */
void prefixsum(int*, int);
void printarr(int*, int);

int main(int argc, char **argv) {
    int capacity = 99999999;
    int* arr = new int[capacity];

    for (int i = 0; i < capacity; i++)
        arr[i] = 1;
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for (int i = 1; i < capacity; i++)
	arr[i] = arr[i] + arr[i-1];
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout << "Time sequential: " << duration <<"ms" << endl;

    for (int i = 0; i < capacity; i++)
	arr[i] = 1;
    
    t1 = high_resolution_clock::now();
    prefixsum(arr, capacity);
    t2 = high_resolution_clock::now();

    duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout << "Time parallel: " << duration <<"ms" << endl;

    return 0;
}

void prefixsum(int* A, int n) {
    if (n <= 1) {
        return;
    } else {
	int* B = new int[n];

        #pragma omp parallel for
        for (int i = 0; i < n/2; i++) {
	    B[i] = A[2*i] + A[2*i + 1];
	}

	prefixsum(B, n/2);
        
        #pragma omp parallel for
	for (int i = 0; i < n; i++) {
	    if (i == 0)
		A[0] = A[0];
	    else if (i % 2 == 0)
	        A[i] = B[i/2 - 1] + A[i];
	    else
		A[i] = B[(i-1) / 2];
	}
    }
}

void printarr(int* A, int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

