@name Shinya Saito
@assignment ICS 332 Homework 2
@date September 18th

EXERCISE 1 Counting system calls in “Hello World” programs [10 pts]

Question 1: In your report give how many system calls are placed in total by each HelloWorld program, and briefly explain how you counted them (e.g., if using the command-line, just give the command(s) you used). Why do you think these numbers are so different?

For the HelloWorld.c file I used the following command to see the system run:
  strace -c ./HelloWorld

where it displayed the following:

  Hello, World! It is Thu Sep 16 19:20:18 2021

  % time     seconds  usecs/call     calls    errors syscall
  ------ ----------- ----------- --------- --------- ----------------
  0.00    0.000000           0         3           read
  0.00    0.000000           0         2           write
  0.00    0.000000           0         3           close
  0.00    0.000000           0         5           fstat
  0.00    0.000000           0         1           lseek
  0.00    0.000000           0         5           mmap
  0.00    0.000000           0         4           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         3         3 access
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         1           arch_prctl
  0.00    0.000000           0         3           openat
  ------ ----------- ----------- --------- --------- ----------------
  100.00    0.000000                    35         3 total

To count the total system calls I have took a look at the total amount of the calls and here it showed that the call is 35.
Therefore, the total system call is 35.

For the HelloWorld.java file I used the following command:
  strace -c java HelloWorld

where it displayed the following:

  Hello, World! It is Thu Sep 16 19:42:55 UTC 2021
  % time     seconds  usecs/call     calls    errors syscall
  ------ ----------- ----------- --------- --------- ----------------
  76.99    0.001298         649         2           futex
  8.54    0.000144           7        21           mprotect
  4.63    0.000078           3        27           mmap
  1.84    0.000031           1        41        29 openat
  1.42    0.000024          12         2           munmap
  1.13    0.000019          19         1           clone
  0.95    0.000016           1        11           read
  0.95    0.000016           2        10         9 access
  0.77    0.000013           1        12           close
  0.71    0.000012           1        12           fstat
  0.65    0.000011           6         2           readlink
  0.47    0.000008           3         3           brk
  0.24    0.000004           0        24        21 stat
  0.24    0.000004           2         2           rt_sigaction
  0.12    0.000002           1         2           getpid
  0.12    0.000002           2         1           set_tid_address
  0.12    0.000002           2         1           prlimit64
  0.06    0.000001           1         1           rt_sigprocmask
  0.06    0.000001           1         1           set_robust_list
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         1           arch_prctl
  ------ ----------- ----------- --------- --------- ----------------
  100.00    0.001686                   178        59 total

Here the total calls are 178 based on the similar reasonings I have stated for the HelloWorld.c file.
Hence, the total system call is HelloWorld.java is 178.

Question 2* How many different system calls (i.e., counting only one occurrence of a particular system call) are placed by each HelloWorld program? Briefly describe how you obtained this information

Using the same call for the HelloWorld.c file, here is the list of calls that occurs
  - read 3
  - write 2
  - close 3
  - fstat 5
  - lseek 1
  - mmap 5
  - mprotect 4
  - munmap 1
  - brk 3
  - 3 access 3
  - execve 1
  - arch_prctl 1
  - openat 3

Using the same call for HelloWorld.java used in question 2 then the different system calls for the java file is the following
  - futex 2
  - mprotect 21
  - mmap 27
  - openat 41
  - munmap 2
  - clone 1
  - read 11
  -access 10
  - close 12
  - fstat 12
  - readlink 2
  - brk 3
  - 21 stat 24
  - rt_sigaction 2
  - getpid 2
  - set_tid_address 1
  - prlimit64 1
  - rt_sigprocmask 1
  - set_robust_list 1
  - execve 1
  - arch_prctl 1

Thus, for the C file there are 13 different system calls but for the Java file there are 21 different calls.

Question 3: Based on your intuition and on reading man pages (make sure you read the correct man page, e.g. man 2 write and not man write), and on the strace output, for each of the broad “OS management” areas below give in your report the name of 2 system calls (8 total) placed by the Java HelloWorld program that fall in this area:
* Process Management
  - fstat
  - getpid
* Memory Management
  - mmap
  - munmap
* File System and I/O
  - read
  - write
* Protection and Security
  - access
  - mprotect


EXERCISE 2 [20 pts]: Is wget getting what it’s asking for?

Answer the following questions using norvig_outfile:

[q1] How many system calls are placed in total?
I typed in the following command
  strace

[q2] How many system calls are placed by wget before it actually starts getting the file content?
There are 359 system calls.
To do this problem I started off by typing in the following command*
  grep -n "The Project Gutenberg" norvig_outfile
Which displayed the following
  360:read(3, "The Project Gutenberg EBook of T"..., 8192) = 1374
  362:write(4, "The Project Gutenberg EBook of T"..., 1374) = 1374

[q3] How many bytes does wget attempt to read from the Web server at a time typically (e.g., the buffer size)? Justify your answer by giving in your report one line of the strace output as an example.
The total bytes for read was 1374 because 360:read(3, "The Project Gutenberg EBook of T"..., 8192) = 1374,


[q4] How many times does wget attempt to read pieces of file content, in total?
The number of times wget attempt to read is 1396.

Using the following command
  grep -c "read(3," norvig_outfile
it displayed the number 1396.

[q5] Out of these, how many times does wget NOT receive the number of bytes it wants?
Using the following command
  strace -c wget http://norvig.com/big.txt

this produces the following
  % time     seconds  usecs/call     calls    errors syscall
  ------ ----------- ----------- --------- --------- ----------------
  77.62    0.114965          57      2005           write
  11.23    0.016631          13      1232           read
  8.42    0.012467          10      1205           select
  0.76    0.001125          23        50           ioctl
  0.30    0.000437          44        10         6 stat
  0.28    0.000416           9        46         7 openat
  0.20    0.000301           6        51           mmap
  0.19    0.000277          10        28           mprotect
  0.19    0.000276           6        44           getpgrp
  0.17    0.000259           6        42           close
  0.14    0.000202           5        41           fstat
  0.14    0.000200         200         1           utime
  0.07    0.000111          28         4           socket
  0.05    0.000074          25         3           munmap
  0.05    0.000073           5        15        15 access
  0.05    0.000071          18         4         2 connect
  0.04    0.000059          59         1           statfs
  0.02    0.000036          12         3           recvfrom
  0.02    0.000027          27         1           sendmmsg
  0.02    0.000026           4         7           rt_sigaction
  0.01    0.000014           5         3           poll
  0.01    0.000010           3         3           brk
  0.01    0.000009           5         2           clock_getres
  0.01    0.000008           4         2           getuid
  0.01    0.000008           4         2           futex
  0.00    0.000005           5         1           arch_prctl
  0.00    0.000004           4         1           getgroups
  0.00    0.000004           4         1           set_tid_address
  0.00    0.000004           4         1           set_robust_list
  0.00    0.000004           4         1           prlimit64
  0.00    0.000003           3         1           lseek
  0.00    0.000003           3         1           rt_sigprocmask
  0.00    0.000000           0         1           execve
  ------ ----------- ----------- --------- --------- ----------------
  100.00    0.148109                  4813        30 total

From this I can see that the error count associated with read is 0.
Thus, the there are 0 times.


[q6] Do you conclude that wget typically fills its buffer or not?
I would say that wget varies with the type, either it is read or a write buffer.
Read system call usually does not fill its buffer whereas, write does fill the buffer.

Answer the following questions using uh_outfile:
[q7] How many times does wget attempt to read pieces of file content, in total?

The amount of times that wget read is 1034.
To determine the value I used the following command of
  grep -c "read(3", uh_outfile
which displayed the following of
  1034



[q8] Out of these, how many times does wget NOT receive the number of bytes it wants?
The amount of times are 40.
To get this number, I typed in the following command of
  strace -c wget https://www.chadmorita.com/ics332_fall2021/morea/OverviewAndInterfaces/uh_outfile

then it displayed the following

2021-09-16 21:43:40 (2.30 MB/s) - ‘uh_outfile.2’ saved [303342/303342]

  % time     seconds  usecs/call     calls    errors syscall
  ------ ----------- ----------- --------- --------- ----------------
  33.67    0.005594          41       135           write
  21.74    0.003611          15       246           read
  7.88    0.001309           8       160           setitimer
  7.53    0.001251           7       167           rt_sigaction
  4.84    0.000804          24        33           ioctl
  3.93    0.000653          10        65           select
  3.24    0.000539           7        81           rt_sigprocmask
  3.21    0.000533           9        60        15 openat
  2.56    0.000425          30        14         8 stat
  1.61    0.000267           5        50           close
  1.44    0.000240           5        50           fstat
  1.02    0.000169          28         6           socket
  1.01    0.000168         168         1           utime
  0.93    0.000154           3        51           mmap
  0.85    0.000142           5        27           getpgrp
  0.82    0.000137          12        11         2 connect
  0.71    0.000118           8        14           getpid
  0.56    0.000093           4        22           futex
  0.48    0.000080           3        28           mprotect
  0.36    0.000059          59         1           statfs
  0.29    0.000049          16         3           munmap
  0.20    0.000033           7         5           brk
  0.20    0.000033          33         1           sendmmsg
  0.14    0.000023           2        15        15 access
  0.11    0.000018           4         5           getsockname
  0.10    0.000017           6         3           recvmsg
  0.08    0.000014           5         3           poll
  0.07    0.000011           6         2           recvfrom
  0.07    0.000011           4         3           getuid
  0.06    0.000010          10         1           sendto
  0.05    0.000009           5         2           clock_getres
  0.05    0.000008           8         1           getrandom
  0.04    0.000006           6         1           sysinfo
  0.03    0.000005           5         1           bind
  0.02    0.000004           4         1           lseek
  0.02    0.000004           4         1           getgroups
  0.02    0.000004           4         1           set_tid_address
  0.02    0.000004           4         1           set_robust_list
  0.02    0.000004           4         1           prlimit64
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         1           arch_prctl
------ ----------- ----------- --------- --------- ----------------
100.00    0.016613                  1275        40 total

[q9] Do you conclude that wget typically fills its buffer or not?
I would say that wget varies with the type, either it is read or a write buffer.
Read system call usually does not fill its buffer whereas, write does fill the buffer.


[q10] Why do you think results are different than in the previous experiment
I think it is because wget does not always fill its buffer, the read system call gets different numbers of bytes for each line of file content each time the wget command is run.
