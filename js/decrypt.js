/* ==========================================================================
 *
 *    Use:
 *    'Uryyb Jbeyq!'.encrypt()
 *    => 'Hello World!'
 *
 * ========================================================================== */

String.prototype.decrypt = function() {
  output = ''
  alphabet = {}

  chr = x => {return String.fromCharCode(x)}

  for (var i = 0; i < 26; i++) {
    alphabet[chr(65+i)] = chr(65 + (i + 13) % 26)
    alphabet[chr(97+i)] = chr(97 + (i + 13) % 26)
  }

  for (var char of this) {
    if (char in alphabet) output += alphabet[char]
    else output += char
  }

  return output
}

module.exports = text => text.decrypt();
