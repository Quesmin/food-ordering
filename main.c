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
    int NoOfFoodTypes = 3, NoOfDrinks = 4, NoOfDrinkOptions = 5, NoOfCutleryOptions = 2;
    double DrinkPrice[] = {5,5,5,4};
    int NoOfFoodOptions[3] = {3,2,4};
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
    printf("Order confirmed! Thank you for buying from us, %s!", username);
    return 0;
}
