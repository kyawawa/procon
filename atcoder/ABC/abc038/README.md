# ABC038
## 豆
iostream(cin, cout, endl)は遅いらしい

解決法として、stdioを使うか、
```c++
cin.tie(0); // cin呼び出し時のcoutのフラッシュを解除
ios::sync_with_stdio(false); // stdioとの同期を解除
```
を書いておき、endlは"\n"を使う

## C
* 間違い(1)

初めはループを
```c++
for (size_t i = 0; i < n - 1; ++i) {
    for (size_t j = i + 1, k = i; j < n; ++j, ++k) {
        if (a[k] < a[j]) ans++;
        else break;
    }
}
ans += n;
```
のように書いていたが、TLEをくらった

* 間違い(2)

ans, chainをint型で宣言していたらダメだった

よく考えなくても単調増加の組み合わせ数はO(n^2)なのでintだと入らない

chainもintにしなくてはいけなかったのは、
```c++
ans += (chain * (chain + 1)) / 2;
```
の右辺の計算時にintとして処理されてしまうから
