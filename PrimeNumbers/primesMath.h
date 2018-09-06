#pragma once
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;


/*This function returns true if a and b are congruent module n and return false otherwise*/
bool congrModN(int a, int b, int n){
	if ((a-b)%n == 0) return true;
	else return false;
}

/*This function calculates the greatest common divisor between two integers a and b using the extended euclidean algorithm*/
int GCD(int a, int b) {
	int gcd, max, min, aux;
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
	while (min > 0)
	{
		if (max % min == 0)
		{
			gcd = min;
			break;
		}
		aux = max % min;
		max = min;
		min = aux;
	}
	return gcd;
}

/*This function calculates the Euler totient function of an integer n*/
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
This integer k can be found only if gcd(a,n) = 1 */
int ord(int a, int n) {
	int count = 1, modA = a % n, val = modA;
	if (GCD(a,n) != 1)
	{
		//cout << "The integer a is not inversible mod n!\n";
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
//Space to Pascal Triangle function implementation

