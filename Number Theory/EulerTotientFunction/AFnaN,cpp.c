#include<iostream>
using namespace std;

void solve(){

    string s;
    cin>>s;

    int len = s.size();
    reverse(s.begin(),s.end());
    char ch;
    int cnt = len;
    for(int i=0; i<len; i++)
    {
       for(int j=i; j<len; j++)
       {
           if(((s[i]-'0')*10 + s[j]-'0') % 25 ==0)
           {
               cnt = len - i - 2;
           }
       }

    }
    cout<<cnt<<endl;
    return;
}

int main()
{
    int t;

    cin>>t;
    while(t--)
    {
        solve();
    }
}
