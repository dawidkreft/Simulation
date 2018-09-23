#include "stdafx.h"
#include "Crand.h"
#include <cstdlib>


Crand::Crand()
{

	int srand = std::rand() % 40;
	setSeed(tab[srand]);
}

Crand::Crand(int x)
{
	int srand = std::rand();
	srand += x;
	setSeed(tab[srand % 40]);
}

void Crand::setSeed(int seed)
{
	x_ = seed;
}

double Crand::uniform()
{
	int h = x_ / q_;
	
	x_ = a_ * (x_ - q_ * h) - r_ * h;
	
	if (x_ < 0)
		x_ += 2147483647;
	return static_cast<double>(x_) / 2147483647;
}

double Crand::uniform(int a, int b)
{
	return uniform()*(b - a) + a;

}

double Crand::exponential(double lambda)
{
	return round(-lambda * log(uniform()));
}

int Crand::geometric(double p)
{
	int i = 1;
	while (uniform() > 1 / p)
		i++;
	return i;
}

double Crand::normal(double mean, double dev)
{
	double x = 0.0;
	for (int i = 0; i < 12; i++)
		x += uniform();

	return mean + sqrt(dev)*(x - 6.0);
}

bool Crand::blood_generator()
{

	return uniform(0, 1) > 0.4;    // true - A type blood
}


