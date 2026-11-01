#include<stdio.h>
void bubble(int a[],int n)
{
int i,j,t;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j]>a[j+1])
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
}
}
}
void selection(int arr[],int n)
{
int i,j,min,temp;
for(i=0;i<n-1;i++)
{
min=i;
for(j=i+1;j<n;j++)
{
if(arr[j]<arr[min])
min=j;
}
temp=arr[min];
arr[min]=arr[i];
arr[i]=temp; }
}
void insertion(int a[],int n)
{
int i,j,key;
for(i=1;i<n;i++)
{
key=a[i];
j=i-1;
while(j>=0 && a[j]>key)
{
a[j+1]=a[j];
j--;
}
a[j+1]=key;
}
}
void merge(int a[],int l,int m,int r)
{
int i,j,k;
int n1=m-l+1;
int n2=r-m;
int left[50],right[50];
for(i=0;i<n1;i++)
left[i]=a[l+i];
for(j=0;j<n2;j++)
right[j]=a[m+1+j];
i=0;j=0;k=l;
while(i<n1 && j<n2)
{
if(left[i]<=right[j])
{
a[k]=left[i];
i++;
}
else
{ a[k]=right[j];
j++;
}
k++;
}
while(i<n1)
{
a[k]=left[i];
i++;
k++;
}
while(j<n2)
{
a[k]=right[j];
j++;
k++;
}
}
void mergesort(int a[],int l,int r)
{
int mid;
if(l<r)
{
mid=(l+r)/2;
mergesort(a,l,mid);
mergesort(a,mid+1,r);
merge(a,l,mid,r);
}
}
int arrange(int a[],int s,int e)
{
int pivot=a[e];
int i=s-1;
int j,t;
for(j=s;j<e;j++)
{
if(a[j]<pivot) {
i++;
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
t=a[i+1];
a[i+1]=a[e];
a[e]=t;
return i+1;
}
void quicksort(int a[],int s,int e)
{
int p;
if(s<e)
{
p=arrange(a,s,e);
quicksort(a,s,p-1);
quicksort(a,p+1,e);
}
}
int main()
{
int a[50],n,i,ch;
printf("enter how many numbers: ");
scanf("%d",&n);
printf("enter the numbers: ");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("\n1.bubble sort\n2.selection sort\n3.insertion sort\n4.quick sort\n5.merge sort\n");
printf("enter your choice: ");
scanf("%d",&ch); if(ch==1)
bubble(a,n);
else if(ch==2)
selection(a,n);
else if(ch==3)
insertion(a,n);
else if(ch==4)
quicksort(a,0,n-1);
else if(ch==5)
mergesort(a,0,n-1);
else
printf("wrong choice\n");
if(ch>=1 && ch<=5)
{
printf("sorted array: ");
for(i=0;i<n;i++)
printf("%d ",a[i]);
printf("\n");
}
return 0;
}
