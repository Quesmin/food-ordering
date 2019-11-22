#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "option.h"
#include "order.h"
#include "constants.h"



int main() {
    char username[20];
    char password[20];
    char AddInfo[100];
    int Food, Type, Drink, Cutlery;
    int state = 0;
    int orderPlaced = 0;
    int NoOfFoodTypes, NoOfDrinks, NoOfDrinkOptions, NoOfCutleryOptions = CUTLERY_OPTIONS ;
    double *DrinkPrice;
    int *NoOfFoodOptions;
    char **FoodType;
    char **Drinks;
    char ***FoodOption;
    double **FoodPrice;
    FILE *f;
    f = fopen("C:\\Users\\Cosmin\\Desktop\\CP\\food-ordering\\data.txt", "r");
    if(f) {

        fscanf(f, "%d:\n", &NoOfFoodTypes);
        NoOfFoodOptions = (int *) malloc(NoOfFoodTypes * sizeof(int));
        FoodType = (char **) malloc(NoOfFoodTypes * sizeof(char *));
        FoodOption = (char ***) malloc(NoOfFoodTypes * sizeof(char **));
        FoodPrice = (double **)malloc(NoOfFoodTypes * sizeof(double*));
        for (int i = 0; i < NoOfFoodTypes; i++) {
            FoodType[i] = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
            FoodOption[i] = (char **)malloc(FOOD_OPTIONS * sizeof(char*));
            FoodPrice[i] = (double *)malloc(FOOD_OPTIONS * sizeof(double));
            readFoodType(FoodType[i], f);
            char Line[100];
            fscanf(f,"%[^\n]", Line);
            fgetc(f);
            getFoodAndPrice(Line, FoodOption[i], FoodPrice[i],&NoOfFoodOptions[i]);
        }
        fscanf(f, "%d:\n", &NoOfDrinks);
        Drinks = (char **)malloc(NoOfDrinks * sizeof(char *));
        DrinkPrice = (double *)malloc(NoOfDrinks * sizeof(double));
            char Line[100];
            fscanf(f,"%[^\n]", Line);
            fgetc(f);
            getDrinksAndPrice(Line, Drinks, DrinkPrice);
            NoOfDrinkOptions = NoOfDrinks + 1;
    }
    else {
        printf("%s:\n", LOAD_DATA);
        fscanf(stdin, "%d:\n", &NoOfFoodTypes);
        NoOfFoodOptions = (int *) malloc(NoOfFoodTypes * sizeof(int));
        FoodType = (char **) malloc(NoOfFoodTypes * sizeof(char *));
        FoodOption = (char ***) malloc(NoOfFoodTypes * sizeof(char **));
        FoodPrice = (double **)malloc(NoOfFoodTypes * sizeof(double*));
        for (int i = 0; i < NoOfFoodTypes; i++) {
            FoodType[i] = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
            FoodOption[i] = (char **)malloc(FOOD_OPTIONS * sizeof(char*));
            FoodPrice[i] = (double *)malloc(FOOD_OPTIONS * sizeof(double));
            readFoodType(FoodType[i], stdin);
            char Line[100];
            fscanf(stdin,"%[^\n]", Line);
            fgetc(stdin);
            getFoodAndPrice(Line, FoodOption[i], FoodPrice[i],&NoOfFoodOptions[i]);
        }
        fscanf(f, "%d:\n", &NoOfDrinks);
        Drinks = (char **)malloc(NoOfDrinks * sizeof(char *));
        DrinkPrice = (double *)malloc(NoOfDrinks * sizeof(double));
        char Line[100];
        fscanf(f,"%[^\n]", Line);
        fgetc(f);
        getDrinksAndPrice(Line, Drinks, DrinkPrice);
        NoOfDrinkOptions = NoOfDrinks + 1;

    }
    printf("Welcome to Food Thingies!\nPlease sign in to continue!\n");

    while(!orderPlaced)
    {
        switch (state){
            case(0):{
                userCredentialsStep(username, password, &state);
                break;
            }
            case(1):{
                printFoodTypes(NoOfFoodTypes, FoodType);
                Food = getChoiceIndex(NoOfFoodTypes, &state);
                break;
            }
            case(2):{
                printf("Please choose the type of %s:\n", FoodType[Food]);
                printFoodOptions(NoOfFoodOptions, FoodPrice, FoodOption, Food);
                Type = getChoiceIndex(NoOfFoodOptions[Food], &state);
                break;
            }
            case(3):{
                printf("Please choose a drink to go with your %s:\n", FoodType[Food]);
                printDrinkOptions(NoOfDrinks, DrinkPrice, Drinks);
                Drink = getChoiceIndex(NoOfDrinkOptions, &state);
                break;
            }
            case(4):{
                printCutleryOptions();
                Cutlery = getChoiceIndex(NoOfCutleryOptions, &state);
                break;
            }
            case(5):{
                getAdditionalInfo(AddInfo);
                state++;
                break;
            }
            case(6):{
                printOrder( username, FoodOption, FoodPrice, Drinks,
                 DrinkPrice, AddInfo, Cutlery, Food, Type, Drink, NoOfDrinks);
                orderConfirmation(&state, &orderPlaced);
                break;
            }
        }
    }
    for(int i=0; i<NoOfDrinks; i++)
        free(Drinks[i]);
    free(Drinks);
    free(DrinkPrice);
    for(int i=0; i<NoOfFoodTypes; i++)
    {
        for(int j=0;j<NoOfFoodOptions[i];j++)
            free(FoodOption[i][j]);
        free(FoodOption[i]);
        free(FoodType[i]);
        free(FoodPrice[i]);
    }
    free(NoOfFoodOptions);
    free(FoodOption);
    free(FoodType);
    free(FoodPrice);
    printf("Order confirmed! Thank you for buying from us, %s!", username);
    return 0;
}

