//
// Created by Cosmin on 05-Nov-19.
//

#ifndef FOOD_ORDERING_ORDER_H
#define FOOD_ORDERING_ORDER_H
#include "constants.h"

void printOrderSummary(char username[], char FoodOption[][FOOD_OPTIONS][MAX_FOOD_OPTION_NAME], double FoodPrice[][FOOD_OPTIONS], char Drinks[][MAX_DRINK_NAME], double DrinkPrice[], int Cutlery, int Food, int Type, int Drink, int noOfDrinks );
void printTotalandAddInfo(char AddInfo[], double FoodPrice[][FOOD_OPTIONS], double DrinkPrice[], int Drink, int Food, int Type, int noOfDrinks);
void OrderConfirmation(int *state, int *orderPlaced);

#endif //FOOD_ORDERING_ORDER_H
