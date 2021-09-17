Shinya Saito
ICS 332 Homework 1

Part 1 Warm Up
Question 1.1 What does the instruction encoded by 110010001 do? Show your work.

To do this problem we will break up the given instruction into pieces from left to right:
  * [110] -> JE: From the given table this translates into the CPU instruction JE
  * 10001 -> 10001 the n

Therefore, the instruction 110010001 translates into "JE 10001".

Question 1.2 Translate “LOAD A, [10110]” to binary. Show your work.

Similar to Question 1.1, the problem will be approached from left to right

  * LOAD -> 010: From the given table the CPU instruction of LOAD has the Opcode of 010
  * A -> 0: From the given description for the opcode STORE, it was given that A = 0.
  * [10110] -> 10110: Since this is the value that will be stored it will be kept as it is.

Therefore, “LOAD A, [10110]” to binary is 010010110.

Question 1.3 Among the instruction encodings below, which one is invalid? Give an explanation.
1. 110101100
This one is valid because going from left to right
  * 110 -> JE
  * 01100 -> [01100]
Thus, this translates into "JE 01100".
Therefore, this is valid.

2. 100110111
For the sake of contradiction let us assume that the given instruction code is valid.
If it is valid then similar to question 1.1 then the instruction has a meaning.
Going from left to right then the code can be translated to an instruction.
However, there is no opcode of [100] that has a corresponding instruction.
Thus, this leads to an initial assumption that the binary code is valid.

Hence, 10011011 is invalid.

3. 011110101
The given one is valid. By breaking it up into pieces each of the instruction encoding into pieces then
  * 011 -> STORE
  * 1 -> B
  * 10101 -> [10101]
Thus, 011110101 translated is, "STORE B, [10101]".


Part 2
Question 2.1 What is the address and the first instruction executed by the program? Explain.
We are given that the program counter is 12d=01100b, therefore, the address associated with the 01100b is
010010110. Using the table given in the previous problem when this is broken apart and translated
  * 010 -> LOAD
  * 0 -> A
  * 10110 -> [10110]

Thus, the instruction is "LOAD A, [10110]".

Question 2.2
Detail the program execution instruction by instruction (the program stops after executing the first STOP).

  LOAD A, [10110] ; set A with the value of 10110b (22d)
  LOAD B, [10111] ; set B with the value of 11011b (23d)
  SUB A, B; subtract A and B such that A is update into 0 with the error register set with 1
  JE [10001] ; since the error register is 1 then update Program Counter with 10001
  STORE A, [10110] ; store A with the value 10110b (22d)
  STOP ; Terminate the Program

Current Program Counter 01100b
  * Fetch: The PC counter increments then it becomes 01101b (13d).
  * Decode: Decode the content associated with 01100b which is 010010110 -> LOAD A, [10110]
  * Execute: The program executes the command LOAD A, [10110]
Current Program Counter 01101b
  * Fetch: The PC counter increments then it becomes 01110b.
  * Decode: Decode the content associated with 01100b which is 010110111 -> LOAD B, [10111]
  * Execute: The program executes the command LOAD B, [01101]
Current Program Counter 01110b
  * Fetch: The PC counter increments then it becomes 01111b.
  * Decode: Decode the content associated with 01110b which is 101100000 -> SUB A, B;
  * Execute: The program executes the command SUB A, B
Current Program Counter 01111b
  * Fetch: The PC counter increments then it becomes 01111b.
  * Decode: Decode the content associated with 01110b which is 110010001 -> JE [10001];
  * Execute: The program executes the command JE [10001]
Current Program Counter 01111b
  * Fetch: The PC counter increments then it becomes 01111b.
  * Decode: Decode the content associated with 01110b which is 110010001 -> JE [10001];
  * Execute: The program executes the command JE [10001] which updates the Program Counter as 10001b
Current Program Counter 10001b
  * Fetch: The PC counter increments then it becomes 10010b.
  * Decode: Decode the content associated with 01110b which is 011010110 ->   STORE A, [10110];
  * Execute: The program executes the command STORE A, [10110].
Current Program Counter: 10010b
  * Fetch: The PC counter increments then it becomes 10011b.
  * Decode: Decode the content associated with 01110b which is 111000000	 ->   STOP;
  * Execute: The program terminates.

Question 2.3 What is the content at address 10010? What is the content at address 10110?
The content at address 10010 is 111000000.
When translated this is
  * 111 STOP
  * For the stop command this terminates the program and ignores the remaining bits.

The content at address 10110 is 001000001.

Question 2.4 The last STORE instruction writes to memory the output of the program. What does this program compute? Also consider other cases with different input values. Explain.
The last STORE instruction sets A with 10101b (21d).

function(A, B):
  if A < B:
    return 0
  return B
