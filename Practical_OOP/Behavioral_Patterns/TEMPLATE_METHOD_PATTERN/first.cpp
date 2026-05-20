#include <bits/stdc++.h>
#define int long long
using namespace std;
/*

    TEMPLATE METHOD PATTERN :

        ALL THE METHODS IN THE CLASS AND IF SOME METHODS INSIDE METHODS ARE PRE DEFINED IN INTERFACE OR IN OTHER WORDS

        THE WHOLE PATH OF FLOW IS PREDECIDED JUST CHILD CLASSES IMPLEMENT THOSE PATH ACCORDING TO THEIR NEEDS


        HERE WE DONT NEED TO THINK OF IF ELSE CASES BECAUSE THAT IS HANDLED BY THE FLOW OF THE BASE CLASS ..

        THE FLOW IS FOLLOWED OF THE BASE CLASS AND FOR THE IMPLEMENTATION IT CALLS THE CHILD CLASS..


*/
class Game
{
public:
    void play()
    {
        void init();
        while (!isGameOver())
        {
            makeMove();
        }
        showResult();
    }

protected:
    virtual void init() = 0;
    virtual bool isGameOver() = 0;
    virtual void makeMove() = 0;
    virtual void showResult() = 0;
};
class TicTacToeGame : public Game
{
private:
    int moves = 0;
    int maxMoves = 5;

protected:
    void init() override
    {
        cout << "Initializing Tic-Tac-Toe... " << endl;
    }
    void makeMove() override
    {
        if (moves >= maxMoves)
        {
            cout << "Game is Over, you cant make any more moves." << endl;
        }
        else
        {
            moves++;
            cout << "Player makes move.." << endl;
        }
    }
    bool isGameOver()
    {
        return moves >= maxMoves;
    }
    void showResult()
    {
        if (moves >= maxMoves)
            cout << "Game is Over and since this is Demo, Player 1 won !!" << endl;
        else
            cout << "Game is not over yet !!" << endl;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Game *tictactoegame = new TicTacToeGame();
    tictactoegame->play();
    return 0;
}
