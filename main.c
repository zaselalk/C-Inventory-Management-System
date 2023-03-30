// #include "./functions/products/product.c"
#include <stdio.h>

int main() {
  printf("Hello Welcome!\n");
  printf("01 - Manage Products \n");
  printf("02 - Managemenet Stocks \n");
  printf("03 - Manage Suppliers \n");
  printf("04 - Warehouse Management \n");
  printf("05 - Order Management \n");
  printf("06 - Seller Management \n");
  printf("07 - Reports \n");

  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    printf("Manage Products\n");
    break;
  case 2:
    printf("Managemenet Stocks\n");
    break;
  case 3:
    printf("Manage Suppliers\n");
    break;
  case 4:
    printf("Warehouse Management\n");
    break;
  case 5:
    printf("Order Management\n");
    break;
  case 6:
    printf("Seller Management\n");
    break;
  case 7:
    printf("Reports\n");
    break;
  default:
    printf("Invalid choice\n");
    break;
  }

  return 0;
}