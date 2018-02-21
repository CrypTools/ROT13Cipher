# ROT13 Cipher
<p align="center">
<!-- replace image by project Image -->
<img height="128" src="https://cryptools.github.io/img/rot13.svg">
</p>
<p align="center">
<img src="https://cryptools.github.io/img/status/implemented.svg">
<img src="https://img.shields.io/travis/CrypTools/ROT13Cipher.svg">
<img src="https://img.shields.io/github/license/Cryptools/ROT13Cipher.svg">
<img src="https://img.shields.io/github/contributors/Cryptools/ROT13Cipher.svg">
</p>

A stupidly simple reversible substitution cipher.

> ROT13 was in use in the net.jokes newsgroup by the early 1980s. It is used to hide potentially offensive jokes, or to obscure an answer to a puzzle or other spoiler. - Wikipedia

## How it works

### Encoding

The ROT13 cipher will substitute each letter by the letter coming 13 places after it in the alphabet. According to this logic, N should map to the 27th character of the alphabet, but we only have 26 characters, so we loop the alphabet around. We now have the formula `ROT13(c) = (c + 13) % 26`, where c is the position in the alphabet of a given character.

Therefore, `A => N, B => O, ..., M => Z, N => A`

When encoding a string, we replace uppercase characters with their uppercase mirror, lowercase character with their lowercase mirror, and leave all other characters untouched.

To help us with the encoding process, we create a lookup table like this:

| A | B | C | D | E | F | G | H | I | J | K | L | M |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| N | O | P | Q | R | S | T | U | V | W | X | Y | Z |

| N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A | B | C | D | E | F | G | H | I | J | K | L | M |

Example:

Let's encode the string `Hello World!`. We need to lookup each character in our table, and then write down its image.

```
H => U
e => r
l => y
...
_ => _ # space maps to space.
W => J
...
! => !
```

Our final encoded string is `Urryb Jbeyq!`.

### Decoding

As you might have noticed from the lookup table, `ROT13(ROT13(c)) = c`. This cipher is therefore reversible, and to decode, we just need to go through the whole encoding process once more.

Example:

Our encoded output was `Urryb Jbeyq!`. We need to lookup each character in our table, and then write down its image.

```
U => H
r => e
y => l
...
_ => _ # space maps to space.
J => W
...
! => !
```

Our final decoded string is `Hello World!`.

## Cons

* Frequency analysis can be used to decrypt the message as each letter is encrypted with the same letter every time.
* Very well known cipher, easy to recognize, easy to crack

## Implementations

|  Language  |           Encrypt            |           Decrypt            |
|------------|------------------------------|------------------------------|
| Javascript | [encrypt.js](js/encrypt.js)  | [decrypt.js](js/decrypt.js)  |
|   Python   | [encrypt.py](py/encrypt.py)  | [decrypt.py](py/decrypt.py)  |
|   Swift    | [lib.swift](swift/lib.swift) | [lib.swift](swift/lib.swift) |
|   ~~C#~~   | ~~[ROT13.cs](cs/ROT13.cs)~~  | ~~[ROT13.cs](cs/ROT13.cs)~~  |

> C# code needs fixing, please do not use.

## Running the tests

Tests are automatically handled by [Travis CI](https://travis-ci.org/CrypTools/ROT13Cipher/).

## Contributing

Please read [CONTRIBUTING.md](https://github.com/CrypTools/cryptools.github.io/blob/master/CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/CrypTools/ROT13Cipher/tags).

## Authors

Made with ❤️ at CrypTools.

See also the list of [contributors](https://github.com/CrypTools/ROT13Cipher/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
