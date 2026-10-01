#include "Customer.h"
#include <iostream>

using namespace std;

Customer:: Customer(){
    gold = 50;
}

void Customer:: talk(){
    cout << "Hello!" << endl;
}

void Customer:: drink(Drink& d){
    cout << "The customer drank a cup of " << d.name << "." << endl;
}

int Customer::choosingDrink(Tavern& t){
    return rand() % t.getDrinksCount();
}

int Customer:: getGold(){
    return gold;
}

bool Customer::canafford(const Drink& d){
    if(gold >= d.price){
        return true;
    } else {
        return false;
    }
}

bool Customer:: ordering(Tavern& t){
    int d = choosingDrink(t);
    bool affordable = canafford(t.getDrink(d));
    bool stocked = t.havestock(t.getDrink(d));
    if(affordable && stocked){
        t.sellDrink(t.getDrink(d));
        gold -= t.getDrink(d).price;
        drink(t.getDrink(d));
        return true;
    } 
    if(!affordable){
        cout << "Customer can't afford it!" << endl;
    } 
    if(!stocked){
        cout << "There's no stock! Please make it." << endl;
    }
    return false;
}

