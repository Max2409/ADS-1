// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cmath>
#include <vector>

// Целочисленный квадратный корень (для uint64_t)
static uint64_t isqrt(uint64_t x) {
    if (x == 0) return 0;
    uint64_t r = static_cast<uint64_t>(std::sqrt(static_cast<double>(x)));
    // корректировка из-за возможной ошибки округления
    while ((r + 1) * (r + 1) <= x) ++r;
    while (r * r > x) --r;
    return r;
}


// Проверка числа на простоту
bool checkPrime(uint64_t value) {
    if (value < 2) return false;
    if (value == 2 || value == 3) return true;
    if (value % 2 == 0 || value % 3 == 0) return false;

    uint64_t limit = isqrt(value);
    // проверяем делители вида 6k ± 1
    for (uint64_t i = 5; i <= limit; i += 6) {
        if (value % i == 0 || value % (i + 2) == 0)
            return false;
    }
    return true;
}


// Поиск n-го простого числа
uint64_t nPrime(uint64_t n) {
    if (n == 0) return 0;  // на всякий случай
    if (n == 1) return 2;

    uint64_t count = 1;          // уже учтена двойка
    uint64_t candidate = 3;      // начинаем с тройки

    while (count < n) {
        if (checkPrime(candidate)) {
            ++count;
            if (count == n) return candidate;
        }
        candidate += 2;          // проверяем только нечётные
    }
    return 0;
}


// Ближайшее простое, строго большее value
uint64_t nextPrime(uint64_t value) {
    if (value < 2) return 2;
    uint64_t candidate = value + 1;
    // чётное число точно не простое (кроме 2), поэтому начнём с нечёта
    if (candidate % 2 == 0) ++candidate;

    while (!checkPrime(candidate)) {
        candidate += 2;
    }
    return candidate;
}


// Сумма всех простых чисел, строго меньших hbound
uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; ++i) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

// Количество пар простых чисел-близнецов в диапазоне lbound, hbound
uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
    uint64_t pairs = 0;
    uint64_t prev = 0;
    for (uint64_t i = lbound; i < hbound; ++i) {
        if (checkPrime(i)) {
            if (prev != 0 && i - prev == 2) {
                ++pairs;
            }
            prev = i;
        }
    }
    return pairs;
}
