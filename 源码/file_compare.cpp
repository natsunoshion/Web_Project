#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool opt[10000][2];

string abbreviation(string a, string b) {
    opt[0][0] = true;
    
    for(int i = 1; i <= a.size(); i++) {
        opt[i][0] = !isupper(a[i - 1]) && opt[i - 1][0];
    }

    opt[0][1] = false;
    
    for(int j = 1; j <= b.size(); j++) {
        for(int i = 1; i <= a.size(); i++) {
            if (isupper(a[i - 1])) {
                if (toupper(a[i - 1]) == b[j - 1]) {
                    opt[i][1] = opt[i - 1][0];
                }
                else {
                    opt[i][1] = false;
                }
            }
            else {
                if (toupper(a[i - 1]) == b[j - 1]) {
                    opt[i][1] = opt[i - 1][0] || opt[i - 1][1];
                }
                else {
                    opt[i][1] = opt[i - 1][1];
                }
            }
        }
        for (int i = 0; i <= a.size(); i++) {
            opt[i][0] = opt[i][1];
        }
    }
    
    return opt[a.size()][0] ? "YES" : "NO";
}

int main() {
    string a, b;
    
    // 读出 "PollutedFile.txt" 然后去除掉特殊字符
    ifstream file1("PollutedFile.txt");
    if (file1.is_open()) {
        char c;
        while (file1.get(c)) {
            if (!isspace(c) && !ispunct(c) && !isdigit(c)) {
                a += c;
            }
        }
        file1.close();
    }
    else {
        cout << "Error opening PollutedFile.txt" << endl;
        return 1;
    }
    
    // 读出 "OriginalFile.txt" 然后去除掉特殊字符
    ifstream file2("OriginalFile.txt");
    if (file2.is_open()) {
        char c;
        while (file2.get(c)) {
            if (!isspace(c) && !ispunct(c) && !isdigit(c)) {
                b += toupper(c);
            }
        }
        file2.close();
    }
    else {
        cout << "Error opening OriginalFile.txt" << endl;
        return 1;
    }

    // cout << a << endl << endl;

    // cout << b << endl;
    
    // 调用函数进行匹配
    string result = abbreviation(a, b);
    cout << result << endl;
    
    return 0;
}
