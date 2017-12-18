###################################
#
# Rot13 is reversible
#  Use: rot13("Hello World")
#  => "Uryyb Jbeyq"
#
##################################
import codecs

def rot13(txt):
	return codecs.encode(txt, "rot13")
