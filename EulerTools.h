#pragma once
namespace EulerTools {
	bool isPrime(long long int amIPrime) {
		// eliminating 2 and 3 as prime
		if (amIPrime == 2 || amIPrime == 3) {
			return true; 
		} 
		
		// one and below can not be prime
		// evens are not prime
		// eliminate anything divisable by 3
		if (amIPrime <= 1 || amIPrime % 2 == 0 || amIPrime % 3 == 0) {
			return false;
		}

		// after eliminating all numbers above
		// every six numbers must be checked between 5 and sqrt(amIPrime)
		for (int potentialFactor = 5; potentialFactor * potentialFactor <= amIPrime; potentialFactor += 6) {
			if (amIPrime % potentialFactor == 0 || amIPrime % (potentialFactor + 2) == 0) {
				return false;
			}
		}

		return true;
	}

	void generatePrimes(int* primeList, const int numPrimes) {
		int count = 0;
		int currentNum = 0;

		while (count < numPrimes) {
			if (isPrime(currentNum) == true) {
				primeList[count] = currentNum;
				count++;
			}
			currentNum++;
		}
	}

	long long int  nthPrime(long long int n) {
		long long int count = 0;
		long long int current = 2; // first prime is two
		while (count < n) {
			if (isPrime(current) == true) {
				count++;
			}
			if (count == n) {
				return current;
			}
			current++;
		}
		return -1;
	}
}