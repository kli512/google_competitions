#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    string b;
    
    string val;
    for(int i = 0; i < t; i++) {
        getline(cin, val);

        b = string(val.length(), '0');

        for(int pos = val.find('4'); pos != -1; pos = val.find('4')) {
            val[pos] = val[pos] - 1;
            b[pos] = '1';
        }

        cout << "Case #" << i + 1 << ": " << val << " " << b << endl;
    }
}