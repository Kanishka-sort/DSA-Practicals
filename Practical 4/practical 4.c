#include <stdio.h>
#include <string.h>
struct employee
{
int emp_no;
char name[20];
float salary;
};
struct employee emp[30];
int n = 0;
void create()
{
int i;
printf("Enter number of employees: ");
scanf("%d", &n);
for(i = 0; i < n; i++)
{
printf("\nEnter employee number: ");
scanf("%d", &emp[i].emp_no);
printf("Enter name: ");
scanf("%s", emp[i].name);
printf("Enter salary: ");
scanf("%f", &emp[i].salary);
} printf("\nEmployee database created!\n");
}
void display()
{
int i;
printf("\nEmployee Details:\n");
for(i = 0; i < n; i++)
{
printf("\nEmployee No: %d", emp[i].emp_no);
printf("\nName: %s", emp[i].name);
printf("\nSalary: %.2f\n", emp[i].salary);
}
}
void search()
{
int no, i;
printf("Enter employee number: ");
scanf("%d", &no);
for(i = 0; i < n; i++)
{
if(emp[i].emp_no == no)
{
printf("\nEmployee found!\n");
printf("Employee No: %d\n", emp[i].emp_no);
printf("Name: %s\n", emp[i].name);
printf("Salary: %.2f\n", emp[i].salary);
return;
}
} printf("\nEmployee not found!\n");
}
void modify()
{
int no, i;
printf("Enter employee number: ");
scanf("%d", &no);
for(i = 0; i < n; i++)
{
if(emp[i].emp_no == no)
{
printf("Enter new name: ");
scanf("%s", emp[i].name);
printf("Enter new salary: ");
scanf("%f", &emp[i].salary);
printf("\nEmployee modified!\n");
return;
}
}
printf("\nEmployee not found!\n");
}
void append()
{
printf("Enter employee number: ");
scanf("%d", &emp[n].emp_no);
printf("Enter name: ");
scanf("%s", emp[n].name);
printf("Enter salary: "); scanf("%f", &emp[n].salary);
n++;
printf("\nEmployee added!\n");
}
void delete_emp()
{
int no, i, j;
printf("Enter employee number: ");
scanf("%d", &no);
for(i = 0; i < n; i++)
{
if(emp[i].emp_no == no)
{
for(j = i; j < n - 1; j++)
{
emp[j] = emp[j + 1];
}
n--;
printf("\nEmployee deleted!\n");
return;
}
}
printf("\nEmployee not found!\n");
}
void sort()
{
int i, j;
struct employee temp; for(i = 0; i < n - 1; i++)
{
for(j = 0; j < n - i - 1; j++)
{
if(emp[j].emp_no > emp[j + 1].emp_no)
{
temp = emp[j];
emp[j] = emp[j + 1];
emp[j + 1] = temp;
}
}
}
printf("\nEmployees sorted!\n");
}
int main()
{
int choice;
do
{
printf("\n--- Employee Database ---");
printf("\n1. Create");
printf("\n2. Display");
printf("\n3. Search");
printf("\n4. Modify");
printf("\n5. Append");
printf("\n6. Delete");
printf("\n7. Sort");
printf("\n8. Exit");
printf("\nEnter choice: ");
scanf("%d", &choice);
switch(choice) {
case 1:
create();
break;
case 2:
display();
break;
case 3:
search();
break;
case 4:
modify();
break;
case 5:
append();
break;
case 6:
delete_emp();
break;
case 7:
sort();
break;
case 8:
printf("\nProgram ended.\n");
break;
default:
printf("\nWrong choice!\n");
} } while(choice != 8);
return 0;
}
