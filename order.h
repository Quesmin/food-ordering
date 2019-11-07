//
// Created by Cosmin on 05-Nov-19.
//

#ifndef FOOD_ORDERING_ORDER_H
#define FOOD_ORDERING_ORDER_H
#include "constants.h"

void printOrderHeader(char username[]);
void printOrderFood(char FoodOption[][FOOD_OPTIONS][MAX_FOOD_OPTION_NAME], double FoodPrice[][FOOD_OPTIONS], int Food, int Type );
void printOrderDrinks(char Drinks[][MAX_DRINK_NAME], double DrinkPrice[], int Drink, int noOfDrinks);
void printOrderCutlery(int Cutlery);
void printAddInfo(char AddInfo[]);
void printOrderTotal(double total);
void orderConfirmation(int *state, int *orderPlaced);

#endif //FOOD_ORDERING_ORDER_H
