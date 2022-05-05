#include "TestICE.h"

void init();

int main() {
	init();
	return 0;
}

void init() { // функция запуска тестового стенда
	TestICE stand; // создаем тестовый стенд для ДВС
	stand.getResult(stand.enterValue()); // ввод значения и получение результата
}