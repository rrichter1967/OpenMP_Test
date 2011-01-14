//: openmp.cpp : SIMD programming - R.Richter 2011-01-07
////////////////////////////////////////////////////////
// compile with -fopenmp
// link with -lgomp

#include <omp.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

void demo(const std::vector<double>& a, const std::vector<double>& b, std::vector<double>& c)
{
  int n = a.size();
  #pragma omp parallel for
  for (int i = 0; i < n; ++i)
  {
    c[i] = sqrt(a[i]*a[i] + b[i]*b[i]);
    // c[i] = (a[i] + b[i]) / 2.0;
    // c[i] = sqrt(double(i));
  }
}

int main()
{
  std::cout << "num threads: " << omp_get_max_threads() << '\n';

  int n = 1000000;
  std::vector<double> a(n, 3.0);
  std::vector<double> b(n, 2.0);
  std::vector<double> c(n);

  int start = clock();
  demo(a, b, c);
  int stop = clock();

  std::cout << "time  (clockticks): " << (stop - start) << '\n';
  return 0;
}
