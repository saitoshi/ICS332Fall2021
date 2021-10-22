@assignment: ICS 332 Homework 6
@author: Shinya Saito
@date:

Exercise 1: Warm Up
Question 1:
[a) Show the execution pattern (as a string of A’s, B’s, C’, and o’s) assuming that the scheduler time quantum is equal to 4 ms. Show the execution for more than 20ms (but less than 30ms).]
Given that A,B,C o format then the sample execution pattern that runs for more than 20ms is

- AAAAoBBBBoCCCCoAAAAoBBBBoCCCC

This executes for 4*6 + 0.1*5 = 24.5 ms.

[(b)  In the long run (i.e, assuming jobs don’t ever terminate), what percentage of the CPU time is wasted doing context-switching/scheduling?]
Our CPU wastes about 2% in the run of its execution into context switching.

Question 2:
[(a)Out of the four jobs, which one do you think is a more interactive process (e.g., a text editor) and why?]
I think out of the four jobs C is the more interactive process.
Suppose we have an execution of a system such that it was
                          AAAAAoBBBBoCoDDDDDoAAAAAoCoDDDDDoAAAoCoDDDDDoAAAAAoBBBBB

From lecture, we know that more interactive jobs can appear to be less interactive as it has small occasional bursts in the CPU.
If we were to break down the occurance of A B C and D then it follows that
      - A 16
      - B 9
      - C 3
      - D 15
From this breakdown one can see that C has 3 occurance. Then from our initial assumption then it follows that C will have the most interactive jobs.

Thus, C is the more interactive process.

[(b)  In general (not specific to the execution above), is it possible to have a job run for longer than the time quantum with a Round Robin scheduling algorithm? Explain your answer.]
I personally believe that it is not possible.
Recall, that the Round Robin processes are preempted after their exectution.
Then it would not be possible for any process to run after its quantum time.


Question 3:
[(a) Could any of A’s I/O-burst time be 6 ms? Explain.]
Suppose we assume that it A could have I/O burst time of 6 ms.
Then it implies that between job A there exits jobs that give that 6 ms of I/o burst time.
    - AAAoBBoCoDoAAA - > 4 ms
    - AAAoBBoAAA -> 2
    - AAAoDoAAA -> 1
    - AAAoBBoCoDoAA -> 4 ms
Notice how this contradicts our initial assumption.

Thus, there does not exist any A's that have an I/O burst time of 6 ms. 

[(b) Could any of B’s I/O-burst time be 4 ms? Explain.]
Yes, it is possible for B to have I/O burst time of 4 ms BBoCoDoAAAoBB where it finishes after A starts.


Exercise 2: Reverse Engineering Scheduler
Question 1:
[q1.1 Is ALG5 preemptive?]
ALG5 is not preemptive as one job 1 starts at execution from time step 0 to 4 and then gets blocked at time step 4 as job 4 begins executing.

[q1.2 Does ALG5 prioritize jobs based on earliest arrival times?]
No, ALG5 does not prioritize jobs based on its earliest arrival times as job3 executes beginning at time step 11 despite the fact job1 has
an earlier arrival time in comaprison.

[q1.3 Is ALG5 Round-Robin?]
For now let us assume that ALG5 is Round Robin.
Then it follows
  - ALG5 is a scheduling algorithm that is preemptive
  - A job is run for a little bit and gets preempted for another job to run

However, from our reasoning from question 1 such that the jobs run for its iteration and that it is not preemptive,
then it follows that ALG5 is not Round Robin.

Thus, ALG5 is not Round Robin.

[q1.4 Does ALG5 prioritize jobs based on their priorities?]
Yes ALG5 does run based on its priority as
  - job 1 with priority of 1 starts at time step 0 and executes again at time step 7
  - job 4 with the same priority level as job 1 starts after job 1 at time step 4 and at time step 15
  - job 3 with priority 3 executes at time step 11
  - job 2 with priority 4 executes at time step 37
Hence, ALG5 does prioritize based on the priority.

[q1.5 Which scheduling algorithm]
I believe that ALG5 is nonpremptive Priority as while it is not preemptive based on the reasonings stated in question 1,
it does prioritize jobs based on their priorites.
Therefore, I think ALG5 is nonpremptive Priority.

Question 2:
[q2.1 Is ALG3 preemptive?]
ALG3 is not preemptive because nonpremptive from the following reasons
  - Job 1 has four iterations and it executes itself for four times and then job 2 executes similarly its same amount of iterations.
  - A job with a higher priority does not interject during the execution of a job with a lower priority.
Therefore, ALG3 is not preemptive and rather is nonpreemptive.

[q2.2 Does ALG3 prioritize jobs based on earliest arrival times? (“arrival time” means “time of first arrival in the system”, not “arrival time in the ready queue”)]
ALG3 does prioritize based on its earliest arrival times.
  - Job 1 with arrival 0 begins from time step 0 to 3
  - Job 2 with arrival 1 begins from time step 4 to 8
  - Job 4 with arrival 1 begins from time step 9 to 11
  - Job 3 with arrival 2 begins after that despite the fact it has a higher priority than job4.
Hence, ALG3 prioritizes jobs based on the arrival times.

[q2.3 Does ALG3 prioritize jobs based on shortest remaining CPU burst duration?]
ALG3 does not prioritize job based on its CPU burst time because job 2 who has a CPU burst time of 5 starts at time step 4 despite the fact that
job4 or job3 have a shorter CPU burst duration compared to 5.

[q2.4 Does ALG3 prioritize jobs based on their priorities?]
ALG3 does not prioritze jobs based on their priorities for the following reasons.
  - Job 2 with a priority of 4 enters at time step 4
  - Job 4 with a priority of 1 enters after that at time step 9
Thus, ALG3 does not prioritize based on its priorities.

[q2.5 Which scheduling algorithm (out of the ones in the bank) is ALG3?]
I would believe that ALG3 is First Come First Serve as the jobs are executed based on the prior reasons stated above.

Question 3:
[q3.1 Is ALG6 preemptive?]
Yes, ALG6 would be preemptive because of the following reason.
    - job1 begins it execution at time step 0 but at time step 3 it goes into a ready state
    - job2 takes over job1 as it has a higher priority as job2 has priority 4 and job 1 has priority 1
Thus, ALG6 is preemptive.

[q3.2 Is there an upper bound on the number of consecutive timesteps a process can spend in the Running state? If so, what is that upper bound?]
There exists an upper bound in the running state.
I believe that the upper bound is 3 as from time step 0 to 2 is the time quantum as job1 who executes through those time steps despite requiring 4 CPU bursts.
Additionally, it finishes later timestep 12.

[q3.3 Which scheduling algorithm (out of the ones in the bank) is ALG6?]
Based on the time quantum and the algorithm cutting the required CPU burst,
ALG6 is Round Robin.

Question 4:
Written on the question 4 text file.
