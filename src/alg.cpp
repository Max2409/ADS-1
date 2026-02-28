// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  
  if (value < 2) {
	  return false;
  }

  if (value == 2) {
	  return true;
  }

  if (value % 2 == 0) {
	  return false;
  }

  for (uint64_t i = 3; i <= value / i; i += 2) {
	  if (value % i == 0) {
		  return false;
	  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t count = 0;
  uint64_t curNumber = 1;

  while (count < n){
    ++curNumber;
    bool checkPrime = true;
    if (curNumber < 2){
      checkPrime = false;
    }
    if (curNumber == 2){
      checkPrime = true;
    }
    if (curNumber % 2 == 0){
      checkPrime = false;
    }

    for (uint64_t k = 3; k <= curNumber / k; k += 2){
      if (curNumber % k == 0){
        checkPrime = false;
        break
          }
    }

    if (checkPrime){
      ++count;
    }
  }
  return curNumber;
}


uint64_t nextPrime(uint64_t value) {
  uint64_t curNumber = value + 1;

  while (true){
    bool checkPrime = true;
    
    if (curNumber < 2){
      checkPrime = false;
    }
    if (curNumber == 2){
      checkPrime = true;
    }
    if (curNumber % 2 == 0){
      checkPrime = false;
    }

    for (uint64_t k = 3; k <= curNumber / k; k += 2){
      if (curNumber % k == 0){
        checkPrime = false;
        break
          }
    }

    if (checkPrime){
      return curNumber;
    } else {
      ++curNumber;
    }

  }
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;

  for (uint64_t i = 2; i < hbound; ++i){
    bool checkPrime = true;

    if (i < 2){
      checkPrime = false;
    }
    if (i == 2){
      checkPrime = true;
    }
    if (i % 2 == 0){
      checkPrime = false;
    }

    for (uint64_t d = 3; d * d <= i; d += 2){
      if (i % d == 0){
        checkPrime = false;
        break
          }
    }
    if (checkPrime){
      sum+=i;
    }
  }

  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;

  for (uint64_t p = lbound; p + 2 <= hbound; ++p) {
    bool checkPrimeP = true;

    if (p < 2){
      checkPrimeP = false;
    }
    if (p == 2){
      checkPrimeP = true;
    }
    if (p % 2 == 0){
      checkPrimeP = false;
    }

    for (uint64_t t = 3; t * t <= p; t += 2){
      if (p % t == 0){
        checkPrimeP = false;
        break
          }
    }
    if (!checkPrimeP){
      continue;
    }

    uint64_t q = p + 2;
    bool checkPrimeQ = true;

    if (q < 2){
      checkPrimeQ = false;
    }
    if (q == 2){
      checkPrimeQ = true;
    }
    if (q % 2 == 0){
      checkPrimeQ = false;
    }

    for (uint64_t t = 3; t * t <= p; t += 2){
      if (q % t == 0){
        checkPrimeQ = false;
        break
          }
    }
    if (isPrimeQ){
      ++count;
    }
  }
  return count;
}
