/*
给定你一个长度为 n
 的整数数列。

请你使用归并排序对这个数列按照从小到大进行排序。

并将排好序的数列按顺序输出。

输入格式
输入共两行，第一行包含整数 n
。

第二行包含 n
 个整数（所有整数均在 1∼109
 范围内），表示整个数列。

输出格式
输出共一行，包含 n
 个整数，表示排好序的数列。

数据范围
1≤n≤100000
输入样例：
5
3 1 2 4 5
输出样例：
1 2 3 4 5
*/

#include<iostream>
using namespace std;

const int N = 1e5+10;
int q[N],tmp[N],n;

void merge_sort(int q[],int l,int r){
    if(l>=r) return;

    int mid = l+r>>1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);

    int k=0,i=l,j=mid+1;
    while(i<=mid && j<=r){
        if(q[i]<=q[j]) tmp[k++]=q[i++];
        else tmp[k++]=q[j++];
    }
    while(i<=mid) tmp[k++]=q[i++];
    while(j<=r) tmp[k++]=q[j++];

    for(int i=l,j=0;i<=r;i++,j++){
        q[i]=tmp[j];
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>q[i];
    }
    int l=0,r=n-1;
    merge_sort(q,l,r);
    for(int i=0;i<n;i++){
        cout<<q[i]<<" ";
    }
    cout<<"\n";

    return 0;
}