#include <iostream>
#include <string>

/*
intSqrt :: Integer -> Integer
intSqrt n = floor $ sqrt $ fromInteger n

primes :: [Integer] -> [Integer]
primes [] = []; primes (h:t) = h : primes [x | x <- t, x `mod` h /= 0]

primeFactors :: Integer -> [Integer]
primeFactors n = primes [x | x <- [2..intSqrt n], n `mod` x == 0]

greatestPrimeFactor :: Integer -> Integer
greatestPrimeFactor n = last $ primeFactors n
*/

int main(int argc, char **argv) {
	long int number = 13195;
	number = 600851475143;
	if (argc == 2)
		number = std::stol(argv[1]);
	std::cout << number << std::endl;

	for (int i = 2; i * i <= number; i ++) {
		while (!(number % i))
			number /= i;
	}
	std::cout << number << std::endl;

	return 0;
}
