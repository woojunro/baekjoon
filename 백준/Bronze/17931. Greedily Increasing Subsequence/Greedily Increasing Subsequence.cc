#include <iostream>
#include <vector>

using namespace std;

vector<int> seq, gis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        seq.push_back(num);
    }
    
    gis.push_back(seq[0]);
    for (int i = 1; i < N; i++) {
        if (seq[i] > gis[gis.size() - 1]) gis.push_back(seq[i]);
    }
    
    cout << gis.size() << "\n";
    for (int i = 0; i < gis.size(); i++) {
        cout << gis[i] << " ";
    }
    cout << "\n";
    
    return 0;
}