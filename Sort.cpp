#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Sort{
    private:
        int partition(T x[],int l,int r);
        void MinHeapify(T a[],int size,int rt);
    public:
        void InsertSort(T x[],const int n);
        void BinInsertSort(T x[],const int n);
        void ShellSort(T x[],const int n);
        void BubbleSort(T x[],const int n);
        void SelectSort(T x[],const int n);
        void MergeSort(T x[],int l,int r);
        void QuickSort(T x[],int l,int r);
        void RadixSort(T x[],const int n);
        void HeapSort(T x[],const int n);
        T QuickSelect(T x[],int l,int r,int k);
};
template<typename T>
inline void Sort<T>::MinHeapify(T a[],int size,int rt){
    int l = rt << 1,r = rt << 1 | 1;
    int Min = rt;
    if(l < size && a[l] < a[Min]){
        Min = l;
    }
    if(r < size && a[r] < a[Min]){
        Min = r;
    }
    if(rt == Min) return;
    swap(a[rt],a[Min]);
    MinHeapify(a,size,Min);
}
template<typename T>
inline void Sort<T>::HeapSort(T a[],const int n){
    for(int i = n - 1 >> 1; i >= 0; i--){
        MinHeapify(a,n,i);
    }
    for(int i = n - 1; i >= 1; i--){
        swap(a[0],a[i]);
        MinHeapify(a,i,0);
    }
    for(int i = n - 1; i >= 0; i--){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
template<typename T>
inline T Sort<T>::QuickSelect(T a[],int l,int r,int k){
    if(l == r) return a[l];
    int pos = partition(a,l,r);
    int ct = pos - l + 1;
    if(ct == k) return a[pos];
    else if(k < ct) return QuickSelect(a,l,pos-1,k);
    else return QuickSelect(a,pos+1,r,k-ct);
}
template<typename T>
inline int Sort<T>::partition(T a[],int l,int r){
    srand(unsigned(time(NULL)));
    int pos = rand() % (r - l + 1) + l;
    swap(a[pos],a[r]);
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(a[j] <= a[r]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i + 1],a[r]);
    return i + 1;
}
template<typename T>
inline void Sort<T>::QuickSort(T x[],int l,int r){
    if(l >= r) return;
    int q = partition(x,l,r);
    QuickSort(x,l,q-1);
    QuickSort(x,q+1,r);
}
template<typename T>
inline void Sort<T>::RadixSort(T x[], const int n){// ºŸ…Ë «int ∑∂Œß,Œ»∂®≈≈–Ú
    const int Max = 0xffff;
    int sum[Max + 1];
    int id[n+1],rank[n+1];
    for(int i = 0; i <= Max; i++) sum[i] = 0;
    for(int i = 0; i < n; i++)
        sum[x[i] & Max]++;
    for(int i = 1; i <= Max; i++) sum[i] += sum[i-1];
    for(int i = n-1; i >= 0; i--) id[--sum[x[i] & Max]] = i;

    for(int i = 0; i <= Max; i++) sum[i] = 0;
    for(int i = 0; i < n; i++)
        sum[x[i] >> 16]++;
    for(int i = 1; i <= Max; i++) sum[i] += sum[i-1];
    for(int i = n-1; i >= 0; i--) rank[--sum[x[id[i]] >> 16]] = id[i];
    for(int i = 0; i < n; i++){
        cout<<x[rank[i]]<<" ";
    }
    cout<<endl;
 }
template <typename T>
inline void Sort<T>::InsertSort(T a[],const int n){//Œ»∂®≈≈–Ú
    for(int i = 1; i < n; i++){
        int tmp = a[i],j;
        for(j = i - 1; j >= 0 && a[j] > tmp; j--){
            a[j+1] = a[j];
        }
        a[j+1] = tmp;
    }
     for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
template <typename T>
inline void Sort<T>::BinInsertSort(T a[],const int n){//Œ»∂®≈≈–Ú
    for(int i = 1; i < n; i++){
        int l = 0,r = i - 1;
        int tmp = a[i];
        while(l <= r){
            int m = l + (r - l >> 1);
            if(tmp >= a[m]) l = m + 1;
            else r = m - 1;
        }
        int pos = l;
        for(int j = i - 1; j >= l; j--){
            a[j+1] = a[j];
        }
        a[l] = tmp;
    }
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
template<typename T>
inline void Sort<T>::MergeSort(T a[],int l,int r){
    if(l == r) return;
    T tmp[r - l + 1];
    int m = l + (r - l >> 1);
    MergeSort(a,l,m);
    MergeSort(a,m+1,r);
    int i = l,j = m + 1,cn = -1;
    while(i <= m && j <= r){
        if(a[i] <= a[j]){
            tmp[++cn] = a[i++];
        }else tmp[++cn] = a[j++];
    }
    while(i <= m) tmp[++cn] = a[i++];
    while(j <= r) tmp[++cn] = a[j++];
    for(int i = 0; i <= cn; i++){
        a[l+i] = tmp[i];
    }
}
template<typename T>
inline void Sort<T>::ShellSort(T a[],const int n){//≤ªŒ»∂®
    int d = n;
    while(true){
        d>>=1;
        for(int i = 1; i < n; i++){
            int tmp = a[i],j;
            for(j = i - d; j >= 0 && a[j] > tmp ; j -= d){
                a[j+d] = a[j];
            }
            a[j+d] = tmp;
        }
        if(d == 1) break;
    }
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    Sort<double>test;
    int n;
    while(cin>>n){
        double x[n+1];
        for(int i = 0; i < n; i++)
            cin>>x[i];
            test.HeapSort(x,n);
    }
    return 0;
}
