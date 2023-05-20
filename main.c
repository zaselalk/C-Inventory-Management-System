#include <stdio.h>
#include <stdlib.h>
#include "./types/structures.c"
#include "./functions/product.c"
#include "./functions/seller.c"
#include "./functions/stock.c"
#include "./functions/warehouse.c"
#include "./functions/report.c"

#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

int main() {


  printf(ANSI_COLOR_GREEN "Hello Welcome!" ANSI_COLOR_RESET "\n");

  printf("+----+------------------------+\n");
  printf("| %2d | %-22s |\n", 1, "Manage Products");
  printf("| %2d | %-22s |\n", 2, "Management Stocks");
  printf("| %2d | %-22s |\n", 3, "Manage Suppliers");
  printf("| %2d | %-22s |\n", 4, "Warehouse Management");
  printf("| %2d | %-22s |\n", 5, "Seller Management");
  printf("| %2d | %-22s |\n", 6, "Reports");
  printf("+----+------------------------+\n");

  int choice;
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    manage_product();
    main();
    break;
  case 2:
    manage_stock();
    main();
    break;
  case 3:
    printf("Manage Suppliers\n");
    break;
  case 4:
    printf("Warehouse Management\n");
    manage_warehouse();
    main();
    break;
  case 5:
    printf("Seller Management\n");
    manage_sellers();
    main();
    break;
  case 6:
    manage_reports();
     main();
    break;
  default:
    printf("Invalid choice\n");
    break;
  }

  return 0;
}

void print_menu() {
  printf("+----+------------------------+\n");
  printf("| %2d | %-22s |\n", 1, "Manage Products");
  printf("| %2d | %-22s |\n", 2, "Management Stocks");
  printf("| %2d | %-22s |\n", 3, "Manage Suppliers");
  printf("| %2d | %-22s |\n", 4, "Warehouse Management");
  printf("| %2d | %-22s |\n", 5, "Order Management");
  printf("| %2d | %-22s |\n", 6, "Seller Management");
  printf("| %2d | %-22s |\n", 7, "Reports");
  printf("+----+------------------------+\n");
}