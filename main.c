#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "option.h"
#include "order.h"
#include "constants.h"

void readFoodType(char *save, FILE *f);
void getFoodAndPrice(char *Line, char *FoodOption[], double FoodPrice[], int *NoOfFoodOptions);


int main() {
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
    FILE *f;
    f = fopen("C:\\Users\\Cosmin\\Desktop\\CP\\food-ordering\\data.txt", "r");
    if(f) {

        fscanf(f, "%d:\n", &NoOfFoodTypes);
        NoOfFoodOptions = (int *) malloc(NoOfFoodTypes * sizeof(int));
        FoodType = (char **) malloc(NoOfFoodTypes * sizeof(char *));
        FoodOption = (char ***) malloc(NoOfFoodTypes * sizeof(char **));
        FoodPrice = (double **)malloc(NoOfFoodTypes * sizeof(double*));
        for (int i = 0; i < NoOfFoodTypes; i++) {
            FoodType[i] = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
            FoodOption[i] = (char **)malloc(FOOD_OPTIONS * sizeof(char*));
            FoodPrice[i] = (double *)malloc(FOOD_OPTIONS * sizeof(double));
            readFoodType(FoodType[i], f);
            char Line[100];
            fscanf(f,"%[^\n]", Line);
            getFoodAndPrice(Line, FoodOption[i], FoodPrice[i],&NoOfFoodOptions[i]);
            printf("%s %lf %d\n", FoodOption[i][0], FoodPrice[i][0], NoOfFoodOptions[i]);
            fgetc(f);
        }
    }
    else {
        printf("%s:\n", LOAD_DATA);

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
void getFoodAndPrice(char *Line, char *FoodOption[], double FoodPrice[], int *NoOfFoodOptions)
{
   int OkBegin = 0;
   int i=0, k=0, Options =0;
   while(i < strlen(Line))
   {
       if(Line[i] == '(') {
           OkBegin = 1; Options++; k=0;
           i++;
           continue;
       }
       if(OkBegin == 1)
       {
           FoodOption[Options-1] = (char*)malloc(MAX_FOOD_OPTION_NAME * sizeof(char));
           while(Line[i] != '-')
           {
               FoodOption[Options-1][k++] = Line[i++];
           }
           FoodOption[Options-1][(strlen(FoodOption[Options-1]))-1] = '\0';
           i = i+2;
           char Number[20];
           k=0;
            printf("%s\n", FoodOption[Options-1]);
           while(Line[i] != ')')
           {
               Number[k++] = Line[i++];
           }
           sscanf(Number,"%lf",FoodPrice[Options-1]);
           i++; OkBegin = 0;
           printf("%lf %s\n", FoodPrice[Options-1],Number);


       }
       i++;

   }
   *NoOfFoodOptions = Options;
}