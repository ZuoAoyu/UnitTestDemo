#include <random>
#include "rng_mt19937.h"

int RandomNumberGeneratorMt19937::Get() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 10);
  return dis(gen);
}