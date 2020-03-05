#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, modus = -999999, curr_max_count = -1, sum = 0;
    double mean, median;
    cin >> n;
    if(n <= 0) {
        cout << "-\n" << "-\n" << "-\n" << "-\n" << "0\n";
        return 0;
    }
    vector < int > vec(n);
    map < int , int > count;
    for(int& i: vec) {
        cin >> i;
        sum += i;
        count[i]++;
        if(count[i] > curr_max_count) {
            modus = i;
            curr_max_count = count[i];
        }
        else if(count[i] == curr_max_count) {
            if(i < modus) {
                modus = i;
            }
        }
    }
    vector < int > temp = vec;


    mean = (double) sum / vec.size();
    sort(temp.begin(),temp.end());
    if(temp.size() & 1) {
        median = temp[temp.size()/2];
    }
    else {
        median = (temp[temp.size()/2] + temp[temp.size()/2 - 1]) / 2.00000;
    }
    
    cout << mean << endl;
    cout << median << endl;
    cout << modus << endl;
    for(int i = 0; i < curr_max_count; i++) {
        vec.push_back(modus);
    }
    for(int i = 0; i < vec.size() - 1; i++) {
        cout << vec[i] << " ";
    }
    cout << vec[vec.size()-1] << endl;
    cout << vec.size() << endl;

    return 0;
}