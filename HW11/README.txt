@assignment ICS 332 HW 11
@author Saito, Shin

[Exercise #1 [42 pts]
Consider a system with four page frames and a program that uses eight pages. Consider the reference string 0 1 7 2 0 3 1 7 0 1 7 and assume that all four page frames are initially empty. Consider the three following algorithms:]

[a. [14 pts] Optimal page replacement]
  | 0  1  7  2  0  3  1  7  0  1  7
------------------------------------
0 | 0  0  0  0  0  0  0  0  0  0  0
1 | -  1  1  1  1  1  1  1  1  1  1
2 | -  -  7  7  7  7  7  7  7  7  7
3 | -  -  -  2  2  3  3  3  3  3  3
------------------------------------
f | X  X  X  X  -  X  -  -  -  -  -

There is a total of 5 page faults break using Optimal Page Replacement.

[b. [14 pts] FIFO page replacement]
  | 0  1  7  2  0  3  1  7  0  1  7
------------------------------------
0 | 0  0  0  0  0  3  3  3  3  3  3
1 | -  1  1  1  1  1  1  1  0  0  0
2 | -  -  7  7  7  7  7  7  7  1  1
3 | -  -  -  2  2  2  2  2  2  2  7
------------------------------------
f | X  X  X  X  -  X  -  -  X  X  X

There is a total of 8 page faults break using FIFO page replacement.

[c. [14 pts] LRU page replacement]
  | 0  1  7  2  0  3  1  7  0  1  7
------------------------------------
0 | 0  0  0  0  0  0  0  0  0  0  0
1 | -  1  1  1  1  3  3  3  3  3  3
2 | -  -  7  7  7  7  1  1  1  1  1
3 | -  -  -  2  2  2  2  7  7  7  7
------------------------------------
f | X  X  X  X  -  X  X  X  -  -  -

There is a total of 7 page faults break using LRU page replacement.

[Exercise #2 [8 pts]
Consider a system that implements demand paging without a TLB. The single-level page table is held in memory, and we assume that there are no free frames. Each memory access requires 100 nanoseconds. It takes 6 additional milliseconds to handle a page fault if the victim page is not “dirty” or 12 additional milliseconds if the victim page is “dirty”.

Experiments show that the probability of page faulting is 0.00003 (i.e., 0.003% chance) and that the average memory access time is 400ns.

What is the percent chance that a page is dirty at the time it is evicted?

Hint: Call the “being dirty” probability d and write a simple equation that gives the average data access time as a function of d. Solve for d (the result should be a number between 0 and 1, which you then convert to a percentage).]
]

To begin with we list the given information which is the following
  - probability of page faulting 0.00003
  - avg. memory access time is 400 ns -> 400 x 10^-9 s
  - memory access 100 ns -> 100 x 10^-9 s
  - dirty page 12 ms -> 12 x 10^-3 s
  - non dirty page 6 ms -> 6 x 10^-3 s

The goal is to find the percent chance which the page being evicted is dirty.
Using the following formula from the slides
  - Average access time = 0.000001 + p((1 - d)t_m + p_d * d)
then
  - 400 x 10^-9 = 100 x 10^-9 + 0.00003((1-d)0.006 + 0.012d)
  - 300 x 10^-9 = 1.8x 10^-7 - 1.8x 10^-7d
  - 1.2 x 10^-7 = 1.8x 10^-7d
  - d = 0.667
Thus, the percentage chances are 66.7% (0.667).
