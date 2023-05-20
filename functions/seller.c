#include <stdio.h>

int get_seller_id() {
  FILE *seller_table;
  seller_table = fopen("./data/sellers.txt", "r");

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


void addSeller() {
    FILE *sellerTable; 
    sellerTable = fopen("./data/sellers.txt","a");
    Seller seller;

    clearInputBuffer();
    system("clear");

    seller.id = get_seller_id();

    printf("Enter seller name: ");
    fgets(seller.name, 100, stdin);
    seller.name[strcspn(seller.name, "\n")] = '\0'; 


    printf("Enter seller rating: ");
    scanf("%f", &seller.rating);

    fprintf(sellerTable, "%d, %s, %.2f \n", seller.id, seller.name, seller.rating);
    fclose(sellerTable);
}

// Function to remove a seller
void removeSeller() {
    FILE *seller_table;
    FILE *new_seller_table;
    Seller seller;
    char line[400];
  
    int sellerId;
    printf("Enter seller ID to remove: ");
    scanf("%d", &sellerId);

    seller_table = fopen("./data/sellers.txt","r");
    new_seller_table = fopen("./data/new_sellers.txt","w");

    if(seller_table == NULL ||  new_seller_table == NULL){
        printf("Seller delete process failed!, Please try again!");
        return ;
    }


 while (fgets(line, sizeof(line), seller_table) != NULL) {
    sscanf(line, "%d, %99[^,], %f", &seller.id, seller.name,
           &seller.rating);
    if (sellerId != seller.id) {
      fprintf(new_seller_table, "%d, %s, %.2f\n", seller.id, seller.name,
              seller.rating);
    }
  }

  fclose(seller_table);
  fclose(new_seller_table);

  int deleteResult = remove("./data/sellers.txt");
  if (deleteResult != 0) {
    printf("Product update failed! Please try again Error Code : P003");
  }

  int renameResult = rename("./data/new_sellers.txt", "./data/sellers.txt");
  if (renameResult != 0) {
    printf("Product update failed! Please try again Error Code : P004");
  }


}

// Function to display active sellers
void displayAllSellers() {
    FILE *seller_table;
    seller_table = fopen("./data/sellers.txt","r");
    char line[400];
    Seller seller;

    printf("Seller Id | Seller Name | Seller rating\n");
    while(fgets(line,sizeof(line),seller_table) != NULL){
        sscanf(line, "%d, %99[^,], %f", &seller.id, seller.name,
           &seller.rating);
  
        printf("%d, %s, %.2f \n",seller.id,seller.name,seller.rating);
    }
}

int manage_sellers() {


    int choice;
    do {
        printf("\nInventory Management System\n");
        printf("1. Add Seller\n");
        printf("2. Remove Seller\n");
        printf("3. Display Active Sellers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSeller();
                break;
            case 2:
                removeSeller();
                break;
            case 3:
                displayAllSellers();
                break;
                       
        }
     
       
    } while(1);
    return 0;

}
