import sys
import os
# import array

def main():

    if len(sys.argv) < 2:
        print("Not sufficient command line argument")
        sys.exit(0)

    # Tokenizing command line arguments:
    input = str(sys.argv[1]).split()
    length = len(input)
    grid = int(input[0])

    if(grid < 2):
        print("Not enough space to move around")
        sys.exit(0)

    # Default coordinate value represented by 0
    world = [[0 for x in range(grid)] for y in range(grid)]

    # Zombie coordinates:  Represented by 1
    z_Xcord = int(input[1][1])
    z_Ycord = int(input[1][3])
    world[z_Xcord][z_Ycord] = 1

    for i in range(2, length-1):
        # Creature coordinates: Represented by -1
        c_Xcord = int(input[i][1])
        c_Ycord = int(input[i][3])
        world[c_Xcord][c_Ycord] = -1

    # Path to travel
    path = input[length-1]

    # Creature to Zombie queue and Final positions of Zombies
    queue = []
    zombiePosition = []

    # Initial position of Zombie:
    X = z_Xcord
    Y = z_Ycord

    # Initial score:
    zombieScore = 0
    
    while(True):
        for p in path:
            if p == 'D':
                if Y+1 == grid:
                    Y = 0
                    if world[X][Y] == -1:
                        queue.append((X, Y))
                        world[X][Y] = 1
                        zombieScore += 1
                else:
                    Y += 1
                    if world[X][Y] == -1:
                        queue.append((X, Y))
                        world[X][Y] = 1
                        zombieScore += 1

            elif p == 'U':
                if Y-1 < 0:
                    Y = grid - 1
                    if world[X][Y] == -1:
                        queue.append((X, Y))
                        world[X][Y] = 1
                        zombieScore += 1
                else:
                    Y -= 1
                    if world[X][Y] == -1:
                        queue.append((X, Y))
                        world[X][Y] = 1
                        zombieScore += 1

            elif p == 'L':
                if X-1 < 0:
                    X = grid - 1
                    if world[X][Y] == -1:
                        queue.append((X, Y))
                        world[X][Y] = 1
                        zombieScore += 1
                else:
                    X -= 1
                    if world[X][Y] == -1:
                        queue.append((X, Y))
                        world[X][Y] = 1
                        zombieScore += 1

            elif p == 'R':
                if X+1 == grid:
                    X = 0
                    if world[X][Y] == -1:
                        queue.append((X, Y))
                        world[X][Y] = 1
                        zombieScore += 1
                else:
                    X += 1
                    if world[X][Y] == -1:
                        queue.append((X, Y))
                        world[X][Y] = 1
                        zombieScore += 1

            else:
                continue

        zombiePosition.append((X, Y))
        if len(queue) == 0:
            break

        else:
            newZombie = queue.pop(0)
            X, Y = newZombie

    print("Zombies' Score: ", zombieScore)
    print("Zombies' Position(s): ", end="")
    for p in zombiePosition:
        print(p, end=" ")
    print()

main()