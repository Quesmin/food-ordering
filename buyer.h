//
// Created by Cosmin on 22-Dec-19.
//

#ifndef FOOD_ORDERING_BUYER_H
#define FOOD_ORDERING_BUYER_H

typedef struct _buyer{
    char *username;
    char *password;
    char *additionalInfo;
}buyer;
buyer createBuyer();
void freeBuyer(buyer *b);
#endif //FOOD_ORDERING_BUYER_H
