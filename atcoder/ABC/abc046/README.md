# ABC046

## C

初めは

```c++
ratio = ((double)ts / t[i] > (double)as / a[i]) ? (long long int)ceil((double)ts / t[i]) : (long long int)ceil((double)as / a[i]);
```

としていたのだが，何故かWAとなる．

```c++
ratio = max((ts % t[i] == 0) ? ts / t[i] : ts / t[i] + 1, (as % a[i] == 0) ? as / a[i] : as / a[i] + 1);
```

としたところ，通った．

確かに下の方が分かりやすいしミスも無さそうだが，具体的にどんなケースで間違うのかが分からない．要調査．

## D

提出時は「相手のグーに合わせてパーを出し，こちらのパーが尽きたら可能な限りグーであいこを取れば良い」という考えであったが，他の方の解答を見て，「取りうる最大得点からパーの数を引いた値」が答えになることに気付いた．

こちらの出す順番は全く関係なく，相手が全てグーの時に最大得点であり，パーがひとつ増えるごとに得点が1減るということに気付けなかった．

```c++
ans = n / 2 - p;
```
