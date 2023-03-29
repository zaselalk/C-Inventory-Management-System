#include<stdio.h>
#include<string.h>
typedef struct {
  int id;
  char name[100];
  char description[300];
  float price;
  int quantity;
  int warehouse_id;
  int expire_date;
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
void store_file(){
  Product product;
  FILE *productTable;
  productTable = fopen("../../data/products.txt", "r");
  char view_stock_product[400];
  while (fgets(view_stock_product, sizeof(view_stock_product), productTable) != NULL) {
      sscanf(view_stock_product, "%d, %*[^,], %*[^,]", &product.id);
  FILE *StockTable;
  StockTable = fopen("../../data/Stock.txt", "w");
  fprintf(StockTable,"%d,%d",get_id(),product.id);
  fclose(StockTable);
  FILE *StockTable;
  StockTable = fopen("../../data/Stock.txt", "a");
  printf("Enter product Quantity: ");
  scanf("%d",&product.quantity);
  printf("Enter product Warehouse_ID: ");
  scanf("%d",&product.warehouse_id);
  printf("Enter product Expire Date: ");
  scanf("%d",&product.expire_date);
  fprintf(StockTable," %d,%d,%d\n", product.quantity,product.warehouse_id,product.expire_date);
  fclose(StockTable);
  fclose(productTable);

}
}
void view_all_stock_product(){
    FILE *productTable;
    productTable = fopen("../../data/products.txt", "r");
    Product product;
    char view_stock_product[400];
    printf("---------------------------------------------------------------------------\n");
    printf("%s\t %s\t\t %s\t %s\t\t %s\n", "Stock_ID", "Product_ID", "Quantity","Warehouse_ID","Expire_Date");
    printf("---------------------------------------------------------------------------\n");

    while (fgets(view_stock_product, sizeof(view_stock_product), productTable) != NULL) {
      sscanf(view_stock_product, "%d,%d,%d,%d,%d", &product.id);
      FILE *StockTable;
      StockTable=fopen("../../data/temp_Stock.txt", "r");
      char view_stock_product1[400];
      fgets(view_stock_product1,sizeof(view_stock_product1),StockTable);

    printf("%d\t %s\t\t %s\t\t %.2f\t\t %d\n",get_id(),product.id,);
    }
    fclose(productTable);
 }
 int main(){
  int operation;
do{ printf("\n\nSTOCK MANAGEMENT\n\n");
    printf("1.view all products\n");
    printf("2.Search products by ID\n");
    printf("3.view single product by Name\n");
    printf("Insert the operation :");
    scanf("%d",&operation);}
    while((operation > 3 )|| (operation < 0));
    
    switch (operation){
        case 1:
            view_all_stock_product();
            break;
        case 2:
            // search_stock_product_by_ID();
            break;
        case 3:
            // view_single_stock_product();
            break;
            
    }
   }