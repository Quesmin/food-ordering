#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "option.h"
#include "order.h"
#include "constants.h"

//void storeFoodAndPricesFromInput(int *NoOfFoodOptions, char **FoodType, char **FoodOption[], double **FoodPrice, int NoOfFoodTypes, FILE *f);


int main() {
    char username[20] = "admin";
    char password[20] = "admin";
    char AddInfo[100];
    int Food, Type, Drink, Cutlery;
    int state = 0;
    int orderPlaced = 0;
    int NoOfFoodTypes, NoOfDrinks, NoOfDrinkOptions, NoOfCutleryOptions = CUTLERY_OPTIONS;
    double *DrinkPrice;
    int *NoOfFoodOptions;
    char **FoodType;
    char **Drinks;
    char ***FoodOption;
    double **FoodPrice;
    FILE *f;
    f = fopen("C:\\Users\\Cosmin\\Desktop\\CP\\food-ordering\\data.txt", "r");
    if (f) {

        fscanf(f, "%d:\n", &NoOfFoodTypes);
        //storeFoodAndPricesFromInput(NoOfFoodOptions, FoodType, FoodOption, FoodPrice, NoOfFoodTypes, f);
        //for some reason it doesn't store the data provided from the file; without the function is working properly;
        NoOfFoodOptions = (int *) malloc(NoOfFoodTypes * sizeof(int));
        FoodType = (char **) malloc(NoOfFoodTypes * sizeof(char *));
        FoodOption = (char ***) malloc(NoOfFoodTypes * sizeof(char **));
        FoodPrice = (double **) malloc(NoOfFoodTypes * sizeof(double *));
        for (int i = 0; i < NoOfFoodTypes; i++) {
            FoodType[i] = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
            readFoodType(FoodType[i], f);
            char Line[100];
            fscanf(f, "%[^\n]", Line);
            fgetc(f);
            NoOfFoodOptions[i] = getFoodOptionsNumber(Line);
            FoodOption[i] = (char **) malloc(NoOfFoodOptions[i] * sizeof(char *));
            FoodPrice[i] = (double *) malloc(NoOfFoodOptions[i] * sizeof(double));
            getFoodAndPrice(Line, FoodOption[i], FoodPrice[i]);
        }
        fscanf(f, "%d:\n", &NoOfDrinks);
        Drinks = (char **) malloc(NoOfDrinks * sizeof(char *));
        DrinkPrice = (double *) malloc(NoOfDrinks * sizeof(double));
        char Line[100];
        fscanf(f, "%[^\n]", Line);
        fgetc(f);
        getDrinksAndPrice(Line, Drinks, DrinkPrice);
        NoOfDrinkOptions = NoOfDrinks + 1;
    } else {
        printf("%s:\n", LOAD_DATA);
        fscanf(stdin, "%d:\n", &NoOfFoodTypes);
        NoOfFoodOptions = (int *) malloc(NoOfFoodTypes * sizeof(int));
        FoodType = (char **) malloc(NoOfFoodTypes * sizeof(char *));
        FoodOption = (char ***) malloc(NoOfFoodTypes * sizeof(char **));
        FoodPrice = (double **) malloc(NoOfFoodTypes * sizeof(double *));
        for (int i = 0; i < NoOfFoodTypes; i++) {
            FoodType[i] = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
            readFoodType(FoodType[i], stdin);
            char Line[100];
            fscanf(stdin, "%[^\n]", Line);
            fgetc(stdin);
            NoOfFoodOptions[i] = getFoodOptionsNumber(Line);
            FoodOption[i] = (char **) malloc(NoOfFoodOptions[i] * sizeof(char *));
            FoodPrice[i] = (double *) malloc(NoOfFoodOptions[i] * sizeof(double));
            getFoodAndPrice(Line, FoodOption[i], FoodPrice[i]);
        }
        fscanf(stdin, "%d:\n", &NoOfDrinks);
        Drinks = (char **) malloc(NoOfDrinks * sizeof(char *));
        DrinkPrice = (double *) malloc(NoOfDrinks * sizeof(double));
        char Line[100];
        fscanf(stdin, "%[^\n]", Line);
        fgetc(stdin);
        getDrinksAndPrice(Line, Drinks, DrinkPrice);
        NoOfDrinkOptions = NoOfDrinks + 1;

    }
    printf("\nWelcome to Food Thingies!\n");
    //printf("Please sign in to continue!\n");
    while (!orderPlaced) {
        switch (state) {
            case (0): {
                //userCredentialsStep(username, password, &state);
                printf("Do you want to sign in or sign up?\n");
                char choice;
                choice = getchar();
                if(choice == 'a')
                    state++;
                else
                    state = state + 2;
                break;
            }
            case(1):{
                printf("Signing in!\n");
                printf("---Username\n");
                char validateUser[20];
                scanf("%[^\n]", validateUser);
                getchar();
                if(strcmp(username, validateUser)==0)
                //userCredentialsStep(username, password, &state);
            }
            case (1): {
                printFoodTypes(NoOfFoodTypes, FoodType);
                Food = getChoiceIndex(NoOfFoodTypes, &state);
                break;
            }
            case (2): {
                printf("Please choose the type of %s:\n", FoodType[Food]);
                printFoodOptions(NoOfFoodOptions, FoodPrice, FoodOption, Food);
                Type = getChoiceIndex(NoOfFoodOptions[Food], &state);
                break;
            }
            case (3): {
                printf("Please choose a drink to go with your %s:\n", FoodType[Food]);
                printDrinkOptions(NoOfDrinks, DrinkPrice, Drinks);
                Drink = getChoiceIndex(NoOfDrinkOptions, &state);
                break;
            }
            case (4): {
                printCutleryOptions();
                Cutlery = getChoiceIndex(NoOfCutleryOptions, &state);
                break;
            }
            case (5): {
                getAdditionalInfo(AddInfo);
                state++;
                break;
            }
            case (6): {
                printOrder(username, FoodOption, FoodPrice, Drinks,
                           DrinkPrice, AddInfo, Cutlery, Food, Type, Drink, NoOfDrinks);
                orderConfirmation(&state, &orderPlaced);
                break;
            }
        }
    }
    for (int i = 0; i < NoOfDrinks; i++)
        free(Drinks[i]);
    free(Drinks);
    free(DrinkPrice);
    for (int i = 0; i < NoOfFoodTypes; i++) {
        for (int j = 0; j < NoOfFoodOptions[i]; j++)
            free(FoodOption[i][j]);
        free(FoodOption[i]);
        free(FoodType[i]);
        free(FoodPrice[i]);
    }
    free(NoOfFoodOptions);
    free(FoodOption);
    free(FoodType);
    free(FoodPrice);
    fclose(f);
    printf("Order confirmed! Thank you for buying from us, %s!", username);
    return 0;
}

/*void storeFoodAndPricesFromInput(int *NoOfFoodOptions, char **FoodType, char ***FoodOption, double**FoodPrice, int NoOfFoodTypes, FILE *f)
{
        NoOfFoodOptions = (int *) malloc(NoOfFoodTypes * sizeof(int));
        FoodType = (char **) malloc(NoOfFoodTypes * sizeof(char *));
        FoodOption = (char ***) malloc(NoOfFoodTypes * sizeof(char **));
        FoodPrice = (double **) malloc(NoOfFoodTypes * sizeof(double *));
        for (int i = 0; i < NoOfFoodTypes; i++) {
            *(FoodType+i) = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
            readFoodType(FoodType[i], f);
            char Line[100];
            fscanf(f, "%[^\n]", Line);
            fgetc(f);
            NoOfFoodOptions[i] = getFoodOptionsNumber(Line);
            FoodOption[i] = (char **) malloc(NoOfFoodOptions[i] * sizeof(char *));
            FoodPrice[i] = (double *) malloc(NoOfFoodOptions[i] * sizeof(double));
        }
}*/


