# アルゴリズム第 2B - 第 13 回課題

五目並べを対象としたゲームアルゴリズム.


## コンパイル方法

ここでは, ビルドシステムに CMake を用いる.

プロジェクトディレクトリ上で, 次のコマンド
```
cmake -S . -B build
```
を 1 回限り実行.
その後, 次のコマンド
```
cmake --build build
```
を実行し, 同ディレクトリ上に出力として各種実行ファイルを得る.


## 実行ファイル

各種実行ファイルの概要は以下の通り.

-   `perf_ab`:
    五目並べにアルゴリズムを適用したときの実行時間を計測.
    アルファ・ベータ法のみを用いる.
-   `perf`:
    五目並べにアルゴリズムを適用したときの実行時間を計測.
    ミニマックス法, アルファ・ベータ法を両者とも用いる.
-   `sanmoku`:
    三目並べに対してアルゴリズムを適用.
    ミニマックス法とアルファ・ベータ法の実装が正しいかのテスト用.
    格子が縦横 3 マスずつの三目並べは,
    先手・後手が両者ともに最善を尽くせば必ず引き分けになることが知られている.
    したがって, いずれのアルゴリズムでも 0 が出力されれば成功.
