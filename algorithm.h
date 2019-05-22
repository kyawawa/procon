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
