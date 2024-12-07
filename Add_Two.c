#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
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

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
struct Node* add(struct Node *h1,struct Node *h2){
struct Node *res=NULL;
struct Node **temp=&res;
int carry=0;
while(h1!=NULL || h2!=NULL || carry!=0){
    int sum=carry;
    if(h1!=NULL){
        sum+=h1->data;
        h1=h1->next;
    }
    if(h2!=NULL){
        sum+=h2->data;
        h2=h2->next;
    }
    carry=sum/10;
    int dig=sum%10;
    *temp=createNode(dig);
    temp=&((*temp)->next);//will point the next address

}
return res;
};
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    // Representing 342 as 2 -> 4 -> 3
    insertAtEnd(&head1, 2);
    insertAtEnd(&head1, 4);
    insertAtEnd(&head1, 3);

    // Representing 465 as 5 -> 6 -> 4
    insertAtEnd(&head2, 5);
    insertAtEnd(&head2, 6);
    insertAtEnd(&head2, 4);
    struct Node *ans=add(head1,head2);
    display(ans);


}
