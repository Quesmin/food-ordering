#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "option.h"
#include "order.h"

#define LOAD_DATA "Please load data"
#define MAX_FOOD 30

void readFoodType(char *save, FILE *f);


int main() {
    //printf("%s:\n", LOAD_DATA);
    FILE *f = fopen("data.txt", "r");

    char username[20];
    char password[20];
    char AddInfo[100];
    int Food, Type, Drink, Cutlery;
    int state = 0;
    int orderPlaced = 0;
    int NoOfFoodTypes, NoOfDrinks, NoOfDrinkOptions, NoOfCutleryOptions;
    double *DrinkPrice;
    int *NoOfFoodOptions;
    char **FoodType;
    char **Drinks;
    char ***FoodOption;
    double **FoodPrice;

    fscanf(f,"%d:", &NoOfFoodTypes);
    fgetchar();
    *NoOfFoodOptions = (int*)malloc(NoOfFoodTypes * sizeof(int));
    **FoodType = (char **)malloc(NoOfFoodTypes * sizeof(char *));
    for(int i=0; i<NoOfFoodTypes; i++)
    {
        FoodType[i] = (char *)malloc(MAX_FOOD * sizeof(char));
        readFoodType(FoodType[i]);
        char *p;
        p = strtok()

    }
    printf("Welcome to Food Thingies!\nPlease sign in to continue!\n");

    while(!orderPlaced)
    {
        switch (state){
            case(0):{
                userCredentialsStep(username, password, &state);
                break;
            }
            case(1):{
                printFoodTypes(NoOfFoodTypes, FoodType);
                Food = getChoiceIndex(NoOfFoodTypes, &state);
                break;
            }
            case(2):{
                printf("Please choose the type of %s:\n", FoodType[Food]);
                printFoodOptions(NoOfFoodOptions, FoodPrice, FoodOption, Food);
                Type = getChoiceIndex(NoOfFoodOptions[Food], &state);
                break;
            }
            case(3):{
                printf("Please choose a drink to go with your %s:\n", FoodType[Food]);
                printDrinkOptions(NoOfDrinks, DrinkPrice, Drinks);
                Drink = getChoiceIndex(NoOfDrinkOptions, &state);
                break;
            }
            case(4):{
                printCutleryOptions();
                Cutlery = getChoiceIndex(NoOfCutleryOptions, &state);
                break;
            }
            case(5):{
                getAdditionalInfo(AddInfo);
                state++;
                break;
            }
            case(6):{
                printOrder( username, FoodOption, FoodPrice, Drinks,
                 DrinkPrice, AddInfo, Cutlery, Food, Type, Drink, NoOfDrinks);
                orderConfirmation(&state, &orderPlaced);
                break;
            }
        }
    }
    printf("Order confirmed! Thank you for buying from us, %s!", username);
    return 0;
}

void readFoodType(char *save, FILE *f)
{
    int i=0;
    char c = fgetc(f);
    while(c!=' ')
    {
        save[i++] = c;
        c = fgetc(f);
    }
    save[--i] = '\0';
}