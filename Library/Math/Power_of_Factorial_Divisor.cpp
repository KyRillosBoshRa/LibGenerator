// You are given two numbers n and k. Find x such that n! is divisible by k^x.
// o(log n)
int fact_pow(int n, int k) {
  int res = 0;
  while (n) {
    n /= k;
    res += n;
  }
  return res;
}
