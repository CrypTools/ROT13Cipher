import string

def encrypt():
  initial = input('Give the message to encrypt (no space or special charcater) : ')
  initial = initial.lower()
  numeros = []
  for char in initial:
      numeros.append(ord(char) - 97)
      
  output = ""
  alphabet = dict(zip(range(0, 26), string.ascii_lowercase))
  
  for char in numeros:
    if char in alphabet:
      image = (int(char) + 13) % 26
      output += alphabet[image]
  print("Encrypted message is : " + output)
