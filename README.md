*This project has been created as part of the 42 curriculum by rishiyam, amiwa.*

# push_swap

## Description

`push_swap` は、重複のない符号付き整数列を昇順に並べ替えるプログラムです。
初期状態ではすべての値がスタックAに入り、スタックBを一時領域として使用します。
ソート後の数値そのものではなく、できるだけ少ない回数で正しい並びを作るための
スタック操作列を標準出力へ出力します。

使用できる操作は `sa`、`sb`、`ss`、`pa`、`pb`、`ra`、`rb`、
`rr`、`rra`、`rrb`、`rrr` の11種類です。正しい実行結果では
スタックBが空になり、スタックAの先頭が最小値となる昇順に並びます。

## Instructions

### Build

CコンパイラとGNU Makeが必要です。リポジトリのルートで次を実行します。

```sh
make
```

Makefileでは、次の標準ターゲットも使用できます。

```sh
make clean    # オブジェクトファイルを削除
make fclean   # オブジェクト、ライブラリ、実行ファイルを削除
make re       # すべてを再ビルド
```

`libft` と `ft_printf` はプロジェクトのMakefileからビルドされるため、
個別にインストールする必要はありません。

### Run

```text
./push_swap [--adaptive | --simple | --medium | --complex] [--bench] integers...
```

実行例:

```sh
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
./push_swap --medium 2 1 3 6 5 8
./push_swap 2 1 --complex 3 6 5 8
```

戦略セレクタと `--bench` は、それぞれ独立した引数として任意の位置に
指定できます。戦略セレクタは1つだけ指定でき、省略時は `--adaptive`
が選択されます。

入力には、任意の `+` または `-` 符号が付いた `int` 範囲内の
10進整数を指定できます。空の値、整数以外の文字列、重複値、範囲外の値、
同じオプションの重複、複数の戦略指定は不正入力です。不正入力では
標準エラー出力へ `Error` を出力します。引数がない場合は何も出力せず、
正常終了します。

互換性のあるcheckerで操作列を確認する例:

```sh
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

### Reviewer quick start

以下のコマンドは、リポジトリのルートからそのままコピーして実行できます。

ビルドと基本動作の確認:

```sh
make re && ./push_swap 2 1 3 6 5 8
```

整列済みの入力で余計な操作を出力しないことの確認:

```sh
test -z "$(./push_swap 1 2 3 4 5)" && echo "OK: no operations" || echo "KO: unexpected operations"
```

重複値を不正入力として扱い、終了ステータス1を返すことの確認:

```sh
./push_swap 1 2 2; printf 'exit status: %s\n' "$?"
```

1から1,000,000までの範囲から重複なしで抽出した、100個のランダム入力に対する操作数の確認（GNU `shuf` が必要）:

```sh
ARG="$(shuf -i 1-1000000 -n 100 | tr '\n' ' ')";  ./push_swap $ARG | wc -l
```

1から1,000,000までの範囲から重複なしで抽出した、500個のランダム入力に対する操作数の確認:

```sh
ARG="$(shuf -i 1-1000000 -n 500 | tr '\n' ' ')";  ./push_swap $ARG | wc -l
```

1回の実行内では同じ100個の入力を使い、再実行時には新しい入力を生成する各戦略の操作数比較:

```sh
ARG="$(shuf -i 1-1000000 -n 100 | tr '\n' ' ')"; for STRATEGY in --adaptive --simple --medium --complex; do COUNT="$(./push_swap "$STRATEGY" $ARG | wc -l)"; printf '%-10s %s operations\n' "$STRATEGY" "$COUNT"; done
```

checkerをリポジトリのルートに配置している場合の、毎回新しく生成される100個のランダム入力の検証:

```sh
ARG="$(shuf -i 1-1000000 -n 100 | tr '\n' ' ')"; ./push_swap $ARG | ./checker_linux $ARG
```

ベンチマーク情報と操作列を分離して確認:

```sh
ARG="4 67 3 87 23"; ./push_swap --bench $ARG > operations.txt 2> benchmark.txt; cat operations.txt; cat benchmark.txt
```

Valgrindがインストールされている環境でのメモリリーク確認:

```sh
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap --adaptive 4 67 3 87 23 > /dev/null
```

Norminetteがインストールされている環境での規約確認:

```sh
norminette *.c *.h libft/*.c libft/*.h ft_printf/*.c ft_printf/*.h
```

### Benchmark mode

`--bench` を指定しても、スタック操作は標準出力にのみ出力されます。
統計情報は標準エラー出力へ分離されるため、操作列をそのままcheckerへ
渡すことができます。

```sh
./push_swap --bench 4 67 3 87 23 > operations.txt 2> benchmark.txt
```

レポートには次の情報が含まれます。

- 小数点以下2桁で表した初期乱雑度
- 指定された戦略と、実際に使用された戦略の計算量クラス
- 操作の合計回数
- 11種類すべての操作ごとの実行回数

## Algorithms and design choices

### Shared representation and indexing

各スタックは先頭ノードを明示的に保持する単方向連結リストです。
pushとswapはリストの先頭を操作するため、定数時間で実行できます。
ソート前に各整数を `0` から `n - 1` までの順位へ座標圧縮します。
この非負の順位を比較対象にすることで、各戦略の処理が読みやすくなり、
負数を特別扱いせずradix戦略でビットを調べられます。

要素数が5以下の場合は専用のsmall sortを使用します。固定された少数の
場合分けを直接処理するため、汎用戦略による余分な準備や操作を避けられます。

以下の計算量は、出力されるpush_swap操作数の増え方を表します。
順位付けと乱雑度計算では入れ子のリスト走査を行うため、プログラム内部の
比較回数はO(n^2)ですが、これらの前処理はスタック操作を出力しません。

### Simple: selection by minimum — O(n^2)

Simple戦略は、スタックAから最小順位を探し、順方向と逆方向のうち短い側へ
回転させて先頭へ移動し、スタックBへpushする処理を繰り返します。
Aが空になった後、Bの全要素をAへ戻します。

処理の流れと不変条件が分かりやすく、入力が小さい場合や乱雑度が低い場合に
十分な性能を得られるため、最も単純な戦略として採用しています。一方、
要素数に対して操作回数が二次的に増える性質も明確に観測できます。

`--simple` で選択できます。

### Medium: square-root chunks — O(n sqrt(n))

Medium戦略では、およそ `1.4 * sqrt(n)` の幅を持つ順位ウィンドウを
移動させます。ウィンドウ内の値をBへpushし、その中でも小さい値をBの
末尾側へrotateします。この配置により、大きい順位がBのどちらかの端に
近い状態を作ります。その後、Bの最大値を短い回転方向で先頭へ移動し、
順番にAへ戻します。

ウィンドウが狭すぎるとAの走査が増え、広すぎるとBから値を戻す際の
回転が増えます。平方根程度の幅にすることで、selectionとradixの中間となる
操作量を狙っています。

`--medium` で選択できます。

### Complex: binary least-significant-digit radix — O(n log(n))

Complex戦略は、座標圧縮した順位のビットを最下位から順番に処理する
二進LSD radix sortです。各ビットについて、0の値をBへpushし、1の値を
A内でrotateした後、Bの全要素をAへ戻します。

各ビットで全要素を1回ずつ確認し、`n - 1` までの順位に必要なビット数は
`ceil(log2(n))` です。そのため、操作回数は予測しやすい
O(n log(n))で増加し、大きく乱れた入力に対して最も安定した選択となります。

`--complex` で選択できます。

### Adaptive selection

乱雑度は、入力に含まれる全ペアのうち順序が逆転しているペアの割合です。

```text
disorder = inverted pairs / all pairs * 100
```

デフォルトの `--adaptive` は、次の基準で戦略を選択します。

| Initial disorder | Strategy | Reason |
| --- | --- | --- |
| 20%未満 | Simple | 乱れが少なく、有用な値がスタック端の近くにある可能性が高いため |
| 20%以上50%未満 | Medium | 全radix passを行わず、chunkによって走査回数を抑えられるため |
| 50%以上 | Complex | 元の順序を利用しにくい入力でも、操作数の増加が予測しやすいため |

要素数が1から5の場合は、戦略選択後に専用のsmall sortが使用されます。
しきい値を明示することで、`--bench` の乱雑度から選択結果を再現でき、
測定結果に基づく調整もしやすくしています。

## Project contributions

- `amiwa`: 初期のスタック操作、計算量に基づく戦略選択、および
  コマンドラインセレクタの原型を実装
- `rishiyam`: プロジェクトインターフェースとファイル構成を定義し、
  `libft` と `ft_printf` の統合、Makefile、入力解析、各戦略、
  ベンチマーク、検証、可読性改善を担当
- 両名: 統合、競合解決、レビュー、およびmandatory部分の最終テスト

## Resources

- プロジェクトで配布された *Push_swap* subject version 1.1:
  mandatory操作、戦略セレクタ、ベンチ出力、エラー処理、README要件の確認に使用
- [42School Norminette](https://github.com/42School/norminette):
  現行の42 Cコーディング規約の確認に使用
- [GNU Make manual](https://www.gnu.org/software/make/manual/):
  ターゲット、依存関係、ライブラリの再帰ビルドの確認に使用
- Cライブラリおよびシステムのmanual page:
  `malloc(3)`、`free(3)`、`write(2)`
- Cormen、Leiserson、Rivest、Stein,
  *Introduction to Algorithms* のソートと漸近解析の章:
  古典的なアルゴリズムと計算量の参考資料として使用

### Use of AI

AIは、実装と入力解析と戦略の検討、正当性と操作数のテスト設計、
メモリのリークチェック、およびREADMEの構成と文章改善に使用しました。
また、可読性向上と、既存の `libft`・`ft_printf` 関数を
利用するためにも使用しました。