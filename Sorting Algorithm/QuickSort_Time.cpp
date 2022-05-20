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

int Partition(int arr[], int left, int right)
{
    int i=left, j=right, pivot, pos=(left+right)>>1;
    pivot=arr[pos];

    while (i<j) {
        do
        {
            i++;
        }
        while (arr[i]<=pivot);
        do
        {
            j--;
        }
        while (arr[j]>pivot);

        if (i<j) swap(arr[i], arr[j]);
    }
    swap(arr[pos], arr[j]);
    return j;
}

void quicksort(int arr[], int left, int right)
{
    if (left>=right) return;
    int p=Partition(arr, left, right);

    quicksort(arr, left, p);
    quicksort(arr, p+1, right);
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
        quicksort(arr, -1, sz);
    }
    auto endd=high_resolution_clock::now();

    double time_taken=duration_cast<nanoseconds>(endd - strt).count();
    time_taken*=1e-9;
    cout << fixed << time_taken << setprecision(5) << " sec " << endl;
    return 0;
}
/**
9
16 15 8 12 10 6 3 9 5

10
10 9 8 7 6 5 4 3 2 1

*/
