#pragma once

#include "TestStand.h"
#include "ICEngine.h"
#include <iostream>

#define B 100 // врем€ симул€ции

using namespace std;

class TestICE :
    public TestStand
{
public:
    double enterValue() override;
    void getResult(double temp) override;
private:
    int start(ICEngine& test);
};

