#include <iostream>
using namespace std;

#define d 256

void rabinKarp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    int q = 101;

    int p = 0, t = 0, h = 1;

    // h = d^(m-1)
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // initial hash
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {

        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << i << " ";
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    rabinKarp(text, pattern);
}
