#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void get_txt(int product_id,char*product_name,int product_quantity,float product_price){
    FILE*file_write;
    file_write=fopen("wh_products.txt", "a");
    fprintf(file_write, "%d , %s , %d , %.2f\n" ,product_id,product_name,product_quantity,product_price);
    fclose(file_write);
}


typedef struct{
	 int product_id;
	 char product_name[50];
	 int product_quantity;
	 float product_price; 
}dil;	

void add_item(){
	dil warehouse;
	printf("Enter item ID:");
	scanf("%d",&warehouse.product_id);
	getchar();

	printf("Enter item name:");
	scanf("%s",warehouse.product_name);
	getchar();

	printf("Enter item quantity:");
	scanf("%d",&warehouse.product_quantity);
	getchar();

	printf("Enter item price:");
	scanf("%f",&warehouse.product_price);
	getchar();	

	get_txt(warehouse.product_id, warehouse.product_name, warehouse.product_quantity, warehouse.product_price);
}



void display_item(){
	 FILE*file_read;
	 file_read=fopen("wh_products.txt","r");
	 char text_store[200];
	 while (fgets(text_store,200,file_read) !=NULL)
	 {
		
		printf("%s\n",text_store);
		
	}
	fclose(file_read);
	
}


void delete_item(int find_id){
	FILE *product_ta=fopen("wh_products.txt","r");
	FILE *product_tanew=fopen("wh_newproducts.txt","w");

	int product_id;
	char product_name[50];
	int product_quantity;
	float product_price; 
	char content[400];

	while (fgets(content,400,product_ta) !=NULL)
	{
		sscanf(content, "%d ,  %[^,] , %d , %f" ,&product_id,product_name,&product_quantity,&product_price);

		if (find_id==product_id)
		{
			    continue;
		}
	else{
			fprintf(product_tanew, "%d , %s , %d, %.2f\n" ,product_id,product_name,product_quantity,product_price);
			  
		}
	
	}

	fclose(product_ta);
	fclose(product_tanew); 
	remove("wh_products.txt");
	rename("wh_newproducts.txt", "wh_products.txt"); 
	
}

void get_id(){
	int find_id;
	printf("Enter id for delete:");
	scanf("%d",&find_id);
    delete_item(find_id);

}

void up_id(int new_id, char *new_name,int new_quantity,float new_price){
	FILE *old_file=fopen("wh_products.txt","r");
	FILE *up_file=fopen("wh_newproducts.txt","w");
	printf("hello");

	int product_id;
	char product_name[50];
	int product_quantity;
	float product_price; 
	char content[400];
	

	while ( fgets(content,400,old_file) !=NULL)
	{

		sscanf(content," %d , %[^,] , %d , %f ",&product_id,product_name,&product_quantity,&product_price);

		 if (new_id==product_id)
		 {
			 
			fprintf(up_file," %d , %s , %d , %.2f \n",new_id,new_name,new_quantity,new_price);
			
		 }
		 else{
			fprintf(up_file,"%d , %s , %d , %.2f\n",&product_id,product_name,&product_quantity,&product_price);
		 }
	}
	fclose(old_file);
	fclose(up_file);
	remove("wh_products.txt");
	rename("wh_newproducts.txt","wh_products.txt");

}
void take_id(){
	int new_id;
	char  *new_name;
	int new_quantity;
	float new_price;
	printf("Enter id for update:");
	scanf("%d",&new_id);
	printf("Enter P_name for update:");
	scanf("%s",new_name);
	printf("Enter P_quantity:");
	scanf("%d",&new_quantity);
	printf("Enter p_price:");
	scanf("%f",&new_price);

	up_id(new_id,new_name,new_quantity,new_price);
	
}

int main(){
	int choise;
	do{
		 printf("------------------------------------\n");
		 printf("1. Add item\n");
		 printf("2. Display items\n");
		 printf("3. Delete  items\n");
		 printf("4. Update items\n");
		 printf("5. Exit\n");
		 printf("------------------------------------\n");
		 printf("Please enter your choise:");
		 scanf("%d",&choise);
		 switch(choise){
		 	case 1:
		 		add_item();
		 		break;
		 	case 2:
				//printf("P_id\t p_name\t p_quntity\t p_price");
		 		display_item();
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
		 		printf("Invalid choise\n");
		 		break;
		 }
	}
	while(choise !=5);
return 0;
}






