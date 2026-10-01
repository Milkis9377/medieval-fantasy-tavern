#pragma once

#include "Customer.h"

class DwarfCustomer : public Customer {
    public:
        DwarfCustomer();

        void talk() override;
        void drink(Drink&) override;
        int choosingDrink(Tavern&) override;
};