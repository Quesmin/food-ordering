//
// Created by Cosmin on 22-Dec-19.
//

#ifndef FOOD_ORDERING_DRINKS_H
#define FOOD_ORDERING_DRINKS_H

typedef struct _drinks{
    int  NoOfDrinks, NoOfDrinkOptions;
    double *DrinkPrice;
    char **Drinks;
}drinks;
void freeDrinks( drinks *d);

#endif //FOOD_ORDERING_DRINKS_H
