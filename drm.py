import math

def charToN(c):
    return ord(c) - 65

def nToChar(n):
    return chr(n+65)

def rotateChar(char,n):
    return nToChar((n + charToN(char)) % 26)

def sumAndRotate(part):
    nRotate = 0
    word = ''
    for idx,char in enumerate(part):
        nRotate += charToN(char)

    for idx,val in enumerate(part):
        word += rotateChar(part[idx],nRotate)

    return word

string = 'EWPGAJRB'

first,second = string[:int(len(string)/2)], string[int(len(string)/2):]

decoded = sumAndRotate(first)
secondDecoded = sumAndRotate(second)

final = ''
for idx,c in enumerate(decoded):
    final += rotateChar(c,charToN(secondDecoded[idx]))

print(final)
