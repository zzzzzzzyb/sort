#include<iostream>
using namespace std;
void InsertionSort(int a[]){
    int v,j;
    for (int i=1;i<=6;i++){
        v=a[i];
        j=i-1;
        while (j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
    }
}
void ShellSort(int a[],int len){
    int gap;
    int i,j,v;
    for (gap=len>>1;gap>0;gap>>=1){//分组
        for (i=gap;i<len;i++){//gap间隔的插入排序
            v=a[i];
            j=i-gap;
            while(j>=0&&a[j]>v){
                a[j+gap]=a[j];
                j-=gap;
            }
            a[j+gap]=v;
        }//
    }
}
void Merge(int a[],int l,int r,int mid){
    int i,j,k;
    int aux[r-l+1];
    for (k=l;k<=r;k++)
        aux[k-l]=a[k];//a是临时数组
    i=l;j=mid+1;
    for (k=l;k<=r;k++){//k即为合并后位置
        if (i>mid){
            a[k]=aux[j-l];
            j++;
        }
        else if (j>r){
            a[k]=aux[i-l];
            i++;
        }
        else if (aux[i-l]>aux[j-l]){
            a[k]=aux[j-l];
            j++;
        }
        else if (aux[i-l]<aux[j-l]){
            a[k]=aux[i-l];
            i++;
        }
    }
}
void MergeSort(int A[],int l,int r){
    int mid=(l+r)/2;
    if (l<r){
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,r);
        Merge(A,l,r,mid);
    }
}
int Partition(int a[],int l,int r){
    int i=0,j=0,p;
    p=a[l];
    i=l+1;j=r;
    int temp;
    while (i<j){
        while (a[j]>p) j--;
        while (a[i]<p&&i<=r) i++;
        temp=a[i];a[i]=a[j];a[j]=temp;
    }
    temp=a[i];a[i]=a[j];a[j]=temp;
    swap(a[l],a[j]);
    return j;
}
void QuickSort(int a[],int l,int r){
    int s;
    if (l<r){
        int s=Partition(a,l,r);//基准归位
        QuickSort(a,l,s-1);
        QuickSort(a,s+1,r);
    }
}
void BuildHeap(int a[],int n){//自底向上算法
    int k,v;
    bool heap=false;
    for (int i=n/2-1;i>=0;i--){
        k=i;v=a[k];
        heap=false;
        while (!heap&&2*k+1<=n-1){
            int j=2*k+1;
            if (j<n-1){//2个子女
                //if (a[j]>=a[k]) swap(a[j],a[k]);if (a[j+1]>=a[k]) swap(a[j+1],a[k]);
                if (a[j]<a[j+1]) j=j+1;
            }
            if (v>=a[j]) heap=true;
            else {
                a[k]=a[j];
                k=j;
                a[k]=v;
            }
        }
    }
}
int main(){
    int a[15]={89,45,68,90,29,34,17,97,65,32,8,18,20,31,78};
    int b[6]={2,9,7,6,5,8};
    //InsertionSort(a);
    //ShellSort(a,7);
    //MergeSort(a,0,6);
    //QuickSort(a,0,14);
    BuildHeap(b,6);
    for (int i=0;i<=5;i++) 
        cout<<b[i]<<' ';
    system("pause");
    return 0;
}