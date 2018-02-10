# ==============================================================================
#
#     Use:
#     decrypt("Uryyb Jbeyq!")
#     => "Hello World!"
#
# ==============================================================================

def decrypt(initial):

    output = ""
    alphabet = {}

    for i in range(26):
        alphabet[chr(65+i)] = chr(65 + (i + 13) % 26)
        alphabet[chr(97+i)] = chr(97 + (i + 13) % 26)

    for char in initial:
        if char in alphabet:
            output += alphabet[char]
        else:
            output += char

    return output
