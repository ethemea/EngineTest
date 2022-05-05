#pragma once
#include "Engine.h"

class ICEngine :
    public Engine
{
public:
	ICEngine(); // конструктор по умолчанию
	ICEngine(double TArea_); // конструктор с параметром температуры
	ICEngine(double TArea_, double TOver_, double Hm_, double Hv_, double C_, double I_, vector <double> M_, vector <double> V_); // конструктор с параметрами
private:
	int VHeat(int i) override; // функция расчета темп-ры нагревания
	void VChill() override; // функция расчета темп-ры охлаждения
	bool TChange(); // функция расчета темп-ры двигателя

	friend class TestICE; // класс TestICE дружественнен по отн-ю к классу ICEngine
};

