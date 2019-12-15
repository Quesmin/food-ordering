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
void readFoodTypeAndNo(char **food, int *number, FILE *f);
void storeFoodAndPricesFromInput(int **NoOfFoodOptions, char ***FoodType, char ****FoodOption, double ***FoodPrice, int NoOfFoodTypes, FILE *f);
void storeDrinksAndPricesFromInput(char ***Drinks, int NoOfDrinks, double **DrinkPrice, int *NoOfDrinkOptions, FILE *f);


#endif //FOOD_ORDERING_INPUT_H
