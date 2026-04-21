#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for user credentials
struct User
{
    char username[100];
    char password[100];
    int isAdmin;
};

struct UserRequest
{
    char username[100];
    char password[100];
};

struct farm
{
    char farm_name[100];
    char farmers_name[100];
    char phone[12];
    char crop_types[1000];
    float production_quantity;
    char chicken_breed[1000];
    char cow_breed[1000];
    char types_of_fishes[1000];
    int quantity_of_milk;
    int eggs_available;
    float sales;
    int no_of_chicken;
    int no_of_cow;
    int no_of_fishes;

};

// Function of interface
void interface()
{
    printf("\n\n\t\t\t\t\t\t      __|__\n");
    printf("\t\t\t\t\t\t   __|__|__|__\n");
    printf("\t\t\t\t\t\t  | __|__|__|__|\n");
    printf("\t\t\t\t\t\t  |____________|\n");
    printf("\t\t\t\t\t\t     (o)   (o)\n");
    printf("\n");
    printf("\t\t\t---------- Welcome To The Agricultural Management System ----------\n");
    printf("\t\t\t          _________________________________________________\n\n");
    printf(" \t\t\t         Easy access to all of your farm data in one place!\n\n");
    printf("\t\t\t\t\t      *****************\n\n");
    printf("\t\t\t\t\t   Presenter: Eusra Amreen\n\n");
    printf(" \t\t\t\t\t   Evaluator: Dr. Nova Ahmed\n");
    printf("\t\t\t\t\t\t      Md. Abdullah Al Sayed\n\n");
    printf("\t\t\t\t\t       *****************\n\n");
    printf("\t\t\t\t        Thank you for using my software!\n\n");
    printf("\t\t\t\t                  Version : 1.1\n\n");
    printf("\t\t\t\t\t        ____________________\n\n");
}

// Function to purchase items from a farm
void purchaseItems(struct farm *Farm)
{
    printf("Items available for purchase from farm:\n");
    printf("1. Chickens\n");
    printf("2. Cows\n");
    printf("3. Fishes\n");
    printf("4. Eggs\n");
    printf("5. Milk\n");
    printf("Enter the item number you want to purchase: ");
    int choice;
    scanf("%d", &choice);

    int quantity;
    float totalCost = 0;

    switch (choice)
    {
    case 1:
        printf("Enter the quantity of chickens you want to purchase: ");
        scanf("%d", &quantity);
        if (quantity <= Farm->no_of_chicken)
        {
            totalCost = 10.0 * quantity; // Assuming chickens cost $10 each
            Farm->no_of_chicken -= quantity;

            printf("You purchased %d chickens for $%.2f\n", quantity, totalCost);
        }
        else
        {
            printf("Not enough chickens available for purchase.\n");
        }
        break;
    case 2:
        printf("Enter the quantity of cows you want to purchase: ");
        scanf("%d", &quantity);
        if (quantity <= Farm->no_of_cow)
        {
            totalCost = 100.0 * quantity; // Assuming cowss cost $100 each
            Farm->no_of_cow -= quantity;

            printf("You purchased %d cows for $%.2f\n", quantity, totalCost);
        }
        else
        {
            printf("Not enough cows available for purchase.\n");
        }
        break;
    case 3:
        printf("Enter the quantity of fishes you want to purchase: ");
        scanf("%d", &quantity);
        if (quantity <= Farm->no_of_fishes)
        {
            totalCost = 20.0 * quantity; // Assuming fishes cost $20 per kg
            Farm->no_of_fishes -= quantity;

            printf("You purchased %d kg fishes for $%.2f\n", quantity, totalCost);
        }
        else
        {
            printf("Not enough fishes available for purchase.\n");
        }
        break;
    case 4:
        printf("Enter the quantity of eggs you want to purchase: ");
        scanf("%d", &quantity);
        if (quantity <= Farm->eggs_available)
        {
            totalCost = 1.0 * quantity; // Assuming eggs cost $1 per egg
            Farm->eggs_available -= quantity;

            printf("You purchased %d eggs for $%.2f\n", quantity, totalCost);
        }
        else
        {
            printf("Not enough eggs available for purchase.\n");
        }
        break;
    case 5:
        printf("Enter the quantity of milk (in liters) you want to purchase: ");
        scanf("%d", &quantity);
        if (quantity <= Farm->quantity_of_milk)
        {
            totalCost = 2.0 * quantity; // Assuming milk costs $2 per liter
            Farm->quantity_of_milk -= quantity;

            printf("You purchased %d liters of milk for $%.2f\n", quantity, totalCost);
        }
        else
        {
            printf("Not enough milk available for purchase.\n");
        }
        break;
    default:
        printf("Invalid choice.\n");
    }
}

// Function to add a farm record to the array
void addFarm(struct farm f[], int *numFarms, int maxSize)
{
    if (*numFarms < maxSize)
    {
        printf("Farm details:\n\n");
        printf("\tFarm name: ");
        fgets(f[*numFarms].farm_name, sizeof(f->farm_name), stdin);
        printf("\tFarmer's name: ");
        fgets(f[*numFarms].farmers_name, sizeof(f->farmers_name), stdin);
        printf("\tFarmer's phone number: ");
        fgets(f[*numFarms].phone, sizeof(f->phone), stdin);
        printf("\tTypes of Crop or Plant: ");
        fgets(f[*numFarms].crop_types, sizeof(f->crop_types), stdin);
        printf("\tProduction from Crops: ");
        scanf("%f", &f[*numFarms].production_quantity);
        printf("\tChicken breeds available: ");
        getchar();
        fgets(f[*numFarms].chicken_breed, sizeof(f->chicken_breed), stdin);
        printf("\tCow breeds available: ");
        fgets(f[*numFarms].cow_breed, sizeof(f->cow_breed), stdin);
        printf("\tFish breeds available: ");
        fgets(f[*numFarms].types_of_fishes, sizeof(f->types_of_fishes), stdin);
        printf("\tMilk available: ");
        scanf("%d", &f[*numFarms].quantity_of_milk);
        printf("\tEggs available: ");
        scanf("%d", &f[*numFarms].eggs_available);
        getchar();
        printf("\tSales: ");
        scanf("%f", &f[*numFarms].sales);
        printf("\tChicken available: ");
        scanf("%d", &f[*numFarms].no_of_chicken);
        printf("\tCow available: ");
        scanf("%d", &f[*numFarms].no_of_cow);
        printf("\tFishes available: ");
        scanf("%d", &f[*numFarms].no_of_fishes);
        getchar();

        // Increment the number of farms
        (*numFarms)++;
    }
    else
    {
        printf("Array is full. Cannot add more farms.\n");
    }
}

// Function to view a farm
void viewFarms(struct farm f[], int numFarms)
{
    for (int i = 0; i < numFarms; i++)
    {
        printf("\n\tFarm %d:\n", i + 1);
        printf("\tFarm Name: %s", f[i].farm_name);
        printf("\tFarmer's Name: %s", f[i].farmers_name);
        printf("\tPhone: %s", f[i].phone);
        printf("\tCrop types: %s", f[i].crop_types);
        printf("\tProduction from crop: %.2f kg\n", f[i].production_quantity);
        printf("\tChicken breeds available: %s", f[i].chicken_breed);
        printf("\tCow breeds available: %s", f[i].cow_breed);
        printf("\tFish breeds available: %s", f[i].types_of_fishes);
        printf("\tMilk available: %d Liter\n", f[i].quantity_of_milk);
        printf("\tEggs available: %d\n", f[i].eggs_available);
        printf("\tSales: %.2f%\n", f[i].sales);
        printf("\tChicken available: %d Liter\n", f[i].no_of_chicken);
        printf("\tCow available: %d\n", f[i].no_of_cow);
        printf("\tFishes available: %d\n", f[i].no_of_fishes);
        printf("\n");
    }
}

// Function to search for a farm by name and provide all data
void searchFarm(struct farm f[], int numFarms, const char *name)
{
    int found = 0;
    for (int i = 0; i < numFarms; i++)
    {
        if (strncmp(f[i].farm_name, name, strlen(name)) == 0)
        {   printf("\n");
            printf("\tFarm found:\n");
            printf("\tFarm Name: %s", f[i].farm_name);
            printf("\tFarmer's Name: %s", f[i].farmers_name);
            printf("\tPhone: %s", f[i].phone);
            printf("\tCrop types: %s", f[i].crop_types);
            printf("\tProduction from crop: %.2f kg\n", f[i].production_quantity);
            printf("\tChicken breeds available: %s", f[i].chicken_breed);
            printf("\tCow breeds available: %s", f[i].cow_breed);
            printf("\tFish breeds available: %s", f[i].types_of_fishes);
            printf("\tMilk available: %d Liter\n", f[i].quantity_of_milk);
            printf("\tEggs available: %d\n", f[i].eggs_available);
            printf("\tSales: %.2f\n", f[i].sales);
            printf("\tChicken available: %d Liter\n", f[i].no_of_chicken);
            printf("\tCow available: %d\n", f[i].no_of_cow);
            printf("\tFishes available: %d\n", f[i].no_of_fishes);
            printf("\n");

            found = 1;
        }
    }

    if (!found)
    {
        printf(" Farm not found.\n");
    }
}

// Function to delete a farm by name
void deleteFarm(struct farm f[], int *numFarms, const char *name)
{
    int found = 0;
    for (int i = 0; i < *numFarms; i++)
    {
        if (strcmp(f[i].farm_name, name) == 1)
        {
            // Shift all elements after the one to delete one position back
            for (int j = i; j < *numFarms - 1; j++)
            {
                f[j] = f[j + 1];
            }
            (*numFarms)--;
            found = 1;
            printf(" Farm deleted.\n");
            break;
        }
    }

    if (!found)
    {
        printf(" Farm not found, no deletion performed.\n");
    }
}

// Function to write farm data to a file
void writeFarmDataToFile(struct farm f[], int numFarms)
{
    FILE *file = fopen("farm_data.dat", "w"); // Open file for writing
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < numFarms; i++)
    {
    fprintf(file, "Farm Name: %s", f[i].farm_name);
    fprintf(file, "Farmer's Name: %s", f[i].farmers_name);
    fprintf(file, "Phone: %s\n", f[i].phone);
    fprintf(file, "Crop types: %s", f[i].crop_types);
    fprintf(file, "Production from crop: %f kg\n", f[i].production_quantity);
    fprintf(file, "Chicken breeds available: %s", f[i].chicken_breed);
    fprintf(file, "Cow breeds available: %s", f[i].cow_breed);
    fprintf(file, "Fish breeds available: %s", f[i].types_of_fishes);
    fprintf(file, "Milk available: %d Liter\n", f[i].quantity_of_milk);
    fprintf(file, "Eggs available: %d\n", f[i].eggs_available);
    fprintf(file, "Sales: %.2f\n\n", f[i].sales);
    fprintf(file, "Chicken available: %d Liter\n", f[i].no_of_chicken);
    fprintf(file, "Cow available: %d\n", f[i].no_of_cow);
    fprintf(file, "Fishes available: %d\n", f[i].no_of_fishes);
    }

    fclose(file); // Close the file after writing
}

// Function to read farm data from a file
void readFarmDataFromFile(struct farm f[], int *numFarms, int maxSize)
{
    FILE *file = fopen("farm_data.dat", "r"); // Open file for reading

    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    while (*numFarms < maxSize && fscanf(file, "Farm Name: %s", f[*numFarms].farm_name) == 1)
    {

        (*numFarms)++;
    }

    fclose(file); // Close the file after reading
}

// Function to perform user login
int userLogin(struct User users[], int numUsers, char *username, char *password)
{
    for (int i = 0; i < numUsers; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            return users[i].isAdmin;
        }
    }
    return -1; // User not found
}

int main()
{
    interface();
    getchar();
    system("cls");

    // Initialize an array of farm structures, users, and other variables
    int maxSize = 5;            // Maximum number of farms
    int numfarms = 0;           // Number of farms in the array
    struct farm Farms[maxSize]; // Array of farm records

    // Read farm data from a file (if any)
    readFarmDataFromFile(Farms, &numfarms, maxSize);

    struct User users[] = {
        {"admin", "admin123", 1},
        {"user1", "user123", 0},
        {"user2", "user456", 0}};

    int numUsers = 3;

    struct UserRequest userRequests[10]; // Store user registration requests
    int numRequests = 0;

    char inputUsername[100];
    char inputPassword[100];

    // Login loop
    while (1)
    {
        int isAdmin = -1;

        while (1)
        {
            printf("\n\n\t1. Login\n\t2. Register\n\n");
            int loginChoice;
            printf("\tEnter your choice: ");
            scanf("%d", &loginChoice);
            while (loginChoice < 1 || loginChoice > 2)
            {
                printf("Invalid choice. Please try again: ");
                scanf("%d", &loginChoice);
            }
            if (loginChoice == 1)
            {
                getchar();
                system("cls");
                printf("\tInput log in credentials:\n\n");
                while (isAdmin == -1)
                {

                    printf("\t\tUsername: ");
                    scanf("%s", inputUsername);
                    printf("\t\tPassword: ");
                    scanf("%s", inputPassword);

                    isAdmin = userLogin(users, numUsers, inputUsername, inputPassword);

                    if (isAdmin == -1)
                    {
                        printf(" Invalid login credentials. Try again.\n");
                    }
                }
                printf("\n");
                break;
            }
            else if (loginChoice == 2)
            {   getchar();
                system("cls");
                printf("\tInput registration credentials:\n");
                printf("\tUsername: ");
                scanf("%s", userRequests[numRequests].username);
                printf("\tPassword: ");
                scanf("%s", userRequests[numRequests].password);
                numRequests++;
                printf("\n");
            }
        }
        // User login logic

        // Main menu and purchase system loop
        while (1)
        {
            int flag = 0;

            if (isAdmin)
            {
                // Main menu and user registration loop
                getchar();
                system("cls");
                printf("MENUE:\n\n1. Add Farm\n\n2. Search Farm\n\n3. Delete Farm\n\n4. Save Data to File\n\n5. View Data\n\n6. Manage Users\n\n7. logout\n\n8. Exit\n\n");
                int choice;
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    if (isAdmin)
                    {   getchar();
                        system("cls");
                        addFarm(Farms, &numfarms, maxSize);
                        writeFarmDataToFile(Farms, numfarms);
                    }
                    break;
                case 2:
                    if (isAdmin)
                    {// Search for a farm
                        getchar();
                        system("cls");
                      printf("Enter farm name to search: ");
                      char searchName[100];
                      scanf("%s", searchName);
                      searchFarm(Farms, maxSize, searchName);
                      printf("\n");
                      getchar();
                    }
                     break;
                case 3:
                    if (isAdmin)
                    {   // Delete a farm
                        getchar();
                        system("cls");
                        printf(" Enter farm name to delete: ");
                        char deleteName[100];
                        scanf("%s", deleteName);
                        deleteFarm(Farms, &maxSize, deleteName);
                        printf("\n");
                        getchar();
                    }
                    break;
                case 4:
                    if (isAdmin)
                    {
                        // Save data to a file
                        writeFarmDataToFile(Farms, numfarms);
                    }
                    break;
                case 5:
                    if (isAdmin)
                    {   getchar();
                        system("cls");
                        // View all farms
                        viewFarms(Farms, numfarms);
                        printf("\n");
                        getchar();
                    }
                    break;
                case 6:
                    if (isAdmin)
                    {
                        // Manage users
                        getchar();
                        system("cls");
                        printf("1. Approve User Registration Request\n2. View User Requests\n3. Exit\n");
                        int userChoice;
                        printf("Enter your choice: ");
                        scanf("%d", &userChoice);
                        if (userChoice == 1)
                        {
                            if (numRequests > 0)
                            {
                                printf("User Registration Requests:\n");
                                for (int i = 0; i < numRequests; i++)
                                {
                                    printf("Request %d: Username: %s\n", i + 1, userRequests[i].username);
                                }
                                printf("Enter the request number to approve: ");
                                int requestNumber;
                                scanf("%d", &requestNumber);
                                if (requestNumber > 0 && requestNumber <= numRequests)
                                {
                                    // Add the user to the users array
                                    strcpy(users[numUsers].username, userRequests[requestNumber - 1].username);
                                    strcpy(users[numUsers].password, userRequests[requestNumber - 1].password);
                                    users[numUsers].isAdmin = 0;
                                    numUsers++;
                                    // Approve the user registration request
                                    printf("User registration approved.\n");
                                    for (int i = requestNumber - 1; i < numRequests - 1; i++)
                                    {
                                        userRequests[i] = userRequests[i + 1];
                                    }
                                    numRequests--;
                                }
                                else
                                {
                                    printf("Invalid request number.\n");
                                }
                            }
                            else
                            {
                                printf("No pending user registration requests.\n");
                            }
                        }
                        else if (userChoice == 2)
                        {
                            if (numRequests > 0)
                            {
                                printf("User Registration Requests:\n");
                                for (int i = 0; i < numRequests; i++)
                                {
                                    printf("Request %d: Username: %s\n", i + 1, userRequests[i].username);
                                }
                            }
                            else
                            {
                                printf("No pending user registration requests.\n");
                            }
                        }
                        else if (userChoice == 3)
                        {
                            // Exit user management
                        }
                        else
                        {
                            printf(" Invalid choice.\n");
                        }
                        getchar();
                    }
                    break;
                case 7:
                    flag = 1;

                    break;
                case 8:
                    // Exit the program
                    return 0;
                default:
                    printf(" Invalid choice. Please try again.\n");
                }
                if (flag)
                {
                    break;
                }
            }
            else
            {
                printf("1. Purchase Items from Farm\n2. View Data\n3. logout\n4. Exit\n");
                int choice;
                printf(" Enter your choice: ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:

                    // Purchase items from a farm
                    getchar();
                    system("cls");
                    printf("Enter farm name to purchase from: ");
                    char purchaseName[100];
                    scanf("%s", purchaseName);
                    int found = 0;

                    for (int i = 0; i < maxSize; i++)
                    {
                        if (strcmp(Farms[i].farm_name, purchaseName) == 1)
                        {
                            purchaseItems(&Farms[i]);
                            found = 1;
                            break;
                        }
                    }

                    if (!found)
                    {
                        printf(" Farm not found.\n");
                    }
                    printf("\n");

                    break;
                case 2:
                    // View all farms
                    getchar();
                    system("cls");
                    viewFarms(Farms, numfarms);
                    printf("\n");
                    break;
                case 3:
                    flag = 1;

                    break;
                case 4:
                    // Exit the program
                    return 0;
                default:
                    printf(" Invalid choice. Please try again.\n");
                }
                if (flag)
                {
                    break;
                }
            }
        }
    }

    return 0;
}
