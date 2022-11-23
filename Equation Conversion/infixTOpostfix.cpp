#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

// int row4[]={0, 1, 0, -1};
// int col4[]={1, 0, -1, 0};
 
//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};
 
//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board

//UVA 727

bool precedence(char topper, char nw)
{
    if ((topper == '+' || topper == '-') && (nw == '+' || nw == '-')) return true;
    if (topper == '*' || topper == '/') return true;
    return false;
}

void solve(vector <char> vch)
{
    string postfix = "";
    stack <char> stk;
    stk.push('(');

    for (auto xx: vch) {
        if (xx >= '0' && xx <= '9') postfix += xx;
        else if (xx == '(') stk.push(xx);
        else if (xx == ')') {
            while (stk.top() != '(') {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else {
            while (precedence(stk.top(), xx)) {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(xx);
        }
    }
    while (stk.top() != '(') {
        postfix += stk.top();
        stk.pop();
    }
    cout << postfix << endl;
}


int main()
{
    RUN_FAST; cin.tie(nullptr);
    int T;
    string s;

    cin >> T;
    cin.ignore();
	cin.ignore();

    bool flag = false;
    while (T) {
        if (flag) cout << endl;
        flag = true;
        vector <char> vch;
        while (1) {
            getline(cin, s);
            if (s.size() == 0) break;
            vch.push_back(s[0]);
        }
        solve(vch);
        T--;
    }
    cout << endl;
    return 0;
}