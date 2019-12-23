//
// Created by Cosmin on 22-Dec-19.
//
#include <stdlib.h>
#include "drinks.h"
void freeDrinks( drinks *d){

    for (int i = 0; i < d->noOfDrinks; i++)
        free(d->Drinks[i]);
    free(d->Drinks);
    free(d->drinkPrice);
}