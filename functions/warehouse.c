#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_txt(int warehouse_id, char *warehouse_name, char *warehouse_location)
{
	FILE *file_write;
	file_write = fopen("./data/wh_products.txt", "a");
	fprintf(file_write,"%d,%s,%s\n",warehouse_id,warehouse_name,warehouse_location);
	fclose(file_write);
}

typedef struct
{
	int warehouse_id;
	char warehouse_name[50];
	char warehouse_location[50];
}wh_add;

void add_warehouse()
{
	wh_add warehouse;
	printf("Enter warehouse ID:");
	scanf("%d",&warehouse.warehouse_id);
	getchar();

	printf("Enter warehouse name:");
	scanf("%s",warehouse.warehouse_name);
	getchar();

	printf("Enter warehouse location:");
	scanf("%s",warehouse.warehouse_location);
	getchar();

	get_txt(warehouse.warehouse_id, warehouse.warehouse_name, warehouse.warehouse_location);
}

void display_warehouse()

{
	int warehouse_id;
	char warehouse_name[200];
	char warehouse_location[200];
	
	FILE *file_read;
	file_read = fopen("./data/wh_products.txt", "r");
	char text_store[200];
	while (fgets(text_store, 200, file_read) != NULL)
	{
		sscanf(text_store,"%d, %49[^,], %49[^,]",&warehouse_id,warehouse_name,warehouse_location);	

		printf("%d\t         %s\t         %s\t\t\t\n",warehouse_id,warehouse_name,warehouse_location);
	}
	fclose(file_read);
}

void delete_warehouse(int find_id)
{
	FILE *warehouse_ta=fopen("./data/wh_products.txt", "r");
	FILE *warehouse_tanew=fopen("wh_newproducts.txt", "w");

	int warehouse_id;
	char warehouse_name[200];
	char warehouse_location[200];
	char content[400];

	 while (fgets(content, 400, warehouse_ta) != NULL)
    {
        sscanf(content, "%d, %[^,], %[^,]", &warehouse_id, warehouse_name, warehouse_location);

        if (find_id == warehouse_id)
        {
            continue;
        }
        else
        {
            fprintf(warehouse_tanew, "%d, %s, %s", warehouse_id, warehouse_name, warehouse_location);
        }
    }


	fclose(warehouse_ta);
	fclose(warehouse_tanew);
	remove("./data/wh_products.txt");
	rename("wh_newproducts.txt","./data/wh_products.txt");
}

void get_id()
{
	int find_id;
	printf("Enter id for delete:");
	scanf("%d",&find_id);
	delete_warehouse(find_id);
}

void up_id(int new_id,char *new_name,char *new_location)
{
	FILE *old_file=fopen("./data/wh_products.txt", "r");
	FILE *up_file=fopen("wh_newproducts.txt", "w");


	int warehouse_id;
	char warehouse_name[200];
	char warehouse_location[200];
	char content[400];

	 while (fgets(content, 400, old_file) != NULL)
    {
        sscanf(content, "%d, %[^,], %[^,]", &warehouse_id, warehouse_id, warehouse_location);

        if (new_id == warehouse_id)
        {
            fprintf(up_file, "%d, %s, %s\n", new_id, new_name, new_location);
        }
        else
        {
            fprintf(up_file, "%d, %s, %s\n", warehouse_id, warehouse_name, warehouse_location);
        }
    } 
	fclose(old_file);
	fclose(up_file);
	remove("./data/wh_products.txt");
	rename("wh_newproducts.txt","./data/wh_products.txt");
}
void take_id()
{
	int new_id;
	char new_name[200];
	char new_location[200];

	printf("Enter id for update:");
	scanf("%d",&new_id);
	printf("Enter w_name for update:");
	scanf("%s",new_name);
	printf("Enter w_location:");
	scanf("%s",new_location);

	up_id(new_id, new_name, new_location);
}

int manage_warehouse()
{
	int choise;
	do
	{
		printf("------------------------------------\n");
		printf("1. Add warehouse\n");
		printf("2. Display warehouse\n");
		printf("3. Delete  warehouse\n");
		printf("4. Update warehouse\n");
		printf("5. Exit\n");
		printf("------------------------------------\n");
		printf("Please enter your choise:");
		scanf("%d", &choise);
		switch (choise)
		{
		case 1:
			add_warehouse();
			break;
		case 2:
			printf("=============================================================\n");
			printf("Warehouse id\t Warehouse name\t Warehouse location\t\n");
			printf("=============================================================\n");
			display_warehouse();
			break;
		case 3:
			get_id();
			break;
		case 4:
			take_id();
			break;
		case 5:
			printf("Goodbye!\n");
			break;
		default:
			printf("Invalid warehouse\n");
			break;
		}
	} while (choise != 5);
	return 0;
}
