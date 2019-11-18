//
// Created by Cosmin on 05-Nov-19.
//

#ifndef FOOD_ORDERING_ORDER_H
#define FOOD_ORDERING_ORDER_H
#include "constants.h"

void printOrder(char username[], char FoodOption[][FOOD_OPTIONS][MAX_FOOD_OPTION_NAME], double FoodPrice[][FOOD_OPTIONS], char Drinks[][MAX_DRINK_NAME],
                double DrinkPrice[], char AddInfo[], int Cutlery, int Food, int Type, int Drink, int NoOfDrinks);
void printOrderHeader(char username[]);
void printOrderFood(char* Food, double Price );
void printOrderDrinks(char* Drink, double Price, int NoOfDrinks);
void printOrderCutlery(int Cutlery);
void printAddInfo(char AddInfo[]);
void printOrderTotal(double total);
void orderConfirmation(int *state, int *orderPlaced);

#endif //FOOD_ORDERING_ORDER_H
