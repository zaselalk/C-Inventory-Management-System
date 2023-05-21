#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_RATING_LENGTH 20
#define MAX_CONTACT_LENGTH 100
#define SUPPLIER_TABLE_ADDRESS "suppliers.txt"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float rating;
    char contact[MAX_CONTACT_LENGTH];
} Supplier;


void add_supplier(){}

void remove_supplier(){};

void view_supplier(){};

int main() {
    int choice;

    while (1) {
        printf("\n--- Supplier Management System ---\n");
        printf("1. Add supplier\n");
        printf("2. Remove supplier\n");
        printf("3. Get single supplier\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                add_supplier();
                break;
            case 2:
                remove_supplier();
                break;
            case 3: {
                int supplier_id;
                printf("Enter supplier ID to search: ");
                scanf("%d", &supplier_id);
                getchar(); // consume newline character
                view_supplier(supplier_id);
                break;
            }
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}