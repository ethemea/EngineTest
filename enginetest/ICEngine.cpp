#include "ICEngine.h"

ICEngine::ICEngine() : Engine() {}

ICEngine::ICEngine(double TArea_) : Engine(TArea_) {}

ICEngine::ICEngine(double TArea_, double TOver_, double Hm_, double Hv_, double C_, double I_, vector <double> M_, vector <double> V_) : Engine (TArea_, TOver_, Hm_, Hv_, C_, I_, M_, V_) {}

int ICEngine::VHeat(int i) {
	int f = 0; // инициализация флага для отслеживания ошибок
	W += A; // расчет скорости 
	double m = -1.0; // крутящий момент 
	if (i == 0) {
		m = M1[i]; // в начальный момент времени m = 20
	} else {
		for (int j = 0; j < V1.size(); j++) {
			if (abs(W - V1[j]) <= 0.075) { // осуществляем поиск значения W в векторе
				m = M1[j]; // затем присваеваем по соответствующему индексу значение крутящего момента
				break;
			}
		}
	}
	if (m < 0) {
		f = 1; // если не был посчитан крутящий момент, то меняем значение флага
	} else {
		A = m / I; // иначе считаем ускорение 
		THeat = m * Hm + W * W * Hv; // и темп-ру нагревания
	}
	return f; // возвращаем значение флага
}

void ICEngine::VChill() {
	TChill = C * (TArea - TEngine); // рассчитываем значение темп-ры охлаждения
}

bool ICEngine::TChange() {
	bool f = false;
	TEngine = TEngine + TChill + THeat; // рассчитываем темп-ру двигателя
	if (TEngine >= TOver) { // если двигатель перегрелся, меняем зн-е флага
		f = true;
	}
	return f; // возвращаем значение флага
}