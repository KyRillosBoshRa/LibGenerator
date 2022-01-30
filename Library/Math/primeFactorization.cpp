int first_factor[N];
void primes() {
  for (int i = 2; i < N; ++i) {
    if (!first_factor[i]) {
      first_factor[i] = i;
      for (int j = i * 2; j < N; j += i) {
        if (!first_factor[j]) {
          first_factor[j] = i;
        }
      }
    }
  }
}
vector<int> get_factors(int x) {
  vector<int> res;
  while (x != 1) {
    res.push_back(first_factor[x]);
    x /= first_factor[x];
  }
  res.resize(unique(res.begin(), res.end()) - res.begin());
  return res;
}