#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

template<typename type>
class UnionFindTree
{
  private:
    vector<type> parent;
    vector<type> rank;

  public:
    UnionFindTree(size_t size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    type findRoot(type x) {
        if (parent[x] == x) return x;
        else return parent[x] = findRoot(parent[x]);
    }

    void uniteTwoGroup(type x, type y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return;

        if (rank[x] < rank[y]) parent[x] = y;
        else {
            parent[y] = x;
            if (rank[x] == rank[y]) ++rank[x];
        }
    }

    bool isSameGroup(type x, type y) {
        return findRoot(x) == findRoot(y);
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    UnionFindTree<int> utree(N);

    vector<int> X(M);
    vector<int> Y(M);
    vector<int> Z(M);

    for (int i = 0; i < M; ++i) {
        cin >> X[i] >> Y[i] >> Z[i];
        utree.uniteTwoGroup(X[i] - 1, Y[i] - 1);
    }

    set<int> s;
    for (int i = 0; i < N; ++i) {
        s.insert(utree.findRoot(i));
    }

    cout << s.size() << endl;
    return 0;
}
