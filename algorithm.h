#include <bits/stdc++.h>

using namespace std;

template<class T>
T gcd(T a, T b)
{
    if (a == 0) return b;
    else if (b == 0) return a;

    if (b > a) swap(a, b); // assume a >= b

    T ret = b;
    while (a % b != 0) {
        ret = a % b;
        a = b;
        b = ret;
    }
    return ret;
}

long long modPow(long long x, long long n, const long long MOD)
{
    long long ans = 1;
    while (n != 0) {
        if (n & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        n = n >> 1;
    }
    return ans;
}

long long modFact(const long long n, const long long MOD)
{
    long long fac = 1;
    for (long long i = 1; i <= n; ++i) {
        fac *= i;
        fac %= MOD;
    }
    return fac;
}

long long modComb(const long long n, long long r, const long long MOD)
{
    if (n < r || n < 0) return 0;
    if (r * 2 > n) r = n - r;

    return ((modFact(n, MOD) * modPow(modFact(r, MOD), MOD - 2, MOD) % MOD)
            * modPow(modFact(n - r, MOD), MOD - 2, MOD)) % MOD;
}

template<typename type>
class UnionFindTree
{
  private:
    vector<type> parent;
    vector<type> rank;

  public:
    UnionFindTree(type size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (type i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    type findRoot(type x) {
        if (parent[x] == x) return x;
        else return parent[x] = findRoot(parent[x]);
    }

    void uniteTwoGroups(type x, type y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return;

        if (rank[x] < rank[y]) parent[x] = y;
        else {
            parent[y] = x;
            if (rank[x] == rank[y]) ++rank[x];
        }
    }

    bool areSameGroups(type x, type y) {
        return findRoot(x) == findRoot(y);
    }
};
