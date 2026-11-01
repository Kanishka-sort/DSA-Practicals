#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node *next;
};
struct node *top = NULL; // NULL means stack is empty
void push(int item)
{
 struct node *newnode;
 newnode = (struct node *)malloc(sizeof(struct node));
 if (newnode == NULL)
 {
 printf("Memory not available\n");
 return;
 }
 newnode->data = item;
 newnode->next = top;
 top = newnode;
 printf("%d pushed\n", item);
}
void pop()
{ struct node *temp;
 if (top == NULL)
 {
 printf("Stack is empty\n");
 return;
 }
 temp = top;
 printf("%d popped\n", temp->data);
 top = top->next;
 free(temp);
}
void display()
{
 struct node *temp;
 if (top == NULL)
 {
 printf("Stack is empty\n");
 return;
 }
 printf("Stack elements: ");
 temp = top;
 while (temp != NULL)
 {
 printf("%d ", temp->data);
 temp = temp->next;
 }
 printf("\nTOP element = %d\n", top->data);
}
int main()
{ int choice, item, n, i;
 do
 {
 printf("\n===== STACK MENU =====\n");
 printf("1. PUSH (Insert)\n");
 printf("2. POP (Delete)\n");
 printf("3. DISPLAY\n");
 printf("4. EXIT\n");
 printf("Enter choice: ");
 if (scanf("%d", &choice) != 1)
 {
 printf("Invalid input\n");
 break;
 }
 switch (choice)
 {
 case 1:
 printf("How many elements do you want to push? ");
 if (scanf("%d", &n) != 1 || n < 0)
 {
 printf("Enter a valid non-negative number\n");
 break;
 }
 for (i = 0; i < n; i++)
 {
 printf("Enter element: ");
 if (scanf("%d", &item) != 1)
 {
 printf("Invalid input\n");
 break;
 }
 push(item); }
 break;
 case 2:
 printf("How many elements do you want to pop? ");
 if (scanf("%d", &n) != 1 || n < 0)
 {
 printf("Enter a valid non-negative number\n");
 break;
 }
 for (i = 0; i < n; i++)
 {
 if (top == NULL)
 {
 printf("Stack is empty\n");
 break;
 }
 pop();
 }
 break;
 case 3:
 display();
 break;
 case 4:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice\n");
 }
 } while (choice != 4);
 // Free all remaining nodes before exiting
 while (top != NULL) {
 struct node *temp = top;
 top = top->next;
 free(temp);
 }
 return 0;
}
