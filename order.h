//
// Created by Cosmin on 05-Nov-19.
//

#ifndef FOOD_ORDERING_ORDER_H
#define FOOD_ORDERING_ORDER_H
#include "constants.h"
#include "buyer.h"
#include "food.h"
#include "drinks.h"

void printOrder(buyer b, choice specific, specificFood food, drinks drink);
void printOrderHeader(char username[]);
void printOrderFood(specificFood food, choice specific);
void printOrderDrinks(drinks drink, choice specific);
void printOrderCutlery(int Cutlery);
void printAddInfo(char AddInfo[]);
void printOrderTotal(double total);
void orderConfirmation(int *state, int *orderPlaced);

#endif //FOOD_ORDERING_ORDER_H
