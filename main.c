#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "option.h"
#include "order.h"
#include "constants.h"
#include "signup&in.h"




int main() {
    char username[MAX_USERNAME];
    char key[20];
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
    f = fopen("data.txt", "r");
    // fopen("data.txt", "r"); fails at finding the specific file
    if (f) {
        // reading food
        fscanf(f, "%d:\n", &NoOfFoodTypes);
        storeFoodAndPricesFromInput(&NoOfFoodOptions, &FoodType, &FoodOption, &FoodPrice, NoOfFoodTypes, f);
        fscanf(f, "%d:\n", &NoOfDrinks);
        storeDrinksAndPricesFromInput(&Drinks, NoOfDrinks,  &DrinkPrice, &NoOfDrinkOptions, f);

    } else {
        printf("%s:\n", LOAD_DATA); // same steps but from the console
        fscanf(stdin, "%d:\n", &NoOfFoodTypes);
        storeFoodAndPricesFromInput(&NoOfFoodOptions, &FoodType, &FoodOption, &FoodPrice, NoOfFoodTypes, stdin);
        fscanf(stdin, "%d:\n", &NoOfDrinks);
        storeDrinksAndPricesFromInput(&Drinks, NoOfDrinks,  &DrinkPrice, &NoOfDrinkOptions, stdin);
    }
    fclose(f);
    f = fopen("users.txt", "r");
    fscanf(f,"%s",key);
    fclose(f);
    printf("\nWelcome to Food Thingies!\n");
    while (!orderPlaced) {
        switch (state) {
            case (0): {
                chooseSignInOrSignUp(&state);
                break;
            }
            case (1): {
                signInProcess(username,&state,key);
                break;
            }
            case (2): {
                signUpProcess(username,&state,key);
                break;
            }
            case (3): {
                printFoodTypes(NoOfFoodTypes, FoodType);
                Food = getChoiceIndex(NoOfFoodTypes, &state);
                if (state == 2)
                    state = 0;
                break;
            }
            case (4): {
                printf("Please choose the type of %s:\n", FoodType[Food]);
                printFoodOptions(NoOfFoodOptions, FoodPrice, FoodOption, Food);
                Type = getChoiceIndex(NoOfFoodOptions[Food], &state);
                break;
            }
            case (5): {
                printf("Please choose a drink to go with your %s:\n", FoodType[Food]);
                printDrinkOptions(NoOfDrinks, DrinkPrice, Drinks);
                Drink = getChoiceIndex(NoOfDrinkOptions, &state);
                break;
            }
            case (6): {
                printCutleryOptions();
                Cutlery = getChoiceIndex(NoOfCutleryOptions, &state);
                break;
            }
            case (7): {
                getAdditionalInfo(AddInfo);
                state++;
                break;
            }
            case (8): {
                printOrder(username, FoodOption, FoodPrice, Drinks,
                           DrinkPrice, AddInfo, Cutlery, Food, Type, Drink, NoOfDrinks);
                orderConfirmation(&state, &orderPlaced);
                break;
            }
        }
    }
    // freeing the memory
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
    printf("Order confirmed! Thank you for buying from us, %s!", username);
    return 0;
}


