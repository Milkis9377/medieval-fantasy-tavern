#include "Tavern.h"
#include "Drinkdata.h"
#include <iostream>

using namespace std;

Tavern::Tavern() {
    gold = 100;
    yesterdayGold = 100;

    raceCount = 4;
    
    drinks = alldrinks;

    unlockedDrink.insert(&drinks[0]);
    unlockedDrink.insert(&drinks[1]);
}

int Tavern::getGold(){
    return gold;
}

int Tavern::getDrinksCount(){
    return drinks.size();
}

int Tavern::getUnlockedDrinkCount(){
    return unlockedDrink.size();
}

void Tavern::Unlocked_Drink(Drink& d){
    unlockedDrink.insert(&d);
}

Drink& Tavern::getDrink(int index){
    return drinks[index]; 
}

int Tavern::getYesterdayGold(){
    return yesterdayGold;
}

int Tavern::getraceCount(){
    return raceCount;
}
void Tavern::Update(){
    yesterdayGold = gold;
}

bool Tavern::havestock(const Drink& d){
    if(d.stock > 0){
        return true;
    } else {
        return false;
    }
}

bool Tavern::isUnlocked(Drink& d){
    return unlockedDrink.find(&d) != unlockedDrink.end();
}

void Tavern::sellDrink(Drink& d){
        gold += d.price;
        d.stock --;
}

void Tavern::makingDrink(Drink& d){
    d.stock += 20;
}

const std::set<Drink*>& Tavern::getunlockedDrink(){
    return unlockedDrink;
}

int Tavern::getDrinkIndex(Drink& d){
    for(int i = 0; i < drinks.size(); i++){
        if(&drinks[i] == &d){
            return i;
        }
    }

    return -1;
}

