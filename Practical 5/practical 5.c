#include <stdio.h>
#define MAX 50
int stack[MAX];
int top = -1;
void push(int item)
{
 if (top == MAX - 1)
 {
 printf("Stack is full\n");
 return;
 }
 top = top + 1;
 stack[top] = item;
 printf("%d pushed\n", item);
}
void pop()
{
 int item;
 if (top == -1)
 {
 printf("Stack is empty\n");
 return;
 }
 item = stack[top]; top = top - 1;
 printf("%d popped\n", item);
}
void displayStack()
{
 int i;
 if (top == -1)
 {
 printf("Stack is empty\n");
 return;
 }
 printf("Stack elements: ");
 for (i = top; i >= 0; i--)
 {
 printf("%d ", stack[i]);
 }
 printf("\nTOP position = %d\n", top);
}
int queue[MAX];
int front = -1;
int rear = -1;
void enqueue(int item)
{
 if (rear == MAX - 1)
 {
 printf("Queue is full\n");
 return;
 }
 if (front == -1)
 { front = 0;
 }
 rear = rear + 1;
 queue[rear] = item;
 printf("%d inserted\n", item);
}
void dequeue()
{
 int item;
 if (front == -1)
 {
 printf("Queue is empty\n");
 return;
 }
 item = queue[front];
 front = front + 1;
 printf("%d deleted\n", item);
 if (front > rear)
 {
 front = -1;
 rear = -1;
 }
}
void displayQueue()
{
 int i;
 if (front == -1)
 {
 printf("Queue is empty\n");
 return;
 } printf("Queue elements: ");
 for (i = front; i <= rear; i++)
 {
 printf("%d ", queue[i]);
 }
 printf("\nFRONT = %d, REAR = %d\n", front, rear);
}
int main()
{
 int choice, item, n, i;
 do
 {
 printf("\n===== MAIN MENU =====\n");
 printf("1. PUSH in Stack\n");
 printf("2. POP from Stack\n");
 printf("3. DISPLAY Stack\n");
 printf("4. ENQUEUE in Queue\n");
 printf("5. DEQUEUE from Queue\n");
 printf("6. DISPLAY Queue\n");
 printf("7. EXIT\n");
 printf("Enter choice: ");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
 printf("How many elements do you want to push? ");
 scanf("%d", &n);
 for (i = 0; i < n; i++)
 {
 printf("Enter element: ");
 scanf("%d", &item);
 push(item); }
 break;
 case 2:
 printf("How many elements do you want to pop? ");
 scanf("%d", &n);
 for (i = 0; i < n; i++)
 {
 pop();
 }
 break;
 case 3:
 displayStack();
 break;
 case 4:
 printf("How many elements do you want to insert? ");
 scanf("%d", &n);
 for (i = 0; i < n; i++)
 {
 printf("Enter element: ");
 scanf("%d", &item);
 enqueue(item);
 }
 break;
 case 5:
 printf("How many elements do you want to delete? ");
 scanf("%d", &n);
 for (i = 0; i < n; i++)
 {
 dequeue();
 }
 break;
 case 6: displayQueue();
 break;
 case 7:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice\n");
 }
 } while (choice != 7);
 return 0;
}
