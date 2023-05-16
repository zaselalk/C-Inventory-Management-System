#include <stdio.h>
#include <stdbool.h>

#define MAX_SELLERS 100 

typedef struct Seller {
    int id;               
    char name[50];          
    float rating;           
    bool isActive;         
} Seller;

Seller sellers[MAX_SELLERS]; 
int numSellers = 0;      
FILE *fp; // File pointer

// Function to add a seller
void addSeller() {
    if (numSellers >= MAX_SELLERS) {
        printf("Maximum number of sellers reached!\n");
        return;
    }

    Seller seller;
    printf("Enter seller ID: ");
    scanf("%d", &seller.id);
    printf("Enter seller name: ");
    scanf("%s", seller.name);
    printf("Enter seller rating: ");
    scanf("%f", &seller.rating);
    seller.isActive = true;

    sellers[numSellers++] = seller; 
    printf("Seller added successfully.\n");

    // Write seller data to file
    fprintf(fp, "%d\t%s\t%.2f\t%d\n", seller.id, seller.name, seller.rating, seller.isActive);
}

// Function to remove a seller
void removeSeller() {
    if (numSellers == 0) {
        printf("No sellers to remove.\n");
        return;
    }

    int sellerId;
    printf("Enter seller ID to remove: ");
    scanf("%d", &sellerId);

    bool found = false;
    for (int i = 0; i < numSellers; i++) {
        if (sellers[i].id == sellerId) {
            sellers[i].isActive = false; 
            found = true;
            printf("Seller removed successfully.\n");

            // Update seller data in file
            rewind(fp); // Move file pointer to the beginning
            for (int j = 0; j < numSellers; j++) {
                fprintf(fp, "%d\t%s\t%.2f\t%d\n", sellers[j].id, sellers[j].name, sellers[j].rating, sellers[j].isActive);
            }
            break;
        }
    }

    if (!found) {
        printf("Seller with ID %d not found.\n", sellerId);
    }
}

// Function to display active sellers
void displayActiveSellers() {
    printf("Active sellers:\n");
    for (int i = 0; i < numSellers; i++) {
        if (sellers[i].isActive) {
            printf("ID: %d, Name: %s, Rating: %.2f\n", sellers[i].id, sellers[i].name, sellers[i].rating);
        }
    }
}

int main() {
    // Open file for writing
    FILE *fp = fopen("sellers.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    fclose(fp);

    // Open file for reading and writing
    fp = fopen("sellers.txt", "w+");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }



    // Read seller data from file
    Seller seller;
    while (fscanf(fp, "%d%s%f%d", &seller.id, seller.name, &seller.rating, &seller.isActive) != EOF) {
        if (seller.isActive) {
            sellers[numSellers++] = seller;
            
        }
    }

    int choice;
    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Seller\n");
        printf("2. Remove Seller\n");
        printf("3. Display Active Sellers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSeller();
                break;
            case 2:
                removeSeller();
                break;
            case 3:
                displayActiveSellers();
                break;
                
            }
             
        }
        fclose(fp);
        return 0;
       
    }
