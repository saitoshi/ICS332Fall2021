@assignment name ICS 332 HW 8
@author Shinya Saito
@author saitoshi
@due date October 30 2021

{Exercise 1 Conversions [6pts]
For each of the following numbers, convert the number into the two other bases among decimal, hex, binary. For example, given the number 0xFF, you should give the conversions into decimal and binary. Because it’s very easy to look up a number converter online, it’s important that you show your work for each conversion.
}
1. 200d
Decimal to Binary Conversion
200/2 = 100 R 0
100/2 = 50 R 0
50/2 = 25 R 0
25/2 = 12 R 1
12/2 = 6 R 0
6/2 = 3 R 0
3/2 = 1 R 1
1/2 = 0 R 1

200d -> 1100 1000b

Decimal to Hexadecimal Conversion
200/16 = 12 R 8
12/16 = 0 R 12

12 -> C

Therefore, 200d -> 0xC8

2. 0xC91

Hexadecimal to Decimal Conversion
  - C -> 12
  Then
  12*16^2 + 9*16 + 1 *16^0
  = 3217
Thus, 0xC91 -> 3217d

Hexadecimal to Binary Conversion
Breakdown the hexadecimal from left most to the right most
  - 0xC -> 12d -> 1100b
  - 0x9 -> 9d -> 1001b
  - 0x1 -> 1d -> 0001b

Combine it
1100 1001 0001b

Thus, 0xC91 -> 1100 1100 0001b

3. 0x8CE
The given is hexadecimal so convert it in the following
  Hexadecimal to Binary

  Break it down from leftmost to rightmost and convert it in the following
  - 0x8 -> 8d -> 1000b
  - 0xC -> 12d -> 1100b
  - 0xE -> 14d -> 1110b
  then combine it therefore,

  0x8CE -> 1000 1100 1110b

  Hexadecimal to Decimal Conversion
  Break it down and convert it to decimal
  (8)*16^2 + 12*16^1 + 14*16^0
  = 2048 + 192 + 14
  = 2254

  Thus,  0x8CE -> 2254d

4. 1010 0101 1011 0110b
Binary to Hexadecimal

1010 -> 10d -> A
0101 -> 5d -> 5
1011 -> 11d -> B
0110 -> 6d -> 6

Thus, A5B6

Binary to Decimal

2^15 + 2^13 + 2^10 + 2^8 + 2^7 + 2^5 + 2^4 + 2^2 + 2^1 =
42422

Thus, the decimal equivalence is 42422d.

5. 256d
Decimal to Binary

Recall that log2(256) = 8 which implies that 2^8 is 256 then it follows that

256d -> 0001 0000 0000b

Decimal to Hexadecimal

Using the binary equivalence of 256d then from the left to right most into hexadecimal

0001b -> 0x1
0000b -> 0x0
0000b -> 0x0

Thus, 256d 0x100.

6. 0111 0011b
Binary to Hexadecimal Conversion

Break down bits from left to right then
0111b -> 7d -> 0x7
0011b -> 3d -> 0x3

Hence the hexadecimal equivalence is 0x73.

Binary to Decimal conversion

To convert from binary to decimal we do the following operation

0*2^7 +1*2^6 +1*2^5 + 1*2^4 + 0*2^3 + 0*2^2 + 1*2^1 + 1
= 64 + 32 + 16 + 2 + 1
= 115

Hence the decimal equivalence is 115d.

[Exercise #2: Arithmetic [8pts]
Give the result of each of the operations below. Show your work by showing carries.]
(1. 0xFEDCBA0123456789 + 0x0987654321FEDCBA)
Let C represent the carry
    CCCC     CCCCCC
  0xFEDCBA0123456789
 +0x0987654321FEDCBA
 ===================
0x108641F4445444443

Thus 0xFEDCBA0123456789 + 0x0987654321FEDCBA = 0x108641F4445444443

(2. 1110 1010 1001 1111b + 1110 0100 1100 0101b)
  CC      C   CC CCC
  1110 1010 1001 1111b
  1110 0100 1100 0101b
+ ====================
0001 1100 1111 0110 0100b

Thus, 1110 1010 1001 1111b + 1110 0100 1100 0101b = 0001 1100 1111 0110 0100b

(3. 0xFEDCBA0123456789 - 0x0987654321FEDCBA)
To solve for this I took the complement of the hexadecimal of 0x0987654321FEDCBA
  0xFFFFFFFFFFFFFFFF
- 0x0987654321FEDCBA
====================
  0xF6789ABCDE012345

    CCCC    C
  0xFEDCBA0123456789
+ 0xF6789ABCDE012345
====================
  0xF55554BE01468ACF
f55554be01468acf
(4. 1110 1010 1001 1111b - 1110 0100 1100 0101b)
          C C CC
    1110 1010 1001 1111b
   -1110 0100 1100 0101b
  ======================
    0000 0101 1101 1010b

1110 1010 1001 1111b - 1110 0100 1100 0101b = 0000 0101 1101 1010b


[Exercise #3: Bitwise Operators [4pts]]
(1 0xDEF AND 0x456)

Convert the given hexadecimal to binary then

0xDEF -> D E F -> 1101 1110 1111b

0x456 -> 4 5 6 -> 0100 0101 0110b

Then

1101 1110 1111b
AND
0100 0101 0110b
--------------------------
0100 0100 0110b
Then convert the resulting binary back to hexadecimal from the leftmost to the rightmost bits

0100b -> 0x4
0100b -> 0x4
0110b -> 0x6

Therefore the result is

	0xDEF AND 0x456 -> 0x446


(2 93d OR 153d)

Convert the given decimal into binary then

93d -> 0101 1101b
153d -> 1001 1001b

0101 1101b
OR
1001 1001b
------------------
1101 1101 b
Convert the following binary to decimal
1101 1101b -> 2^7 + 2^6 + 2^4 + 2^3 + 2^2 + 1 = 221

Thus,  93d OR 153d => 221d

[Exercise #4: Memory sizes [6pts]]
(1 How many bytes are there in 1 KiB?)
There are 1024 bytes in 1 KiB.
  Recall that 1 KiB is 2^10 bytes then using the conversion track we know that
  1 KiB * (2^10 bytes/KiB) = 1024 bytes
  Thus, there exists 1024 bytes.

(2 How many bytes are there in 1KB?)
Recall that 1 KiloByte (KB) is 1000 bytes therefore,
there are 1000 bytes in 1 KB.

(3 How many 4MiB chunks in a 256GiB file?)
Given that we are working with 256GiB file and saving it in a chunk of 4 MiB then recall the following facts
  - 1 GiB -> 2^30 bytes
  - 1 MiB -> 1,048,576 bytes
  - 4 MiB per chunk

256 GiB | 2^30 bytes / GiB | 1,048,576 bytes/MiB | 1/4 chunk/MiB | = 65536 chunk

Thus, there are 65536 chunks.

[Exercise #5: Eggs [4pts]]
(1 I have a basket with x eggs in it, and a bunch of 7-egg boxes to fill. How many boxes do I need to store all the eggs?)
Suppose we have x number of eggs to fill a box that contains 7 eggs each.
Let n be in the positive integer system such that n represent the number of the boxes.

To answer this question let us break this up into two cases.

Case 1: n = x div 7 where 0 = x mod 7
Suppose that x is a divisible number by 7. Then it implies that n = x div 7 then it follows that n boxes are required as there are no remainders to concern about.

Case 2: n = x div 7 where z = x mod 7 such that z between [1,6]

Suppose that there exits a z when x mod 7 is taken. Then it implies that we have a remainder such that implying that we need n + 1 amount of boxes to fill in the left over remainder eggs.

Thus, for every x eggs then it follows that x/7 = n boxes or n +1 of boxes are required depending whether 7 is divisible or not.

(2 I have a basket with x eggs in it, and a bunch of 7-egg boxes. I fill boxes one after another. The last box is not full and contains z < 7 eggs. What is z.)
Suppose that we have x amount of eggs to fill up a 7 egg box with.
Given that we fill one box after another with the last box not being filled up to the full, we can assume that x is a positive integer greater than 7 but also is one that is not divisible by 7
therefore implying that there exists a positive integer z between 1 to 6 such that z = x mod 7.
The reason 0 is excluded from z because 0 = x mod 7 implies that x is divisible by 7 by definition of modularity.

Thus, z is x mod 7 where x is the amount of eggs in the basket.

[Exercise #6: Addressing [2pts]]
(1 How many bits are required to address a 4 GiB address space?)
Given that the address space is 4 GiB then convert the GiB to B then we have that
4 GiB -> 2^32 Bytes. From this a total of 32 bits would make it sufficient to map every byte in the 4 GiB address space to its own unique address. 
