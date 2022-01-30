long long nCr(unsigned long long n, unsigned long long k) {
  if (n == k) return 1;
  return nCr(n - 1, k) * n / (n - k);
}
_________________________________________________________________
long long nCr(int n, int r) {
  if (r > n) return 0;
  if (r > n / 2) r = n - r;
  long long ans = 1;
  for (int i = 1; i <= r; ++i) {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}
_________________________________________________________________

long long nCr[N][N];

void init() {
  for (int i = 1; i < N; ++i) {
    nCr[i][0] = nCr[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
    }
  }
}
