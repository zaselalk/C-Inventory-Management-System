#include <stdio.h>
#include <string.h>
#define productTableAddress "../data/products.txt"

typedef struct {
  int id;
  char name[100];
  char description[300];
  char cost_price[20];
  char selling_price[20];
  char supplier_id[20];
} Product;

Product get_single_product(int find_id) {

  FILE *productTable;
  productTable = fopen("../../data/products.txt", "r");

  Product product;
  char single_stock_product[400];
  printf("%s\t %s\t\t %s\n", "Id", "Name", "Description");
  printf("--\t --\t\t --\n");

  while (fgets(single_stock_product, sizeof(single_stock_product),
               productTable) != NULL) {
    sscanf(single_stock_product, "%d, %99[^,], %299[^,]", &product.id,
           product.name, product.description);
    if (find_id == product.id) {
      printf("%d\t %s\t %s", product.id, product.name, product.description);
    }
  }
}
int get_product_id() {
  FILE *productTable;
  productTable = fopen("products.txt", "r");

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

void add_product() {
  Product product;
  FILE *productTable;

  printf("Enter product name: ");
  fgets(product.name, 100, stdin);
  product.name[strcspn(product.name, "\n")] = '\0'; // remove new line character

  printf("Enter product description: ");
  fgets(product.description, 300, stdin);
  product.description[strcspn(product.description, "\n")] =
      '\0'; // remove new line character

  printf("Enter product cost price: ");
  fgets(product.cost_price, 20, stdin);
  product.cost_price[strcspn(product.cost_price, "\n")] =
      '\0'; // remove new line character

  printf("Enter product selling price: ");
  fgets(product.selling_price, 20, stdin);
  product.selling_price[strcspn(product.selling_price, "\n")] =
      '\0'; // remove new line character

  printf("Enter product supplier id: ");
  fgets(product.supplier_id, 20, stdin);
  product.supplier_id[strcspn(product.supplier_id, "\n")] =
      '\0'; // remove new line character

  product.id = get_product_id();

  productTable = fopen("products.txt", "a");

  if (productTable == NULL) {
    printf("Product creation failed! Please try again. Error Code : P001");
    return;
  }

  fprintf(productTable, "%d, %s, %s, %s, %s, %s \n", product.id,
          product.name, product.description, product.cost_price,
          product.selling_price, product.supplier_id );
  fclose(productTable);
}

void delete_product() {
  FILE *productTable;
  FILE *newProductTable;

  int product_id;
  printf("Enter product id: ");
  scanf("%d", &product_id);

  productTable = fopen("products.txt", "r");

  if (productTable == NULL) {
    printf("Product deletion failed! Please try again. Error Code : P005");
    return;
  }

  newProductTable = fopen("products_new.txt", "w");

  if (newProductTable == NULL) {
    printf("Product deletion failed! Please try again. Error Code : P006");
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

  int deleteResult = remove("products.txt");
  if (deleteResult != 0) {
    printf("Product update failed! Please try again Error Code : P003");
  }

  int renameResult = rename("products_new.txt", "products.txt");
  if (renameResult != 0) {
    printf("Product update failed! Please try again Error Code : P004");
  }
}

void update_product() {
  int find_product_id;

  printf("Enter product id: ");
  scanf("%d", &find_product_id);

  // get product
  // Product product = get_single_product(find_product_id);

  FILE *productTable;
  FILE *newProductTable;

  productTable = fopen("products.txt", "r");

  if (productTable == NULL) {
    printf("Product deletion failed! Please try again. Error Code : P005");
    return;
  }

  newProductTable = fopen("products_new.txt", "w");

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

  int deleteResult = remove("products.txt");
  if (deleteResult != 0) {
    printf("Product update failed! Please try again Error Code : P003");
  }

  int renameResult = rename("products_new.txt", "products.txt");
  if (renameResult != 0) {
    printf("Product update failed! Please try again Error Code : P004");
  }
}

// Error codes
// P001 - Product creation failed - Error opening file
// P002 - Product update failed - Error opening file

// Product deletion
//        P003 - failed to delete old file
//        P004 - Error renaming file
//        P005 - Error opening product table
//        P006 - Error opening new product table