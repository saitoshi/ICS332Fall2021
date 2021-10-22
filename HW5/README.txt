@assignments ICS 332 HOMEWORK 5
@date
@author Shinya Saito


Question #1 [2 pts]

The subsequent value for vertices size is 200 as it lead to 27.525 seconds.

Question #3 [8 pts]
------------Table of Run ------------------------------
Thread Count | 1 | 2    | 3   | 4| 5 | 6 | 7 | 8 | 9 | 10
Count
1        |29.742|16.169|16.17|15.678|16.442|16.367 |16.518|16.438|16.477|16.432
2        |28.267|15.220|16.022|16.273|16.612|16.510|16.485|17.861|16.363|16.415
3        |28.214|15.937|17.374|16.585|16.670|16.494|16.361|16.363|16.380|16.524
4        |28.237|16.462|16.232|16.401|16.201|16.358|16.392|16.555|16.292|18.108
5        |28.446|15.768|16.855|16.693|16.380|16.713|16.437|16.537|16.370|16.397
______________________________________________________
average |28.581 |15.911 |16.531|16.326|16.461|16.488|16.439|16.751|16.376|16.775


---------Average RunTime---------
Thread| Time (seconds)
---------------------------------
1     |28.581
2     |15.911
3     |16.531
4     |16.326
5     |16.461
6     |16.488
7     |16.439
8     |16.751
9     |16.376
10    |16.775

([q1] How much faster does the program run with 2 threads when compared to using 1 thread? (e.g., 1.95x faster))
When using 2 threads, it takes roughly around (55.67%) of the time that it takes using 1 thread.
Therefore it takes roughly around 1.79x faster.

[q2] How many physical cores do you have on your machine?
The total of physical cores I have is 6.

[q3] Is using more threads than the number of physical cores useful on your machine?
Using 2 threads brought significant difference compared to 1, but after 2 there was not much difference as the average stay within the range of 16 seconds.

[q4] What is the largest acceleration factor you observe in your results when compared to the 1-thread case, and with how many threads?
The difference between 2 and 1 is 12.67 seconds however after 3 threads there are not any significant difference as the time stays within the range of 16 to 17 seconds.
