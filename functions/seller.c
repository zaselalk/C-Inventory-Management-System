#include <stdbool.h>
#include <stdio.h>

#define MAX_SELLERS 100

typedef struct Seller {
  int id;
  char name[50];
  float rating;
  bool isActive;
} Seller;

Seller sellers[MAX_SELLERS];
int numSellers = 0;

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
      break;
    }
  }

  if (!found) {
    printf("Seller with ID %d not found.\n", sellerId);
  }
}

// Function to display active sellers
void displayActiveSellers() {
  printf("Active Sellers:\n");
  printf("ID\tName\tRating\n");
  for (int i = 0; i < numSellers; i++) {
    if (sellers[i].isActive) {
      printf("%d\t%s\t%.2f\n", sellers[i].id, sellers[i].name,
             sellers[i].rating);
    }
  }
}

// Function to write seller data to a file
void writeSellersToFile() {
  FILE *fp;
  fp = fopen("sellers.txt", "w");

  if (fp == NULL) {
    printf("Error opening file!\n");
    return;
  }

  fprintf(fp, "ID\tName\tRating\n");
  for (int i = 0; i < numSellers; i++) {
    fprintf(fp, "%d\t%s\t%.2f\n", sellers[i].id, sellers[i].name,
            sellers[i].rating);
  }

  fclose(fp);
  printf("Seller data written to file.\n");
}

int manage_sellers() {
  int choice;

  while (1) {
    printf("\nInventory Management System\n");
    printf("1. Add Seller\n");
    printf("2. Remove Seller\n");
    printf("3. Display Active Sellers\n");
    printf("4. Write Sellers to File\n");
    printf("5. Exit\n");
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
    case 4:
      writeSellersToFile();
      break;
    case 5:
      return 0;
    default:
      printf("Invalid choice.\n");
    }
  }
}
