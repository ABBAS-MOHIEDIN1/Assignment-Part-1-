// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT6L
// Names:HUBAISH YASER MUSTAFA AHMED|ABBAS MOHIEDDIN ALI  | none
// IDs: 1211310073 | 1211310075 | none
// Emails: 1211310073@student.mmu.edu.my | yln050140@gmail.com | none
// Phones: 01125132735 | 01125113534 | none
// *********************************************************









#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;
int rows = 5, column = 9, zombie = 1;
int user_rows, user_column, user_zombie;
int health = 30;
int attack = 40;
void help();

int setting_screen(int &user_rows, int &user_column, int &user_zombie)
{
    cout << "\t\t\t Default Game Setting" << endl;
    cout << "-----------------------------------" << endl;
    cout << "Board rows is 5" << endl;
    cout << "Board column is 5" << endl;
    cout << "Board zombize is 1" << endl;
    cout << "If you want to keep this setting press y if not press n   : ";
    char Choice;
    cin >> Choice;
    switch (Choice)
    {
    case 'y':
        cout << "Enter rows =>  :";
        cin >> user_rows;
        cout << endl;
        cout << "Enter  column =>";
        cin >> user_column;
        cout << endl;
        cout << "+++++++++++++++++++++++++++++++++++++" << endl;
        cout << "zombie setting";
        cout << endl;
        cout << "Enter The Numbers of zombise => ";
        cin >> user_zombie;
        cout << endl;
        cout << "setting updated" << endl;
        system("cls");
        system("pause");

        break;

    case 'n':
        user_rows = 5;
        user_column = 5;
        user_zombie = 1;

        break;

   
    }
}
class Mars
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_;          // to indicate private data
public:
   
    Mars(int dimX = user_rows, int dimY = user_column);
    void increaseHealth()
    {
        ::health += 20;
    }
    void init(int dimX, int dimY);
    void display() const;

    void middle_R()
    {
        int middleRow = dimY_ / 2;
        int middleCol = dimX_ / 2;
        map_[middleRow][middleCol] = 'R';
    }

    void add_random_z()
    {
        for (int i = 0; i < user_zombie; i++)
        {
            int x = rand() % dimX_;
            int y = rand() % dimY_;
            map_[y][x] = 'Z';
        }
    }

   
    void moveZombies(vector<vector<char>> &map, int dimX, int dimY)
    {
        for (int row = 0; row < dimY; row++)
        {
            for (int col = 0; col < dimX; col++)
            {
                if (map[row][col] == 'Z')
                {
                    int move = rand() % 4; // Randomly choose direction to move
                    if (move == 0)         // Move up
                    {
                        if (row - 1 >= 0 && map[row - 1][col] == ' ')
                        {
                            map[row][col] = ' ';
                            map[row - 1][col] = 'Z';
                        }
                    }
                    else if (move == 1) // Move down
                    {
                        if (row + 1 < dimY && map[row + 1][col] == ' ')
                        {
                            map[row][col] = ' ';
                            map[row + 1][col] = 'Z';
                        }
                    }
                    else if (move == 2) // Move left
                    {
                        if (col - 1 >= 0 && map[row][col - 1] == ' ')
                        {
                            map[row][col] = ' ';
                            map[row][col - 1] = 'Z';
                        }
                    }
                    else // Move right
                    {
                        if (col + 1 < dimX && map[row][col + 1] == ' ')
                        {
                            map[row][col] = ' ';
                            map[row][col + 1] = 'Z';
                        }
                    }
                }
            }
        }
    }

    void move_R()
    {

        Mars f;
        int middleRow = dimY_ / 2;
        int middleCol = dimX_ / 2;
        map_[middleRow][middleCol] = 'A';
        int currRow = middleRow;
        int currCol = middleCol;

        while (true)
        {
            display();
            cout << "Move R up (w), down (s), left (a), right (d)  or (h) for help : ";
            char direction;
            cin >> direction;
            switch (direction)
            {

            case 'w':
                if (currRow - 1 >= 0 && map_[currRow - 1][currCol] != 'r' && map_[currRow - 1][currCol] != 'A')
                {
                    if (direction == 'w' && currRow - 1 >= 0 && map_[currRow - 1][currCol] == 'h')
                    {
                        f.increaseHealth();
                    }
                    map_[currRow][currCol] = ' ';
                    currRow--;
                    map_[currRow][currCol] = 'A';
                }
                moveZombies(map_, dimX_, dimY_);
                system("pause");
                system("cls");
                
                break;
            case 's':
                if (currRow + 1 < dimY_ && map_[currRow + 1][currCol] != 'r' && map_[currRow + 1][currCol] != 'A')
                {
                    if (direction == 'w' && currRow - 1 >= 0 && map_[currRow - 1][currCol] == 'h')
                    {
                        f.increaseHealth();
                    }
                    map_[currRow][currCol] = ' ';
                    currRow++;
                    map_[currRow][currCol] = 'A';
                }
                moveZombies(map_, dimX_, dimY_);
                system("pause");
                system("cls");
                
                break;
            case 'a':
                if (currCol - 1 >= 0 && map_[currRow][currCol - 1] != 'r' && map_[currRow][currCol - 1] != 'A')
                {
                    if (direction == 'w' && currRow - 1 >= 0 && map_[currRow - 1][currCol] == 'h')
                    {
                        f.increaseHealth();
                    }
                    map_[currRow][currCol] = ' ';
                    currCol--;
                    map_[currRow][currCol] = 'A';
                }
                moveZombies(map_, dimX_, dimY_);
                system("pause");
                system("cls");
                
                break;
            case 'd':
                if (currCol + 1 < dimX_ && map_[currRow][currCol + 1] != 'r' && map_[currRow][currCol + 1] != 'A')
                {
                    if (direction == 'w' && currRow - 1 >= 0 && map_[currRow - 1][currCol] == 'h')
                    {
                        f.increaseHealth();
                    }
                    map_[currRow][currCol] = ' ';
                    currCol++;
                    map_[currRow][currCol] = 'A';
                }
                moveZombies(map_, dimX_, dimY_);
                system("pause");
                system("cls");
                
                break;
            case 'q':
                return;

            case 'h':
            {
                help();
            }
           
            }
        }
    }
};

Mars::Mars(int dimX, int dimY)
{
    init(dimX, dimY);
}
void Mars::init(int dimX, int dimY)
{
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', 'h', 'r', ' ', '^', ' ', 'p', ' ', 'v', '>', ' ', '<', ' '};
    int noOfObjects = 12; // number of objects in the objects array
    // create dynamic 2D array using vector
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)

    {
        map_[i].resize(dimX_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
            //
        }
    }
}
void random_heath()
{
}

void Mars::display() const
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    cout << " --__--__--__--__--__--__--__--_" << endl;
    cout << " = Alien Vs Zombie=" << endl;
    cout << " __--__--__--__--__--__--__--__-" << endl;
    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << " ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-"
                 << "+-"
                 << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (dimY_ - i);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << " "
                 << " | " << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-"
             << "+-"
             << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << "  ";
        if (digit == 0)
            cout << "  ";
        else
            cout << digit;
    }
    cout << endl;
    cout << " ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
    cout << "-> Alien  :  Life : " << ::health << " , Attack " << ::attack << "\n";
    for (int i = 0; i < ::user_zombie; i++)
    {
        cout << "-> zombie" << i + 1 << " :  Life : " << ::health << " , Attack " << ::attack << "\n";
    }
}

void test1_1()
{
    Mars mars;

    mars.middle_R();
    mars.add_random_z();
    mars.move_R();
    mars.display();
}

int main()
{

    int setting;
    setting_screen(user_rows, user_column, user_zombie);

    srand(1);
    test1_1();

    return 0;
}

void help()
{
    cout << "+++++++++++++++HELP++++++++++++++++" << endl;
    cout << "1. w - Move Up" << endl;
    cout << "2. s - Move Down" << endl;
    cout << "3. a - Move Lift" << endl;
    cout << "4. d - Move right" << endl;
    cout << "5. arrow - chang the direction for an arrow" << endl;
    cout << "6. h - Display help commands" << endl;
    cout << "7. save - save the game" << endl;
    cout << "8. load - to load the game" << endl;
    cout << "9. q - for quit the game " << endl;
    cout << "+++++++++++++++HELP++++++++++++++++" << endl;
    system("pause");
    
}