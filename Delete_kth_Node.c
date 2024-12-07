#include <stdio.h>
#include <stdlib.h>

// Node structure for a circular linked list
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

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // Make the node circular
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}
void delete_k(struct Node **head,int k){
struct Node *prev = NULL,*temp=*head;
if(k==1){
    while(temp->next!=*head){
        temp=temp->next;
    }
    if((*head)->next==*head){
        free(*head);
        *head=NULL;
    }else{
    struct Node *del = *head;
    temp->next=(*head)->next;
    *head=(*head)->next;
    free(del);
    }
    return;
}
int count=1;
if(count<k){
    prev =temp;
    temp=temp->next;
    count++;
}
prev->next=temp->next;
free(temp);

}
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD)\n");
}

// Driver code
int main() {
    struct Node* head = NULL;

    // Insert nodes into the circular linked list
    insertAtEnd(&head, 10);
    //insertAtEnd(&head, 20);
    //insertAtEnd(&head, 30);
    //insertAtEnd(&head, 40);
    //insertAtEnd(&head, 50);
    delete_k(&head,1);
    display(head);
}
