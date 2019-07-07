#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

long long mPerm(const long long n, const long long k, const long long MOD)
{
    long long per = 1;
    for (long long i = 0; i < k; ++i) {
        per *= (n - i);
        per %= MOD;
    }
    return per;
}

class Node
{
  private:
    int id;
    bool is_child;
    vector<int> childs;

  public:
    Node(int _id, bool _root = false) :
        id(_id),
        is_child(_root)
    {
    }

    void connectNode(Node& other)
    {
        if (other.isChild()) {
            other.addChild(id);
            become_child();
        } else {
            addChild(other.getId());
            other.become_child();
        }
    }

    void become_child()
    {
        is_child = true;
    }

    void addChild(int _id)
    {
        childs.push_back(_id);
    }

    bool isChild()
    {
        return is_child;
    }

    int getId()
    {
        return id;
    }

    vector<int> getChilds()
    {
        return childs;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    constexpr long long MOD = 1e9 + 7;

    int N, K;
    cin >> N >> K;

    vector<Node> nodes;
    nodes.reserve(N);
    for (int i = 0; i < N; ++i) {
        nodes.emplace_back(i, i == 0);
    }


    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        nodes[a - 1].connectNode(nodes[b - 1]);
    }

    long long int ans = K;
    queue<int> node_queue;
    int num_parent = 0;
    node_queue.push(0);

    while(node_queue.size() > 0) {
        int idx = node_queue.front();
        const vector<int> childs = nodes[idx].getChilds();

        ans = (ans * mPerm(K - num_parent - 1, childs.size(), MOD)) % MOD;
        for (const auto& child_id : childs) {
            node_queue.push(child_id);
        }

        num_parent = 1;
        node_queue.pop();
    }

    cout << ans << endl;

    return 0;
}
