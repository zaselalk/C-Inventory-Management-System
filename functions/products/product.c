#include <stdio.h>
#include <string.h>

typedef struct {
  int id;
  char name[100];
  char description[300];
} Product;

int get_id() {
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

  // remove new line character
  product.name[strcspn(product.name, "\n")] = '\0';

  printf("Enter product description: ");
  fgets(product.description, 300, stdin);
  product.description[strcspn(product.description, "\n")] = '\0';

  productTable = fopen("products.txt", "a");
  fprintf(productTable, "%d, %s, %s", get_id(), product.name,
          product.description);
  fclose(productTable);
}

void view_all_products() {
  FILE *productTable;
  productTable = fopen("products.txt", "r");
  Product product;
  char line[400];
  printf("%s\t %s\t\t %s\n", "Id", "Name", "Description");
  printf("--\t --\t\t --\n");

  while (fgets(line, sizeof(line), productTable) != NULL) {
    sscanf(line, "%d, %99[^,], %299[^,]", &product.id, product.name,
           product.description);
    printf("%d\t %s\t %s", product.id, product.name, product.description);
  }
}

void delete_product(int product_id) {
  FILE *productTable;
  FILE *newProductTable;

  productTable = fopen("products.txt", "r");
  newProductTable = fopen("products_new.txt", "w");

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
    printf("Product update failed! Please try again");
  }

  int renameResult = rename("products_new.txt", "products.txt");
  if (renameResult != 0) {
    printf("Product update failed! Please try again");
  }
}
