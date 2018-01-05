# ROT13 Cipher

## History and usage

The ROT13 Cipher stands for "rotate by 13 places" and is a **substitution cipher**. ROT13 is based on a special shift of the Caesar cipher. It was developed in ancient Rome. ROT13 Cipher encrypts a message using an affine function : 1x + 13. According to wikipedia :

> ROT13 was in use in the net.jokes newsgroup by the early 1980s. It is used to hide potentially offensive jokes, or to obscure an answer to a puzzle or other spoiler.

## Detailed Explanations : How it works?

1. Firstly, each character of the initial text (message to encrypt) is converted in a number from 0 to 25, corresponding to its position in the Latin alphabet which contains 26 letters --> (a = 0, b = 1 ... z = 25 ).

2. Then, each number obtained is transformed by an affine function (1x + 13). "x" is representing the number and 13 is the value of the shift.

3. If we take all the images and put them in a list, we obtain n numbers corresponding to n charcaters of the initial text. The next step consists in finding the values of mudulo 26 of each number. (**Modulo means remainder**)

> Example : Modulo 4 of 19 is **3** because 15 = 4 * 4 + **3** In the other hand, modulo 26 of 26 is **0** because 26 = 26 * 1 + **0**

4.  Therefore, we cobtain a new list with n element, each between 0 and 25 both included. All these numbers are converted in letters of the Latin Alphabet using the tables below.

5. We finally create the final message by putting all the letters side by side.

Steps 1 and 4 can be done with these tables : 

| A | B | C | D | E | F | G | H | I | J | K  | L  | M  |
|---|---|---|---|---|---|---|---|---|---|----|----|----|
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |

| N  | O  | P  | Q  | R  | S  | T  | U  | V  | W  | X  | Y  |  Z |
|----|----|----|----|----|----|----|----|----|----|----|----|----|
| 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 | 24 | 25 |

## Weaknesses

- If an attacker knows that the message has been encrypted using ROT13 Cipher, he just needs to use the same function to decrypt the message (f(x) = 1x + 13) as 2 x 13 = 26; the number of letters existing in the alphabet.
- We can also use **frequency analysis** to decrypt the message as each letter is encrypted with the same algorithm and the most common letters in english are : 

<p align="center"> 
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/d5/English_letter_frequency_%28alphabetic%29.svg/340px-English_letter_frequency_%28alphabetic%29.svg.png">
</p>

## Example

### Encrypting

- Message to encrypt : **ATTACK**

- The function used is the same for encrypting/decrypting : **1x + 13**
- Using the above tables, **ATTACK** can be written as : **0 19 19 0 2 10**

Images of each number :

- f(0) = 13
- f(19) = 32
- f(2) = 15
- f(10) = 23

The new list is : **13 32 32 13 15 23**

Using the **modulo 26 method**, we obtain:

- Mod(13,26) = 13
- Mod(32,26) = 6
- Mod(15,26) = 15
- Mod(23,26) = 23

The final message is **13 6 6 13 15 23** and using the tables again, we convert them in the encrypted message :

> **NGGNPX**

**ATTACK** is encrypted with the function **1x + 13** and becomes **NGGNPX**.

### Decrypting

- Message to decrypt : **NGGNPX**

- The function used is the same for encrypting/decrypting : **1x + 13**
- Using the above tables, **NGGNPX** can be written as : **13 6 6 13 15 23**

Images of each number :

- f(13) = 26
- f(6) = 19
- f(15) = 28
- f(23) = 36

The new list is : **26 19 19 26 28 36**

Using the **modulo 26 method**, we obtain:

- Mod(26,26) = 0 (26 = 26 * 1 + 0)
- Mod(19,26) = 19
- Mod(28,26) = 2
- Mod(36,26) = 10

The final message is **0 19 19 0 2 10** and using the tables again, we convert them in the encrypted message :

> **ATTACK**

**NGGNPX** is decrypted with the function **1x + 13** and becomes **ATTACK**.
