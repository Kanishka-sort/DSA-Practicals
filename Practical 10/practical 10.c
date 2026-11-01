#include <stdio.h>
#define MAX 5
char tx[MAX], rx[MAX];
int tf = 0, tr = -1, tc = 0;
int rf = 0, rr = -1, rc = 0;
void send(char ch)
{
 if (tc == MAX)
 {
 printf("TX buffer is full\n");
 return;
 }
 tr = (tr + 1) % MAX;
 tx[tr] = ch;
 tc++;
}
void receive(char ch)
{
 if (rc == MAX)
 {
 printf("RX buffer is full\n");
 return;
 }
 rr = (rr + 1) % MAX;
 rx[rr] = ch;
 rc++; }
int main()
{
 char data[100];
 int i;
 printf("Enter data to send: ");
 scanf("%99s", data);
 for (i = 0; data[i] != '\0'; i++)
 {
 send(data[i]);
 }
 while (tc > 0)
 {
 char ch = tx[tf];
 tf = (tf + 1) % MAX;
 tc--;
 receive(ch);
 }
 printf("Received data: ");
 while (rc > 0)
 {
 printf("%c", rx[rf]);
 rf = (rf + 1) % MAX;
 rc--;
 }
 printf("\n");
 return 0;
}
