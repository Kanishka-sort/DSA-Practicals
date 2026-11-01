#include<stdio.h>
void substring(), palindrome(), compare(), copy(), reverse();
int main()
{
int ch;
printf("\n1.Substring\n2.Palindrome\n3.Compare\n4.Copy\n5.Reverse");
printf("\nEnter Choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1: substring(); break;
case 2: palindrome(); break;
case 3: compare(); break;
case 4: copy(); break;
case 5: reverse(); break;
default: printf("Invalid Choice");
}
return 0;
}
void substring()
{
char brand[20];
int i,s,n;
printf("Enter Car Brand : ");
scanf("%s",brand);
printf("Start & Length : ");
scanf("%d%d",&s,&n);
for(i=s;i<s+n;i++)
printf("%c",brand[i]); }
void palindrome()
{
char brand[20];
int i,len=0;
printf("Enter Word : ");
scanf("%s",brand);
while(brand[len]!='\0') len++;
for(i=0;i<len/2;i++)
{
if(brand[i]!=brand[len-1-i])
{
printf("Not Palindrome");
return;
}
}
printf("Palindrome");
}
void compare()
{
char a[20],b[20];
int i=0;
printf("Enter First Brand : ");
scanf("%s",a);
printf("Enter Second Brand : ");
scanf("%s",b);
while(a[i]==b[i] && a[i]!='\0')
i++;
if(a[i]==b[i])
printf("Same");
else
printf("Different");
}
void copy()
{ char a[20],b[20];
int i=0;
printf("Enter Car Brand : ");
scanf("%s",a);
while((b[i]=a[i])!='\0')
i++;
printf("Copied = %s",b);
}
void reverse()
{
char brand[20];
int i,len=0;
printf("Enter Car Brand : ");
scanf("%s",brand);
while(brand[len]!='\0') len++;
for(i=len-1;i>=0;i--)
printf("%c",brand[i]);
}
