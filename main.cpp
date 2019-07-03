#include<iostream>
#include<conio.h>
using namespace std;
void mergesort(int a[],int i, int j);
void merge(int a[],int p , int q, int r1);
int main()
{
    int a[20],i,n,item;
    cout<<"\n enter number of elements in array";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"enter number::"<<i+1<<" ";
        cin>>a[i];
    }
    cout<<"iteams in the array are"<<endl;
    for(i=0;i<n;i++)
    {

        cout<<a[i]<<"\t";
    }
    cout<<"applying merge sort"<<endl;
    mergesort(a,0,n-1);

    cout<<"sorting after merge sort"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    getch();
    return 0;
}
void mergesort(int a[],int i, int j)
{    int mid;
    if(i>=j)
        return;
    else
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);
        mergesort(a,mid+1,j);
        merge(a,i,mid,j);
    }

}

void merge(int a[],int p , int q, int r)
{
    // cout<<"\n values of p is "<<p <<" and q(mid) is "<<q<<" and r is"<<r<<endl;
    int n1=q-p+1;
    int n2=r-q;
    int *left=new int[n1+1];
    int *right=new int[n2+1];

    for(int i=0;i<n1;i++)
        left[i]=a[p+i];


    for(int i=0;i<n2;i++)
        right[i]=a[q+i+1];

    left[n1]=99999;
    right[n2]=99999;


    int i=0;
    int j=0;

    for(int k=p;k<=r;k++)
    {
        if(left[i]<right[j])
        {
            a[k]=left[i];
            i++;

        }
        else
        {
            a[k]=right[j];
            j++;

        }
    }
}
