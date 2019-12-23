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
        for (int j = 0; j < food->noOfFoodOptions[i]; j++)
            free(food->foodOption[i][j]);
        free(food->foodOption[i]);
        free(food->foodPrice[i]);
    }
    free(food->noOfFoodOptions);
    free(food->foodOption);
    free(food->foodPrice);
}
