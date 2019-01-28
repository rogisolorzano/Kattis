#!/usr/bin/python

import string
import math

input1 = [
    # "PAIN IS ONLY TEMPORARY BUT VICTORY IS FOREVER",
    # "WINNERS DON'T WAIT FOR CHANCES THEY TAKE THEM",
    "WINNING ISN'T EVERYTHING IT'S THE ONLY THING",
    "1"
];

chars = string.ascii_uppercase + " '"
table = {c: i for i, c in enumerate(chars)}

def dist(a, b):
    d = abs(table[a] - table[b])
    print a,b + ' = ' + str(d) if d <= 14 else str(28 - d)
    return d if d <= 14 else 28 - d

diameter = 60
speed = 15.0
circumference = math.pi * diameter
time_per_stack = circumference / len(chars) / speed

n = int(input1.pop())
for _ in range(n):
    line = input1.pop()
    f = lambda i: dist(line[i], line[i+1])
    units_run = sum(map(f, range(len(line)-1)))
    print(units_run)
    time = len(line) + units_run * time_per_stack
    print '{0:0.10f}'.format(time)
