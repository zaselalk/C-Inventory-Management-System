#include <stdio.h>

int get_supplier_id() {
  FILE *seller_table;
  seller_table = fopen("./data/supplier.txt", "r");

  if (seller_table == NULL) {
    return 1;
  }

  int last_id = 0;
  char line[400];

  while (fgets(line, sizeof(line), seller_table) != NULL) {
    sscanf(line, "%d", &last_id);
  }

  return last_id + 1;
}


void add_supplier() {
    FILE *supplier_table; 
    supplier_table = fopen("./data/supplier.txt","a");
    Supplier supplier;

    clearInputBuffer();
    system("clear");

    supplier.id = get_supplier_id();

    printf("Enter supplier name: ");
    fgets(supplier.name, 100, stdin);
    supplier.name[strcspn(supplier.name, "\n")] = '\0'; 


    printf("Enter seller contact number: ");
    fgets(supplier.contact_number, 12, stdin);
    supplier.contact_number[strcspn(supplier.contact_number, "\n")] = '\0'; 

    fprintf(supplier_table, "%d, %s, %s \n", supplier.id, supplier.name, supplier.contact_number);
    fclose(supplier_table);
}

// Function to remove a seller
void remove_supplier() {
    FILE *supplier_table;
    FILE *new_supplier_table;
    Supplier supplier;
    char line[400];
  
    int supplierId;
    printf("Enter supplier ID to remove: ");
    scanf("%d", &supplierId);

    supplier_table = fopen("./data/supplier.txt","r");
    new_supplier_table = fopen("./data/new_supplier.txt","w");

    if(supplier_table == NULL ||  new_supplier_table == NULL){
        printf("Seller delete process failed!, Please try again!");
        return ;
    }


 while (fgets(line, sizeof(line), supplier_table) != NULL) {
    sscanf(line, "%d, %99[^,], %12[^,]", &supplier.id, supplier.name,
           supplier.contact_number);
    if (supplierId != supplier.id) {
      fprintf(new_supplier_table, "%d, %s, %s\n", supplier.id, supplier.name,
              supplier.contact_number);
    }
  }

  fclose(supplier_table);
  fclose(new_supplier_table);

  int deleteResult = remove("./data/supplier.txt");
  if (deleteResult != 0) {
    printf("Product update failed! Please try again Error Code : P003");
  }

  int renameResult = rename("./data/new_supplier.txt", "./data/supplier.txt");
  if (renameResult != 0) {
    printf("Product update failed! Please try again Error Code : P004");
  }


}

// Function to display active supplier
void display_all_suppliers() {
    FILE *supplier_table;
    supplier_table = fopen("./data/supplier.txt","r");
    char line[400];
    Supplier supplier;

    printf("\n");
    printf("Supplier Id | Supplier Name | Supplier rating\n");
    while(fgets(line,sizeof(line),supplier_table) != NULL){
        sscanf(line, "%d, %99[^,], %11[^,]", &supplier.id, supplier.name,
           supplier.contact_number);
  
        printf("\t(%d)\t%s\t\t%s\n",supplier.id,supplier.name,supplier.contact_number);
    }
}

int manage_suppliers() {

    system("clear");
    int choice;
    do {

        printf(ANSI_COLOR_GREEN "Manage Suppliers" ANSI_COLOR_RESET "\n");
        printf("+----+------------------------+\n");
        printf("| %2d | %-22s |\n", 1, "Add Supplier");
        printf("| %2d | %-22s |\n", 2, "Remove Supplier");
        printf("| %2d | %-22s |\n", 3, "Display All Supplier");
        printf("| %2d | %-22s |\n", 4, "Exit");
        printf("+----+------------------------+\n");


        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_supplier();
                break;
            case 2:
                remove_supplier();
                break;
            case 3:
                display_all_suppliers();
                break;
                       
        }
     
       
    } while(choice !=4);
    return 0;

}
