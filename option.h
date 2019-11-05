//
// Created by Cosmin on 05-Nov-19.
//

#ifndef FOOD_ORDERING_OPTION_H
#define FOOD_ORDERING_OPTION_H
#include "constants.h"

void printFoodTypes(int noOfFoodTypes, char FoodType[][MAX_FOOD_TYPE_NAME]);
void printFoodOptions(int noOfFoodOptions[], double FoodPrice[][FOOD_OPTIONS], char FoodType[][MAX_FOOD_TYPE_NAME], char FoodOption[][FOOD_OPTIONS][MAX_FOOD_OPTION_NAME], int Food);
void printDrinkOptions(int noOfDrinks, double DrinkPrice[], char FoodType[][MAX_FOOD_TYPE_NAME], char Drinks[][MAX_DRINK_NAME], int Food);
void printCutleryOptions();

#endif //FOOD_ORDERING_OPTION_H
