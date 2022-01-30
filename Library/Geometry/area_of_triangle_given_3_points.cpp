long long area(long long x0, long long x1, long long x2, long long y0, long long y1, long long y2) {
  return abs((x0 - x2) * (y1 - y0) - (x0 - x1) * (y2 - y0));
}