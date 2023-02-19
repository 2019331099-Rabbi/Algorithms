#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int n;
bool flag=true;
string a,b;
cin>>n;
cin>>a;
cin>>b;
for(int i=0;i<n;i++){
if(a[i]=='1'&& b[i]=='1'){
   flag=false;
   break;
   }
}
    cout<<(flag? "YES": "NO")<<endl;
}
}
