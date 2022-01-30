const int N = 1e5 + 55;
int EulerPhi[N];
void EulerPhiSieve() {
  for (int i = 1; i <= 2000009; i++) EulerPhi[i] = i;
  for (int i = 2; i <= 2000009; i++)
    if (EulerPhi[i] == i)
      for (int j = i; j <= 2000009; j += i) EulerPhi[j] = (EulerPhi[j] / i) * (i - 1);
}