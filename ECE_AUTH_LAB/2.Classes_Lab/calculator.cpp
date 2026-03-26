#include <iostream>
using namespace std;
class Calculator
{
  private:
    float num1, num2;
    char op;

  public:
    Calculator(float n1 = 0, float n2 = 0, char c = ' ');
    ~Calculator();
    void set_num1(float n);
    void set_num2(float n);
    void set_op(char c);
    char get_op() const;
    float get_num1() const;
    float get_num2() const;
    float add();
    float subtruct();
    float mult();
    float divide();
    int modulo();
    float do_calculation();
};

float Calculator::add()
{
    return num1 + num2;
}
float Calculator::divide()
{
    return num1 / num2;
}
float Calculator::subtruct()
{
    return num1 - num2;
}
float Calculator::mult()
{
    return num1 * num2;
}
float Calculator::get_num1() const
{
    return num1;
}
float Calculator::get_num2() const
{
    return num2;
}
void Calculator::set_num1(float n)
{
    num1 = n;
}
void Calculator::set_num2(float n)
{
    num2 = n;
}
char Calculator::get_op() const
{
    return op;
}
void Calculator::set_op(char c)
{
    op = c;
}
Calculator::Calculator(float n1, float n2, char c)
{
    num1 = n1;
    num2 = n2;
    op = c;
    cout << "Calc initialized" << endl;
}
Calculator::~Calculator()
{
    cout << "CALC DESTROYED" << endl;
}
int Calculator::modulo()
{
    return (int)num1 % (int)num2;
}
float Calculator::do_calculation()
{
    if (op == '+')
        return this->add();
    else if (op == '-')
        return this->subtruct();
    else if (op == '*')
        return this->mult();
    else if (op == '/')
        return this->divide();
    else if (op == '%')
        return this->modulo();
    else
        return -1;
}
int main(void)
{
    class Calculator MyCalc;
    while (1)
    {
        char ch;
        float n1, n2;
        cout << "GEIVE ME AN OPERATOR: " << endl;
        cin >> ch;
        if (ch == 'e')
            break;
        cout << "Give me N1" << endl;
        cin >> n1;
        cout << "Give me N2" << endl;
        cin >> n2;
        MyCalc.set_num1(n1);
        MyCalc.set_num2(n2);
        MyCalc.set_op(ch);
        cout << "RESULT  IS: " << MyCalc.do_calculation() << endl;
    }
}
