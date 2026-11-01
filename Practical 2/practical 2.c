#include <stdio.h>
int search(int a[], int start, int end, int num)
{
 int mid;
 if (start > end)
 return -1;
 mid = (start + end) / 2;
 if (a[mid] == num)
 return mid;
 else if (num > a[mid])
 return search(a, mid + 1, end, num);
 else
 return search(a, start, mid - 1, num);
}
int main()
{
 int a[100], n, i, num, result;
 printf("Enter number of elements: ");
 scanf("%d", &n);
 printf("Enter sorted elements:\n");
 for(i = 0; i < n; i++)
 scanf("%d", &a[i]); printf("Enter element to search: ");
 scanf("%d", &num);
 result = search(a, 0, n - 1, num);
 if(result == -1)
 printf("Element not found");
 else
 printf("Element found at index %d", result);
 return 0;
}
