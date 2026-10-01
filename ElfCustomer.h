#pragma once

#include "Customer.h"

class ElfCustomer : public Customer {
    public:
        ElfCustomer();

        void talk() override;
        void drink(Drink&) override;
        int choosingDrink(Tavern&) override;
};