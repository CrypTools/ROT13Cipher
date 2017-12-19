import string

def decrypt(initial):
  """ Use : decrypt('zrffntr')
  => 'message'
  """
  initial = initial.lower()
  list = []
  for char in initial:
      list.append(ord(char) - 97)
  
  output = ""
  alphabet = dict(zip(range(0, 26), string.ascii_lowercase))
  
  for char in list:
    if char in alphabet:
      image = (int(char) + 13) % 26
      output += alphabet[image]
  
  return output
