#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    int size;
    string l_path;

    for (int i = 0; i < t; i++) {
        cin >> size;
        cin.ignore();

        getline(cin, l_path);

        cout << "Case #" << i + 1 << ": ";

        for (char m : l_path) {
            switch (m) {
                case 'S':
                    cout << "E";
                    break;
                case 'E':
                    cout << "S";
            }
        }

        cout << endl;
    }
}