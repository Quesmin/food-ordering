//
// Created by Cosmin on 05-Nov-19.
//

#ifndef FOOD_ORDERING_INPUT_H
#define FOOD_ORDERING_INPUT_H
#include "constants.h"

void userCredentialsStep (char username[], char password[], int *state);
int getChoiceIndex(int noOfFoodTypes, int *state);
void getAdditionalInfo(char AddInfo[]);

#endif //FOOD_ORDERING_INPUT_H
