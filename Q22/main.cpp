#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    
    map < string, int > count;
    cin >> n;
    vector < string > q(n);
    for(string& i: q) {
        cin >> i;
        count[i]++;
    }
    cin >> m;
    vector < string > h(m);
    for(string& i: h) {
        cin >> i;
        count[i]--;
    }

    for(const string& i: q) {
        if(count[i] > 0) {
            cout << i << endl;
            count[i]--;
        }
    }

    return 0;
}