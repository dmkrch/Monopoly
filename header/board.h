#include <iostream>
#include <vector>
#include <memory>

// player of single game : has name, balance 
class Player 
{
public:
    Player(std::string name, int balance)
        : m_name(name)
        , m_balance(balance)
    {

    }

private:    
    std::string m_name;
    int m_balance;
};

// abstract class that represents a single board cell of monopoly map
class BoardCell
{
public:
    BoardCell() = default;

    virtual void Do() = 0;

    void SetOwner(std::shared_ptr<Player> owner)
    {
        m_owner = std::make_shared<Player>(owner);
    }

    std::shared_ptr<Player> GetOwner() const
    {
        return m_owner;
    }

private:
    std::shared_ptr<Player> m_owner;
    std::string m_title;
    std::string m_icon;
};

class ChanceCell : public BoardCell
{
public:
    virtual void Do() override 
    {
        // player should take chance card and do the action on it
    }

private:

};

// board of monopoly
class Board
{
public:
    Board()
    {
        Init();
    }

private:
    void Init()
    {
        // create map with certain cells: all streets, chances etc.
    }

private:
    std::vector<std::unique_ptr<BoardCell>> m_cells;
};
