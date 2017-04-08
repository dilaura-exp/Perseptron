#include "stdafx.h"
#include <iostream>
#include "Perceptron.h"

using namespace std;

Perceptron::Perceptron() {
	cout << "Masukkan panjang input: ";
	cin >> inputLength;
	cout << "Masukkan panjang target: ";
	cin >> targetLength;
	initWeight();
	initInput();
	initTarget();
	initTreshold();
	initLearningRate();
}

Perceptron::Perceptron(int inputLength, int targetLength) {
	this->inputLength = inputLength;
	this->targetLength = targetLength;
	inputs = new float[inputLength] {
		0, 1, 0, 1, 1, 1, 1,
		1, 1, 0, 1, 0, 0, 0,
		0, 1, 0, 1, 1, 1, 1,
		0, 1, 0, 1, 0, 0, 1,
		1, 1, 1, 1, 1, 1, 1
	};
	cout << endl;
	initWeight();
	targets = new int[targetLength] {
		1, 0, 0, 0, 0
	};
	treshold = 0.5f;
	learningRate = 0.02f;
}


Perceptron::~Perceptron() {
	delete[] inputs;
	delete[] targets;
	for (int i = 0; i < inputLength; i++) {
		delete[] weights[i];
	}
}


void Perceptron::initInput() {
	inputs = new float[inputLength];
	cout << "Masukkan dataset input:\n";
	for (int i = 0; i < inputLength; i++) {
		cout << i << "/" << inputLength << ": ";
		cin >> inputs[i];
	}
	cout << endl;
}

void Perceptron::initWeight() {
	weights = new float*[inputLength];
	for (int i = 0; i < inputLength; i++) {
		weights[i] = new float[targetLength];
	}
	for (int i = 0; i < inputLength; i++) {
		for (int j = 0; j < targetLength; j++) {
			weights[i][j] = randomRange(0, 1);
			cout << "i: " << i << " j: " << j << " value: " << weights[i][j] << endl;
		}
	}
	cout << endl;
}

void Perceptron::initTarget() {
	targets = new int[targetLength];
	for (int i = 0; i < targetLength; i++) {
		cout << i << "/" << targetLength << ": ";
		cin >> targets[i];
	}
}

void Perceptron::initTreshold() {
	cout << "Masukkan treshold (0-1): ";
	cin >> treshold;
}

void Perceptron::initLearningRate() {
	cout << "Masukkan learning rate (0-1): ";
	cin >> learningRate;
	cout << endl;
}

float Perceptron::randomRange(float low, float high) { 
	return low + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (high - low)));
}

void Perceptron::recalculateWeight(int j, int i, int O) {
	weights[j][i] = weights[j][i] + learningRate * (targets[i] - O) * inputs[j];
}


void Perceptron::startTraining() {
	int i = 0;
	int j = 0;
	for (i = 0; i < targetLength; i++) {
		while (true) {
			float I = 0;
			for (j = 0; j < inputLength; j++) {
				I += weights[j][i] * inputs[j];
			}
			j--;
			int O = (I > treshold) ? 1 : 0;
			if (O == targets[i]) {
				cout << "O ke-" << i << ": " << O << endl;
				break;
			}
			else {
				recalculateWeight(j, i, O);
			}
		}
	}
}