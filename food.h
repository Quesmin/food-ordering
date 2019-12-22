//
// Created by Cosmin on 22-Dec-19.
//

#ifndef FOOD_ORDERING_FOOD_H
#define FOOD_ORDERING_FOOD_H

typedef struct _choice{
    int Food, Type, Drink, Cutlery;
}choice;

typedef struct _foodType{
    char **foodType;
    int noOfFoodTypes;
}foodType;

typedef struct _specificFood{
    int *NoOfFoodOptions;
    char ***FoodOption;
    double **FoodPrice;

}specificFood;
void freeSpecificFood( specificFood *food, int noOfFoodTypes);
void freeFoodType( foodType *type);

#endif //FOOD_ORDERING_FOOD_H
