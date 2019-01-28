input1 = ['Z','Z','Z','Z','4']

n = int(input1.pop())
total = 0
val = 0
for i in range(n):
    val = 0 if input1.pop() == 'Z' else 1
    total = total * 2 + val

print(total)
