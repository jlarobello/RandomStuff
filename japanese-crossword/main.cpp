#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <memory>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <limits.h>
#include <set>
#include <iomanip>

using namespace std;

int main(int argc, char **argv) {
    int n, x, sum = 0, temp;

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> temp;

        if (i != n-1)
            sum += temp + 1;
        else
            sum += temp;
    }
    
    if (sum == x)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
        
    return 0;
}
