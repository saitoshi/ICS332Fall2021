@Assignment ICS 332 HW 9
@author Shinya Saito

Exercise 1
[Question #1 [4 pts]
If invoking the program as

./memory  480,0,0,0
produced this output:

0 | 1024 | 1088 | 2112 | 2624 | 3648 | 3776 | 4800 | 4864 |
--------------
The 480-byte chunk was allocated at address 2144
would you conclude that the heap allocator allocates new chunks of RAM at the beginning (i.e., lower addresses) or at the end (i.e., higher addresses) of holes in memory? Why? To explain why just use a contraposition argument (e.g., if the heap allocator did X then Y would have happened, but instead Z happened).

Whatever the heap allocator does, this is what we assume it does for all subsequent questions. Also, in all subsequent questions, we assume that all considered algorithms go through the list of holes left to right (i.e., from low addresses to high addresses), and when there is a choice, the algorithms always pick the leftmost hole.]

Heap allocator allocates new chunks of RAM at the end of the hole in memory.
Given that it is 480 byte chunk, then 2624 - 480 = 2144.
Which we can see that it takes up the upper bound of the hole between 2112|2624.

If the heap allocator allocated new chunks of RAM at the beginning of holes, then it would have been allocated at 2112 rather than 2144.

[Question #2 [10 pts]
If invoking the program as

./memory  100,200,100,80
produces this output:

0 | 1024 | 1088 | 2112 | 2624 | 3648 | 3776 | 4800 | 4864 |
--------------
The 100-byte chunk was allocated at address 2524
The 200-byte chunk was allocated at address 2324
The 100-byte chunk was allocated at address 2224
The 80-byte chunk was allocated at address 3696
would you say that the heap allocator uses

first fit
best fit
worst fit
none of the above?]

The heap allocator uses WORST FIT algorithm and to solve this problem we will do a series of proof by contradictions.

Below are the list of memory availability of each hole:
  - 1024 | 1088: 64 bytes
  - 2112 | 2624: 512 bytes
  - 3648 | 3776: 128 bytes
  - 4800 | 4864: 64 bytes

Proof on why it is not FIRST FIT
  - Suppose for the sake of contradiction it was FIRST FIT algorithm.
    Then it would follow that that two 100 byte and 200 byte chunks would have been allocated correctly since the 512 byte
    was the first hole big enough to accomodate the allocation. Then it would reduce it the hole into 112.

    However, the 80 byte chunk was placed in the 128 byte hole.
    Which causes a contradiction as it was not the first hole that was big enough to fit the chunk.

    Hence, it is not FIRST FIT.

Proof on why it is not BEST FIT:
  - Suppose for the sake of contradiction that this was BEST FIT algorithm.
    The first 100 byte chunk would go into the 128 byte hole rather than the 512 byte which reflects more of WORST FIT algorithm characteristic.
    Hence, it is not BEST FIT but rather WORST FIT from the previous reasoning.

[Question #3 [10 pts]
If invoking the program as

./memory  40, 400, 80, 60
produces this output:

0 | 1024 | 1088 | 2112 | 2624 | 3648 | 3776 | 4800 | 4864 |
--------------
The 40-byte chunk was allocated at address 3736
The 400-byte chunk was allocated at address 2224
The 80-byte chunk was allocated at address 2144
The 60-byte chunk was allocated at address 4804
would you say that the heap allocator uses

first fit
best fit
worst fit
none of the above?]

The heap allocator is NONE OF THE ABOVE.

Below are the list of memory availability of each hole:
- 1024 | 1088: 64 bytes
- 2112 | 2624: 512 bytes
- 3648 | 3776: 128 bytes
- 4800 | 4864: 64 bytes

To prove that it is NONE OF THE ABOVE let us do a proof by contradiction.

PROOF ON WHY IT IS NOT FIRST FIT
  - Suppose that we assumed that this heap allocator was FIRST FIT.
    Then it would mean that the 40 byte chunk would be placed within the 64 byte hole.
    However, this is not the case as it was placed within the 128 byte hole.
    Thus, it is not FIRST FIT.

PROOF ON WHY IT IS NOT BEST FIT
  - Suppose we assumed that this heap allocator was BEST FIT.
  Then it would follow that the 40 byte would be placed within the left most 64 bytes.
  Despite placed within the 128 byte hole.
  Thus, it is not BEST FIT.


PROOF ON WHY IT IS NOT WORST FIT
  - Suppose that we assumed that this heap allocator was WORST FIT.
  Then it would mean that the 40 byte chunk would be placed within the 512 byte hole.
  However, it was placed in the 128 bytes.

Hence it is NONE OF THE ABOVE.


[Question #4 [16 pts]
After looking up some documentation, you find out that the heap allocator uses worst fit! What would the output of the memory program be when invoked as follows:

./memory  400, 100, 10, 10]

Given that this uses worst fit then using the holes of the following
- 1024 | 1088: 64 bytes
- 2112 | 2624: 512 bytes
- 3648 | 3776: 128 bytes
- 4800 | 4864: 64 bytes

1st step
  - The 400 byte would be placed within the 512 bytes since it is the biggest hole such that
    hole is reduced into 512 - 400 = 112 bytes
2nd step
  - The 100 byte is placed within the 128 bytes hole reducing it to 128 - 100 = 28 bytes
3rd step
  - The 10 byte is placed to the 512 byte as it is the next biggest hole.
  It would be allocated to the address 2214 which reduces the size of that hole into 112 - 10 = 102 bytes.

  4th step
  - The next 10 byte is placed to the 512 byte hole again as it is still the largest available hole.
    It would be allocated to the 2204 address reducing the hole into 92 bytes.

Thus, in summary, we have that
  - 400 byte and 2 x 10 byte chunks being placed in the second hole
  - 100 byte chunk being placed in the third hole.
  0 | 1024 | 1088 | 2112 | 2624 | 3648 | 3776 | 4800 | 4864 |
--------------
The 400-byte chunk was allocated at address 2224
The 100-byte chunk was allocated at address 3676
The 10-byte chunk was allocated at address 2214
The 10-byte chunk was allocated at address 2204
