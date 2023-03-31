#include <stdio.h>
#include <string.h>
typedef struct {
  int id;
  int quantity;
  int warehouse_id;
  char expire_date[20];
  int st_id;
} Stock;

//--------------------Creating a ID--------------------------

int get_stock_id() {
  FILE *productTable;
  productTable = fopen("../data/stock.txt", "r");

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

//-------------------------WAREHOUSE------------------------------

void display_warehouse_in_stock()

{
	int warehouse_id;
	char warehouse_name[200];
	char warehouse_location[200];
	
	FILE *file_read;
	file_read = fopen("warehouse/wh_products.txt", "r");
	char text_store[200];
  printf("--------------------------------------------------------------\n");
  printf("%s\t  %s\t %s\t\t\n","Warehouse ID","Warehouse Name","Warehouse Location");
  printf("--------------------------------------------------------------\n");
	while (fgets(text_store, 200, file_read) != NULL)
	{
		sscanf(text_store,"%d, %49[^,], %49[^,]",&warehouse_id,warehouse_name,warehouse_location);	

		printf("%d\t\t  %s\t\t %s\t\t\n",warehouse_id,warehouse_name,warehouse_location);
	}
	fclose(file_read);
}


//----------------------STORE DATA IN TEXT-----------------------------

void store_file() {
  Stock product;
  FILE *StockTable;
  StockTable = fopen("../data/stock.txt", "a+");
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
  int st_count;
  Stock product;
  FILE *productTable;
  productTable = fopen("../data/stock.txt", "r");
  char view_stock_product[400];
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
}
//--------------------SEARCH STOCK BY PRODUCT ID--------------------------------

void search_stock_product_by_ID() {
  int st_count;
  Stock product;
  int product_stock_id;
  printf("Insert the Product ID: ");
  scanf("%d", &product_stock_id);
  FILE *productTable;
  productTable = fopen("../data/stock.txt", "r");
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
  productTable = fopen("../data/stock.txt", "r");
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
//manage_stock
int main() {
  int operation;

  printf("\n");
  printf("\033[1;34mSTOCK MANAGEMENT\033[0m\n\n");
  printf("\033[1mOperations\033[0m\n\n");
  printf("\033[1m-------------------------------\033[0m\n");
  printf("\033[1;32m+\033[0m 1 -Add a new stock item\n");
  printf("\033[1;36m?\033[0m 2 -View current stock\n");
  printf("\033[1;34m?\033[0m 3 -Search for a stock item by ID\n");
  printf("\033[1;34m?\033[0m 4 -Search for a stock item by product ID\n");
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
  }
  return 0;
}