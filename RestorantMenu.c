#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Menu{
    char name[150];
    int price;
    struct Menu *prev;
    struct Menu *next;
};

struct Menu *head = NULL;
struct Menu *tail = NULL;


void addMenu(char name[], int price){
    struct Menu *newMenu = (struct Menu*) malloc(sizeof(struct Menu));
    strcpy(newMenu -> name, name);
    newMenu -> price = price;
    newMenu -> prev = tail;
    newMenu -> next = NULL;

    if(head == NULL){
        head = newMenu;
        tail = newMenu;
    }else{
        tail -> next = newMenu;
        tail = newMenu;
    }
}

void inputMenu(){
    char name[150];
    int price;
    printf("Enter menu name: ");
    scanf("%s", name);
    printf("Enter menu price: ");
    scanf("%d", &price);
    addMenu(name, price);
    printf("Menu Name: %s\n", name);
    printf("Price: %d\n", price);
}

void deleteMenu(char name[]){
    struct Menu *curr = head;
    while(curr != NULL){
        if(strcmp(curr -> name, name) == 0){
            if(curr == head && curr == tail){
                head = NULL;
                tail = NULL;
            }else if(curr = head){
                head = curr -> next;
                head -> prev = NULL;
            }else{
                curr -> prev -> next = curr -> next;
                curr -> next -> prev = curr -> prev;
            }
            free(curr);
            printf("%s delete from the menu\n", name);
            return;
        }
        curr = curr -> next;
    }
    printf("%s not found in the menu\n", name);
}

void printMenu(){
    struct Menu *curr = head;
    while(curr != NULL){
        printf("Name: %s\n", curr -> name);
        printf("Price: %d\n", curr -> price);
        curr = curr -> next;
    }
}

int main(){
    int choice;
    char name[100];
    do{
        menu:
        printf("\nMENU\n");
        printf("1. Input Menu\n");
        printf("2. Delete Menu\n");
        printf("3. Print Menu\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                inputMenu();
                break;
            case 2:
                printf("Enter Menu name to delete: ");
                scanf("%s", name);
                deleteMenu(name);
                break;
            case 3:
                printMenu();
                break;
            case 4:
                printf("Thank You!");
                exit(1);
                break;
            default:
                printf("Wrong Choice!\n");
                goto menu;
                break;
        }
    } while(choice != 4);
    return 0;
}