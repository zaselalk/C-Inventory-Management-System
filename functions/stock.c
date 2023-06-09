#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int manage_stock();

//------------------------DISPLAY PRODUCTS IN STOCK----------------------------

void display_product_in_stock() {

  FILE *productTable;
  productTable = fopen("./data/products.txt", "r");

  Product product;
  char single_stock_product[400];
  printf("--------------------------------------\n");
  printf("%s\t %s\t\t %s\t\t\n", "Id", "Name", "Description");
  printf("--------------------------------------\n");

  while (fgets(single_stock_product, sizeof(single_stock_product),
               productTable) != NULL) {
    sscanf(single_stock_product, "%d, %99[^,], %299[^,]", &product.id,
           product.name, product.description);
    printf("%d\t %s\t\t %s\n", product.id, product.name, product.description);
  }
}

//-------------------------CREATING A STOCK ID--------------------------

int get_stock_id() {
  FILE *productTable;
  productTable = fopen("./data/stock.txt", "r");

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

//-------------------------DISPLAY WAREHOUSE IN
// STOCK------------------------------

void display_warehouse_in_stock()

{
  int warehouse_id;
  char warehouse_name[200];
  char warehouse_location[200];

  FILE *file_read;
  file_read = fopen("./data/wh_products.txt", "r");
  char text_store[200];
  printf("--------------------------------------------------------------\n");
  printf("%s\t  %s\t %s\t\t\n", "Warehouse ID", "Warehouse Name",
         "Warehouse Location");
  printf("--------------------------------------------------------------\n");
  while (fgets(text_store, 200, file_read) != NULL) {
    sscanf(text_store, "%d, %49[^,], %49[^,]", &warehouse_id, warehouse_name,
           warehouse_location);

    printf("%d\t\t  %s\t\t %s\t\t\n", warehouse_id, warehouse_name,
           warehouse_location);
  }
  fclose(file_read);
}

//----------------------STORE DATA IN TEXT-----------------------------

void store_file() {
  Stock product;
  FILE *StockTable;
  StockTable = fopen("./data/stock.txt", "a+");
  display_product_in_stock();
  printf("Enter product ID: ");
  scanf("%d", &product.id);
  printf("Enter product Quantity: ");
  scanf("%d", &product.quantity);
  display_warehouse_in_stock();
  printf("Enter product Warehouse_ID: ");
  scanf("%d", &product.warehouse_id);
  printf("Enter product Expire Date(2001/09/26): ");
  scanf("%s", product.expire_date);
  product.st_id = get_stock_id();
  fprintf(StockTable, "%d,%d,%d,%d,%s\n", product.st_id, product.id,
          product.quantity, product.warehouse_id, product.expire_date);

  fclose(StockTable);
}
//-----------------------VIEW ALL STOCK--------------------------------

void view_all_stock_product() {
  system("clear");
  int st_count;
  Stock product;
  FILE *productTable;
  productTable = fopen("./data/stock.txt", "r");
  char view_stock_product[400];
  printf("\033[1;34mView Stock\033[0m\n\n");
  printf("---------------------------------------------------------------------"
         "---------------------------\n");
  printf("%s\t %s\t\t %s\t %s\t\t %s\n", "Stock_ID", "Product_ID", "Quantity",
         "Warehouse_ID", "Expire_Date");
  printf("---------------------------------------------------------------------"
         "---------------------------\n");
  while (fgets(view_stock_product, sizeof(view_stock_product), productTable) !=
         NULL) {
    sscanf(view_stock_product, "%d,%d,%d,%d,%s", &st_count, &product.id,
           &product.quantity, &product.warehouse_id, product.expire_date);
    printf("%d\t\t   %d\t\t\t  %d\t\t   %d\t\t\t  %s\n", st_count, product.id,
           product.quantity, product.warehouse_id, product.expire_date);
  }
  fclose(productTable);
  printf("\n\n");

  printf("-------------------------------------- END "
         "-------------------------------"
         "---------------------------\n");
}
//--------------------SEARCH STOCK BY PRODUCT ID--------------------------------

void search_stock_product_by_ID() {
  int st_count;
  Stock product;
  int product_stock_id;
  printf("Insert the Product ID: ");
  scanf("%d", &product_stock_id);
  FILE *productTable;
  productTable = fopen("./data/stock.txt", "r");
  char search_st_product[400];
  printf("---------------------------------------------------------------------"
         "---------------------------\n");
  printf("%s\t %s\t\t %s\t %s\t\t %s\n", "Stock_ID", "Product_ID", "Quantity",
         "Warehouse_ID", "Expire_Date");
  printf("---------------------------------------------------------------------"
         "---------------------------\n");
  while (fgets(search_st_product, sizeof(search_st_product), productTable) !=
         NULL) {
    sscanf(search_st_product, "%d,%d,%d,%d,%s", &st_count, &product.id,
           &product.quantity, &product.warehouse_id, product.expire_date);
    if (product_stock_id == product.id) {
      printf("%d\t\t   %d\t\t\t  %d\t\t   %d\t\t\t  %s\n", st_count, product.id,
             product.quantity, product.warehouse_id, product.expire_date);
    }
  }
  fclose(productTable);
}

//--------------------SEARCH STOCK BY STOCK ID--------------------------------

void search_stock_by_stock_ID() {
  int st_count;
  Stock product;
  int product_stock_id;
  printf("Insert the Stock ID: ");
  scanf("%d", &product_stock_id);
  FILE *productTable;
  productTable = fopen("./data/stock.txt", "r");
  char search_st_by_id[400];
  printf("---------------------------------------------------------------------"
         "---------------------------\n");
  printf("%s\t %s\t\t %s\t %s\t\t %s\n", "Stock_ID", "Product_ID", "Quantity",
         "Warehouse_ID", "Expire_Date");
  printf("---------------------------------------------------------------------"
         "---------------------------\n");
  while (fgets(search_st_by_id, sizeof(search_st_by_id), productTable) !=
         NULL) {
    sscanf(search_st_by_id, "%d,%d,%d,%d,%s", &st_count, &product.id,
           &product.quantity, &product.warehouse_id, product.expire_date);
    if (product_stock_id == st_count) {
      printf("%d\t\t   %d\t\t\t  %d\t\t   %d\t\t\t  %s\n", st_count, product.id,
             product.quantity, product.warehouse_id, product.expire_date);
    }
  }
  fclose(productTable);
}

//-----------------------------MAIN-------------------------------------
int manage_stock() {
  int operation;
 system("clear");
  printf("\n");
  printf("\033[1;34mSTOCK MANAGEMENT\033[0m\n\n");
  do {
    printf("\033[1mOperations\033[0m\n\n");
    printf("\033[1m-------------------------------\033[0m\n");
    printf("1 - Add a new stock item\n");
    printf("2 - View current stock\n");
    printf("3 - Search for a stock item by ID\n");
    printf("4 - Search for a stock item by product ID\n");
    printf("5 - Back to Main menu\n");

    printf("\033[1m-------------------------------\033[0m\n\n");
    printf("Insert the operation: ");
    scanf("%d", &operation);

    switch (operation) {
    case 1:
      store_file();
      break;
    case 2:
      view_all_stock_product();
      break;
    case 3:
      search_stock_by_stock_ID();
      break;
    case 4:
      search_stock_product_by_ID();
      break;
    case 5:
      break;
    }
  } while (operation != 5);
  return 0;
}