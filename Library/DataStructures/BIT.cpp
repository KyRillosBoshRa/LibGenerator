// can be used 0 based
struct BIT {
  vector<long long> bit;
  BIT(int s = 10) {
    s = 1 << (int)ceil(log2(1.0 * s) + 1e-7);  // make the size pow of 2
    bit.assign(s, 0);
  }
  long long sum(int idx) {
    ++idx;
    long long ret = 0;
    for (; idx; idx -= idx & -idx) ret += bit[idx - 1];
    return ret;
  }
  long long sum(int l, int r) {
    if (l == 0) return sum(r);
    return sum(r) - sum(l - 1);
  }
  void add(int idx, long long delta) {
    ++idx;
    for (; idx < bit.size(); idx += idx & -idx) bit[idx - 1] += delta;
  }
  int find(long long val) {
    int s = 0;
    for (int m = bit.size() >> 1; m; m >>= 1) {
      if (bit[s + m - 1] < val) val -= bit[(s += m) - 1];
    }
    return s;
  }
};
