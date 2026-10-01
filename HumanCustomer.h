#pragma once

#include "Customer.h"

class HumanCustomer : public Customer {
    public:
        HumanCustomer();

        void talk() override;
        void drink(Drink&) override;
        int choosingDrink(Tavern&) override;
};