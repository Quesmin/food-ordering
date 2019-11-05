//
// Created by Cosmin on 05-Nov-19.
//

#include <stdio.h>
#include "constants.h"

void printOrderSummary(char username[], char FoodOption[][FOOD_OPTIONS][MAX_FOOD_OPTION_NAME], double FoodPrice[][FOOD_OPTIONS], char Drinks[][MAX_DRINK_NAME], double DrinkPrice[], int Cutlery, int Food, int Type, int Drink, int noOfDrinks )
{
    printf("This is your order:\n");
    printf("-------------------\n");
    printf("Name: %s\n", username);
    printf("Food items:\n");
    printf("---%s: %.2f RON\n", FoodOption[Food][Type], FoodPrice[Food][Type]);
    if(Drink != noOfDrinks)
        printf("---%s: %.2f RON\n", Drinks[Drink],DrinkPrice[Drink]);
    if(Cutlery == 0)
        printf("Cutlery: yes\n");
    else
        printf("Cutlery: no\n");
}

void printTotalandAddInfo(char AddInfo[], double FoodPrice[][FOOD_OPTIONS], double DrinkPrice[], int Drink, int Food, int Type, int noOfDrinks)
{
    double total = 0;
    if(AddInfo[0] != '\0' && AddInfo[0] != '\n')
        printf("Additional info: \"%s\"\n", AddInfo);
    if(Drink == noOfDrinks)
        total = FoodPrice[Food][Type];
    else
        total = FoodPrice[Food][Type] + DrinkPrice[Drink];
    printf("Payment amount: %.2f RON\n", total);
    printf("-------------------\n");
    printf("a) Confirm order\n");
    printf("b) Go back\n");
}

void OrderConfirmation(int *state, int *orderPlaced)
{
    int choice;
    choice = getchar();
    getchar();
    if(choice == 'a' + 1)
        *state = 4;
    else
        *orderPlaced = 1;
}