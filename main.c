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
    int noOfFoodTypes = 3, noOfDrinks = 4, noOfDrinkOptions = 5, noOfCutleryOptions = 2;
    double DrinkPrice[] = {5,5,5,4};
    int noOfFoodOptions[3] = {3,2,4};
    char FoodType[3][10] = {"Pizza", "Pasta", "Salad"};
    char Drinks[4][10] = {"Coca-Cola", "Fanta", "Lipton", "Water"};
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
        switch (state){
            case(0):{
                userCredentialsStep(username, password, &state);
                break;
            }
            case(1):{
                printFoodTypes(noOfFoodTypes, FoodType);
                Food = getChoiceIndex(noOfFoodTypes, &state);
                break;
            }
            case(2):{
                printf("Please choose the type of %s:\n", FoodType[Food]);
                printFoodOptions(noOfFoodOptions, FoodPrice, FoodOption, Food);
                Type = getChoiceIndex(noOfFoodOptions[Food], &state);
                break;
            }
            case(3):{
                printf("Please choose a drink to go with your %s:\n", FoodType[Food]);
                printDrinkOptions(noOfDrinks, DrinkPrice, Drinks);
                Drink = getChoiceIndex(noOfDrinkOptions, &state);
                break;
            }
            case(4):{
                printCutleryOptions();
                Cutlery = getChoiceIndex(noOfCutleryOptions, &state);
                break;
            }
            case(5):{
                getAdditionalInfo(AddInfo);
                state++;
                break;
            }
            case(6):{
                printOrderHeader(username);
                printOrderFood( FoodOption, FoodPrice, Food, Type);
                printOrderDrinks(Drinks, DrinkPrice, Drink, noOfDrinks);
                printOrderCutlery(Cutlery);
                printAddInfo(AddInfo);
                double total = 0;
                if(Drink == noOfDrinks)
                    total = FoodPrice[Food][Type];
                else
                    total = FoodPrice[Food][Type] + DrinkPrice[Drink];
                printOrderTotal(total);
                orderConfirmation(&state, &orderPlaced);
                break;
            }
        }
    }
    printf("Order confirmed! Thank you for buying from us, %s!", username);
    return 0;
}
