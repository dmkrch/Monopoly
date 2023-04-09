#include "board.h"


class Game
{
public:
    Game()
    {
        Init();
    }

    bool Start()
    {
        // first all players roll the dice to determinate turns sequence

        
    }

private:
    void Init() 
    {

    }

private:
    std::vector<std::shared_ptr<Player>> m_players;
    Board m_board;
};