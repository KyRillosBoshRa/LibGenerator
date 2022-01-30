random_device Rd;
mt19937 rd(Rd());
uniform_int_distribution<> rnd(1, INT_MAX);
struct node {
  int priority, cnt, val;
  bool lazy;
  node *l, *r;
  node(int _val = 0, int _priority = 0) : val(_val), priority(_priority) {
    l = r = NULL;
    lazy = 0;
    cnt = 1;
  }
  ~node() {
    delete l;
    delete r;
  }
} * root;
struct Treap {
  Treap() { root = NULL; }
  ~Treap() { clear(); }
  void clear(node*& t = root) {
    delete t;
    t = NULL;
  }
  void push_down(node* t) {
    if (!t || !t->lazy) return;
    if (t->l) t->l->lazy ^= 1;
    if (t->r) t->r->lazy ^= 1;
    swap(t->l, t->r);
    t->lazy = 0;
  }
  int get_cnt(node* t) { return t ? t->cnt : 0; }
  void upd_cnt(node* t) {
    if (t) t->cnt = 1 + get_cnt(t->l) + get_cnt(t->r);
  }
  void split(node*& l, node*& r, int key, node* t = root, int add = 0) {
    if (!t) return void(l = r = NULL);
    push_down(t);
    int cur_key = add + get_cnt(t->l);
    if (cur_key > key)
      split(l, t->l, key, t->l, add), r = t;
    else
      split(t->r, r, key, t->r, cur_key + 1), l = t;
    upd_cnt(t);
  }
  void merge(node* l, node* r, node*& t = root) {
    if (!l || !r) return void(t = (l ? l : r));
    push_down(l);
    push_down(r);
    if (l->priority > r->priority)
      merge(l->r, r, l->r), t = l;
    else
      merge(l, r->l, r->l), t = r;
    upd_cnt(t);
  }
  void insert(node* it, int key) {
    if (!root) return void(root = it);
    node *a, *b, *c, *d;
    split(a, b, key - 1);
    merge(a, it, a);
    merge(a, b);
  }
  int query(int l) {
    node *a, *b, *c, *d;
    split(a, b, l - 1);
    split(c, d, 0, b);
    int res = c->val;
    merge(c, d, b);
    merge(a, b);
    return res;
  }
  void cyclic_shift(int l, int r) {
    if (l == r) return;
    node *a, *b, *c, *d, *e, *f;
    split(a, b, l - 1);
    split(c, d, r - l - 1, b);
    split(e, f, 0, d);
    merge(e, c, d);
    merge(d, f, b);
    merge(a, b);
  }
  void reverse(int l, int r) {
    node *a, *b, *c, *d;
    split(a, b, l - 1);
    split(c, d, r - l, b);
    c->lazy ^= 1;
    merge(c, d, b);
    merge(a, b);
  }
} tr;
