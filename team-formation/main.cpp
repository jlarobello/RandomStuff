#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;
using std::stringstream;

int main(int argc, char **argv) {
    int n,k,m, temp, total = 0;
    string input;

    getline(cin, input);

    stringstream stream(input);

    stream >> n;
    stream >> k;
    stream >> m;

    vector<long long> arr;

    getline(cin, input);

    arr.reserve(n);
    stream.clear();
    stream.str(input);

    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        stream >> temp;
        arr[temp] += m;
    }

    for (int i = 0; i < n; i++) {
        if (i != 0) {
            total += arr[i] % k;
        }
    }

    cout << total << endl;

    return 0;
}
