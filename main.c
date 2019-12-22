#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "option.h"
#include "order.h"
#include "constants.h"
#include "signup&in.h"
#include "buyer.h"
#include "food.h"
#include "drinks.h"

int main() {
    buyer b = createBuyer();
    foodType type;
    specificFood food;
    drinks d;
    choice specific;
    char key[20];
    enum Position { SIGN_IN_OR_UP, SIGN_IN_STATE, SIGN_UP_STATE, FOOD_TYPE,
            SPECIFIC_FOOD, DRINK_OPTIONS, CUTLERY, ADD_INFO,ORDER_SUMMARY};
    int state = 0;
    int orderPlaced = 0;
    int NoOfCutleryOptions = CUTLERY_OPTIONS;
    FILE *f;
    f = fopen("data.txt", "r");
    if (f) {
        // reading food
        fscanf(f, "%d:\n", &type.noOfFoodTypes);
        storeFoodAndPricesFromInput(&food.NoOfFoodOptions, &type.foodType, &food.FoodOption, &food.FoodPrice, type.noOfFoodTypes, f);
        fscanf(f, "%d:\n", &d.NoOfDrinks);
        storeDrinksAndPricesFromInput(&d.Drinks, d.NoOfDrinks,  &d.DrinkPrice, &d.NoOfDrinkOptions, f);

    } else {
        printf("%s:\n", LOAD_DATA); // same steps but from the console
        fscanf(stdin, "%d:\n", &type.noOfFoodTypes);
        storeFoodAndPricesFromInput(&food.NoOfFoodOptions, &type.foodType, &food.FoodOption, &food.FoodPrice, type.noOfFoodTypes, stdin);
        fscanf(stdin, "%d:\n", &d.NoOfDrinks);
        storeDrinksAndPricesFromInput(&d.Drinks, d.NoOfDrinks,  &d.DrinkPrice, &d.NoOfDrinkOptions, stdin);
    }
    fclose(f);
    f = fopen("users.txt", "r");
    fscanf(f,"%s",key);
    fclose(f);
    printf("\nWelcome to Food Thingies!\n");
    while (!orderPlaced) {
        switch (state) {
            case (SIGN_IN_OR_UP): {
                chooseSignInOrSignUp(&state);
                break;
            }
            case (SIGN_IN_STATE): {
                signInProcess(b.username,&state,key);
                break;
            }
            case (SIGN_UP_STATE): {
                signUpProcess(b.username,&state,key);
                break;
            }
            case (FOOD_TYPE): {
                printFoodTypes(type);
                specific.Food = getChoiceIndex(type.noOfFoodTypes, &state);
                if (state == 2)
                    state = 0;
                break;
            }
            case (SPECIFIC_FOOD): {
                printf("Please choose the type of %s:\n", type.foodType[specific.Food]);
                printFoodOptions(food.NoOfFoodOptions, food.FoodPrice, food.FoodOption, specific.Food);
                specific.Type = getChoiceIndex(food.NoOfFoodOptions[specific.Food], &state);
                break;
            }
            case (DRINK_OPTIONS): {
                printf("Please choose a drink to go with your %s:\n", type.foodType[specific.Food]);
                printDrinkOptions(d.NoOfDrinks, d.DrinkPrice, d.Drinks);
                specific.Drink = getChoiceIndex(d.NoOfDrinkOptions, &state);
                break;
            }
            case (CUTLERY): {
                printCutleryOptions();
                specific.Cutlery = getChoiceIndex(NoOfCutleryOptions, &state);
                break;
            }
            case (ADD_INFO): {
                getAdditionalInfo(b.additionalInfo);
                state++;
                break;
            }
            case (ORDER_SUMMARY): {
                printOrder(b.username, food.FoodOption, food.FoodPrice, d.Drinks,
                           d.DrinkPrice, b.additionalInfo, specific.Cutlery, specific.Food, specific.Type, specific.Drink, d.NoOfDrinks);
                orderConfirmation(&state, &orderPlaced);
                break;
            }
        }
    }
    // freeing the memory
    freeDrinks(&d);
    freeSpecificFood(&food, type.noOfFoodTypes);
    freeFoodType(&type);
    printf("Order confirmed! Thank you for buying from us, %s!", b.username);
    freeBuyer(&b);
    return 0;
}


