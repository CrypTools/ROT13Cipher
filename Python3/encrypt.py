def encrypt(initial):
  """ Use : encrypt("message")
  => 'zrffntr'
  """
  initial = initial.lower()
  mylist = []
  for char in initial:
      mylist.append(ord(char) - 97)
      
  output = ""
  alphabet = dict(zip(range(0, 26), string.ascii_lowercase))
  
  for char in mylist:
    if char in alphabet:
      image = (int(char) + 13) % 26
      output += alphabet[image]
      
  return output
