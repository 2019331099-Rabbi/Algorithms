#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 10000
#define inf 1e9
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;
using namespace std::chrono;

//int row4[]={0, 0, -1, 1};
//int col4[]={1, -1, 0, 0};

//int row8[]={0, 0, -1, 1, 1, -1, -1, 1};///8 adjacent
//int col8[]={1, -1, 0, 0, 1, 1, -1, -1};

//int rowkt[]={-2, -2, 2, 2, -1, -1, 1, 1};///Knight moves on
//int colkt[]={1, -1, 1, -1, 2, -2, 2, -2};///chess board


void merge(int arr[], int left, int right, int mid)
{
    int i, j;
    int ls=mid-left+1, rs=right-mid;
    int larr[ls], rarr[rs];

    for (i=0; i<ls; i++) larr[i]=arr[left+i];
    for (i=0; i<rs; i++) rarr[i]=arr[mid+1+i];

    i=j=0;
    while (i<ls && j<rs) {
        if (larr[i]<=rarr[j]) arr[left++]=larr[i++];
        else arr[left++]=rarr[j++];
    }
    while (i<ls) arr[left++]=larr[i++];
    while (j<rs) arr[left++]=rarr[j++];
}

void mergesort(int arr[], int left, int right)
{
    if (left>=right) return;
    int mid=((left+right)>>1);
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);

    merge(arr, left, right, mid);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    srand(time(0));
    int i, j;
    int arr[sz];

    auto strt=high_resolution_clock::now();
    for (i=0; i<1000; i++) {
        for (j=0; j<sz; j++) arr[j]=rand()%sz;
        mergesort(arr, 0, sz-1);
    }
    auto endd=high_resolution_clock::now();

    double time_taken=duration_cast<nanoseconds>(endd - strt).count();
    time_taken*=1e-9;
    cout << fixed << time_taken << setprecision(5) << " sec " << endl;
    return 0;
}
