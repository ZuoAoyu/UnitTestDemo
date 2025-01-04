#include "calc.h"

Calc::Calc(RandomNumberGenerator *rng) : rng_(rng) {
}

int Calc::AddRandomNumber(int a) {
  return a + rng_->Get();
}

int Calc::Sum(int a, int b) {
  return a + b;
}

int Calc::Multiply(int a, int b) {
  // return a * a;  // 一个错误的实现
  return a * b;  // 修复错误
}