long long pow(long long x, long long e, int mod) {
  a %= mod;
  long long res = 1;
  while (e) {
    if (e & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    e >>= 1;
  }
  return res;
}
