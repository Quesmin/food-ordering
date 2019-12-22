//
// Created by Cosmin on 05-Nov-19.
//

#ifndef FOOD_ORDERING_OPTION_H
#define FOOD_ORDERING_OPTION_H
#include "constants.h"
#include "food.h"

void printFoodTypes(foodType f);
void printFoodOptions(int noOfFoodOptions[], double **FoodPrice, char ***FoodOption, int Food);
void printDrinkOptions(int noOfDrinks, double *DrinkPrice, char **Drinks);
void printCutleryOptions();

#endif //FOOD_ORDERING_OPTION_H
