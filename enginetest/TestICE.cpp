#include "TestICE.h"

double TestICE::enterValue() {
	double temp;
	while (true) { // программа будет запрашивать данные до тех пор, пока не будут введены корректные значения
		cout << "Enter the temperature: ";
		cin >> temp;

		if (cin.fail()) { // проверка на корректность введенных данных
			cin.clear();
			cin.ignore(32767, '\n');
		} else {
			break;
		}
	}
	return temp;
}

void TestICE::getResult(double temp) {
	ICEngine test(temp); // создаем ДВС

	int time = start(test); // получаем искомое время
	switch (time) {
	case -1:
		cout << "The engine hasn't overheated\n"; // за заданное время двигатель не перегрелся
		break;
	case -2:
		cout << "Not enough data to simulate\n"; // недостаточно данных для симуляции работы двигателя
		break;
	default:
		cout << "The time it took for the engine to overheat: " << time << " seconds\n"; // вывод времени перегревания двигателя
	}
}

int TestICE::start(ICEngine& test) {
	int i, j = -1;

	for (i = 0; i < B; i++) {
		if (test.VHeat(i)) { // расчет темп-ры нагревания
			j = -2; //если не был посчитан крутящий момент - выход из цикла
			break;
		}
		test.VChill(); // расчет темп-ры охлаждения
		if (test.TChange()) { // если двигатель перегрелся, то выходим из цикла
			j = i;
			break;
		}
	}

	return j; // возвращаем время или ошибку
}