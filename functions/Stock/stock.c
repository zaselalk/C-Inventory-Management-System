#include<stdio.h>
#include<string.h>
typedef struct {
  int id;
  char name[100];
  char description[300];
  float price;
  int quantity;
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

void search_stock_product_by_ID(){
     int product_stock_id;
    printf("Insert the Product ID: ");
    scanf("%d",&product_stock_id);
    FILE *productTable;
    productTable = fopen("../../data/products.txt", "r");
    Product product;
    char search_st_product[400];
    printf("---------------------------------------------------------------------------\n");
    printf("%s\t %s\t\t %s\t %s\t\t %s\n", "Id", "Name", "Description","Price","Quantity");
    printf("---------------------------------------------------------------------------\n");

    while (fgets(search_st_product, sizeof(search_st_product), productTable) != NULL) {
      sscanf(search_st_product, "%d, %99[^,], %299[^,], %f, %d", &product.id, product.name,
            product.description, &product.price, &product.quantity);
        if(product_stock_id == product.id){
      printf("%d\t %s\t\t %s\t\t %.2f\t\t %d\n", product.id, product.name, product.description, product.price, product.quantity);}
    }
    fclose(productTable);
}
 void view_all_stock_product(){
    FILE *productTable;
    productTable = fopen("../../data/products.txt", "r");
    Product product;
    char view_stock_product[400];
    printf("---------------------------------------------------------------------------\n");
    printf("%s\t %s\t\t %s\t %s\t\t %s\n", "Id", "Name", "Description","Price","Quantity");
    printf("---------------------------------------------------------------------------\n");

    while (fgets(view_stock_product, sizeof(view_stock_product), productTable) != NULL) {
      sscanf(view_stock_product, "%d, %99[^,], %299[^,], %f, %d", &product.id, product.name,
            product.description, &product.price, &product.quantity);
      printf("%d\t %s\t\t %s\t\t %.2f\t\t %d\n", product.id, product.name, product.description, product.price, product.quantity);
    }
    fclose(productTable);
 }
 void view_single_stock_product(){//This Function part is in under construction!
     FILE *productTable;
    productTable = fopen("../../data/products.txt", "r");
    Product product;
    char single_stock_product[400];
    printf("-----------------------------------------\n");
    printf("%s\t %s\t\t %s\n", "Id", "Name", "Quantity");
    printf("-----------------------------------------\n");

    while (fgets(single_stock_product, sizeof(single_stock_product), productTable) != NULL) {
      sscanf(single_stock_product, "%d, %99[^,], %*[^,], %f, %d", &product.id, product.name, &product.price, &product.quantity);
      printf("%d\t %s\t\t %d\n", product.id, product.name, product.quantity);
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
            search_stock_product_by_ID();
            break;
        case 3:
            view_single_stock_product();
            break;
            
    }
   }