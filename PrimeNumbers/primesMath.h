#pragma once
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

//Dinamic programming applied to the expansion of Pascal's Triangle
vector<vector<unsigned long long int>> pascalTriangleMemory;

/*This function returns true if a and b are congruent module n and return false otherwise*/
bool congrModN(int a, int b, int n){
	/*
	The definition of congruence module n says that two integers a and b are congruents if, and only if, n divides a-b
	*/
	if ((a-b)%n == 0) return true;
	else return false;
}

/*This function calculates the greatest common divisor between two integers a and b using the extended euclidean algorithm*/
int GCD(int a, int b) {
	int gcd, max, min, aux;
	/*the next 10 lines are responsible to define the greater number and get values in order so division can occur normally*/
	if (a <= b)
	{
		min = a;
		max = b;
	}
	else
	{
		min = b;
		max = a;
	}

	/*
	here I use the expansion on Euclids' Division Algorithm applied to the calculus of GCD. This algorithm says that the last rest of division before 0 is the GCD between the two integers given
	*/
	while (min > 0)
	{
		/*In each loop the function verify if the max value divided by the minimum value results zero, if this occur then min is the GCD*/
		if (max % min == 0)
		{
			gcd = min;
			break;
		}
		/* Here the division is calculated and the minimum value receives the rest of division between max and min */
		aux = max % min;
		max = min;
		min = aux;
	}
	return gcd;
}

/*This function calculates the Euler totient function of an integer n
Given an integer n, the Euler's totient function calculates the number of integers a less or equal then n that GCD(a,n) == 1
So it tries each integer a that 1 <= a <= n and count each success. In the end it returns the count value*/
int EulerPhi(int n) {
	int count = 1;
	for (int i = 2; i < n; i++)
	{
		if (GCD(i,n) == 1)
		{
			count++;
		}
	}
	return count;
}

/*Given two integers a and n, this function calculates tor order of a module n
In other words we are seaching for an integer k so that a^k is congruent to 1 module n
This integer k can be found only if gcd(a,n) == 1 */
int ord(int a, int n) {
	int count = 1, modA = a % n, val = modA;

	/*The definition of ordn(a) says that the number a is just invertible if, and only if, GCD(a,n) == 1
	So if GCD(a,n) is not equal to 1, then does not exists ordn(a)*/
	if (GCD(a,n) != 1)
	{
		cout << "The integer a is not inversible mod n!\n";
		return 0;
	}
	else
	{
		while (!congrModN(val, 1, n))
		{
			val = (val * modA)%n;
			count++;
		}
		return count;
	}
}

/*the next function will be necessary to discover the expansion of (X + a)^n on the Zn field. We'll use it to find whether (X + A)^n is congruent to X^n + 1 (mod X^r -1, n) or not. 
So, we'll need two integers: n and a, which are respectively the exponent of the power and the coeficient of degree 0 in the polynomial X + a. 
We also need two empty vectors coef and listcoef to store those coeficients different from zero and which exponent of the polynomial doesn't have coeficient congruent to zero.*/

std::vector<unsigned long long int> pascalTriangle(int n) {
	int count = 0;
	
	//Using the values allocated at pascalTriangleMemory
	if (n < pascalTriangleMemory.size()) {
		return pascalTriangleMemory[n];
	} else {
		//define the vector that will be returned 
		std::vector<unsigned long long int> v;

		//verify if pascalTriangleMemory is empty
		if (pascalTriangleMemory.size() == 0) {
			v.push_back(1);
			if (pascalTriangleMemory.size() == 0){
				pascalTriangleMemory.push_back(v);
			}
			if (n == 0)
			{
				return v;
			}
			
			//Here each loop will form the i-th line of pascal triangle
			for (int i = 1; i <= n; i++)
			{
				//here we calculate the values of the i-th line
				for (int j = i; j > 0; j--)
				{
					if (j == i)
					{
						v.push_back(1);
						continue;
					}
					else {
						v[j] = v[j] + v[j-1];
					}
				}
				//the line below was used for debug
				//cout << ++count << '\n';

				//hereeach line is added to pascalTriangleMemory so it can be used easily when it's necessary
				pascalTriangleMemory.push_back(v);
			}
			cout << "\n\n";
		} else { //Here it'll continue the pascal's triangle calculation after the last element of pascalTriangleMemory
			v = pascalTriangleMemory.back();
			for (int i = pascalTriangleMemory.size(); i <= n; i++)
			{
				for (int j = i; j > 0; j--)
				{
					if (j == i)
					{
						v.push_back(1);
						continue;
					}
					else {
						v[j] = v[j] + v[j-1];
					}
				}
				cout << i << '\n';
				pascalTriangleMemory.push_back(v);
			}
			cout << "\n\n";
		}

		return v;
	}
}

