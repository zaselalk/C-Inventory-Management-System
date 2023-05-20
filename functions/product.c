#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define productTableAddress "./data/products.txt"


void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

Product get_single_product(int find_id) {

  FILE *productTable;
  productTable = fopen(productTableAddress, "r");

  Product product;
  char single_stock_product[400];
  system("clear");
  printf("%s\t %s\t\t %s\n", "Id", "Name", "Description");
  printf("--\t --\t\t --\n");

  while (fgets(single_stock_product, sizeof(single_stock_product),
               productTable) != NULL) {
    sscanf(single_stock_product, "%d, %99[^,], %299[^,]", &product.id,
           product.name, product.description);
    if (find_id == product.id) {
      printf("%d\t %s\t \t%s", product.id, product.name, product.description);
    }
  }

  printf("\n\n\n\n\n");
}
int get_product_id() {
  FILE *productTable;
  productTable = fopen(productTableAddress, "r");

  if (productTable == NULL) {
    return 1;
  }

  int last_id = 0;
  char line[400];

  while (fgets(line, sizeof(line), productTable) != NULL) {
    sscanf(line, "%d", &last_id);
  }

  return last_id + 1;
}

void show_single_product() {
  int product_id;
  printf("Enter product id: ");
  scanf("%d", &product_id);
  get_single_product(product_id);
}

void show_suppliers(){
  char line[400];
  FILE *supplier_table;
  Supplier supplier;
  supplier_table = fopen("./data/supplier.txt","r");

  printf("All Suppliers \n");

  while(fgets(line,sizeof(line),supplier_table) != NULL){
        sscanf(line, "%d, %99[^,], %12[^,]", &supplier.id, supplier.name,
           supplier.contact_number);
  
        printf("%d, %s, %s \n",supplier.id,supplier.name,supplier.contact_number);
    }

  fclose(supplier_table);
}

void add_product() {
  Product product;
  FILE *productTable;



  clearInputBuffer();
  system("clear");

  printf("Enter New Product to the Database \n");
  
  printf("Enter product name: ");
  fgets(product.name, 100, stdin);
  product.name[strcspn(product.name, "\n")] = '\0'; 

  printf("Enter product description: ");
  fgets(product.description, 300, stdin);
  product.description[strcspn(product.description, "\n")] =
      '\0'; 

  printf("Enter product cost price: ");
  fgets(product.cost_price, 20, stdin);
  product.cost_price[strcspn(product.cost_price, "\n")] =
      '\0'; 

  printf("Enter product selling price: ");
  fgets(product.selling_price, 20, stdin);
  product.selling_price[strcspn(product.selling_price, "\n")] =
      '\0'; // remove new line character

  //load supplier data
   show_suppliers();


  printf("Enter product supplier id: ");
  fgets(product.supplier_id, 20, stdin);
  product.supplier_id[strcspn(product.supplier_id, "\n")] =
      '\0'; // remove new line character

  product.id = get_product_id();

  productTable = fopen(productTableAddress, "a");

  if (productTable == NULL) {
    printf("Product creation failed! Please try again. ");
    return;
  }

  fprintf(productTable, "%d, %s, %s, %s, %s, %s \n", product.id, product.name,
          product.description, product.cost_price, product.selling_price,
          product.supplier_id);
  fclose(productTable);
}

void delete_product() {
  FILE *productTable;
  FILE *newProductTable;

  int product_id;
  printf("Enter product id: ");
  scanf("%d", &product_id);

  productTable = fopen(productTableAddress, "r");

  if (productTable == NULL) {
    printf("Product deletion failed! Please try again. ");
    return;
  }

  newProductTable = fopen("./data/products_new.txt", "w");

  if (newProductTable == NULL) {
    printf("Product deletion failed! Please try again.");
    return;
  }

 

  Product product;

  char line[400];

  while (fgets(line, sizeof(line), productTable) != NULL) {
    sscanf(line, "%d, %99[^,], %299[^,]", &product.id, product.name,
           product.description);
    if (product_id != product.id) {
     
      fprintf(newProductTable, "%d, %s, %s", product.id, product.name,
              product.description);
    }
  }

  fclose(newProductTable);
  fclose(productTable);

  int deleteResult = remove("./data/products.txt");
  if (deleteResult != 0) {
    printf("Product update failed! Please try again Error Code : P003");
  }

  int renameResult = rename("./data/products_new.txt", "./data/products.txt");
  if (renameResult != 0) {
    printf("Product update failed! Please try again Error Code : P004");
  }
}

void update_product() {
  int find_product_id;

  printf("Enter product id: ");
  scanf("%d", &find_product_id);

  FILE *productTable;
  FILE *newProductTable;

  productTable = fopen(productTableAddress, "r");

  if (productTable == NULL) {
    printf("Product deletion failed! Please try again. Error Code : P005");
    return;
  }

  newProductTable = fopen("./data/products_new.txt", "w");

  if (newProductTable == NULL) {
    printf("Product deletion failed! Please try again. Error Code : P006");
    return;
  }

  Product product;

  char line[400];

  while (fgets(line, sizeof(line), productTable) != NULL) {
    sscanf(line, "%d, %99[^,], %299[^,]", &product.id, product.name,
           product.description);
    if (find_product_id != product.id) {

      fprintf(newProductTable, "%d, %s, %s", product.id, product.name,
              product.description);
    }
  }

  int deleteResult = remove(productTableAddress);
  if (deleteResult != 0) {
    printf("Product update failed! Please try again");
  }

  int renameResult = rename("./data/products_new.txt", productTableAddress);
  if (renameResult != 0) {
    printf("Product update failed! Please try again ");
  }
}

int manage_product() {
  int operation;
  system("clear");
  printf("\n");
  printf("\033[1;34m MANAGE PRODUCTS\033[0m\n\n");
  do {
    printf("\n\033[1mOperations\033[0m\n\n");
    printf("\033[1m-------------------------------\033[0m\n");
    printf("1 - Add a new Product\n");
    printf("2 - View Single Product \n");
    printf("3 - Update Product \n");
    printf("4 - Delete Product \n");
    printf("5 - Back to Main menu\n");

    printf("\033[1m-------------------------------\033[0m\n\n");
    printf("Insert the operation: ");
    scanf("%d", &operation);

    switch (operation) {
    case 1:
      system("clear");
      add_product();
      break;
    case 2:
      system("clear");
      show_single_product();
      break;
    case 3:
      system("clear");
      update_product();
      break;
    case 4:
      system("clear");
      delete_product();
      break;
    case 5:
      break;
    }
  } while (operation != 5);
  return 0;
}
