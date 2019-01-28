input1 = [
    "PAIN IS ONLY TEMPORARY BUT VICTORY IS FOREVER",
    "WINNERS DON'T WAIT FOR CHANCES THEY TAKE THEM",
    "WINNING ISN'T EVERYTHING IT'S THE ONLY THING",
    "3"
];

def charToN(c):
    if c == ' ':
        return 91
    elif c == '\'':
        return 92
    else:
        return ord(c)

def nToChar(n):
    if n == 91:
        return ' '
    elif n == 92:
        return '\''
    else:
        return chr(n)

import math

n = int(input1.pop())

# speed is 15 feet / s
# circumference in feet
circum = math.pi * 60.0
oneUnit = circum / 28.0

for i in range(n):
    thisString = input1.pop()
    totalDistance = 0.0
    for j in range(1,len(thisString)):
        thisChar = charToN(thisString[j-1])
        destination = charToN(thisString[j])
        if thisChar < destination:
            # dest is to the right
            stepsToRight = destination - thisChar
            stepsToLeft = (thisChar - 65) + (92 - destination) + 1
        else:
            # dest is to the left
            stepsToRight = (destination - 65) + (92 - thisChar) + 1
            stepsToLeft = thisChar - destination

        thisSteps = stepsToRight if stepsToRight < stepsToLeft else stepsToLeft
        totalDistance += thisSteps * oneUnit / 15.0
        #print totalDistance

    print totalDistance + (len(thisString))
