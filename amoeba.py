
# List size = [ySize,xSize]
def getNeighbors(pos,size):
    neighbors = {
        'top':{},
        'right':{},
        'bottom':{},
        'left':{},
        'topright':{},
        'bottomright':{},
        'bottomleft':{},
        'topleft':{}
    }
    x = pos['x']
    y = pos['y']
    ym1 = pos['y'] - 1
    yp1 = pos['y'] + 1
    xm1 = pos['x'] - 1
    xp1 = pos['x'] + 1
    topLimit = ym1 < 0
    rightLimit = xp1 >= size[1]
    bottomLimit = yp1 >= size[0]
    leftLimit = xm1 < 0

    if topLimit:
        neighbors['top'] = None
    else:
        neighbors['top']['y'] =  ym1
        neighbors['top']['x'] = x

    if rightLimit:
        neighbors['right'] = None
    else:
        neighbors['right']['y'] = y
        neighbors['right']['x'] = xp1

    if bottomLimit:
        neighbors['bottom'] = None
    else:
        neighbors['bottom']['y'] = yp1
        neighbors['bottom']['x'] = x

    if leftLimit:
        neighbors['left'] = None
    else:
        neighbors['left']['y'] = y
        neighbors['left']['x'] = xm1

    if topLimit or rightLimit:
        neighbors['topright'] = None
    else:
        neighbors['topright']['y'] = ym1
        neighbors['topright']['x'] = xp1

    if bottomLimit or rightLimit:
        neighbors['bottomright'] = None
    else:
        neighbors['bottomright']['y'] = yp1
        neighbors['bottomright']['x'] = xp1

    if bottomLimit or leftLimit:
        neighbors['bottomleft'] = None
    else:
        neighbors['bottomleft']['y'] = yp1
        neighbors['bottomleft']['x'] = xm1

    if topLimit or leftLimit:
        neighbors['topleft'] = None
    else:
        neighbors['topleft']['y'] = ym1
        neighbors['topleft']['x'] = xm1

    return neighbors

# Map pos = {x: n, y: n}
# follows the loops, turning all # into 0
def followLoop(pos,matrix,size):

    while True:
        neighbors = getNeighbors(pos,size)
        found = False

        for idx,key in enumerate(neighbors):
            if neighbors[key] is not None:
                if matrix[ neighbors[key]['y'] ][ neighbors[key]['x'] ] == '#':
                    matrix[ neighbors[key]['y'] ][ neighbors[key]['x'] ] = '0'
                    pos = neighbors[key]
                    found = True
                    break

        if found == False:
            break

    return matrix


ySize,xSize = map(int, raw_input().split())
matrix = [[] for a in range(ySize)]

for i in range(ySize):
    str = raw_input()
    for j in range(len(str)):
        matrix[i].append(str[j])

count = 0
for i in range(ySize):
    for j in range(xSize):
        if matrix[i][j] == '#':
            count += 1;
            matrix = followLoop({'x': j, 'y': i},matrix,[ySize,xSize])

print count
