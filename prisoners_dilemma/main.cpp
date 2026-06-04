/*
 * 2026-06-04
 * Copyright (c) 2026 Michael Kartsiotis. All Rights Reserved.
 * This is an attempt to creatre a simulation of the well known in game theory prisoner's dilemma and evaluate the
 * different strategies. For educational purposes the game will have a player Vs computer option. Initial thoughts -
 * Class specifiactions:
 * - Interface strategy class
 * - Stategies subclasses
 * - Grading class to grade and keep a history of the game(made with templates just for eduactional purposes as well as
 * for possible future development)
 * - Game arena class that is going to hande all the communication as well as keep up with the history of the game
 * - UI class for UI purposes
 * NOTE THAT DURING THE WHOLE GAME 1 is COLLABORATION AND 0 is STEAL
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

class Strategy
{
  protected:
    string name;

  public:
    Strategy(std::string name)
    {
        this->name = name;
    }
    virtual bool next_move(const vector<bool> &game_history) = 0;
    virtual ~Strategy()
    {
    }
};

class TitForTat : public Strategy
{
  private:
  public:
    TitForTat() : Strategy("Tit for Tat")
    {
    }
    bool next_move(const vector<bool> &game_history) override
    {
        if (game_history.size() >= 3)
            return game_history.at(game_history.size() - 3);
        else
            return 1;
    }
};

class AlwaysSteal : public Strategy
{
  public:
    AlwaysSteal() : Strategy("Always Steal")
    {
    }
    bool next_move(const vector<bool> &game_history) override
    {
        return 0;
    }
};
class AlwaysCollab : public Strategy
{
  public:
    AlwaysCollab() : Strategy("Always Collab")
    {
    }
    bool next_move(const vector<bool> &game_history) override
    {
        return 1;
    }
};

class Random : public Strategy
{
  public:
    Random() : Strategy("Random")
    {
        srand(time(NULL));
    }
    bool next_move(const vector<bool> &game_history) override
    {
        return (rand() % 2);
    }
};

class RageBaiter : public Strategy
{
  public:
    RageBaiter() : Strategy("Ragebait")
    {
    }
    bool next_move(const vector<bool> &game_history) override
    {
        unsigned int total_size = game_history.size();
        int base_point =
            (total_size + 1) % 2; // Logical since if I played first then every time I check the size will be a multiple
                                  // of 2. I want to get the point of my opponent that is why I add 1.
        for (int i = base_point; i < game_history.size(); i++)
            if (game_history.at(i) == 0)
                return 0;
        return 1;
    }
};

class Player : public Strategy
{
  public:
    Player() : Strategy("Player Input")
    {
    }
    bool next_move(const vector<bool> &game_history) override
    {
        bool playermove;
        cin >> playermove;
        return playermove;
    }
};

class history
{
  private:
    vector<bool> game_history;

  public:
    history()
    {
    }
    void store_next(bool value_to_store);
    const vector<bool> &game_history_vector() const;
};

void history::store_next(bool value_to_store)
{
    game_history.push_back(value_to_store);
}
const vector<bool> &history::game_history_vector() const
{
    return game_history;
}

class GameGrader
{
  private:
    int total_rounds, final_grade = 0;
    const vector<bool> &game_history_vector;

  public:
    GameGrader(int number_of_rounds, const vector<bool> &history_vector)
        : total_rounds(number_of_rounds), game_history_vector(history_vector)
    {
    }
    int getFinalGrade() const
    {
        return final_grade;
    }
    int getRoundNumber() const
    {
        return total_rounds;
    }
    // Game is graded in respect to player 1
    void grade_game()
    {
        for (int i = 0; i < total_rounds; i++)
        {
            bool player1_decision = game_history_vector.at(2 * i);
            bool player2_decision = game_history_vector.at(((2 * i) + 1));
            if (player1_decision == true)
            {
                if (player2_decision == true)
                    final_grade += 1;
                else
                    final_grade -= 2;
            }
            else
            {
                if (player2_decision == true)
                    final_grade += 3;
                else
                    final_grade -= 4;
            }
        }
    }
};

class UI
{
  public:
    void print_initial_message()
    {
        cout << "HELLO AND WELCOME TO PRISONER'S DILEMMA!!!" << endl;
        cout << "YOU ARE TRAPPED INSIDE A PRISON WITH YOUR TEAMATE AND THE GUARDS GIVE YOU A CHANCE TO ESCAPE" << endl;
        cout << "YOU AND YOUR TEAMATE ARE IS SEPARATE ROOMS AND COMMUNICATION IS STRICTLY PROHIBITED" << endl;
        cout << "IF YOU BOTH OPT TO HELP EACH OTHER YOU GET A MILD PUNISHMENT(1 more year). " << endl;
        cout << "IF ONE of YOU DO NOT COLLABORATE AND THE OTHER DOES, THE PLAYER WHO COLLABORATED LOSES(10 years "
             << "sentence) AND THE OTHER ESCAPES" << endl;
        cout << "BUT IF YOU BOTH DECLINE TO COLLABORATE YOU BOTH LOSE and get 5 years each" << endl;
    }
    void print_selection_message()
    {
        cout << "---------------SELECT PLAYER STRATEGIES--------------" << endl;
        cout << "1. Player Input" << endl
             << "2. TIT FOR TAT" << endl
             << "3. ALWAYS ACCEPT" << endl
             << "4. ALWAYS DECLINE" << endl
             << "5. Random" << endl
             << "6. Ragebaiter" << endl;
    }
    void print_game_over()
    {
        cout << "GAME OVER!" << endl;
    }
    void print_game_history_matrix(const vector<bool> &history)
    {
        cout << "PLAYER 1: " << endl;
        for (int i = 0; i < history.size(); i += 2)
            cout << history.at(i) << " ";
        cout << endl << " PLAYER 2:  ";
        for (int i = 1; i < history.size(); i += 2)
            cout << history.at(i) << " ";
        cout << endl;
    }
};

int main()
{
    UI myUI;
    Strategy **player = new Strategy *[2];
    myUI.print_initial_message();
    for (int i = 0; i < 2; i++)
    {
        cout << "FOR PLAYER: " << i << endl;
        myUI.print_selection_message();
        char in;
        cin >> in;
        switch (in)
        {
        case '1':
            player[i] = new Player;
            break;
        case '2':
            player[i] = new TitForTat;
            break;
        case '3':
            player[i] = new AlwaysCollab;
            break;
        case '4':
            player[i] = new AlwaysSteal;
            break;
        case '5':
            player[i] = new Random;
            break;
        case '6':
            player[i] = new RageBaiter;
            break;
        default:
            player[i] = new AlwaysCollab;
        }
    }
    history GAME_HISTORY_RECORDS;
    for (int i = 0; i < 100; i++)
    {
        GAME_HISTORY_RECORDS.store_next(player[0]->next_move(GAME_HISTORY_RECORDS.game_history_vector()));
        GAME_HISTORY_RECORDS.store_next(player[1]->next_move(GAME_HISTORY_RECORDS.game_history_vector()));
    }
    myUI.print_game_history_matrix(GAME_HISTORY_RECORDS.game_history_vector());
    GameGrader grader(100, GAME_HISTORY_RECORDS.game_history_vector());
    grader.grade_game();
    cout << "ROUNDS = " << grader.getRoundNumber() << " " << "RESULTS: " << grader.getFinalGrade() << endl;
}
