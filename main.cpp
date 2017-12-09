// Author - Ali Alqattan
// project 4 - Account Manager

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdlib>
#include "account.h"

using namespace std;

void msg1();
void msg2();
int import(vector <account> &);
int main()
{
        string a;
        int amount;
        char user2;
        vector <account> accounts;
        amount = import(accounts);
        string id;
        string password;
        string name;
        string id2;
        string id3;
        float cash;
        float remaining ;
        string b;
        string pass2;
        string secretq;
        string secretans;
        int accountnumber;
        int logged = 0; 
        int exists = 0;
        do
        {


                msg1();
                cin >> a;
                if(a == "1")
                {
                        cout <<"Enter login ID - " ;
                        cin >> id;
                        cout <<"Enter Password - ";
                        cin >> password;
                        for(int i = 0;i<amount;i++)
                        {

                                if((accounts[i].getUsername()) == id)
                                {
                                        if(accounts[i].Pass() == password)
                                        {
                                                logged = 1;
                                                accountnumber = i;
                                        }

                                }
                        }
                        if(logged == 1)
                        {
                                cout <<"Login Successfull , Welcome "<<accounts[accountnumber].Name() << endl;
                                logged = 0;
                                do
                                {
                                        msg2();
                                        cin>>user2;
                                        switch(user2)
                                        {
                                                case '1':
                                                        cout <<"Your Balance is $"<<accounts[accountnumber].getBalance() << endl;
                                                        break;
                                                case '2':
                                                        cout <<"How much cash do you want to deposit? - " ;
                                                        cin >> cash;
                                                        remaining = accounts[accountnumber].getBalance();
                                                        accounts[accountnumber].updateBalance(remaining+cash);
                                                        cout <<"Your Balance is $"<<accounts[accountnumber].getBalance() << endl;
                                                        cash = 0;

                                                        break;
                                                case '3':
                                                        cout <<"How much cash do you want to withdraw? - " ;
                                                        cin >> cash;
                                                        remaining = accounts[accountnumber].getBalance();
                                                        if(remaining >= cash)
                                                        {
                                                                accounts[accountnumber].updateBalance(remaining-cash);


                                                        }
                                                        else
                                                        {
                                                                cout <<"You dont have that much in your account" << endl;
                                                        }

                                                        cout <<"Your Balance is $"<<accounts[accountnumber].getBalance() << endl;
                                                        cash =0;


                                                        break;
                                                case '4':
                                                        break;
                                                default:
                                                        cout <<"Wrong choice try again" << endl;
                                                        break;

                                        }   

                                }while(user2 != '4');
                        }
                        else
                        {
                                cout <<"Invalid UserName or password try Again" << endl;
                        }



                }
                else if(a == "2")
                {
                        cout <<"Enter Your name - " ;
                        cin.ignore();
                        getline (cin,name);

                        do{
                                cout <<"Enter a new username - " ;

                                getline(cin,id2);

                                exists = 0;
                                for(int i = 0;i<amount;i++)
                                {
                                        if(accounts[i].getUsername() == id2)
                                        {
                                                cout <<"This username already exists. Please try another one" << endl;
                                                exists = 1;
                                        }
                                }
                        }while(exists == 1);
                        cout << "Enter a new Password - ";
                        getline(cin,pass2);
                        cout << "Enter a Secret Question - ";
                        getline(cin,secretq);
                        cout << "Enter a Secret Answer - ";
                        getline(cin,secretans); 


                        accounts.push_back(account());
                        accounts[amount].setName(name);
                        accounts[amount].setUsername(id2);
                        accounts[amount].setPass(pass2);
                        accounts[amount].setQ(secretq);
                        accounts[amount].setA(secretans);
                        accounts[amount].updateBalance(0);
                        amount = amount + 1;

                }
                else if(a == "4")
                {

                        cout <<"Have a Nice Day" << endl;
                        ofstream f;
                        f.open("accounts.txt");
                        for(int i = 0;i<amount;i++)
                        {
                                f << accounts[i].Name() << endl;
                                f << accounts[i].getUsername() << endl;
                                f << accounts[i].Pass() << endl;
                                f << accounts[i].getQ() << endl;
                                f << accounts[i].getA() << endl;
                                f << accounts[i].getBalance() << endl;
                        }   
                        f.close();
                }
                else if(a == "3")
                {
                        cin.ignore();
                        cout << "Whats your Username - ";
                        cin >> id3;

                        for(int i = 0;i<amount;i++)
                        {
                                if(accounts[i].getUsername() == id3)
                                {
                                        cout <<accounts[i].getQ() << endl;
                                        cout <<"Answer - " ;
                                        cin.ignore();
                                        getline(cin,secretans);
                                        if(secretans == accounts[i].getA())
                                        {
                                                cout <<"Your Password is - "<<accounts[i].Pass() << endl;   


                                        }
                                        else
                                        {
                                                cout <<"Wrong Secret Answer" << endl;
                                        }

                                }
                        }

                }
                else
                {   
                        cout <<"Wrong Choice try again" << endl;


                }
        }while(a != "4");

        return 0;
}
void msg2()
{
        cout <<"What do you want to do?" << endl;
        cout <<"1. Check Balance" << endl;
        cout <<"2. Deposit" << endl;
        cout <<"3. Withdraw" << endl;
        cout <<"4. Quit" << endl;
        cout <<"Enter the Number corresponding to the choice" << endl;
        cout <<"Input - " ;


}
void msg1()
{


        cout <<"welcome to Bank . What do u want to do?" << endl;
        cout <<"1. Login" << endl;
        cout <<"2. Create New Account" << endl;
        cout <<"3. Forgot my Password" << endl;
        cout <<"4. Quit" << endl;
        cout <<"Enter the Number corresponding to the choice" << endl;
        cout <<"Input - " ;
}
int import(vector <account> &acc)
{
        ifstream f;
        f.open("accounts.txt");
        string field;
        int iteration = 0;
        int dataindex = 0;
        int data =0;
        float data2;
        string data1;
        if(dataindex == 0)
        {
                acc.push_back(account());
        }
        while(f.good())
        {
                getline (f,field);
                switch(iteration)
                {
                        case 0:
                                acc[dataindex].setName(field);      
                                break;
                        case 1:
                                acc[dataindex].setUsername(field);
                                break;
                        case 2:
                                acc[dataindex].setPass(field);
                                break;
                        case 3:
                                acc [dataindex].setQ(field);
                                break;
                        case 4:
                                acc[dataindex].setA(field);
                                break;
                        case 5:
                                data2 = atof(field.c_str());
                                acc[dataindex].updateBalance(data2);        

                                break;
                }
                if(iteration >=5)
                {
                        iteration = 0;
                        dataindex = dataindex + 1;
                        acc.push_back(account());
                }
                else
                {
                        iteration = iteration + 1;
                }


        }

        return dataindex;

}
