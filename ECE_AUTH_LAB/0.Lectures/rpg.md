# RPG GAME 
## Οδηγίες
Να μπορεί να επιτεθεί ένας χαρακτήρα σε έναν άλλο χαρακτήρα και αντίστροφα.  
Συνήθως υπάρχει ένας χαρακτήρας σε μία θέση και μπορεί να δράσει να επιτεθεί ή να αμυνθεί  
## Τύποι χαρακτήρων 
- Μαγοι  
- Πολεμιστές  
- Τοξοβόλος  
## Όπλα  
- Ραβδι  
- Ρόπαλο  
- Τόξο  
```cpp  
class weapon
{
protected:
    int proximity;
    int damage;
    string name;
    int level;
    int durability;
public:
    weapon(int d, string n, int level);
    int getDamage() const;
    string getName() const;
    int getLevel() const;
    int getDurability() const;
    void setDurability(int db);
    virtual int generateDamage() = 0; 
    // Abstract class->No instance of this class can be initiated!!!
};
class sword : public weapon
{
protected:
public:
    sword(int d, string n, int level) : weapon(d, n ,level)
    {
        cout << "Sword weapon created" << endl;
    }
    void generateDamage();
};
int sword::generateDamage()
{
    durability--;
    return damage * level;
}

class Character
{
protected:
    string CharacterName;
    int health;
    int strength;
    weapon *w;
public:
    Character(string name, int health, weapon *w, int my_strength);
    bool BattleReady(); //Health state and proximity
    bool isAlive();
    virtual int Attack(Character *c) = 0;
    virtual int Defend(int d) = 0;
    void move();
    virtual void battleStrategy();
};

int main(void)
{
    Character **Players = {};
    wand *pt_wand = new Staff(...);
    Character *pt = Magician M("dgsagwdyw", 100, pt_wand, 10);
    sword * pt_sword= new Sword(...);
    Character *pt1 = Warrior("dsdhs", 100, pt_sword, 10);
    for(int i = 0;i< 3; i++)
    {
        if(pt->isAlive())
            pt->battleStrategy(pt1);
        if(pt1->isAlive())
            pt1->battleStrategy(pt);
    }
}
```
