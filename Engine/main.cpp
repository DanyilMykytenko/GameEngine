#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0)); //command to learn our PC to work with random

    const int worldSizeY = 40; // const for world size X && Y coordinates
    const int worldSizeX = 70;

    int pPosX = worldSizeX / 2; // const for player position
    int pPosY = worldSizeY / 2;


    char action = -1; // variable for movement

    char gMap[worldSizeY][worldSizeX]; // map, that contain objects
    char pMap[worldSizeY][worldSizeX]; // map, that sees player

    for(int y = 0; y < worldSizeY; y++)
        for(int x = 0; x < worldSizeX; x++)
        {
            switch(rand()%20) // rand()%20 - do a random number from 0 to 20
            {
            case 1: gMap[y][x] = 't'; break; //paint a tree
            case 2: gMap[y][x] = 's'; break; //paint a stone
            default: gMap[y][x] = '.'; //paint a field
            }
            pMap[y][x] = '*'; //filling player map with *
        }

    while(true) //while, that has no end(all the time repeating)
    {
        // commands that allow user to know the world
        pMap[pPosY-1][pPosX] = gMap[pPosY-1][pPosX]; //up
        pMap[pPosY+1][pPosX] = gMap[pPosY+1][pPosX]; //down
        pMap[pPosY][pPosX-1] = gMap[pPosY][pPosX-1]; //left
        pMap[pPosY][pPosX+1] = gMap[pPosY][pPosX+1]; //right

        pMap[pPosY-1][pPosX-1] = gMap[pPosY-1][pPosX-1]; //up && left
        pMap[pPosY-1][pPosX+1] = gMap[pPosY-1][pPosX+1]; //up && right
        pMap[pPosY+1][pPosX-1] = gMap[pPosY+1][pPosX-1]; //down && left
        pMap[pPosY+1][pPosX+1] = gMap[pPosY+1][pPosX+1]; //down && right

        system("cls"); //command, that clears all text from console
        //for linux - system("clear")

        for(int y = 0; y < worldSizeY; y++)
        {
            for(int x = 0; x < worldSizeX; x++)
            {
                if(y == pPosY && x == pPosX)//painting a player
                    cout << "@";
                else
                    cout << pMap[y][x];//painting player map
            }
            cout << endl;
        }
        cout << ">"; //asking for an action
        cin >> action; //writing in variable
        switch(action) //switch, that works with player movement
        {
            case 'w': if(gMap[pPosY-1][pPosX] == '.') pPosY--; break; //movement to up
            case 's': if(gMap[pPosY+1][pPosX] == '.') pPosY++; break; //movement to down
            case 'd': if(gMap[pPosY][pPosX+1] == '.') pPosX++; break; //movement to right
            case 'a': if(gMap[pPosY][pPosX-1] == '.') pPosX--; break; //movement to left
        }
    }

    return 0; //the most important code!!!!!!!!!!!!!
}
