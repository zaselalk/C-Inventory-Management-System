#include <stdio.h>
#include <string.h>

typedef struct {
  int order_id;
  int product_id;
  char seller_name[100];
  char product_name[100];
  float unit_price;
  int quantity;
} SellerOrder;

typedef struct {
  int order_id;
  int product_id;
  char supplier_name[100];
  char product_name[100];
  float unit_price;
  int quantity;
} SupplierOrder;

int get_order_id() {
  FILE *orderTable;
  orderTable = fopen("orders.txt", "r");

  if (orderTable == NULL) {
    return 1;
  }

  int last_id = 0;
  char line[400];

  while (fgets(line, sizeof(line), orderTable) != NULL) {
    sscanf(line, "%d", &last_id);
  }

  return last_id + 1;
}

void add_seller_order() {
  SellerOrder order;
  FILE *orderTable;

  printf("Enter product id: ");
  scanf("%d", &order.product_id);
  getchar();

  printf("Enter seller name: ");
  fgets(order.seller_name, sizeof(order.seller_name), stdin);

  printf("Enter product name: ");
  fgets(order.product_name, sizeof(order.product_name), stdin);

  printf("Enter unit price: ");
  scanf("%f", &order.unit_price);

  printf("Enter quantity: ");
  scanf("%d", &order.quantity);

  order.order_id = get_order_id("seller_orders.txt");

  orderTable = fopen("seller_orders.txt", "a");
  if (orderTable == NULL) {
    printf("Error opening seller_orders.txt file\n");
    return;
  }

  int ret = fprintf(orderTable, "%d,%d,%s,%s,%.2f,%d", order.order_id,
                    order.product_id, order.seller_name, order.product_name,
                    order.unit_price, order.quantity);
  if (ret < 0) {
    printf("Error writing to seller_orders.txt file\n");
  }

  fclose(orderTable);
}

void add_supplier_order() {
  SupplierOrder order;
  FILE *orderTable;

  printf("Enter product id: ");
  scanf("%d", &order.product_id);
  getchar();

  printf("Enter supplier name: ");
  fgets(order.supplier_name, sizeof(order.supplier_name), stdin);

  printf("Enter product name: ");
  fgets(order.product_name, sizeof(order.product_name), stdin);

  printf("Enter unit price: ");
  scanf("%f", &order.unit_price);

  printf("Enter quantity: ");
  scanf("%d", &order.quantity);

  order.order_id = get_order_id("supplier_orders.txt");

  orderTable = fopen("supplier_orders.txt", "a");
  if (orderTable == NULL) {
    printf("Error opening supplier_orders.txt file\n");
    return;
  }

  int ret = fprintf(orderTable, "%d,%d,%s,%s,%.2f,%d", order.order_id,
                    order.product_id, order.supplier_name, order.product_name,
                    order.unit_price, order.quantity);
  if (ret < 0) {
    printf("Error writing to supplier_orders.txt file\n");
  }

  fclose(orderTable);
}

void view_seller_orders() {
  FILE *orderTable;
  orderTable = fopen("seller_orders.txt", "r");

  if (orderTable == NULL) {
    printf("Error opening seller_orders.txt file\n");
    return;
  }

  char line[400];

  while (fgets(line, sizeof(line), orderTable) != NULL) {
    SellerOrder order;

    sscanf(line, "%d,%d,%[^,],%[^,],%f,%d", &order.order_id, &order.product_id,
           order.seller_name, order.product_name, &order.unit_price,
           &order.quantity);

    printf("Order ID: %d\n", order.order_id);
    printf("Product ID: %d\n", order.product_id);
    printf("Seller Name: %s", order.seller_name);
    printf("Product Name: %s", order.product_name);
    printf("Unit Price: %.2f\n", order.unit_price);
    printf("Quantity: %d\n", order.quantity);
    printf("\n");
  }

  fclose(orderTable);
}

void view_supplier_orders() {
  FILE *orderTable;
  orderTable = fopen("supplier_orders.txt", "r");

  if (orderTable == NULL) {
    printf("Error opening supplier_orders.txt file\n");
    return;
  }

  char line[400];

  while (fgets(line, sizeof(line), orderTable) != NULL) {
    SupplierOrder order;

    sscanf(line, "%d,%d,%[^,],%[^,],%f,%d", &order.order_id, &order.product_id,
           order.supplier_name, order.product_name, &order.unit_price,
           &order.quantity);

    printf("Order ID: %d\n", order.order_id);
    printf("Product ID: %d\n", order.product_id);
    printf("Supplier Name: %s", order.supplier_name);
    printf("Product Name: %s", order.product_name);
    printf("Unit Price: %.2f\n", order.unit_price);
    printf("Quantity: %d\n", order.quantity);
    printf("\n");
  }

  fclose(orderTable);
}

int manage_orders() {
  int choice = 0;

  do {
    printf("\n\n+-------------------------------+\n");
    printf("|\tOrder Management\t|");
    printf("\n+-------------------------------+\n\n");
    printf("1. Add Seller Order\n");
    printf("2. Add Supplier Order\n");
    printf("3. View Seller Orders\n");
    printf("4. View Supplier Orders\n");
    printf("5. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      add_seller_order();
      break;
    case 2:
      add_supplier_order();
      break;
    case 3:
      view_seller_orders();
      break;
    case 4:
      view_supplier_orders();
      break;
    case 5:
      break;
    default:
      printf("\nInvalid choice, please try again.\n");
      break;
    }
  } while (choice != 5);
}
