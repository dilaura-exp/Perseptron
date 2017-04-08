// SingleLayerPerseptron.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Perceptron.h"

using namespace std;

int main() {
	Perceptron perceptron(35, 5);
	perceptron.startTraining();

	system("Pause");
	return 0;
}

