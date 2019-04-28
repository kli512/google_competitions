#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

int main() {
    int tests;
    cin >> tests;

    for (int _ = 0; _ < tests; _++) {
        int n, s;
        cin >> n;
        cin >> s;

        vector<int> trinkets;
        for (int n_i = 0; n_i < n; n_i++) {
            int tmp;
            cin >> tmp;

            trinkets.push_back(tmp);
        }

        int best = 1;
        pair<int, int> best_is = {0, 0};

        for (int l = 0; l < n; l++) {
            unordered_map<int, int> occurances;
            unordered_set<int> bad_trinkets;

            occurances.clear();
            bad_trinkets.clear();

            for (int r = l; r < n; r++) {
                int& tnew = trinkets[r];

                if (occurances.find(tnew) != occurances.end())
                    occurances[tnew]++;
                else
                    occurances[tnew] = 1;

                if (occurances[tnew] > s) bad_trinkets.insert(tnew);

                int good = 0;
                for (auto it = occurances.begin(); it != occurances.end();
                     it++) {
                    if (bad_trinkets.find(it->first) == bad_trinkets.end())
                        good += it->second;
                }

                if(good > best)
                    best = good;
            }
        }

        cout << "Case #" << _ + 1 << ": " << best << endl;
    }
}