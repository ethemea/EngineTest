#pragma once

class TestStand
{
protected:
	double virtual enterValue() = 0;
	void virtual getResult(double temp) = 0;
};

