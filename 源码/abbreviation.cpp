#include <iostream>
#include <vector>

using namespace std;

bool opt[1000][1000];

string abbreviation(string a, string b) {
    opt[0][0] = true;
    
    for(int i = 1; i <= a.size(); i++) {
        opt[i][0] = !isupper(a[i - 1]) && opt[i - 1][0];
    }

    for (int j = 0; j < b.size(); j++) {
        opt[0][j + 1] = false;
    }
    
    for(int j = 1; j <= b.size(); j++) {
        for(int i = 1; i <= a.size(); i++) {
            if (isupper(a[i - 1])) {
                if (toupper(a[i - 1]) == b[j - 1]) {
                    opt[i][j] = opt[i - 1][j - 1];
                }
                else {
                    opt[i][j] = false;
                }
            }
            else {
                if (toupper(a[i - 1]) == b[j - 1]) {
                    opt[i][j] = opt[i - 1][j - 1] || opt[i - 1][j];
                }
                else {
                    opt[i][j] = opt[i - 1][j];
                }
            }
        }
    }
    
    return opt[a.size()][b.size()] ? "YES" : "NO";
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string a, b;
        cin >> a >> b;

        cout << abbreviation(a, b) << endl;
    }

    return 0;
}
