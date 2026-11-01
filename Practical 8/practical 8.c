#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
 struct node *left;
 struct node *right;
};
struct node* createNode(int value)
{
 struct node *newnode;
 newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data = value;
 newnode->left = NULL;
 newnode->right = NULL;
 return newnode;
}
struct node* insert(struct node *root, int value)
{
 if (root == NULL)
 {
 return createNode(value);
 }
 if (value < root->data)
 {
 root->left = insert(root->left, value); }
 else if (value > root->data)
 {
 root->right = insert(root->right, value);
 }
 return root;
}
void inorder(struct node *root)
{
 if (root != NULL)
 {
 inorder(root->left);
 printf("%d ", root->data);
 inorder(root->right);
 }
}
void search(struct node *root, int key)
{
 if (root == NULL)
 {
 printf("Element not found\n");
 return;
 }
 if (root->data == key)
 {
 printf("Element found\n");
 }
 else if (key < root->data)
 {
 search(root->left, key);
 }
 else
 {
 search(root->right, key);
 }
} int main()
{
 struct node *root = NULL;
 int n, value, key, i;
 printf("Enter number of nodes: ");
 scanf("%d", &n);
 printf("Enter elements:\n");
 for (i = 0; i < n; i++)
 {
 scanf("%d", &value);
 root = insert(root, value);
 }
 printf("\nInorder Traversal: ");
 inorder(root);
 printf("\nEnter element to search: ");
 scanf("%d", &key);
 search(root, key);
 return 0;
}
