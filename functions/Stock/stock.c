#include<stdio.h>
#include<string.h>
typedef struct {
  int id;
  char name[100];
  char description[300];
// float price;
  int quantity;
} Product;

void search_stock_product(){
     int product_stock_id;
    printf("Insert the Product ID: ");
    scanf("%d",&product_stock_id);
    FILE *productTable;
    productTable = fopen("../../data/products.txt", "r");
    Product product;
    char search_st_product[400];
    printf("%s\t %s\t\t %s\n", "Id", "Name", "Description");
    printf("--\t --\t\t --\n");

    while (fgets(search_st_product, sizeof(search_st_product), productTable) != NULL) {
      sscanf(search_st_product, "%d, %99[^,], %299[^,]", &product.id, product.name,
            product.description);
        if(product_stock_id == product.id){
      printf("%d\t %s\t %s", product.id, product.name, product.description);}
    }
    fclose(productTable);
}
 void view_all_stock_product(){
    FILE *productTable;
    productTable = fopen("../../data/products.txt", "r");
    Product product;
    char view_stock_product[400];
    printf("%s\t %s\t\t %s\n", "Id", "Name", "Description");
    printf("--\t --\t\t --\n");

    while (fgets(view_stock_product, sizeof(view_stock_product), productTable) != NULL) {
      sscanf(view_stock_product, "%d, %99[^,], %299[^,]", &product.id, product.name, product.description);
      printf("%d\t %s\t %s", product.id, product.name, product.description);
    }
    fclose(productTable);
 }
 void view_single_stock_product(){
    int product_stock_id;
    printf("Insert the Product ID: ");
    scanf("%d",&product_stock_id);
    FILE *productTable;
    productTable = fopen("../../data/products.txt", "r");
    Product product;
    char single_stock_product[400];
    printf("%s\t %s\t\t %s\n", "Id", "Name", "Description");
    printf("--\t --\t\t --\n");

    while (fgets(single_stock_product, sizeof(single_stock_product), productTable) != NULL) {
      sscanf(single_stock_product, "%d, %99[^,], %299[^,]", &product.id, product.name,
            product.description);
        if(product_stock_id == product.id){
      printf("%d\t %s\t %s", product.id, product.name, product.description);}
    }
    fclose(productTable);
 }
 int main(){
    int operation;
    printf("1.Search products\n");
    printf("2.view all products\n");
    printf("3.view single product\n");
    printf("Insert the operation :");
    scanf("%d",&operation);
    
    switch (operation){
        case 1:
            search_stock_product();
            break;
        case 2:
            view_all_stock_product();
            break;
        case 3:
            view_single_stock_product();
            break;
    }
}