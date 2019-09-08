# Tsinghua-Online-Judge-MOOC
[OJ地址](https://dsa.cs.tsinghua.edu.cn/oj)
## Range
### Descriptioin  
Let S be a set of n integral points on the x-axis. For each given interval [a, b], you are asked to count the points lying inside.

*Input*

The first line contains two integers: n (size of S) and m (the number of queries).

The second line enumerates all the n points in S.

Each of the following m lines consists of two integers a and b and defines an query interval [a, b].

*Output*

The number of points in S lying inside each of the m query intervals.

**Example**

*Input*

5 2

1 3 7 9 11

4 6

7 12

*Output*

0

3

**Restrictions**

0 <= n, m <= 5 * 10^5

For each query interval [a, b], it is guaranteed that a <= b.

Points in S are distinct from each other.

Coordinates of each point as well as the query interval boundaries a and b are non-negative integers not greater than 10^7.

Time: 2 sec

Memory: 256 MB

## Zuma

### Description

Let's play the game Zuma!

There are a sequence of beads on a track at the right beginning. All the beads are colored but no three adjacent ones are allowed to be with a same color. You can then insert beads one by one into the sequence. Once three (or more) beads with a same color become adjacent due to an insertion, they will vanish immediately.

Note that it is possible for such a case to happen for more than once for a single insertion. You can't insert the next bead until all the eliminations have been done.

Given both the initial sequence and the insertion series, you are now asked by the fans to provide a playback tool for replaying their games. In other words, the sequence of beads after all possible eliminations as a result of each insertion should be calculated.

*Input*

The first line gives the initial bead sequence. Namely, it is a string of capital letters from 'A' to 'Z', where different letters correspond to beads with different colors.

The second line just consists of a single interger n, i.e., the number of insertions.

The following n lines tell all the insertions in turn. Each contains an integer k and a capital letter Σ, giving the rank and the color of the next bead to be inserted respectively. Specifically, k ranges from 0 to m when there are currently m beads on the track.

*Output*
n lines of capital letters, i.e., the evolutionary history of the bead sequence.

Specially, "-" stands for an empty sequence.

**Example**

*Input*

ACCBA

5

1 B

0 A

2 B

4 C

0 A


*Output*


ABCCBA

AABCCBA

AABBCCBA

_

A

**Restrictions**

0 <= n <= 10^4

0 <= length of the initial sequence <= 10^4

Time: 2 sec

Memory: 256 MB

## LightHouse

### Description

As shown in the following figure, If another lighthouse is in gray area, they can beacon each other.

![](https://dsa.cs.tsinghua.edu.cn/oj/attachment/c6c8/c6c8562b88ed7fd518cacf0264ae624f59598ed7.png)

For example, in following figure, (B, R) is a pair of lighthouse which can beacon each other, while (B, G), (R, G) are NOT.

![](https://dsa.cs.tsinghua.edu.cn/oj/attachment/9d7f/9d7f16b4bddbee9795e12ba22fd7f88af5438aa6.png)

*Input*

1st line: N

2nd ~ (N + 1)th line: each line is X Y, means a lighthouse is on the point (X, Y).

*Output*

How many pairs of lighthourses can beacon each other

( For every lighthouses, X coordinates won't be the same , Y coordinates won't be the same )

**Example**

*Input*

3

2 2

4 3

5 1

*Output*

1

**Restrictions**

For 90% test cases: 1 <= n <= 3 * 105

For 95% test cases: 1 <= n <= 106

For all test cases: 1 <= n <= 4 * 106

For every lighthouses, X coordinates won't be the same , Y coordinates won't be the same.

1 <= x, y <= 10^8

Time: 2 sec

Memory: 256 MB

**Hints**

The range of int is usually [-231, 231 - 1], it may be too small.
