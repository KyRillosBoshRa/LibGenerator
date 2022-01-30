// example problem : https://codeforces.com/problemset/problem/221/D
#include <bits/stdc++.h>

using namespace std;
const int N = 100009;
int n, q, st[N], nd[N], idx[N], a[N], comp[N];
int freq[N], an[N];
int ans;
void add(int x) {
  if (freq[x] == comp[x]) --ans;
  ++freq[x];
  if (freq[x] == comp[x]) ++ans;
}
void remove(int x) {
  if (freq[x] == comp[x]) --ans;
  --freq[x];
  if (freq[x] == comp[x]) ++ans;
}
void mo() {
  int l = 0, r = 0;
  for (int x = 0; x < q; ++x) {
    int i = idx[x];
    while (l < st[i]) {
      remove(a[l++]);
    }
    while (r <= nd[i]) {
      add(a[r++]);
    }
    while (l > st[i]) {
      add(a[--l]);
    }
    while (r - 1 > nd[i]) {
      remove(a[--r]);
    }
    an[i] = ans;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
#ifndef ONLINE_JUDGE
//  freopen("in.txt", "r", stdin);
#endif  // ONLINE_JUDGE
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i], comp[i] = a[i];
  int sq = sqrt(n);
  sort(comp, comp + n);
  int cz = unique(comp, comp + n) - comp;
  for (int i = 0; i < n; ++i) a[i] = lower_bound(comp, comp + cz, a[i]) - comp;
  for (int i = 0; i < q; ++i) {
    cin >> st[i];
    --st[i];
    cin >> nd[i];
    --nd[i];
    idx[i] = i;
  }
  sort(idx, idx + q, [&](int a, int b) {
    int aid = st[a] / sq, bid = st[b] / sq;
    if (aid != bid) return aid < bid;
    return ((aid & 1) ? (nd[a] < nd[b]) : (nd[a] > nd[b]));
  });
  mo();
  for (int i = 0; i < q; ++i) cout << an[i] << '\n';
  return 0;
}
