#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

#define HEIGHT 18
#define WIDTH  12


int shapes[7][4][4] =  {{                                                           //3D array of shapes
                    {1, 1, 0, 0},                                                   //Z block
                    {0, 1, 1, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
                }, {
                    {0, 0, 0, 0},                                                   //I block
                    {1, 1, 1, 1},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
                }, {
                    {0, 0, 0, 0},                                                   //O block
                    {1, 1, 0, 0},
                    {1, 1, 0, 0},
                    {0, 0, 0, 0}
                }, {
                    {1, 1, 1, 0},                                                   //T block
                    {0, 1, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
                }, {
                    {0, 1, 0, 0},                                                   //J block
                    {0, 1, 0, 0},
                    {1, 1, 0, 0},
                    {0, 0, 0, 0}
                }, {
                    {0, 1, 1, 0},                                                   // S block
                    {1, 1, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}
                }, {
                    {1, 0, 0, 0},                                                   //L block
                    {1, 0, 0, 0},
                    {1, 1, 0, 0},
                    {0, 0, 0, 0}
                }};
int ctrl = 0;
int multiplier;
unsigned int type;
int screen[HEIGHT][WIDTH];
bool gameOver;
int score;
char wall = '#';
char block = 'X';
char emptySpace = ' ';
char clear = '=';
int blockArray[4][4];
int tetrominoX;
int tetrominoY;

void clearScreen()                                                                  //delete current contents of screen
{	
    COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void reset()                                                                        //initialize the game
{
    system("cls");
    score = 0;
    gameOver = false;
    for(int i = 0; i<HEIGHT; i++)
    {
        for(int j = 0; j<WIDTH; j++)
        {
            if(i == 0 || i == HEIGHT-1 || j == 0 || j == WIDTH-1)
            {
                screen[i][j] = -1;
            }
            else screen[i][j] = 0;
        }
    }
}

void rotateBlock(int array[][4])                                                    //rotating the tetronimos
{
    if(type == 2) return;
	for(int i = 0; i<4; i++)                                                        //transposing
        {
            for(int j = 0; j<i; j++)
            {
                char temp = array[i][j];
                array[i][j] = array[j][i];
                array[j][i] = temp;
            }
        }
        for(int i = 0; i<4; i++)                                                    //flipping
        {
            int temp = array[i][0];
            array[i][0] = array[i][2];
            array[i][2] = temp;
        }
}

void spawn()                                                                        //Spawns a random tetronimo
{
    srand(time(0));                                                                 //random number generation from seed
    type = rand()%7;
    for(int y = 0; y<4; y++)
    {
        for(int x = 0; x<4; x++)
        {
            blockArray[y][x] = shapes[type][y][x];                                  //random tetronimo
        }
    }
    tetrominoX = (rand()%(WIDTH-5))+1;
    tetrominoY = 1;
    for(int i = 0; i<rand()%2+1; i++)                                               //random rotation
    {
        rotateBlock(blockArray);
    }
}

bool doesFit(int xInc, int yInc)                                                    //if tetronimo fits after x and y increment/decrement                                             
{
    int location[4][2];
    int ptr = 0; 
    for(int i = -1; i<4; i++)                                                        //calculationg coordinates of blocks
    {
        for(int j = -1; j<4; j++)
        {
            if(blockArray[i][j] == 1)
            {
                location[ptr][0] = tetrominoY+i+yInc;
                location[ptr][1] = tetrominoX+j+xInc;
                ptr++;
            }
        }
    }
    for(int i = 0; i<4; i++)
    {
        if(screen[location[i][0]][location[i][1]] != 0) return false; 
                                                                                    //if pos at screen is filled
                                                                                    //if out of bounds
    }
    return true;
}

void render()                                                                       //rendering the screen
{
    clearScreen();
    cout << "Score: " << score << endl;
    for(int i = 0; i<HEIGHT; i++)
    {
        for(int j = 0; j<WIDTH; j++)
        {
            if(screen[i][j] == -1) cout << wall;                                    //if walls
            else if(screen[i][j] != 0) cout << block;                               //if stationary block        
            else if((blockArray[i-tetrominoY][j-tetrominoX] == 1) && 
                    (i-tetrominoY>=0) && (j-tetrominoX >=0) && 
                    (i-tetrominoY<=3) && (j-tetrominoX<=3)) cout << block;
            else cout << emptySpace;                                                //if empty space
        }
        cout << endl;
    }
    // cout << endl << endl;
    // for(int i = 0; i<4; i++)
    // {
    //     for(int j = 0; j<4; j++)
    //     {
    //         cout << blockArray[i][j]; 
    //     }
    //     cout << endl;
    //}
    // cout << "X: " << tetrominoX << ", Y: " << tetrominoY << endl;
}

bool isLegal(int array[][4])                                                        //checked
{
    int location[4][2];
    int ptr = 0; 
    for(int i = 0; i<4; i++)                                                        //calculationg coordinates of blocks
    {
        for(int j = 0; j<4; j++)
        {
            if(array[i][j] == 1)
            {
                location[ptr][0] = tetrominoY+i;
                location[ptr][1] = tetrominoX+j;
                ptr++;
            }
        }
    }
    for(int i = 0; i<ptr; i++)
    {
        if(screen[location[i][0]][location[i][1]] != 0) return false;               //if pos at screen is filled
    }
    return true;
}

void lineClear(int row)                                                             //clearing the row
{
    clearScreen();
    score += (multiplier*40);
    cout << "Score: " << score << endl;
    for(int i = 0; i<HEIGHT; i++)                                                   //animation
    {
        for(int j = 0; j<WIDTH; j++)
        {
            if(screen[i][j] == -1) cout << wall;                                    //if walls
            else if(i == row) cout << clear;                                        //if cleared row
            else if(screen[i][j] != 0) cout << block;                               //if stationary block        
            else if((blockArray[i-tetrominoY][j-tetrominoX] == 1) && 
                    (i-tetrominoY>=0) && (j-tetrominoX >=0) && 
                    (i-tetrominoY<=3) && (j-tetrominoX<=3)) cout << block;
            else cout << emptySpace;                                                //if empty space
        }
        cout << endl;
    }
    for(int i = 0; i<row; i++)                                                      //shifting all rows above one row down
    {
        for(int j = 1; j<WIDTH-1; j++)
        {
            screen[row-i][j] = screen[row-i-1][j];
        }
    }
    for(int i = 1; i<WIDTH-1; i++)                                                  //inserting a new row on top
    {
        screen[1][i] = 0;
    }
    Sleep(500);
    clearScreen();
}

void plant()                                                                        //converting current into stationary blocks
{
    for(int y = 0; y<4; y++)
    {
        for(int x = 0; x<4; x++)
        {
            if((blockArray[y][x] == 1) && (y+tetrominoY>=0) && (x+tetrominoX>=0)) screen[y+tetrominoY][x+tetrominoX] = 1;
        }
    }
    multiplier = 0;
    for(int i = 0; i<4; i++)                                                        //checking rows for line clears
    {
        if(tetrominoY+i>HEIGHT-1) break;
        bool clr = true;
        for(int j = 1; j<WIDTH-1; j++)
        {
            if(screen[tetrominoY+i][j] != 1)
            {
                clr = false;
                break;
            }
        }
        if(clr)
        {
            multiplier++;
            lineClear(tetrominoY+i);
        }
    }
    for(int i = 0; i<WIDTH; i++)                                                    
    {
        if(screen[2][i] == 1)                                                   //if screen filled  
        {
            gameOver = true;
            system("cls");
            cout << "Game Over!" << endl;
            cout << endl;
            cout << endl;
            cout << " /$$     /$$                         /$$$$$$                      /$$      " << endl;
            cout << "|  $$   /$$/                        /$$__  $$                    | $$      " << endl;
            cout << " \\  $$ /$$//$$$$$$  /$$   /$$      | $$  \\__/ /$$   /$$  /$$$$$$$| $$   /$$" << endl;
            cout << "  \\  $$$$//$$__  $$| $$  | $$      |  $$$$$$ | $$  | $$ /$$_____/| $$  /$$/" << endl;
            cout << "   \\  $$/| $$  \\ $$| $$  | $$       \\____  $$| $$  | $$| $$      | $$$$$$/ " << endl;
            cout << "    | $$ | $$  | $$| $$  | $$       /$$  \\ $$| $$  | $$| $$      | $$_  $$ " << endl;
            cout << "    | $$ |  $$$$$$/|  $$$$$$/      |  $$$$$$/|  $$$$$$/|  $$$$$$$| $$ \\  $$" << endl;
            cout << "    |__/  \\______/  \\______/        \\______/  \\______/  \\_______/|__/  \\__/" << endl;
            cout << "\n Your Score:" << score << endl;
            system("pause");
            break;
        }
    }
}

void update()                                                                       //falling down of pieces
{
    if(doesFit(0, 1)) tetrominoY++;
    else
    {
        plant();
        spawn();
    }
}

void input()                                                                        //taking inputs
{
    if(_kbhit())
    {
        switch (_getch())
        {
                case 72:                                                            //up arrow detection
                    int cpyBlock[4][4];
                    for(int i = 0; i<4; i++)
                    {
                        for(int j = 0; j<4; j++)
                        {
                            cpyBlock[i][j] = blockArray[i][j];
                        }
                    }
                    rotateBlock(cpyBlock);
                    if(isLegal(cpyBlock)) rotateBlock(blockArray);
                    break;
                case 80:                                                            //down arrow detection
                    update();
                    break;
                case 75:                                                           //left arrow detection
                    if(doesFit(-1, 0)) tetrominoX--;
                    break;
                case 77:                                                           //right arrow detection
                    if(doesFit(1, 0)) tetrominoX++;
                    break;
                case ' ':
                    system("pause");
                    system("cls");
                    break;
                default:
                    break;
        }
    }
}

int main()
{
    system("cls");
    cout <<              "$$$$$$$$\\         $$\\               $$\\" << endl;           
    cout <<              "\\__$$  __|        $$ |              \\__|" << endl;         
    cout <<              "   $$ | $$$$$$\\ $$$$$$\\    $$$$$$\\  $$\\  $$$$$$$\\" << endl; 
    cout <<              "   $$ |$$  __$$\\_$$  _|   $$  __$$\\ $$ |$$  _____|" << endl;
    cout <<              "   $$ |$$$$$$$$ | $$ |    $$ |  \\__|$$ |\\$$$$$$\\  " << endl;
    cout <<              "   $$ |$$   ____| $$ |$$\\ $$ |      $$ | \\____$$\\ " << endl;
    cout <<              "   $$ |\\$$$$$$$\\  \\$$$$  |$$ |      $$ |$$$$$$$  |" << endl;
    cout <<              "   \\__| \\_______|  \\____/ \\__|      \\__|\\_______/" << endl;
    cout << endl << endl;
    cout << "LeftArrow: Move Left" << endl << "RightArrow: Move Right" << endl << "UpArrow: Rotate" << endl << "DownArrow: Drop" << endl;
    system("pause");
    reset();
    spawn();
    while(!gameOver)                                                                //gameloop
    {
        input();
        if(ctrl%25==0) update();
        render();
        Sleep(10);
        clearScreen();
        ctrl++;
    }
    return 0;
}