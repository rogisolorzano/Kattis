input1 = ['O','Z','Z','O','4']

# this function rings a bell which:
# finds the lowest ocelet in array
# turns the ocelot to zebra
# turns all subsequent zebras into ocelots
def ringBell(animals):
    i = len(animals) - 1
    lastOcelot = None
    while i >= 0:
        if animals[i] == 'O':
            lastOcelot = i
            animals[i] = 'Z'
            break
        i -= 1

    if lastOcelot is not None:
        for j in range((lastOcelot + 1),len(animals)):
            if animals[j] == 'Z':
                animals[j] = 'O'

    return animals

def hasOcelot(animals):
    return ''.join(animals) != 'Z' * len(animals)

nAnimals = int(input())
animals = []

for i in range(nAnimals):
    animals.append(input())

bells = 0;
while True:
    if hasOcelot(animals) == False:
        break
    bells += 1;
    animals = ringBell(animals);

print(bells);
