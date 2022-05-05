#pragma once
#include <vector>
using namespace std;
class Engine
{
public:
	Engine(); // конструктор по умолчанию
	Engine(double TArea_); // конструктор с параметром температуры
	Engine(double TArea_, double TOver_, double Hm_, double Hv_, double C_, double I_, vector <double> M_, vector <double> V_); // конструктор с параметрами
	virtual int VHeat(int i) = 0; // чисто виртуальная функция расчета темп-ры нагревания
	virtual void VChill() = 0; // чисто виртуальная функция расчета темп-ры охлаждения

protected:
	double THeat = 0, TChill = 0, W = 0, // поля темп-ры нагревания, охлаждения, угловой скорости
		A = 0, TEngine, TArea, TOver, // ускорения, темп-ры двигателя, окр. среды, перегрева
		Hm, Hv, C, I; // коэфф-ты зависимостей
	vector <double> M, V, M1, V1; // векторы со значениями крутящего момента и скорости
	void SetValues(); // функция, задающая значения полям объекта класса
	void SetMV(); // функция, воссоздающая численный ряд крутящего момента в зависимости от скорости

};

