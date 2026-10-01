#include <iostream>
#include "HumanCustomer.h"
#include "Tavern.h"

using namespace std;

HumanCustomer:: HumanCustomer(){

}

void HumanCustomer:: talk() {
    int c = rand() % 2;
    switch (c) 
    {
        case 0:
            cout << "Line 0" << endl;
            break;
        case 1: 
            cout << "Line 1" << endl;
            break;
        default:
            break;
    }  
}

void HumanCustomer:: drink(Drink& d){
    int c = rand() % 2;
    switch (c) 
    {
        case 0:
            cout << "Line 0 " << d.name << "." << endl;
            break;
        case 1: 
            cout << "Line 1 " << d.name << "." << endl;
            break;
        default:
            break;
    }  
}

int HumanCustomer:: choosingDrink(Tavern& t){
    int other_weight = 0;
    int juice_weight = 0;
    int alcohol_weight = 0;

    for(Drink* d : t.getunlockedDrink()){
        if(d->type == Drinktype::Other){
            other_weight = 30;
        } else if(d->type == Drinktype::Juice){
            juice_weight = 30;
        } else if(d->type == Drinktype::Alcohol){
            alcohol_weight = 40 ;
        }
    }

    int total_weight = other_weight + juice_weight + alcohol_weight;

    if(total_weight == 0){
        return -1;
    }

    int c = rand() % total_weight;
    Drinktype chosentype;
    if(c < other_weight){
        chosentype = Drinktype::Other;  
    } else if(c < other_weight + juice_weight){
        chosentype = Drinktype::Juice;
    } else if(c < other_weight + juice_weight + alcohol_weight){
        chosentype = Drinktype::Alcohol;
    }
    int count = 0;
    for(Drink* d : t.getunlockedDrink()){
        if(d->type == chosentype){
            count++;
        }
    }

    int r = rand() % count;
    for(Drink* d : t.getunlockedDrink()){
        if(d->type == chosentype){
            if(r == 0){
                return t.getDrinkIndex(*d);
            }
            r--;
        }
    }
    return -1;
}