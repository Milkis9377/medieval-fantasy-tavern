#pragma once

#include "Tavern.h"

class Customer{
    private :
        int gold;
    public :
        Customer();

        virtual void talk();
        virtual void drink(Drink&);
        virtual int choosingDrink(Tavern&);
        bool ordering(Tavern&);
        bool canafford(const Drink&);
        int getGold();
    
        virtual ~Customer() = default;
};