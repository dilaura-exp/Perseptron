#pragma once
class Perceptron
{
public:
	Perceptron();
	Perceptron(int inputLength, int targetLength);
	~Perceptron();
	
	void startTraining();

private:
	void initInput();
	void initWeight();
	void initTarget();
	void initTreshold();
	void initLearningRate();
	float randomRange(float low, float high);
	void recalculateWeight(int j, int i, int O);

	int inputLength;
	int targetLength;

	float *inputs;
	int *targets;
	float **weights;
	float treshold;
	float learningRate;
};

