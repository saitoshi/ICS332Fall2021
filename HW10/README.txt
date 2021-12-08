@author Shin Saito
@assignemnt ICS 332

[Exercise #1: Address Translation [20 pts]
Consider the following page table, in which “x” means an invalid entry.

------------------
logical | physical
------------------
|  15   |    x   |
|  14   |    x   |
|  13   |    x   |
|  12   |    x   |
|  11   |   31   |
|  10   |    x   |
|   9   |    5   |
|   8   |    7   |
|   7   |    x   |
|   6   |    2   |
|   5   |    x   |
|   4   |    4   |
|   3   |    6   |
|   2   |    1   |
|   1   |    0   |
|   0   |   12   |
------------------
Assume a 2KiB (i.e., 2,048 bytes) page size. Give the physical address corresponding to the following logical addresses. For convenience, in this exercise all physical and logical addresses are decimal values.

Your answer should thus be decimal values. Show your work.]

[a. [4 pts] 2020]

Given that the page size is 2048 bytes then
  - 2020 div 2048 = 0 -> page number is 0
  - 2020 mod 2048 = 2020 -> offset is 2020
Then
  - 2048(12) + 2020 = 26596

Thus the physical address is 26596.

[b. [4 pts] 12540]
  - 12540 div 2048 = 6 -> page number is 6
  - 12540 mod 2048 = 252 -> offset is 252
Then
  - 2048(2) + 252 = 4348

[c. [4 pts] 8150]
  - 8150 div 2048 = 3 -> page number is 3
  - 8150 mod 2048 = 2006 -> offset is 2006
  Then
  2048(6) + 2006 = 14294

  Thus the physical address is 14294.

[d. [4 pts] 22540]
  - 22540 div 2048 = 11 -> page number is 11
  - 22540 mod 2048 = 12 -> offset is 12
  Then
  2048(31) + 12 = 63500

  Thus the physical address is 63500.

[e. [4 pts] Give a logical address (in the range 0-32767) that will generate an error given the above page table and explain.]
Suppose we have 10250 as a logical address then
  - 10250 div 2048 = 5 -> page number is 5.
  However, from the page table page number 5 is invalid.

  Thus, there is no physical address that this number can be translated into.

[Exercise #2: Logical and physical address size [6 pts]
Consider a logical address space of 16 pages with 4,096 bytes per page, mapped onto a physical memory of 8 frames.
a. [3 pts] How many bits are required in the logical address? (show your work)]

Given that
- page size 4096 bytes per page -> 2^12
- page number 16 -> 2^4

Since logical address = (page number)(page size) then we have
  (2^4)(2^12) = 2^16 as multiplying with the same bases then we add the exponent values

Thus there are 16 bits required.

[b. [3 pts] How many bits are required in the physical address? (show your work)]
Given that
  - there are 8 frames -> 8 = 2^3
  - page size 4096 bytes per page & 4096 = 2^12
Then recall that physical address = (frame number)(frame size ) then
  physical address = (2^12)(2^3) = 2^15
Thus, 15 bits are required for the physical address.

[Exercise #3: Page table size [8 pts]
Consider a computer system with 64-bit logical addresses, 2-KiB page/frame size, and 4GiB of physical memory. (Give all answers as powers of 2.)
a. [4 pts] How many entries are there in a conventional single-level page table for a process that would use the maximum possible address space? (show your work)]
Given that we have a system of
  64 bit logical address -> 2^64 bytes
  2 KiB page size which in bytes is 2^11 bytes
Then we have
  2^64/2^11 = 2^(64-11) = 2^53
Thus, there are 2^53 single level page table available.

[b. [4 pts] How many entries are there in an inverted page table? (show your work)]
Given that
  physical memory 4 GiB = 2^2 2^30 bytes = 2^32 bytes
  2 KiB page size which in bytes is 2^11 bytes
Then to find the amount of entries
  2^32/2^11= 2^(32 - 11) = 2^21
Thus there are 2^21 entries.

[Exercise #4: Page table structure [16 pts]
Suppose we have a computer system with 44-bit logical addresses, page size of 64KiB, and 4 bytes per page table entry.]

[a. [8 pts] How many pages are in the logical address space for a process that uses the largest possible address space? (show your work)]
Given that we have 44 bit logical addresses and that the page size is 64 KiB then
  - 44 bit-> 2^44 bytes
  - 64 KiB -> 2^6 * 2^10 bytes = 2^16 bytes
  Then it follows that
  - 2^44/2^16 = 2^(44 - 16) = 2^28
  Therefore, there are 2^28 pages that uses the largest possible address space.

[b. [8 pts] Suppose we use two-level paging and arrange for all page tables to fit into a single page frame. How will the bits of the address be divided up? (show your work)]
There are
  - 14 bits inner page
  - 14 bits outer page
  - 16 bits off set

From part (a) we foudn that 2^28 pages and given that there are 2^2 bytes per page. Then
  - 2^28 * 2^2 = 2^30 bytes.

Thus,
  - 2^30/2^16 = 2^(30 - 16) = 2^14

[c. [6 pts EXTRA CREDIT] Suppose we have a program with a 4GiB address space. Counting the program and all page tables, using the two-level page table scheme from the previous question, how much memory, in number of page frames, is used? (show your work)]
To calculate the the page number we have that
  - 4 GiB -> 2^2 * 2^30 = 2^32 bytes
  - pages = (address space)/ (page size ) -> 2^32/2^16 = 2^16 pages with 16 bits offset.
  - Page table size is now 2^16 * 2^2 = 2^18 which exceeds the table size so we have to create another page table.
    2^18 / 2^16 = 2^2 = 4 pages in page table 2
  - pages to store outer page table

  2^16 + 2^2 + 1　= 65541

  65541 page frames are used
