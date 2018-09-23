#pragma once


class Crand
{

	int x_ = 0;
	int a_ = 16807;
	int q_ = 127773;
	int r_ = 2836;
	int tab[40] = { 3119,1523,4027,181,6571,883,10181,263,2389,3253,1471,467,1213,2731,3571,3847,7393,9931,8191,
		11813,9803,16087,14197,13147,15401,4177,5879,7793,10663,8863,7927,10657,12553,14033,13009,16831,17389,13463,37,2053 };


public:

	Crand();
	Crand(int x);
	void setSeed(int seed);
	double uniform();  //generate a random number (0, 1)
	double uniform(int a, int b);
	double exponential(double lambda); //exponential, mean lambda
	int geometric(double p);
	double normal(double mean, double dev);
	bool blood_generator();
};
