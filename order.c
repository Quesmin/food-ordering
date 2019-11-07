//
// Created by Cosmin on 05-Nov-19.
//

#include <stdio.h>
#include "constants.h"

void printOrderHeader(char username[])
{
    printf("This is your order:\n");
    printf("-------------------\n");
    printf("Name: %s\n", username);
}
void printOrderFood(char FoodOption[][FOOD_OPTIONS][MAX_FOOD_OPTION_NAME], double FoodPrice[][FOOD_OPTIONS], int Food, int Type )
{
    printf("Food items:\n");
    printf("---%s: %.2f RON\n", FoodOption[Food][Type], FoodPrice[Food][Type]);

}
void printOrderDrinks(char Drinks[][MAX_DRINK_NAME], double DrinkPrice[], int Drink, int noOfDrinks)
{
    if(Drink != noOfDrinks)
        printf("---%s: %.2f RON\n", Drinks[Drink],DrinkPrice[Drink]);
}
void printOrderCutlery(int Cutlery)
{
    if(Cutlery == 0)
        printf("Cutlery: yes\n");
    else
        printf("Cutlery: no\n");
}
void printOrderTotal(double total)
{

    printf("Payment amount: %.2f RON\n", total);
    printf("-------------------\n");
    printf("a) Confirm order\n");
    printf("b) Go back\n");
}
void printAddInfo(char AddInfo[])
{
    if(AddInfo[0] != '\0' && AddInfo[0] != '\n')
        printf("Additional info: \"%s\"\n", AddInfo);
}
void orderConfirmation(int *state, int *orderPlaced)
{
    int choice;
    choice = getchar();
    getchar();
    if(choice == 'a' + 1)
        *state = 4;
    else
        *orderPlaced = 1;
}