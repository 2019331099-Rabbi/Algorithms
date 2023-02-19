#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,d;

    cin>>n>>d;
    string s;
    cin>>s;
    int cnt =0;
    int st = 1;
    for(int i=1; i<n; i++)
    {
        int a =d;
        while(a)
        {
            if(i+a>n)
            {
                a--;
                continue;
            }
            else if(s[i+a] == '0')
            {
                a--;
            }
            else{
                i = i+a;
            cout<<s[i]<<"--> "<<i<<endl;
                cnt++;
                break;
            }

        }
        if(a==0)
        {
            cout<<-1<<endl;
            return 0;
        }
    }

    cout<<cnt<<endl;



    return 0;
}
