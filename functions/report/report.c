#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[100];
    char description[300];
    char cost_price[20];
    char selling_price[20];
    char supplier_id[20];
} Product;

typedef struct {
    int st_id;
    int id;
    int quantity;
    int warehouse_id;
    char expire_date[20];
} Stock;

typedef struct {
    int search_count;
    int product_id;
    char product_name[100];
} SearchLog;

// List all product
int productDetails()
{
    FILE *productTable;
    productTable = fopen("../../data/products.txt", "r");
    FILE *stockTable;
    stockTable = fopen("../../data/stock.txt", "r");
    if (productTable == NULL || stockTable == NULL)
    {
        return 1;
    }

    Product product;
    Stock stock;
    char product_line[400];
    char stock_line[400];

    printf("--------------------------------------------------------------------------------------------\n");
    printf("%s\t %s\t\t %s\t\t %s\t %s\n", "Id", "Name", "Description", "Selling Price", "Quantity");
    printf("---\t ---\t\t ---\t\t\t ---\t ---\n");

    while (fgets(product_line, sizeof(product_line), productTable) != NULL)
    {   
        sscanf(product_line, "%d, %99[^,], %299[^,], %19[^,], %19[^,], %19[^,],", &product.id, product.name, product.description, &product.cost_price, &product.selling_price, &product.supplier_id);
        int total_quentity = 0;
        rewind(stockTable);
        while (fgets(stock_line, sizeof(stock_line), stockTable) != NULL) {
            sscanf(stock_line, "%d,%d,%d,%d,%s", &stock.st_id, &stock.id, &stock.quantity, &stock.warehouse_id, stock.expire_date);
            if (product.id == stock.id) {
                total_quentity += stock.quantity;
            }
        }
            printf("%d\t %s\t\t %s\t\t\t %.2f\t %d\n", product.id, product.name, product.description, product.selling_price, total_quentity);  
    }

    fclose(productTable);
    fclose(stockTable);
}

// List most search products
int search_log_compare(const void *a, const void *b)
{
    SearchLog *logA = (SearchLog *)a;
    SearchLog *logB = (SearchLog *)b;
    return logB->search_count - logA->search_count;
}
void get_most_searched_product()
{
    FILE *searchLogTable;
    searchLogTable = fopen("../../data/search_log.txt", "r");
    FILE *searchIdLogTable;
    searchIdLogTable = fopen("../../data/search_by_id_log.txt", "r");
    if (searchLogTable == NULL || searchIdLogTable == NULL)
    {
        printf("Couldn't open");
    }

    SearchLog search_logs[1000] = {0};
    int product_id;
    char product_name[100];
    char search_log_line[400];
    int search_logs_count = 0;

    while (fgets(search_log_line, sizeof(search_log_line), searchLogTable) != NULL) {
    sscanf(search_log_line, "%99[^\n]", product_name);

    int found = 0;
    for (int i = 0; i < search_logs_count; i++) {
        if (strcmp(search_logs[i].product_name, product_name) == 0) {
            search_logs[i].search_count++;
            found = 1;
            break;
    }
    }

    if (!found) {
        strcpy(search_logs[search_logs_count].product_name, product_name);
        search_logs[search_logs_count].search_count = 1;
        search_logs_count++;
    }
    qsort(search_logs, search_logs_count, sizeof(SearchLog), search_log_compare);

    printf("Most searched products || Search Count\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < 3 && i < search_logs_count; i++) {
        printf("%-20s || %d\n", search_logs[i].product_name, search_logs[i].search_count);
    }
    fclose(searchLogTable);
    }
}


//     while (fgets(search_log_line, sizeof(search_log_line), searchLogTable) != NULL)
//     {
//         sscanf(search_log_line, "%d", &product_id);
//         search_logs[product_id].product_id = product_id;
//         search_logs[product_id].search_count++;
//     }

//     while (fgets(search_log_line, sizeof(search_log_line), searchLogTable) != NULL) {
//         sscanf(search_log_line, "%99[^\n]", product_name);
//         Product product = get_product_by_name(product_name);
// if (product.id != -1) {
// search_logs[product.id].product_id = product.id;
// strcpy(search_logs[product.id].product_name, product.name);
// search_logs[product.id].search_count++;
// }
    
//     int max_search_count = 0;
//     int most_searched_product_id = -1;

//     for (int i = 0; i < 1000; i++) { if (search_logs[i].search_count > max_search_count) {
//             max_search_count = search_logs[i].search_count;
//             most_searched_product_id = search_logs[i].product_id;
//         }
//     }

//     if (most_searched_product_id != -1) {
//         printf("Most searched product: %s (ID: %d) with %d searches\n", search_logs[most_searched_product_id].product_name, most_searched_product_id, max_search_count);
//     } else {
//         printf("No search data available\n");


// fclose(searchLogTable);
// fclose(searchIdLogTable);


// List low stock products
void get_low_stock_products()
{
    FILE *productTable;
    productTable = fopen("products.txt", "r");
    Product product;
    Stock stock;
    char line[400];
    printf("%s\t %s\t\t %s\t\t %s\t %s\n", "Id", "Name", "Description", "Price", "Stock");
    printf("--\t --\t\t --\t\t --\t --\n");

    while (fgets(line, sizeof(line), productTable) != NULL)
    {
        sscanf(line, "%d, %99[^,], %299[^,], %f, %d", &product.id, product.name,
               product.description, &product.selling_price, &stock.quantity);
        if (stock.quantity < 10)
        {
            printf("%d\t %s\t %s\t %.2f\t %d\n", product.id, product.name, product.description, product.selling_price, stock.quantity);
        }
    }
    fclose(productTable);
}

// List expiring products
void get_expiring_items()
{
    FILE *productTable;
    productTable = fopen("products.txt", "r");
    Product product;
    Stock stock;
    char line[400];
    printf("%s\t %s\t\t %s\t\t %s\t %s\n", "Id", "Name", "Description", "Price", "Expiry Date");
    printf("--\t --\t\t --\t\t --\t --\n");

    while (fgets(line, sizeof(line), productTable) != NULL)
    {
        sscanf(line, "%d, %99[^,], %299[^,], %f, %d", &product.id, product.name,
               product.description, &product.selling_price, &stock.quantity);
        if (stock.quantity > 0)
        {
            printf("%d\t %s\t %s\t %.2f\t %s\n", product.id, product.name, product.description, product.selling_price, "30/06/2022");
        }
    }
    fclose(productTable);
}

//sales profit
void view_sales_profit()
{

}

int main(){
  int operation;

  printf("\n");
  printf("\033[1;34mREPORT\033[0m\n\n");
  printf("\033[1mOperations\033[0m\n\n");
  printf("\033[1m-------------------------------\033[0m\n");
  printf("\033[1;32m+\033[0m 1 -List all products\n");
  printf("\033[1;36m?\033[0m 2 -List most seached products\n");
  printf("\033[1;34m?\033[0m 3 -List low stock products\n");
  printf("\033[1;34m?\033[0m 4 -List expiring products\n");
  printf("\033[1;34m?\033[0m 5 -View sales profit\n");
  printf("\033[1m-------------------------------\033[0m\n\n");
  printf("Insert the operation: ");
  scanf("%d", &operation);

  switch (operation) {
    case 1:
        productDetails();
        break;
    case 2:
        get_most_searched_product();
        break;
    case 3:
        get_low_stock_products();
        break;
    case 4:
        get_expiring_items();
        break;
    case 5:
        view_sales_profit();
        break;
  }
  return 0;
}