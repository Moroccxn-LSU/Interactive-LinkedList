// Adam Elkhanoufi
// 10/13/2022
// Prog1
// Interactive Singly Linked List in C
// Due: 10/20/2022

/*  Tasks
    1. Display shows only first node inserted [done]
    2. Insert methods
        ~ Insert node at the end [done]
        ~ Insert node at a position [done]
    3. Delete methods
        ~ Delete node by value [done]
        ~ Delete node at a position [done]
    4. View value of node at given position [done]
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head = NULL;
typedef struct Node node;

void InsertEnd(node **start, int val){
    node *newNode = malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    node *curr = *start;

    if (newNode != NULL){
        if (curr == NULL){
            head = newNode;
            *start = newNode;
        }else{
            while (curr->next != NULL){
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }else{
        printf("[ERROR] Unable to Insert Node");
        return;
    }
}

void InsertPos(node **start, int val, int pos){
    node *curr = *start;

    if (pos < 0){
        printf("[ERROR] Invalid Index");
        return;
    }

    while (pos--){
        if (pos == 0){
            node *newNode = malloc(sizeof(node));
            newNode->data = val;
            newNode->next = curr->next;
            curr->next = newNode;
            if (newNode == NULL){
                printf("[ERROR] Unable to Insert Node");
                return;
            }
        }else{
            curr = curr->next;
        }
    }
}

void DeleteVal(node **start, int val){
    node *curr = *start;
    node *prev;

    if (curr == NULL){
        printf("[ERROR] List is Empty");
        return;
    }else if (curr->next == NULL){
        *start = NULL;
        free(curr);
    }else{
        prev = curr;

        while (curr->data != val){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        free(curr);
    }
}

void DeletePos(node **start, int pos){
    if (*start == NULL){return;}

    node *curr = *start;

    if (pos == 0){
        *start = curr->next;
        free(curr);
        return;
    }

    for (int i = 0; curr != NULL && i < pos - 1; i++){
        curr = curr->next;
    }

    if (curr == NULL || curr->next == NULL){
        printf("[ERROR] Index does not exist");
        return;
    }

    node *next = curr->next->next;
    free(curr->next);
    curr->next = next;
}

void Display(node **start){
    node *curr = *start;

    if (curr == NULL){
        printf("[ERROR] List is Empty");
    }else{
        while (curr->next != NULL){
            printf("%d --> ", curr->data);
            curr = curr->next;
        }
        printf("%d\n", curr->data);
    }
}

void DisplayPos(node **start, int pos){
    node *curr = *start;
    
    if (pos < 0){
        printf("[ERROR] Invalid Position");
        return;
    }

    pos++;

    while (pos--){
        if (pos == 0){
            if (curr == NULL){
                printf("[ERROR] Invalid Position");
                return;
            }else{
                printf("%d", curr->data);
                return;
            }
        }else{
            curr = curr->next;
        }
    }
}

int main(){
    node *start = head;
    int state = 1;

    while (state){
        printf("___________________________________\n");
        printf("Interactive Singly Linked List in C\n");
        printf("[1] Insert Node at the End\n");
        printf("[2] Insert Node at a Position\n");
        printf("[3] Delete Node by Value\n");
        printf("[4] Delete Node by Position\n");
        printf("[5] Display Linked List\n");
        printf("[6] Display a Node's Value\n");
        printf("[7] Exit\n");
        printf("\nEnter your option: ");
        scanf("%d", &state);
        int val, pos;

        switch (state){
            case 1:
                printf("What value would you like to insert? ");
                scanf("%d", &val);
                InsertEnd(&start, val);
                printf("\n[*] %d has been Inserted\n", val);
                break;

            case 2:
                printf("What value would you like to insert? ");
                scanf("%d", &val);
                printf("At what position would you like to insert? ");
                scanf("%d", &pos);
                InsertPos(&start, val, pos);
                printf("\n[*] %d has been Inserted\n", val);
                break;

            case 3:
                printf("What value would you like to delete? ");
                scanf("%d", &val);
                DeleteVal(&start, val);
                printf("\n[*] %d has been Deleted\n", val);
                break;

            case 4:
                printf("What position would you like to delete? ");
                scanf("%d", &val);
                DeletePos(&start, val);
                printf("\n[*]Node at index %d has been Deleted\n", val);
                break;
            
            case 5:
                printf("\nCurrent Linked List: ");
                Display(&start);
                break;
            
            case 6:
                printf("Which Node would you like displayed? ");
                scanf("%d", &pos);
                printf("\nNode %d contains Value ", pos);
                DisplayPos(&start, pos);
                printf("\n");
                break;

            case 7:
                printf("\n");
                return 0;

            default:
                printf("\n[ERROR] Invalid Option\n");
                state = 1;
                break;
        }
    }

    return 0;
}