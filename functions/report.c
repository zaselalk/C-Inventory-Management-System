#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// List all product
int productDetails()
{
    FILE *productTable;
    productTable = fopen("./data/products.txt", "r");
    FILE *stockTable;
    stockTable = fopen("./data/stock.txt", "r");
    if (productTable == NULL || stockTable == NULL)
    {
        return 1;
    }

    Product product;
    Stock stock;
    char product_line[400];
    char stock_line[400];

    printf("---------------------------------------------------------------------------\n");
    printf("%s\t %s\t\t %s\t\t %s\t %s\n", "Id", "Name", "Description", "Selling Price", "Quantity");
    printf("---\t ---\t\t ---\t\t\t ---\t\t ---\n");

    while (fgets(product_line, sizeof(product_line), productTable) != NULL)
    {
        sscanf(product_line, "%d, %99[^,], %299[^,], %19[^,], %s, %s", &product.id, product.name, product.description, &product.cost_price, &product.selling_price);
        int total_quentity = 0;
        rewind(stockTable);
        while (fgets(stock_line, sizeof(stock_line), stockTable) != NULL)
        {
            sscanf(stock_line, "%d,%d,%d,%d,%s", &stock.st_id, &stock.id, &stock.quantity, &stock.warehouse_id, stock.expire_date);
            if (product.id == stock.id)
            {
                total_quentity += stock.quantity;
            }
        }
        printf("%d\t %s\t\t %s\t\t\t %s\t\t %d\n", product.id, product.name, product.description, product.selling_price, total_quentity);
    }

    fclose(productTable);
    fclose(stockTable);
}

// List most search products
void get_most_searched_product()
{
    FILE *searchLogTable;
    searchLogTable = fopen("./data/search_log.txt", "r");
    FILE *searchIdLogTable;
    searchIdLogTable = fopen("./data/search_by_id_log.txt", "r");
    if (searchLogTable == NULL || searchIdLogTable == NULL)
    {
        printf("Couldn't open");
    }

    char product_name[100];
    int search_count = 0;
    char search_log_line[400];
    char most_appeared_names[3][100];
    int most_appeared_count[3] = {0};

    while (fgets(search_log_line, sizeof(search_log_line), searchLogTable) != NULL)
    {
        sscanf(search_log_line, "%99[^\n]", product_name);

        int index = -1;
        for (int i = 0; i < 3; i++)
        {
            if (strcmp(product_name, most_appeared_names[i]) == 0)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            most_appeared_count[index]++;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                if (search_count > most_appeared_count[i])
                {
                    for (int j = 2; j > i; j--)
                    {
                        most_appeared_count[j] = most_appeared_count[j - 1];
                        strcpy(most_appeared_names[j], most_appeared_names[j - 1]);
                    }
                    most_appeared_count[i] = search_count;
                    strcpy(most_appeared_names[i], product_name);
                    break;
                }
            }
            search_count = 1;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (search_count > most_appeared_count[i])
        {
            for (int j = 2; j > i; j--)
            {
                most_appeared_count[j] = most_appeared_count[j - 1];
                strcpy(most_appeared_names[j], most_appeared_names[j - 1]);
            }
            most_appeared_count[i] = search_count;
            strcpy(most_appeared_names[i], product_name);
            break;
        }
    }
    int product_id;
    search_count = 0;
    char log_by_id_line[400];
    int most_appeared_ids[3] = {0};
    int most_appeared_id_count[3] = {0};

    while (fgets(log_by_id_line, sizeof(log_by_id_line), searchIdLogTable) != NULL)
    {
        sscanf(log_by_id_line, "%d", &product_id);

        int index = -1;
        for (int i = 0; i < 3; i++)
        {
            if (product_id == most_appeared_ids[i])
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            most_appeared_id_count[index]++;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                if (search_count > most_appeared_id_count[i])
                {
                    for (int j = 2; j > i; j--)
                    {
                        most_appeared_id_count[j] = most_appeared_id_count[j - 1];
                        most_appeared_ids[j] = most_appeared_ids[j - 1];
                    }
                    most_appeared_id_count[i] = search_count;
                    most_appeared_ids[i] = product_id;
                    break;
                }
            }
            search_count = 1;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (search_count > most_appeared_id_count[i])
        {
            for (int j = 2; j > i; j--)
            {
                most_appeared_id_count[j] = most_appeared_id_count[j - 1];
                most_appeared_ids[j] = most_appeared_ids[j - 1];
            }
            most_appeared_id_count[i] = search_count;
            most_appeared_ids[i] = product_id;
            break;
        }
    }

    printf("\e[0;31m----------------------------------------------------------------------------------------------\e[0;37m\n");
    printf("Most searched ids\t\e[0;31m |\e[0;37m\tCount\t\e[0;31m |\e[0;37m\tMost searched products\t\e[0;31m |\e[0;37m\tCount\n");
    printf("\e[0;31m----------------------------------------------------------------------------------------------\e[0;37m\n");
    for (int i = 0; i < 3; i++)
    {
        printf("\t%d\t\t\e[0;31m |\e[0;37m\t%d times\t\e[0;31m |\e[0;37m\t", most_appeared_ids[i], most_appeared_id_count[i]);
        printf("\t%s\t\t\e[0;31m |\e[0;37m\t%d times\n", most_appeared_names[i], most_appeared_count[i]);
    }
    printf("\e[0;31m----------------------------------------------------------------------------------------------\e[0;37m\n");
    fclose(searchLogTable);
    fclose(searchIdLogTable);
}
// Get low stock products
int get_low_stock_products()
{
    FILE *productTable;
    productTable = fopen("./data/products.txt", "r");
    FILE *stockTable;
    stockTable = fopen("./data/stock.txt", "r");
    if (productTable == NULL || stockTable == NULL)
    {
        return 1;
    }

    Product product;
    Stock stock;
    char product_line[400];
    char stock_line[400];

    printf("-----------------------------------------------------------------\n");
    printf("%s\t %s\t\t %s\t\t %s\n", "Id", "Name", "Description", "Quantity Left");
    printf("---\t ---\t\t ---\t\t\t ------\n");

    while (fgets(product_line, sizeof(product_line), productTable) != NULL)
    {
        sscanf(product_line, "%d, %99[^,], %299[^,], %19[^,], %19[^,]", &product.id, product.name, product.description, &product.cost_price, &product.selling_price);
        int total_quentity = 0;
        rewind(stockTable);
        while (fgets(stock_line, sizeof(stock_line), stockTable) != NULL)
        {
            sscanf(stock_line, "%d,%d,%d,%d,%s", &stock.st_id, &stock.id, &stock.quantity, &stock.warehouse_id, stock.expire_date);
            if (product.id == stock.id)
            {
                total_quentity += stock.quantity;
            }
        }
        if (total_quentity <= 10)
        {
            printf("%d\t %s\t\t %s\t\t\t %d\n", product.id, product.name, product.description, total_quentity);
        }
    }

    fclose(productTable);
    fclose(stockTable);
}

// List expiring products
int get_expiring_items()
{
    FILE *productTable;
    productTable = fopen("./data/products.txt", "r");
    FILE *stockTable;
    stockTable = fopen("./data/stock.txt", "r");
    if (productTable == NULL || stockTable == NULL)
    {
        return 1;
    }

    Product product;
    Stock stock;
    char product_line[400];
    char stock_line[400];

    // get the current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("-----------------------------------------------------------------\n");
    printf("%s\t %s\t\t %s\t\t %s\n", "Id", "Name", "Description", "Days Left to expire");
    printf("---\t ---\t\t ---\t\t\t ------\n");

    while (fgets(product_line, sizeof(product_line), productTable) != NULL)
    {
        sscanf(product_line, "%d, %99[^,], %299[^,], %19[^,], %19[^,]", &product.id, product.name, product.description, &product.cost_price, &product.selling_price);
        rewind(stockTable);
        while (fgets(stock_line, sizeof(stock_line), stockTable) != NULL)
        {
            sscanf(stock_line, "%d,%d,%d,%d,%s", &stock.st_id, &stock.id, &stock.quantity, &stock.warehouse_id, stock.expire_date);
            if (product.id == stock.id)
            {
                int year, month, day;
                if (sscanf(stock.expire_date, "%d/%d/%d", &year, &month, &day) == 3)
                {
                    struct tm expire_tm = {0};
                    expire_tm.tm_year = year - 1900;
                    expire_tm.tm_mon = month - 1;
                    expire_tm.tm_mday = day;
                    time_t expire_t = mktime(&expire_tm);
                    double diff = difftime(expire_t, t);
                    int days_left = (int)(diff / (24 * 60 * 60));
                    if (days_left <= 50)
                    {
                        printf("%d\t %s\t\t %s\t\t\t %d\n", product.id, product.name, product.description, days_left);
                    }
                }
            }
        }
    }

    fclose(productTable);
    fclose(stockTable);
    return 0;
}

int manage_reports()
{
    int operation;

    do{
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

    switch (operation)
    {
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
        // view_sales_profit();
        break;
    }
    } while(true);

   
    return 0;
}