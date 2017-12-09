//Author: Ali Alqattan

#include <string>
#include "account.h"
using namespace std;

void account::setName(string name)
{

        acname = name;
}
string account::Name()
{
        return acname;
}
void account::updateBalance(float amount)
{
        balance = amount;

}
float account::getBalance()
{

        return balance;

}
void account::setQ(string Q)
{
        secretquestion = Q;

}
void account::setA(string A)
{
        secretanswer = A;

}

string account::getQ()
{

        return secretquestion;
}
string account::getA()
{

        return secretanswer;
}
void account::setPass(string pwd)
{

        password = pwd;
}
string account::Pass()
{

        return password;
}
string  account::getUsername()
{

        return username;
}
void account::setUsername(string u)
{
        username = u;

}
