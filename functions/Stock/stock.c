#include<stdio.h>
#include<string.h>
typedef struct {
  int id;
  char name[100];
  char description[300];
  float price;
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
    printf("1.Search products\n");
    printf("2.view all products\n");
    printf("3.view single product\n");
    printf("Insert the operation :");
    scanf("%d",&operation);}
    while((operation > 3 )|| (operation < 0));
    
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