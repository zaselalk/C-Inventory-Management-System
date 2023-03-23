#include<stdio.h>
#include<string.h>
#define PRODUCT_TABLE "./data/products.txt"

typedef struct {
  int id;
  char name[50];
  char description[100];
  float price;
  int quantity;
} Product;

void add_product(Product product) {

  // open products.txt in append mode
  FILE *file = fopen(PRODUCT_TABLE, "a");

  if (file == NULL) {
    printf("Error opening file!\n");
    return;
  }

  // write product to file
  fprintf(file, "%d %s %s %f %d \n", product.id, product.name,
          product.description, product.price, product.quantity);

  // close file
  fclose(file);
}

void list_products(int limit) {

  // open products.txt in read mode
  FILE *file = fopen(PRODUCT_TABLE, "r");

  if (file == NULL) {
    printf("Error opening file!\n");
    return;
  }

  // read products from file
  Product product;
  int count = 0;
  while (fscanf(file, "%d %[^\n] %[^\n] %f %d", &product.id, product.name,
                product.description, &product.price,
                &product.quantity) != EOF) {
    printf("%d %s %s %f %d\n\n", product.id, product.name, product.description,
           product.price, product.quantity);
    printf("\n");
    count++;
    if (count >= limit) {
      break;
    }
  }

  // close file
  fclose(file);
}

void search_product(){
  
}
 void view_all_product(Product product){
    printf("\tid,\tname,\tdescription,\tprice,\tquantity");
    FILE *prod;
    prod=fopen("./data/products.txt","r");
    char prd_array[100];
    while(fgets(prd_array,100,prod)){
        printf("%d %s %s %f %d \n", product.id, product.name,
          product.description, product.price, product.quantity);
    }

 }
 void view_single_product(){

 }
 int main(){
    int operation;
    printf("1.Search products");
    printf("2.view all products");
    printf("3.view single product");
    printf("Insert the operation :");
    scanf("%d",&operation);
    
    switch (operation){
        case 1:
            void search_product();
            break;
        case 2:
            void view_all_product();
            break;
        case 3:
            void view_single_product();
            break;
    }
}