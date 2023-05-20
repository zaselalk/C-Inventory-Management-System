typedef struct {
  int id;
  char name[100];
  char description[300];
  char cost_price[20];
  char selling_price[20];
  char supplier_id[20];
} Product;

typedef struct
{
    int st_id;
    int id;
    int quantity;
    int warehouse_id;
    char expire_date[20];
} Stock;

typedef struct Seller {
    int id;               
    char name[100];          
    float rating;                  
} Seller;