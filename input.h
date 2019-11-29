//
// Created by Cosmin on 05-Nov-19.
//

#ifndef FOOD_ORDERING_INPUT_H
#define FOOD_ORDERING_INPUT_H
#include "constants.h"

int getFoodOptionsNumber(char *line);
void userCredentialsStep (char username[], char password[], int *state);
int getChoiceIndex(int noOfFoodTypes, int *state);
void getAdditionalInfo(char AddInfo[]);
void getDrinksAndPrice(char *Line, char ***Drinks, double **DrinkPrices);
void getFoodAndPrice(char *Line, char *FoodOption[], double FoodPrice[]);
void readFoodType(char **save, FILE *f);


#endif //FOOD_ORDERING_INPUT_H
