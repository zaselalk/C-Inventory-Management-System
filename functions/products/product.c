#include <stdio.h>
#include <string.h>
#define productTableAddress "../data/products.txt"

typedef struct
{
  int id;
  char name[100];
  char description[300];
  char entry_date[20];
  int cost_price[20];
  char selling_price[20];
  char quantity[20];
  char supplier[100];

} Product;


int get_id()
{
  FILE *productTable;
  productTable = fopen(productTableAddress, "r");

  if (productTable == NULL)
  {
    return 1;
  }

  int last_id = 0;
  char line[400];

  while (fgets(line, sizeof(line), productTable) != NULL)
  {
    sscanf(line, "%d", &last_id);
  }

  return last_id + 1;
}

void add_product()
{
  Product product;
  FILE *productTable;

  printf("Enter product name: ");
  fgets(product.name, 100, stdin);

  product.name[strcspn(product.name, "\n")] = '\0';


  printf("Enter product description: ");
  fgets(product.description, 300, stdin);
  product.description[strcspn(product.description, "\n")] = '\0'; // remove new line character

  printf("Enter product cost price: ");
  fgets(product.cost_price, 20, stdin);
  product.cost_price[strcspn(product.cost_price, "\n")] = '\0'; // remove new line character

  printf("Enter product selling price: ");
  fgets(product.selling_price, 20, stdin);
  product.selling_price[strcspn(product.selling_price, "\n")] = '\0'; // remove new line character

  printf("Enter product supplier id: ");
  fgets(product.supplier_id, 20, stdin);
  product.supplier_id[strcspn(product.supplier_id, "\n")] = '\0'; // remove new line character

  product.id = get_id();


  printf("Enter product cost price: ");
  scanf("%d", &product.cost_price);

  printf("Enter product selling price: ");
  fgets(product.selling_price, 300, stdin);
  product.description[strcspn(product.selling_price, "\n")] = '\0';

  printf("Enter product quantity: ");
  fgets(product.quantity, 300, stdin);
  product.description[strcspn(product.quantity, "\n")] = '\0';

  printf("Enter product supplier: ");
  fgets(product.supplier, 300, stdin);
  product.description[strcspn(product.supplier, "\n")] = '\0';

  productTable = fopen(productTableAddress, "a");
  fprintf(productTable, "%d, %s, %s", get_id(), product.name,
          product.description);
  fclose(productTable);
}

void view_all_products()
{
  FILE *productTable;
  productTable = fopen(productTableAddress, "r");

  Product product;

  char line[400];

  while (fgets(line, sizeof(line), productTable) != NULL)
  {
    sscanf(line, "%d, %99[^,], %299[^,]", &product.id, product.name,
           product.description);
    if (product_id != product.id)
    {

      fprintf(newProductTable, "%d, %s, %s", product.id, product.name,
              product.description);
    }
  }

  int deleteResult = remove("products.txt");
  if (deleteResult != 0)
  {
    printf("Product update failed! Please try again Error Code : P003");
  }

  int renameResult = rename("products_new.txt", "products.txt");
  if (renameResult != 0)
  {
    printf("Product update failed! Please try again Error Code : P004");
  }
}


void delete_product(int product_id)
{
  FILE *productTable;
  FILE *newProductTable;

  productTable = fopen(productTableAddress, "r");

  newProductTable = fopen("products_new.txt", "w");

  if (newProductTable == NULL)
  {
    printf("Product deletion failed! Please try again. Error Code : P006");
    return;
  }

  Product product;

  char line[400];

  while (fgets(line, sizeof(line), productTable) != NULL)
  {
    sscanf(line, "%d, %99[^,], %299[^,]", &product.id, product.name,
           product.description);

    if (product_id != product.id)

    {

      fprintf(newProductTable, "%d, %s, %s", product.id, product.name,
              product.description);
    }
  }


  int deleteResult = remove(productTableAddress);
  if (deleteResult != 0)
  {
    printf("Product update failed! Please try again");

  }

  int renameResult = rename("products_new.txt", "products.txt");
  if (renameResult != 0)
  {

    printf("Product update failed! Please try again");

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