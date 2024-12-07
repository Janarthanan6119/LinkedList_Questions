#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtEnd(struct Node **headad,int data){//(1000,30)
//Dbl ptr (**) - holds the ptr var address
struct Node *newnode = createNode(data);//9000
//*1000 - value at 1000
if(*headad==NULL){
    *headad=newnode;
    return;
}
struct Node *temp = *headad;//1000
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next = newnode;
}
int check(struct Node *head){
struct Node *temp = head->next;
while(temp!=NULL && temp!=head)
    temp=temp->next;
return (temp==head);
}
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Driver code
int main() {
    struct Node* head = NULL;
    insertAtEnd(&head,10);//(1000,10)
    insertAtEnd(&head,20);//(1000,20)
    insertAtEnd(&head,30);//(1000,20)
    insertAtEnd(&head,40);
    insertAtEnd(&head,50);
    /*struct Node *temp = head;
    while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=head;*/
    if(check(head))
        printf("It is Circular");
    else
        printf("It is Not");

    }

