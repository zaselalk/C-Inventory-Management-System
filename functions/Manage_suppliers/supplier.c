#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ID_LENGTH 100000
#define MAX_NAME_LENGTH 100
#define MAX_RATING_LENGTH 20
#define MAX_CONTACT_LENGTH 100
#define SUPPLIER_TABLE_ADDRESS "suppliers.txt"

typedef struct
{
  int id;
  char name[MAX_NAME_LENGTH];
  float rating;
  char contact[MAX_CONTACT_LENGTH];
} Supplier;

void add_supplier()
{   

  Supplier supplier;
  FILE *supplierTable;

  printf("Enter supplier ID: ");
  char supplierIdInput[MAX_ID_LENGTH];
  fgets(supplierIdInput, MAX_ID_LENGTH, stdin);
  supplier.id = atoi(supplierIdInput); // convert string to integer

  printf("Enter supplier name: ");
  fgets(supplier.name, MAX_NAME_LENGTH, stdin);
  supplier.name[strcspn(supplier.name, "\n")] = '\0'; // remove new line character

  printf("Enter supplier rating: ");
  char supplierRating[MAX_RATING_LENGTH];
  fgets(supplierRating, MAX_RATING_LENGTH, stdin);
  supplier.rating = atof(supplierRating); // convert string to float

  printf("Enter supplier contact details: ");
  fgets(supplier.contact, MAX_CONTACT_LENGTH, stdin);
  supplier.contact[strcspn(supplier.contact, "\n")] = '\0'; // remove new line character

  supplierTable = fopen(SUPPLIER_TABLE_ADDRESS, "a");

  if (supplierTable == NULL)
  {
    printf("Failed to open file.\n");
    return;
  }

  fprintf(supplierTable, "%d, %s, %.2f, %s\n", supplier.id, supplier.name, supplier.rating, supplier.contact);
  fclose(supplierTable);

  printf("Supplier added successfully.\n");
}

void remove_supplier(){

int supplier_id;
    printf("Enter supplier ID to remove: ");
    scanf("%d", &supplier_id);
    getchar(); // consume newline character

    FILE *supplierTable;
    FILE *newSupplierTable;

    supplierTable = fopen(SUPPLIER_TABLE_ADDRESS, "r");

    if (supplierTable == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    newSupplierTable = fopen("new_suppliers.txt", "w");

    if (newSupplierTable == NULL) {
        fclose(supplierTable);
        printf("Failed to open file.\n");
        return;
    }

    Supplier supplier;
    char line[400];

    while (fgets(line, sizeof(line), supplierTable) != NULL) {
        sscanf(line, "%d, %99[^,], %f, %99[^\n]", &supplier.id, supplier.name, &supplier.rating, supplier.contact);

        if (supplier.id != supplier_id) {
            fprintf(newSupplierTable, "%d, %s, %.2f, %s\n", supplier.id, supplier.name, supplier.rating, supplier.contact);
        }
    }

    fclose(supplierTable);
    fclose(newSupplierTable);

    if (remove(SUPPLIER_TABLE_ADDRESS) == 0) {
        if (rename("new_suppliers.txt", SUPPLIER_TABLE_ADDRESS) == 0) {
            printf("Supplier removed successfully.\n");
            return;
        }
    }

    printf("Failed to remove supplier.\n");

};

int view_supplier() {
    FILE *supplierTable;
    supplierTable = fopen(SUPPLIER_TABLE_ADDRESS, "r");

    if (supplierTable == NULL) {
        printf("Supplier retrieval failed! Please try again.\n");
        return 1;
    }

    Supplier supplier;
    char single_supplier[400];
    int find_id;

    printf("Enter supplier ID to view: ");
    scanf("%d", &find_id);
    getchar(); // consume newline character

    printf("%s\t %s\t %s\t %s\n", "ID", "Name", "Rating", "Contact");
    printf("--\t --\t ------\t ------\n");

    while (fgets(single_supplier, sizeof(single_supplier), supplierTable) != NULL) {
        sscanf(single_supplier, "%d, %99[^,], %f, %99[^\n]", &supplier.id, supplier.name, &supplier.rating, supplier.contact);

        if (find_id == supplier.id) {
            printf("%d\t %s\t %.2f\t %s\n", supplier.id, supplier.name, supplier.rating, supplier.contact);
            fclose(supplierTable);
            return 0;
        }
    }

    fclose(supplierTable);
    printf("Supplier not found!\n");
    return 1;
}

int main()
{
  int choice;

  while (1)
  {
    printf("\n--- Supplier Management System ---\n");
    printf("1. Add supplier\n");
    printf("2. Remove supplier\n");
    printf("3. View supplier\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // consume newline character

    switch (choice)
    {
    case 1:
      add_supplier();
      break;
    case 2:
      remove_supplier();
      break;
    case 3:
    {
      view_supplier();
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