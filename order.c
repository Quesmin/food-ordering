//
// Created by Cosmin on 05-Nov-19.
//

#include <stdio.h>
#include "buyer.h"
#include "food.h"
#include "drinks.h"

void printOrderHeader(char username[])
{
    printf("This is your order:\n");
    printf("-------------------\n");
    printf("Name: %s\n", username);
}
void printOrderFood(specificFood food, choice specific)
{
    printf("Food items:\n");
    printf("---%s: %.2f RON\n", food.foodOption[specific.Food][specific.Type], food.foodPrice[specific.Food][specific.Type]);

}
void printOrderDrinks(drinks drink, choice specific)
{
    if(specific.Drink != drink.noOfDrinkOptions - 1) // decrement with 1 because we convert to index
        printf("---%s: %.2f RON\n", drink.Drinks[specific.Drink],drink.drinkPrice[specific.Drink]);
}
void printOrderCutlery(int Cutlery)
{
    if(Cutlery == 0)
        printf("Cutlery: yes\n");
    else
        printf("Cutlery: no\n");
}
void printOrderTotal(double total)
{

    printf("Payment amount: %.2f RON\n", total);
    printf("-------------------\n");
    printf("a) Confirm order\n");
    printf("b) Go back\n");
}
void printAddInfo(char AddInfo[])
{
    if(AddInfo[0] != '\0' && AddInfo[0] != '\n')
        printf("Additional info: \"%s\"\n", AddInfo);
}
void orderConfirmation(int *state, int *orderPlaced)
{
    int choice;
    choice = getchar();
    getchar();
    if(choice == 'a' + 1)
        *state = 6;
    else
        *orderPlaced = 1;
}
void printOrder(buyer b, choice specific, specificFood food, drinks drink)
{
    printOrderHeader(b.username);
    printOrderFood(food, specific);
    printOrderDrinks(drink, specific);
    printOrderCutlery(specific.Cutlery);
    printAddInfo(b.additionalInfo);
    double total = 0;
    if(specific.Drink == drink.noOfDrinks)
        total = food.foodPrice[specific.Food][specific.Type];
    else
        total = food.foodPrice[specific.Food][specific.Type] + drink.drinkPrice[specific.Drink];
    printOrderTotal(total);
}