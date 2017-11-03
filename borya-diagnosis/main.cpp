#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;
using std::stringstream;

int getMinDays(vector<int*>);

int main(int argc, char **argv) {
    int n, o;
    vector<int*> arr;
    string input;

    getline(cin, input);
    n = atoi(input.c_str());

    for (int i = 0; i < n; i++) {

        int* temp = new int[3];
        getline(cin, input);
        stringstream stream(input);

        for (int j = 0; stream; j++) {
            stream >> o;
            temp[j] = o;
        }

        temp[2] = temp[0];
        arr.push_back(temp);
    }

    cout << getMinDays(arr) << endl;

    return 0;
}

int getMinDays(vector<int*> arr) {
    int result;

    for (int i = 1; i < arr.size(); i++) {
        for (int j = 1; arr[i][2] <= arr[i-1][2]; j++) {
            arr[i][2] = arr[i][0] + j*arr[i][1];
        }
    }

    result = arr[arr.size()-1][2];

    return result;
}
