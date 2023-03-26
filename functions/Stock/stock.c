#include<stdio.h>
#include<string.h>
// #define PRODUCT_TABLE "./data/products.txt"
//  void search_product();
//  void view_all_product();
//  void view_single_product();

typedef struct {
  int id;
  char name[100];
  char description[300];
//   float price;
  int quantity;
} Product;

void search_product(){
  
}
 void view_all_product(){
    // Product product;
    // printf("\tid,\tname,\tquantity");
    // FILE *prod;
    // prod=fopen("./data/products.txt","r");
    // char prd_array[100];
    // while(fgets(prd_array,100,prod)){
    //     sscanf(prd_array, "%d, %99[^,], %d", &product.id, product.name,
    //        product.quantity);
    //     printf("%d %s %d \n", product.id, product.name, product.quantity);
    // }
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
 void view_single_product(){

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
            search_product();
            break;
        case 2:
            view_all_product();
            break;
        case 3:
            view_single_product();
            break;
    }
}