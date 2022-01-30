struct monoQueue {
  deque<pair<int, int> > dq;
  int sz = 0;
  int min() { return dq.size() ? dq.front().first : -1; }

  void push(int v) {
    ++sz;
    int cnt = 1;
    while (dq.size() && v <= dq.back().first) cnt += dq.back().second, dq.pop_back();
    dq.push_back({v, cnt});
  }

  void pop() {
    --sz;
    if (dq.front().second == 1) return dq.pop_front();
    dq.front().second--;
  }

  int size() { return sz; }
};