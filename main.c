#include <stdio.h>
#include "input.h"
#include "option.h"
#include "order.h"

int main() {
    printf("Welcome to Food Thingies!\nPlease sign in to continue!\n");
    char username[20];
    char password[20];
    char AddInfo[100];
    int Food, Type, Drink, Cutlery;

    int state = 0;
    int orderPlaced = 0;
    int noOfFoodTypes = 3;
    int noOfDrinks = 4, noOfDrinkOptions = 5;
    int noOfCutleryOptions = 2;
    char FoodType[3][10] = {"Pizza", "Pasta", "Salad"};
    char Drinks[4][10] = {"Coca-Cola", "Fanta", "Lipton", "Water"};
    double DrinkPrice[] = {5,5,5,4};
    int noOfFoodOptions[3] = {3,2,4};
    char FoodOption[3][4][50] = {
            {"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita" },
            {"Chicken alfredo", "Mac&Cheese"},
            {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}
    };
    double FoodPrice[3][4] = {
            {21,23,19},
            {23,21},
            {23,22,19,21}
    };

    while(!orderPlaced)
    {
        switch (state)
        {
            case(0):
            {
                getUserCredentials(username, password, &state);
                break;
            }
            case(1):
            {
                printFoodTypes(noOfFoodTypes, FoodType);
                Food = getChoiceIndex(noOfFoodTypes, &state);
                break;
            }
            case(2):
            {
                printFoodOptions(noOfFoodOptions, FoodPrice, FoodType, FoodOption, Food);
                Type = getChoiceIndex(noOfFoodOptions[Food], &state);
                break;
            }
            case(3):
            {
                printDrinkOptions(noOfDrinks, DrinkPrice, FoodType, Drinks, Food);
                Drink = getChoiceIndex(noOfDrinkOptions, &state);
                break;
            }
            case(4):
            {
                printCutleryOptions();
                Cutlery = getChoiceIndex(noOfCutleryOptions, &state);
                break;
            }
            case(5):
            {
                getAdditionalInfo(AddInfo, &state);
                break;
            }
            case(6):
            {
                printOrderSummary(username, FoodOption, FoodPrice, Drinks, DrinkPrice, Cutlery, Food, Type, Drink, noOfDrinks);
                printTotalandAddInfo(AddInfo, FoodPrice, DrinkPrice, Drink, Food, Type, noOfDrinks);
                OrderConfirmation(&state, &orderPlaced);
                break;
            }
        }
    }
    printf("Order confirmed! Thank you for buying from us, %s!", username);
    return 0;
}
