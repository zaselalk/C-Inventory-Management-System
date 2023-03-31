#include "./functions/product.c"
#include "./functions/stock.c"
#include <stdio.h>
#include <stdlib.h>
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main() {
  system("clear");
  // printf("Hello Welcome!\n");
  // printf("01 - Manage Products \n");
  // printf("02 - Managemenet Stocks \n");
  // printf("03 - Manage Suppliers \n");
  // printf("04 - Warehouse Management \n");
  // printf("05 - Order Management \n");
  // printf("06 - Seller Management \n");
  // printf("07 - Reports \n");

  printf(ANSI_COLOR_GREEN "Hello Welcome!" ANSI_COLOR_RESET "\n");

  printf("+----+------------------------+\n");
  printf("| %2d | %-22s |\n", 1, "Manage Products");
  printf("| %2d | %-22s |\n", 2, "Management Stocks");
  printf("| %2d | %-22s |\n", 3, "Manage Suppliers");
  printf("| %2d | %-22s |\n", 4, "Warehouse Management");
  printf("| %2d | %-22s |\n", 5, "Order Management");
  printf("| %2d | %-22s |\n", 6, "Seller Management");
  printf("| %2d | %-22s |\n", 7, "Reports");
  printf("+----+------------------------+\n");

  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    printf("Manage Products\n");
    break;
  case 2:
    system("clear");
    manage_stock();
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