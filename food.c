//
// Created by Cosmin on 22-Dec-19.
//
#include <stdlib.h>
#include "food.h"
void freeFoodType( foodType *type){
    for (int i = 0; i < type->noOfFoodTypes; i++)
        free(type->foodType[i]);
    free(type->foodType);

}
void freeSpecificFood( specificFood *food, int noOfFoodTypes){
    for (int i = 0; i < noOfFoodTypes; i++) {
        for (int j = 0; j < food->NoOfFoodOptions[i]; j++)
            free(food->FoodOption[i][j]);
        free(food->FoodOption[i]);
        free(food->FoodPrice[i]);
    }
    free(food->NoOfFoodOptions);
    free(food->FoodOption);
    free(food->FoodPrice);
}
