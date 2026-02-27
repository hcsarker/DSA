---
icon: chess-pawn-piece
---

# Python Contest Cheat Sheet

Quick reference for CP (Codeforces/AtCoder/ICPC style) in Python.

### 0) Minimal contest template (fast I/O)

{% code title="template.py" %}
```python
import sys
from collections import defaultdict, Counter, deque
import heapq
import bisect
import math
from itertools import accumulate

def solve():
    HAS_T = True  # set False when the problem has no testcases
    data = sys.stdin.buffer.read().split()
    it = iter(data)
    t = int(next(it)) if HAS_T else 1
    out = []
    for _ in range(t):
        # n = int(next(it))
        # arr = [int(next(it)) for _ in range(n)]
        out.append("OK")
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    solve()
```
{% endcode %}

{% hint style="info" %}
`sys.stdin.buffer.read()` is fastest. Use it when input is big.
{% endhint %}

### Codeforces copy-paste templates

{% tabs %}
{% tab title="Full (recommended)" %}
{% code title="cf_template.py" %}
```python
import sys
from collections import defaultdict, Counter, deque
import heapq
import bisect
import math

def solve_case(it):
    # n = int(next(it))
    # a = [int(next(it)) for _ in range(n)]
    return "OK"

def main():
    HAS_T = True  # set False when the problem has no testcases
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(data)

    # Codeforces: usually t exists.
    t = int(next(it)) if HAS_T else 1

    out = []
    for _ in range(t):
        out.append(str(solve_case(it)))
    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()
```
{% endcode %}

{% hint style="info" %}
If a problem has **no** `t`, set `t = 1` and don’t read it.
{% endhint %}
{% endtab %}

{% tab title="Just lines (helpers)" %}
{% code title="cf_helpers.py" %}
```python
import sys
input = sys.stdin.readline

def ints():
    return map(int, input().split())

def li():
    return list(map(int, input().split()))

def debug(*args):
    print(*args, file=sys.stderr)
```
{% endcode %}
{% endtab %}
{% endtabs %}

### 1) Input patterns (common)

{% code title="input-snippets.py" %}
```python
import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
mat = [list(map(int, input().split())) for _ in range(n)]

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
```
{% endcode %}

### 2) Output patterns

{% code title="output-snippets.py" %}
```python
print(*arr)                      # space-separated
print("\n".join(map(str, arr)))  # one per line
```
{% endcode %}

### 3) Core Python tricks you will use daily

* Swap: `a, b = b, a`
* Reverse list: `arr[::-1]`
* Slice copy: `b = a[:]`
* Sort with key: `sorted(a, key=lambda x: (x[0], -x[1]))`
* Unique (keep order): `list(dict.fromkeys(a))`
* Ceiling division: `(a + b - 1) // b`

### 4) Collections (must know)

#### `deque` (BFS / sliding window)

```python
from collections import deque
q = deque([start])
q.append(x)
q.appendleft(x)
v = q.popleft()
```

#### `Counter` (frequency)

```python
from collections import Counter
cnt = Counter(arr)
most = cnt.most_common(3)
```

#### `defaultdict` (adj list)

```python
from collections import defaultdict
g = defaultdict(list)
g[u].append(v)
```

### 5) `heapq` (priority queue)

```python
import heapq
h = []
heapq.heappush(h, x)
x = heapq.heappop(h)          # min

# max-heap trick
heapq.heappush(h, -x)
mx = -heapq.heappop(h)
```

### 6) `bisect` (binary search on sorted list)

```python
import bisect
i = bisect.bisect_left(a, x)   # first >= x
j = bisect.bisect_right(a, x)  # first > x
```

### 7) Prefix sums (1D / 2D)

#### 1D

```python
from itertools import accumulate
pref = [0] + list(accumulate(arr))
sum_l_r = pref[r] - pref[l]    # [l, r)
```

#### 2D (classic)

```python
pref = [[0]*(m+1) for _ in range(n+1)]
for i in range(n):
    row = mat[i]
    for j in range(m):
        pref[i+1][j+1] = row[j] + pref[i][j+1] + pref[i+1][j] - pref[i][j]

def rect_sum(r1, c1, r2, c2):  # [r1,r2) x [c1,c2)
    return pref[r2][c2] - pref[r1][c2] - pref[r2][c1] + pref[r1][c1]
```

### 8) Two pointers / sliding window

```python
l = 0
cur = 0
for r, x in enumerate(arr):
    cur += x
    while cur > K:
        cur -= arr[l]
        l += 1
    # now window [l..r] valid
```

### 9) Binary search on answer (pattern)

```python
def ok(mid):
    # return True if mid is feasible
    return True

lo, hi = 0, 10**18
while lo < hi:
    mid = (lo + hi) // 2
    if ok(mid):
        hi = mid
    else:
        lo = mid + 1
ans = lo
```

### 10) Monotonic stack (next greater / histogram)

```python
st = []  # stores indices, values increasing
for i, x in enumerate(arr):
    while st and arr[st[-1]] >= x:
        st.pop()
    prev_smaller = st[-1] if st else -1
    st.append(i)
```

### 11) Graph basics

#### DFS (iterative)

```python
stack = [src]
seen = {src}
while stack:
    u = stack.pop()
    for v in g[u]:
        if v not in seen:
            seen.add(v)
            stack.append(v)
```

#### BFS (shortest path in unweighted graph)

```python
from collections import deque
dist = {src: 0}
q = deque([src])
while q:
    u = q.popleft()
    for v in g[u]:
        if v not in dist:
            dist[v] = dist[u] + 1
            q.append(v)
```

#### Dijkstra (weighted, non-negative)

```python
INF = 10**30
dist = [INF]*n
dist[s] = 0
pq = [(0, s)]
while pq:
    d, u = heapq.heappop(pq)
    if d != dist[u]:
        continue
    for v, w in g[u]:
        nd = d + w
        if nd < dist[v]:
            dist[v] = nd
            heapq.heappush(pq, (nd, v))
```

### 12) DSU (Union-Find)

```python
class DSU:
    def __init__(self, n):
        self.p = list(range(n))
        self.sz = [1]*n

    def find(self, x):
        while self.p[x] != x:
            self.p[x] = self.p[self.p[x]]
            x = self.p[x]
        return x

    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a == b:
            return False
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        self.p[b] = a
        self.sz[a] += self.sz[b]
        return True
```

### 13) Math essentials (CP)

```python
import math
g = math.gcd(a, b)
l = a // math.gcd(a, b) * b
r = math.isqrt(x)          # floor(sqrt(x))

MOD = 10**9 + 7
pow_mod = pow(a, b, MOD)   # fast exp
inv = pow(a, MOD-2, MOD)   # when MOD is prime
```

#### Sieve (primes up to N)

```python
N = 10**6
is_prime = bytearray(b"\x01") * (N + 1)
is_prime[0:2] = b"\x00\x00"
for p in range(2, int(N**0.5) + 1):
    if is_prime[p]:
        is_prime[p*p:N+1:p] = b"\x00" * (((N - p*p)//p) + 1)
primes = [i for i in range(N+1) if is_prime[i]]
```

#### Prime factorization (trial division)

```python
def factorize(x):
    f = {}
    d = 2
    while d*d <= x:
        while x % d == 0:
            f[d] = f.get(d, 0) + 1
            x //= d
        d += 1 if d == 2 else 2
    if x > 1:
        f[x] = f.get(x, 0) + 1
    return f
```

### 14) Strings quickies

```python
s = s.strip()
parts = s.split()
s2 = "".join(parts)

# frequency
cnt = Counter(s)

# check palindrome
is_pal = (s == s[::-1])
```

### 15) CP safety checklist

* Use `sys.setrecursionlimit(1_000_000)` only if recursion is necessary.
* Prefer iterative DFS for deep graphs.
* Always confirm indexing: `0-based` vs `1-based`.
* Watch for `n=0`, `k=0`, empty arrays, duplicates.
* For big output, buffer with `out.append(...)` then `"\n".join(out)`.

### 16) Coordinate compression

Use it for Fenwick/SegTree, sweep line, offline queries.

```python
vals = sorted(set(arr))
idx = {v: i for i, v in enumerate(vals)}  # 0-based
comp = [idx[x] for x in arr]
```

### 17) LIS (O(n log n))

```python
import bisect
tails = []
for x in arr:
    i = bisect.bisect_left(tails, x)
    if i == len(tails):
        tails.append(x)
    else:
        tails[i] = x
ans = len(tails)
```

### 18) Fenwick Tree (BIT)

Prefix sum queries. Point updates.

```python
class BIT:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)  # 1-based internal

    def add(self, i, delta):  # i: 0-based
        i += 1
        while i <= self.n:
            self.bit[i] += delta
            i += i & -i

    def sum(self, i):  # sum [0..i], i: 0-based
        i += 1
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s

    def range_sum(self, l, r):  # [l, r)
        if l >= r:
            return 0
        return self.sum(r - 1) - (self.sum(l - 1) if l else 0)
```

### 19) Segment Tree (iterative)

Range query + point update. `op` must be associative.

```python
class SegTree:
    def __init__(self, arr, op=min, e=10**30):
        self.op = op
        self.e = e
        n = len(arr)
        self.n = 1
        while self.n < n:
            self.n <<= 1
        self.t = [e] * (2 * self.n)
        self.t[self.n:self.n + n] = arr
        for i in range(self.n - 1, 0, -1):
            self.t[i] = op(self.t[i << 1], self.t[i << 1 | 1])

    def set(self, i, v):
        i += self.n
        self.t[i] = v
        i >>= 1
        while i:
            self.t[i] = self.op(self.t[i << 1], self.t[i << 1 | 1])
            i >>= 1

    def query(self, l, r):  # [l, r)
        resl = self.e
        resr = self.e
        l += self.n
        r += self.n
        while l < r:
            if l & 1:
                resl = self.op(resl, self.t[l])
                l += 1
            if r & 1:
                r -= 1
                resr = self.op(self.t[r], resr)
            l >>= 1
            r >>= 1
        return self.op(resl, resr)
```

### 20) Toposort (Kahn)

```python
from collections import deque

indeg = [0] * n
for u in range(n):
    for v in g[u]:
        indeg[v] += 1

q = deque([i for i in range(n) if indeg[i] == 0])
order = []
while q:
    u = q.popleft()
    order.append(u)
    for v in g[u]:
        indeg[v] -= 1
        if indeg[v] == 0:
            q.append(v)

is_dag = (len(order) == n)
```

### 21) SCC (Kosaraju)

```python
def kosaraju_scc(n, g):
    rg = [[] for _ in range(n)]
    for u in range(n):
        for v in g[u]:
            rg[v].append(u)

    seen = [0] * n
    order = []

    for s in range(n):
        if seen[s]:
            continue
        stack = [(s, 0)]
        seen[s] = 1
        while stack:
            u, i = stack[-1]
            if i == len(g[u]):
                order.append(u)
                stack.pop()
                continue
            v = g[u][i]
            stack[-1] = (u, i + 1)
            if not seen[v]:
                seen[v] = 1
                stack.append((v, 0))

    comp = [-1] * n
    cid = 0
    for s in reversed(order):
        if comp[s] != -1:
            continue
        comp[s] = cid
        q = [s]
        for u in q:
            for v in rg[u]:
                if comp[v] == -1:
                    comp[v] = cid
                    q.append(v)
        cid += 1

    return comp, cid
```

### 22) DP patterns (snippets)

#### 0/1 Knapsack (max value)

```python
dp = [0] * (W + 1)
for wt, val in items:
    for w in range(W, wt - 1, -1):
        dp[w] = max(dp[w], dp[w - wt] + val)
```

#### Subset DP (bitmask)

Good for `n <= 20`.

```python
dp = [0] * (1 << n)
for mask in range(1 << n):
    # transition from smaller masks
    pass
```

#### Grid DP (classic)

```python
dp = [[0] * m for _ in range(n)]
dp[0][0] = 1
for i in range(n):
    for j in range(m):
        if i:
            dp[i][j] += dp[i - 1][j]
        if j:
            dp[i][j] += dp[i][j - 1]
```

### 23) Combinatorics mod prime (nCr)

Use when MOD is prime.

```python
MOD = 10**9 + 7

def build_fact(n):
    fact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = fact[i - 1] * i % MOD
    invfact = [1] * (n + 1)
    invfact[n] = pow(fact[n], MOD - 2, MOD)
    for i in range(n, 0, -1):
        invfact[i - 1] = invfact[i] * i % MOD
    return fact, invfact

def nCr(n, r, fact, invfact):
    if r < 0 or r > n:
        return 0
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD
```

### 24) Bit tricks (quick)

* Check bit: `(x >> k) & 1`
* Set bit: `x |= 1 << k`
* Clear bit: `x &= ~(1 << k)`
* Lowest set bit: `x & -x`
* Popcount: `x.bit_count()`

### 25) String algorithms (CP staples)

#### Prefix-function (KMP π array)

```python
def prefix_function(s):
    n = len(s)
    pi = [0] * n
    for i in range(1, n):
        j = pi[i - 1]
        while j and s[i] != s[j]:
            j = pi[j - 1]
        if s[i] == s[j]:
            j += 1
        pi[i] = j
    return pi
```

#### KMP find occurrences

```python
def kmp_find_all(text, pat):
    if not pat:
        return list(range(len(text) + 1))
    s = pat + "#" + text
    pi = prefix_function(s)
    m = len(pat)
    res = []
    for i in range(m + 1, len(s)):
        if pi[i] == m:
            res.append(i - 2 * m)
    return res
```

#### Z-function

```python
def z_function(s):
    n = len(s)
    z = [0] * n
    l = r = 0
    for i in range(1, n):
        if i <= r:
            z[i] = min(r - i + 1, z[i - l])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if i + z[i] - 1 > r:
            l, r = i, i + z[i] - 1
    return z
```

### 26) LCA (binary lifting)

Tree queries: distance, kth ancestor, path checks.

```python
import math

LOG = (n).bit_length()
up = [[-1] * n for _ in range(LOG)]
depth = [0] * n

def build(root=0):
    st = [root]
    parent = [-1] * n
    parent[root] = root
    order = [root]
    while st:
        u = st.pop()
        for v in g[u]:
            if v == parent[u]:
                continue
            parent[v] = u
            depth[v] = depth[u] + 1
            st.append(v)
            order.append(v)

    for v in range(n):
        up[0][v] = parent[v]
    for k in range(1, LOG):
        row = up[k]
        prev = up[k - 1]
        for v in range(n):
            row[v] = prev[prev[v]]

def lift(v, k):
    i = 0
    while k:
        if k & 1:
            v = up[i][v]
        k >>= 1
        i += 1
    return v

def lca(a, b):
    if depth[a] < depth[b]:
        a, b = b, a
    a = lift(a, depth[a] - depth[b])
    if a == b:
        return a
    for k in range(LOG - 1, -1, -1):
        if up[k][a] != up[k][b]:
            a = up[k][a]
            b = up[k][b]
    return up[0][a]

def dist(a, b):
    c = lca(a, b)
    return depth[a] + depth[b] - 2 * depth[c]
```

{% hint style="warning" %}
এটা assume করে `g` হলো tree adjacency (undirected). `build()` আগে `n, g` set থাকতে হবে।
{% endhint %}

### 27) 0-1 BFS (edges weight 0/1)

Dijkstra-এর faster special case.

```python
from collections import deque

INF = 10**30
dist = [INF] * n
dist[s] = 0
dq = deque([s])

while dq:
    u = dq.popleft()
    for v, w in g[u]:          # w in {0,1}
        nd = dist[u] + w
        if nd < dist[v]:
            dist[v] = nd
            if w == 0:
                dq.appendleft(v)
            else:
                dq.append(v)
```
