long long multiply(long long A, long long B, long long MOD) {
  if (!B) return 0;
  if (B % 2) return (A + multiply(A, B - 1, MOD)) % MOD;
  long long partial = multiply(A, B / 2, MOD);
  return (partial + partial) % MOD;
}
