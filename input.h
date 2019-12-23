//
// Created by Cosmin on 05-Nov-19.
//

#ifndef FOOD_ORDERING_INPUT_H
#define FOOD_ORDERING_INPUT_H
#include "constants.h"
#include "food.h"
#include "drinks.h"

int getChoiceIndex(int noOfFoodTypes, int *state);
void getAdditionalInfo(char AddInfo[]);
void getDrinksAndPrice(char *Line, char ***Drinks, double **DrinkPrices);
void getFoodAndPrice(char *Line, char *FoodOption[], double FoodPrice[]);
void readFoodTypeAndNo(char **food, int *number, FILE *f);
void storeFoodAndPricesFromInput(specificFood *food, foodType *type, FILE *f);
void storeDrinksAndPricesFromInput(drinks *drink, FILE *f);


#endif //FOOD_ORDERING_INPUT_H
