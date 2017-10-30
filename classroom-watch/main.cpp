#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
    int n, k, sum, result, bit = 0, size = 0;

    cin >> n;

    result = n;

    priority_queue<int, vector<int>, greater<int>> pq;

    while(n > result - 100000) {
        k = n;
        sum = 0;

	while (k > 0) {
	    sum += k % 10;
	    k /= 10;
        }

        sum += n;
        
	if (sum == result) {
	    pq.push(n);
	    size++;
	}

	n--;
    }
    
    cout << size << endl;
    
    while(!pq.empty()) {
        cout << pq.top() << endl;
	pq.pop();
    }

    return 0;
}

