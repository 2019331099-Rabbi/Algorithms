#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <sstream>
#define endl '\n'
#define ll long long
#define pb push_back
#define PI acos(-1)
#define RUN_FAST ios::sync_with_stdio(false);
#define sz 500010
using namespace std;
/** 100! % 97
(a*b)%97 = ((a%97)*(b%97))%97
Here are taking 1 number from 1 to 100 and another number.
First another number is 1.
we calculate temp=((1%97)*(1%97))%97;
temp is a new value. we take temp and a number from 1 to 100.
SO the time complexity is O(n);
*/
void fct(int n, int d)
{
    int fact=1, i;
    for (i=1; i<=n; i++) {
        fact=((fact%d)*(i%d))%d;
        printf("%d %d\n", fact, i);

    }
    cout << fact << endl;
}

int main()
{
    RUN_FAST;
    int n, d;
    cin >> n;
    cin >> d;
    fct(n, d);
}
