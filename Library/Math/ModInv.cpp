int inv[N];
inv[1] = 1;
for (int i = 2; i < N; ++i) inv[i] = (N - (N / i) * inv[N % i] % N) % N;
_______________________________________________________
long long pow(long long x, long long e, int mod) {
  x %= mod;
  long long res = 1;
  while (e) {
    if (e & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    e >>= 1;
  }
  return res;
}

long long inv(long long n, int mod) { return pow(n % mod, mod - 2, mod); }
______________________________________________________
long long inv(long long a, long long b) { return 1 < a ? b - inv(b % a, a) * b / a : 1; }
