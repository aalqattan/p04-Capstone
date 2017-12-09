//Author: Ali Alqattan

#include<string>
using namespace std;

class account{
        public : 

                void setName(string);
                string Name();
                void updateBalance(float);
                float getBalance();
                void setQ(string);
                void setA(string);
                string getQ();
                string getA();
                void setPass(string);
                string Pass(); 
                string getUsername();
                void setUsername(string);

        private:

                string acname;
                float balance;
                string secretquestion;
                string secretanswer;
                string password;
                string username;        




};
