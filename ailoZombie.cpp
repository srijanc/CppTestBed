#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>

int main(int argc, char** argv)
{
    if(argv[1] != nullptr)
    {
        std::string input = std::string(argv[1]);

        // Tokenizing command line arguments:
        std::istringstream streamInput(input);
        std::vector<std::string> tokenInputs{
            std::istream_iterator<std::string>{streamInput},
            std::istream_iterator<std::string>{}};

        int length = tokenInputs.size();

        size_t grid = std::stoi(tokenInputs[0]);
        if(grid < 2) {
            std::cout << "Not enough space to move around" << std::endl;
            exit(0);
        }

        // Default coordinate value represented by 0
        int world[grid][grid] = {{0}};

        // Zombie coordinates:  Represented by 1
        size_t z_Xcord = tokenInputs[1][1] - '0';
        size_t z_Ycord = tokenInputs[1][3] - '0';
        world[z_Xcord][z_Ycord] = 1;

        for(int i = 2; i < length-1; i++)
        {
            // Creature coordinates: Represented by -1
            size_t c_Xcord = tokenInputs[i][1] - '0';
            size_t c_Ycord = tokenInputs[i][3] - '0';

            world[c_Xcord][c_Ycord] = -1;
        }

        // Path to travel
        std::string path = tokenInputs[length-1];

        // Creature to Zombie queue and Final positions of Zombies
        std::queue<std::pair<int, int>> que, zombiePosition;

        // Initial position of Zombie:
        int X = z_Xcord;
        int Y = z_Ycord;

        // Initial score:
        int zombieScore = 0;

        while(true)
        {
            for(auto p: path)
            {
                switch (p)
                {
                case 'D':
                    if(Y+1 == grid)
                    {
                        Y = 0;
                        if(world[X][Y] == -1)
                        {
                            que.push({X, Y});
                            world[X][Y] = 1;
                            ++zombieScore;
                        }
                    }
                    else
                    {
                        if(world[X][++Y] == -1)
                        {
                            que.push({X, Y});
                            world[X][Y] = 1;
                            ++zombieScore;
                        }
                    }
                    break;

                case 'U':
                    if(Y-1 < 0)
                    {
                        Y = grid - 1;
                        if(world[X][Y] == -1)
                        {
                            que.push({X, Y});
                            world[X][Y] = 1;
                            ++zombieScore;
                        }
                    }
                    else {
                        if(world[X][--Y] == -1)
                        {
                            que.push({X, Y});
                            world[X][Y] = 1;
                            ++zombieScore;
                        }
                    }
                    break;

                case 'L':
                    if(X-1 < 0)
                    {
                        X = grid - 1;
                        if(world[X][Y] == -1)
                        {
                            que.push({X, Y});
                            world[X][Y] = 1;
                            ++zombieScore;
                        }
                    }
                    else
                    {
                        if(world[--X][Y] == -1)
                        {
                            que.push({X, Y});
                            world[X][Y] = 1;
                            ++zombieScore;
                        }
                    }
                    break;

                case 'R':
                    if(X+1 == grid)
                    {
                        X = 0;
                        if(world[X][Y] == -1)
                        {
                            que.push({X, Y});
                            world[X][Y] = 1;
                            ++zombieScore;
                        }
                    }
                    else
                    {
                        if(world[++X][Y] == -1)
                        {
                            que.push({X, Y});
                            world[X][Y] = 1;
                            ++zombieScore;
                        }
                    }
                    break;
                
                default:
                    break;

                }
            }

            zombiePosition.push({X, Y});
            if(que.size() == 0)
            {
                break;
            }
            else
            {
                auto newZombie = que.front();
                X = newZombie.first;
                Y = newZombie.second;
                que.pop();
            }
        }

        std::cout << "Zombies' Score: " << zombieScore << std::endl;
        std::cout << "Zombies' Position(s): ";
        while(zombiePosition.size() > 0)
        {
            auto pos = zombiePosition.front();
            std::cout << "(" << pos.first << "," << pos.second << ") ";
            zombiePosition.pop();
        }

        std::cout << std::endl;

    }
    else {
        std::cout << "Not sufficient command line argument" << std::endl;
    }

}