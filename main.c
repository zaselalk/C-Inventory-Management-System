#include "./functions/products/product.c"
#include <stdio.h>

int main() {
  printf("Hello World!\n");
  Product product = {1, "Product 1", "Description 1", 10.0, 10};
  add_product(product);
  list_products(5);
  return 0;
}