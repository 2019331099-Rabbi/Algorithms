#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PI acos(-1)
#define sz 10000
#define inf 1000000000
#define mod 1000000007
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;
using namespace std::chrono;

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

    auto time1=high_resolution_clock::now();

    for (i=0; i<1000; i++) {
        for (j=0; j<sz; j++) arr[j]=rand()%inf;
        mergesort(arr, 0, sz-1);
    }

    auto time2=high_resolution_clock::now();

    for (i=0; i<1000; i++) {
        for (j=0; j<sz; j++) arr[j]=rand()%inf;
        quicksort(arr, -1, sz);
    }

    auto time3=high_resolution_clock::now();

    double time_taken=duration_cast<nanoseconds>(time2 - time1).count();
    time_taken*=1e-9;
    cout << fixed;
    cout << "Merge sort time = " << time_taken << setprecision(5) << " sec " << endl;
    time_taken=duration_cast<nanoseconds>(time3 - time2).count();
    time_taken*=1e-9;
    cout << "Quick sort time = " << time_taken << setprecision(5) << " sec " << endl;


    return 0;
}