@author Shinya Saito
@assignment ICS 332 Homework 3
@date September 26, 2021

[EXERCISE 1 20pts]

[Question 1: How many child processes does this program create if the command-line argument is 1?]
When the argument is 1 then the amount of child process will be 2.

[Question 2: How many child processes does this program create if the command-line argument is 2?]
When the argument is 2 then the amount of child process will be 4.

[Question 3: Let T(n) be the number of child processes this program creates when its input is n (the answer to Question #1 above is thus T(1)).

Write an recursive formula (i.e., a recurrence relation) that gives T(i) as a function of one or more values of T for smaller input (i.e., smaller i). Explain your reasoning.]

T(n) = 2T(n-2) + T(n-1) + 2

To this problem I started to list out how many child there exists for each term of n in the natural number system following the given code.
For every n, number of child T(n) is the amount

n  |   T(n)
_  _   _
0  |    0
1  |    2
2  |    4
3  |    10
4  |    20

It follows that T(0) = 0 and T(1) = 2 and that the pattern is that there is an increase of 2 such as T(2) = 4.
However the pattern is more than that as by n = 3 then T(3) = 10 as 4 + 2 does not equal to 10.

However, I have noticed that for every 2T(2n+1) = T(2n) such as for T(3) and T(4).
Therefore, I guessed that there is a double related increase.

Thus, I landed to T(n) = 2T(n-2) + T(n-1) + 2.

[Question 4: Say the maximum number of processes that can be created on your machine is 100,000 (you can find out the actual number of your machine with ulimit -u).
What is the smallest value of the command-line argument for which the above program would experience failed fork() calls?]

Given the maximum number is 100,000 then

100,000 = 2T(n-2) + T(n-1) + 2

99,998 = 2T(n-2) + T(n-1)

While not exact the closest whole number of n that produces a value close to it is n = 16 where
T(16) = 87380.

n | T(n)
0  0
1  2
2 4
3 10
4  20
5  42
6  84
7  170
8  340
9  682
10 1364
11 2730
12 5460
13 10922
14 21844
15 43690
16 87380
17 174762

Given that the maximum is 100,000 and the assumption is that n is a whole number once n = 17 it surpasses that 100,000
therefore for it fails at n = 17.

[EXERCISE 2 30 pts]

[Question 1: At what time is “** ONE **” printed to the terminal?]
It takes 40 seconds for “** ONE **” to be printed to the terminal.

[Question 2:  At what time is “** TWO **” printed to the terminal?]
It takes 50 seconds for “** TWO **” to be printed to the terminal.

[Question 3:  What is the PID of the process that prints “** TWO **”?]
The PID that prints “** TWO **” will be 42.

[Question 4: What is the initial PPID of the process with PID 99?]
The initial PPID would be 36.

[Question 5:  At what time does the process with PID 123 terminate?]
The time PID 123 prints would be in an instant.

[Question 6: How many children (NOT counting grand-children, great-grant-children, etc.) does PID 42 create?]
PID 42 creates 3 child process.

[Question 7: What is the PPID of the process that prints ONE (when it prints it)]
The PPID that prints ONE will be 36.

[Question 8: Which processes are “alive” (i.e., not terminated/zombies) at time 25]
Processes that are alive at time 25 seconds will be the processes with the PID of the following*
  - 42
  - 99
  - 71
