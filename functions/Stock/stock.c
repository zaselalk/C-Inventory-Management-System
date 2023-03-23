#include<stdio.h>
#include<string.h>
int main(){
    // int search_pr;
    // int view_all;
    // int view_single;
    int operation;
    printf("1.Search products")
    printf("2.view all products")
    printf("3.view single product")
    printf("Insert the operation :")
    scanf("%d",%operation);
    switch (operation){
        case 1:
            void search_product();
            break;
        case 2:
            void view_all_product();
            break;
        case 3:
            void view_single_product();
            break;
    }

    

}
void search_product(){
  
}
 void view_all_product(){
    FILE *prod;
    prod=fopen("./data/produts.txt","r");
    char prd_array[100];
    while(fgets(prd_array,100,prod)){
        printf("%s",prd_array);
    }

 }
 void view_single_product(){

 }