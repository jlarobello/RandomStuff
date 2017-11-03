#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;
using std::stringstream;

int main(int argc, char **argv) {
    int n, t, temp, days = 1;
    string input;

    getline(cin, input);
    stringstream stream(input);

    stream >> n;
    stream >> t;

    stream.clear();
    getline(cin, input);
    stream.str(input);

    vector<int> arr;

    arr.reserve(n);

    for (int i = 0; i < n; i++) {
        stream >> temp;
        arr[i] = 86400 - temp;
    }

    for (int i = 0; i < n; i++) {
        t -= arr[i];
        if (t > 0)
            days++;
        else
            break;
    }

    cout << days << endl;
    
    return 0;
}
