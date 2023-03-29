#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char name[100];
    char description[300];
    float price;
    int stock;
} 
Product;

// List all product
void productDetails()
{
    FILE *productTable;
    productTable = fopen("products.txt", "r");
    Product product;
    char line[400];
    printf("%s\t %s\t\t %s\t\t %s\t %s\n", "Id", "Name", "Description", "Price", "Stock");
    printf("--\t --\t\t --\t\t --\t --\n");

    while (fgets(line, sizeof(line), productTable) != NULL)
    {
        sscanf(line, "%d, %99[^,], %299[^,], %f, %d", &product.id, product.name, product.description, &product.price, &product.stock);
        printf("%d\t %s\t %s\t %.2f\t %d\n", product.id, product.name, product.description, product.price, product.stock);
    }
    fclose(productTable);
}

// List most search products
int get_most_searched_product()
{
    FILE *searchHistory;
    searchHistory = fopen("search_history.txt", "r");
    int product_id, search_count, max_search_count = 0, most_searched_product_id = 0;
    char line[100];

    while (fgets(line, sizeof(line), searchHistory) != NULL)
    {
        sscanf(line, "%d, %d", &product_id, &search_count);
        if (search_count > max_search_count)
        {
            max_search_count = search_count;
            most_searched_product_id = product_id;
        }
    }
    fclose(searchHistory);
    return most_searched_product_id;
}

// List low stock products
void get_low_stock_products()
{
    FILE *productTable;
    productTable = fopen("products.txt", "r");
    Product product;
    char line[400];
    printf("%s\t %s\t\t %s\t\t %s\t %s\n", "Id", "Name", "Description", "Price", "Stock");
    printf("--\t --\t\t --\t\t --\t --\n");

    while (fgets(line, sizeof(line), productTable) != NULL)
    {
        sscanf(line, "%d, %99[^,], %299[^,], %f, %d", &product.id, product.name,
               product.description, &product.price, &product.stock);
        if (product.stock < 10)
        {
            printf("%d\t %s\t %s\t %.2f\t %d\n", product.id, product.name, product.description, product.price, product.stock);
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
    char line[400];
    printf("%s\t %s\t\t %s\t\t %s\t %s\n", "Id", "Name", "Description", "Price", "Expiry Date");
    printf("--\t --\t\t --\t\t --\t --\n");

    while (fgets(line, sizeof(line), productTable) != NULL)
    {
        sscanf(line, "%d, %99[^,], %299[^,], %f, %d", &product.id, product.name,
               product.description, &product.price, &product.stock);
        if (product.stock > 0)
        {
            printf("%d\t %s\t %s\t %.2f\t %s\n", product.id, product.name, product.description, product.price, "30/06/2022");
        }
    }
    fclose(productTable);
}
int main(){
    
    return 0;
}

//sales profit
