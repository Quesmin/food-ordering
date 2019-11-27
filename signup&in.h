//
// Created by Cosmin on 27-Nov-19.
//

#ifndef FOOD_ORDERING_SIGNUP_IN_H
#define FOOD_ORDERING_SIGNUP_IN_H

int isPasswordValid(char pass[], char username[]);
void signUpProcess(char username[], char password[], int *state);
void signInProcess(char username[], char password[], int *state);
void chooseSignInOrSignUp(int *state);



#endif //FOOD_ORDERING_SIGNUP_IN_H
