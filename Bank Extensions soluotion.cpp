
#include <iostream>
#include <vector> 
#include  <string> 
#include <iomanip> 
#include  <fstream>  
using namespace std; 
string  namefile = "myfile.txt";   
string filenameusersss = "usersfile.txt"; 
struct   currinusers
{
    string nameusers;
    short   passwoord = 0; 
    int   Permissions = 0; 
    bool markfordelte = false;




};
currinusers   dateUsers;


enum  enmangeusers {
    listusers = 1, addNewUsers = 2, DeleteUsers = 3, updateUsers = 4, FindUsers = 5, manimenue = 6
};

enum  enisPermissions {


    all = -1, showClintlists = 1, AddNewClient = 2, DeleteClient = 4, UpdateClient = 8, FindClient = 16, Transactions = 32, MangeUserss = 64

};
enum   enMainMenueOption {
    showclint = 1, addnewclint = 2, Deleteclint = 3, Updateclint = 4, findclint = 5, Transaction = 6, MangeUsers = 7, logout = 8
        







};


void showMangeUsersMenueScreen(); 
void     login();
void mainmenue();
void     ShowTransaction();
  bool IsPermissions(enisPermissions  Permission); 
  int ReadPermissions();


struct   infooacount
{
    string  accountnumber;
    string  pincode;
    string name;
    string  iphone;
    double  accountbalance = 0; 
    bool  markfordelte = false;
};     

string  readAccount()
{
    string  nameaccount;
    cout << "place enter  Account ";
    cin >> nameaccount;

    return  nameaccount;
}
short  ReadMainMenueOption()
{

    short   num = 0;
    cout << "choose  what do you want to do  ? [1to 6 ] ? ";
    cin >> num;

    return  num;
}
vector<string> splitstring(string S1, string Delim)
{
    vector<string> vString;
    int pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }

    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

infooacount  convortfromstringtostruct(string word, string dlim = "#//#")
{
    infooacount stinffoo;
    vector  <string >  vstring;
    vstring = splitstring(word, dlim);

    stinffoo.accountnumber = vstring[0];
    stinffoo.pincode = vstring[1];
    stinffoo.name = vstring[2];
    stinffoo.iphone = vstring[3];
    stinffoo.accountbalance = stod(vstring[4]); // cast string to 




    return   stinffoo;

}

bool sarchaccount(string accountnumber)
{

    fstream myfile;
    infooacount  date;
    myfile.open(namefile, ios::in);

    if (myfile.is_open())
    {
        string line;
        while (getline(myfile, line))
        {

            date = convortfromstringtostruct(line);
            if (date.accountnumber == accountnumber)
            {


                myfile.close();
                return  true;


            }

        }
        myfile.close();
    }
    return false;
}

infooacount  readaddclint()
{

    infooacount   info;
    cout << endl << "place enter  accountnumber " << endl;
    getline(cin >> ws, info.accountnumber);

    while (sarchaccount(info.accountnumber))
    {

        cout << "Clint  With [" << info.accountnumber << "] already  exists   , enter anther Account Number";
        cin >> info.accountnumber;


    }


    cout << endl << "Enter Pincode  ?";
    getline(cin >> ws, info.pincode);
    cout << endl << "enter Name ? ";
    getline(cin, info.name);

    cout << endl << "Enter phone  ? ";
    getline(cin, info.iphone);
    cout << endl << "Enter  Accountbalance ? ";
    cin >> info.accountbalance;



    return   info;





}
string  convortstrct(infooacount  claint, string     dlim = "#//#")
{

    string s = "";
    s += claint.accountnumber + dlim;
    s += claint.pincode + dlim;
    s += claint.name + dlim;
    s += claint.iphone + dlim;
    s += to_string(claint.accountbalance) + dlim;

    return  s;
}
string  ConvertUserRecordToLine(currinusers  claint, string     dlim = "#//#")
{

    string s = "";
    s += claint.nameusers + dlim;
    s += to_string(claint.passwoord) + dlim;
    s += to_string(claint.Permissions) + dlim;










    return  s;






}
currinusers  convortfromstringtostruct2(string word, string dlim = "#//#")
{
    currinusers stinffoo;
    vector  <string >  vstring;
    vstring = splitstring(word, dlim);
    stinffoo.nameusers = vstring[0];
    stinffoo.passwoord = stoi(vstring[1]);
    stinffoo.Permissions = stoi(vstring[2]);
    return   stinffoo;
}
bool UserExistsByUsername(string accountnumber)
{

    fstream myfile;
    currinusers  date;
    myfile.open(filenameusersss, ios::in);

    if (myfile.is_open())
    {
        string line;
        while (getline(myfile, line))
        {

            date = convortfromstringtostruct2(line);
            if (date.nameusers == accountnumber)
            {


                myfile.close();
                return  true;


            }

        }
        myfile.close();
    }
    return false;
}

vector < infooacount>    loaddatefromfile(string  namefile)
{
    fstream   myfile;
    vector  < infooacount>  vdate;
    myfile.open(namefile, ios::in);
    if (myfile.is_open())
    {

        string  line;
        infooacount  date;
        while (getline(myfile, line))
        {
            date = convortfromstringtostruct(line);

            vdate.push_back(date);


        }
        myfile.close();
    }
    return vdate;
}  
vector < currinusers>    loaddateUsersfromfile(string  namefile)
{
    fstream   myfile;
    vector  < currinusers>  vdate;
    myfile.open(namefile, ios::in);
    if (myfile.is_open())
    {

        string  line;
        currinusers  date;
        while (getline(myfile, line))
        {
            date = convortfromstringtostruct2(line);

            vdate.push_back(date);


        }

        myfile.close();
    }
    return vdate;
}

infooacount    ChangClientRecord(string Accountnumber)
{
    infooacount info;
    info.accountnumber = Accountnumber;

    cout << endl << "Enter Pincode  ?";
    getline(cin >> ws, info.pincode);
    cout << endl << "enter Name ? ";
    getline(cin, info.name);

    cout << endl << "Enter phone  ? ";
    getline(cin, info.iphone);
    cout << endl << "Enter  Accountbalance ? ";
    cin >> info.accountbalance;






    return info;






}
void ShowAccessDeniedMessage()
{

    cout << "\n------------------------------------\n";
    cout << "Access Denied, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin.";
    cout << "\n------------------------------------\n";





 }
void  printClientcard(infooacount   date)
{

    cout << "the folwing are the clint detals " << endl;

    cout << "Accountnumber : " << date.accountnumber << endl;
    cout << "pin code      : " << date.pincode << endl;
    cout << "Name          : " << date.name << endl;
    cout << "phone         : " << date.iphone << endl;
    cout << "Accountbalance: " << date.accountbalance << endl;


}
void  printdate(infooacount  date)
{

    cout << "|" << setw(15) << left << date.accountnumber;
    cout << "|" << setw(12) << left << date.pincode;
    cout << "|" << setw(40) << left << date.name;
    cout << "|" << setw(12) << left << date.iphone;
    cout << "|" << setw(12) << left << date.accountbalance;


}
void  showClintlist(
)
{
    if (!IsPermissions(enisPermissions::showClintlists))
    {
        ShowAccessDeniedMessage(); 
        return;  

    }
    vector < infooacount  >   vClient;

    vClient = loaddatefromfile(namefile);

    cout << "\n\t\t\t\t   Clint list  ( " << vClient.size() << ") Clint (s) " << endl;
    cout << "---------------------------------------------------------------------------------";
    cout << "----------------------------------------" << endl;
    cout << "|" << setw(15) << left << "Account Number  ";
    cout << "|" << setw(12) << left << "pin code ";
    cout << "|" << setw(40) << left << "Clint  Name ";
    cout << "|" << setw(12) << left << "phone    ";
    cout << "|" << setw(12) << left << "Blance ";
    cout << endl << "---------------------------------------------------------------------------------";
    cout << "----------------------------------------" << endl;
    if (vClient.size() == 0)
    {


        cout << "\t\t\t No Client Available in the system ! ";

    }
    else
    {
        for (infooacount& date : vClient)
        {

            printdate(date);


            cout << endl;




        }

        cout << endl << "---------------------------------------------------------------------------------";
        cout << "----------------------------------------" << endl;





    }
}
void   AddDataLineToFile(string  namefile, string   linecline)
{
    fstream   myfile;

    myfile.open(namefile, ios::in | ios::app);

    if (myfile.is_open())
    {


        myfile << linecline << endl;


        myfile.close();

    }



}

void  addclint()



{
    infooacount  clint;
    clint = readaddclint();



    AddDataLineToFile(namefile, convortstrct(clint));


}
void  addclints()
{
    char Addmore = 'y';
    do
    {
        addclint();




        cout << " Add Clint successsfuly  ,   Do you want to add more? y/n ";
        cin >> Addmore;





    } while (toupper(Addmore) == 'Y');














}
bool FindClintbyAccountnumber(string  user, infooacount& date, vector   < infooacount  >& vClient
)
{

    for (infooacount& line : vClient)
    {
        if (line.accountnumber == user)
        {
            date = line;
            return true;
        }






    }






    return false;





}
bool  MarkClintforDeleteByAccountnumber(string nameaccount, vector  < infooacount>& vClient)
{


    for (infooacount& date : vClient)
    {

        if (date.accountnumber == nameaccount)
        {


            date.markfordelte = true;



            return  true;


        }









    }

    return  false;








}
vector  < infooacount >  saveClientRecord(string namefile, vector < infooacount >  vdate)
{

    fstream  myfile;

    string   line;
    myfile.open(namefile, ios::out);

    if (myfile.is_open())
    {

        for (infooacount& date : vdate)
        {

            if (date.markfordelte == false)
            {

                line = convortstrct(date);

                myfile << line << endl;
            }

        }

        myfile.close();
    }

    return vdate;
}
bool  DeleteClint(vector < infooacount >& vClient, string accontnumber)
{
    infooacount date;
    char    deleteclint = 'n';
    if (FindClintbyAccountnumber(accontnumber, date, vClient))
    {


        printClientcard(date);

        cout << "Are you sure you want delete this clinet  ? y/n ? ";
        cin >> deleteclint;

        while (deleteclint == 'y' || deleteclint == 'Y')
        {


            MarkClintforDeleteByAccountnumber(accontnumber, vClient);



            saveClientRecord(namefile, vClient);



            cout << "Clint  delete  successsfuly " << endl;

            vClient = loaddatefromfile(namefile);
            return  true;

        }







    }
    else
    {



        cout << "Clint with Accountnumber (" << accontnumber << ") Not Found !" << endl;
        return false;


    }




    return  false;





}
bool updateClint(vector < infooacount  >& vClient, string  accountnumber)
{
    infooacount date;
    char updet = 'y';
    if (FindClintbyAccountnumber(accountnumber, date, vClient))
    {

        printClientcard(date);
        cout << "Are you sure you want update this clinet  ? y/n ? ";
        cin >> updet;
        if (updet == 'y' || updet == 'Y')
        {
            infooacount  updeteclint = ChangClientRecord(accountnumber);


            for (infooacount& date : vClient)
            {

                if (date.accountnumber == accountnumber)
                {


                    date = updeteclint;




                    cout << "Clint  update  successsfuly " << endl;

                    saveClientRecord(namefile, vClient);
                    return  true;

                }









            }







        }




    }


    else
    {



        cout << "Clint with Accountnumber (" << accountnumber << ") Not Found !" << endl;

        return false;




    }







    return  false;  
}
void   showAddNewClint()
{  
    if (!IsPermissions(enisPermissions::AddNewClient))
    {

        ShowAccessDeniedMessage();
            return;

    }

    cout << "----------------------------------------------------" << endl;
    cout << " \t Add  New  Clint " << endl;
    cout << "----------------------------------------------------" << endl;



    addclints();






}

void   showDeleteClint()
{ 
    if (!IsPermissions(enisPermissions::DeleteClient))
    {

        ShowAccessDeniedMessage();
        return;

    }

    cout << "\n----------------------------------------------------\n" << endl;
    cout << "\t Delete Clint  " << endl;
    cout << "\n----------------------------------------------------\n" << endl;

    vector < infooacount  >   vClient;
    vClient = loaddatefromfile(namefile);

    string accountnumber = readAccount();



    DeleteClint(vClient, accountnumber);





}

void  showupdateClint()
{ 
    if (!IsPermissions(enisPermissions::UpdateClient))
    {

        ShowAccessDeniedMessage();
        return;

    }

    cout << "\n----------------------------------------------------\n" << endl;

    cout << " \t Update Clint  " << endl;
    cout << "\n----------------------------------------------------\n" << endl;
    vector < infooacount  >   vClient;
    vClient = loaddatefromfile(namefile);
    string accountnumber = readAccount();


    updateClint(vClient, accountnumber);


}
void  showfindClint()
{
    if (!IsPermissions(enisPermissions::FindClient))
    {

        ShowAccessDeniedMessage();
        return;

    }

    cout << "\n----------------------------------------------------\n" << endl;
    cout << "\t  Find  Clint  " << endl;
    cout << "\n----------------------------------------------------\n" << endl;
    vector < infooacount  >   vClient;
    vClient = loaddatefromfile(namefile);
    string accountnumber = readAccount();
    infooacount Clint;

    if (FindClintbyAccountnumber(accountnumber, Clint, vClient))
    {

        printClientcard(Clint);


    }
    else
    {


        cout << "Clint with Accountnumber (" << accountnumber << ") Not Found !" << endl;




    }

}

void  gobacktomenue()
{


    cout << "press any key to go back to main menue " << endl;

    system("pause>0");
    system("cls  ");
    mainmenue();




}
void  gobacktomenueMangeUsers()
{


    cout << "press any key to go back to main menue " << endl;

    system("pause>0");
    system("cls  ");
    showMangeUsersMenueScreen();



}

void perfromainoption(enMainMenueOption  enoption)
{

    switch (enoption)
    {

    case enMainMenueOption::showclint:
        system("cls");
        showClintlist();
        gobacktomenue();
        break;
    case  enMainMenueOption::addnewclint:
        system("cls");
        showAddNewClint();
        gobacktomenue();
        break;
    case  enMainMenueOption::Deleteclint:
        system("cls");
        showDeleteClint();
        gobacktomenue();
        break;
    case  enMainMenueOption::Updateclint:
        system("cls");
        showupdateClint();
        gobacktomenue();
        break;
    case enMainMenueOption::findclint:
        system("cls");
        showfindClint();
        gobacktomenue();
        break;
    case enMainMenueOption::Transaction:
        system("cls");
        ShowTransaction();
        gobacktomenue();
        break;  
    case enMainMenueOption::MangeUsers:
        system("cls");
        showMangeUsersMenueScreen();
        gobacktomenue();
        break; 
    case enMainMenueOption::logout : 
        system("cls");
        login();
        break;
    }

}
void mainmenue()
{
    system("cls");

    cout << "----------------------------------------------------" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "\t Main Menue Screen " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "\t [1]  Show Clint List. " << endl;
    cout << "\t [2]  Add New Clint.  " << endl;
    cout << "\t [3]  Delete Clint. " << endl;
    cout << "\t [4]  Update Clint info." << endl;
    cout << "\t [5]  Find Clint. " << endl;
    cout << "\t [6]  Transaction." << endl; 
    cout << "\t [7]  Manage Users ." << endl;
    cout << "\t [8]  logout." << endl;

    cout << "----------------------------------------------------" << endl;
    cout << "----------------------------------------------------" << endl;



    perfromainoption(enMainMenueOption(ReadMainMenueOption()));

}
enum enTransactioOptions {
    Deposit = 1, Withdraw = 2, TotalBalances = 3, MainMenue = 4
};
short  ReadMainMenuetransction()
{

    short   num = 0;
    cout << "choose  what do you want to do  ? [1to 6 ] ? ";
    cin >> num;
    return  num;



}
void  gobacktomenuetransction()
{


    cout << "press any key to go back to main menue " << endl;

    system("pause>0");
    system("cls  ");
    ShowTransaction();



}

double  homanyamountWithdraw()
{


    double  amount;  
    cout << "Place enter Withdraw  amount ?  "; 
    cin >> amount;





    return amount;  



} 
double  homanyamountdeposit ()
{


    double  amount;
    cout << "Place enter  Deposit  amount ?  ";
    cin >> amount;





    return amount;



}

bool DepositBalancetoClientByAccountNumber(vector < infooacount >  vClient, string nameaccount, double  amount)
{

    char  areyou = 'y'; 
    cout << "are  you sure you want perfrom this transaction y/n ? ";
    cin >> areyou;  

    while (areyou == 'Y' || areyou == 'y')
    {

        for (infooacount& date : vClient)
        {
            if (date.accountnumber == nameaccount)
            {

                date.accountbalance += amount;  


                cout << "Done  successsfuly  new balance  "   <<  date.accountbalance << endl;  
                saveClientRecord(namefile, vClient);
         
                return true; 



            }

         }
    }
    return false;   
}
void  printtotalbalance(infooacount    date)
{
    cout << "|" << setw(12) << left << date.accountnumber;  
    cout << "|" << setw(40) << left << date.name;  
    cout << "|" << setw(25) << left << date.accountbalance; 
    cout << endl;     
}
void  totalBalances()
{
    vector < infooacount  >   vClient;
    vClient = loaddatefromfile(namefile);
    int  sum = 0;  
    cout << "\n\t\t\t   Balances list ( " << vClient.size() << ") Client (s) ." << endl;  
    cout << endl << "-------------------------------------------------------------------------";
    cout << "----------------" << endl;
    cout << "|" << left << setw(12) << "Accout  Number ";  
    cout << "|" << left << setw(40) << "Client Name ";  
    cout << "|" << left << setw(25) << "Balance"; 
    cout << endl << "-------------------------------------------------------------------------";
    cout << "----------------" << endl;
    if (vClient.size() == 0)
    {
        cout << "\t\t\t No Client Available in the system ! ";
    }

    else
    {


        for (infooacount& date : vClient)
        {
            printtotalbalance(date);   

            sum += date.accountbalance;  


        }
        cout << "-------------------------------------------------------------------------";
        cout << "----------------" << endl;
    }
    cout << "\n\t\t\t  Total Balance = " << sum;
}
void showtotalBalances()
{


    totalBalances();  
}
void   showdeposit()
{
    cout << "----------------------------------------------------" << endl;
    cout << "\t Deposit Screen  " << endl;  
    cout << "----------------------------------------------------" << endl;

    infooacount Clint;  
    vector < infooacount  >   vClient;
    vClient = loaddatefromfile(namefile);
    string accountnumber = readAccount();
    double  amount = 0;  

    while (!FindClintbyAccountnumber(accountnumber, Clint, vClient))
    {

        cout << "Client with [" << accountnumber << "] does not exist ." << endl;   
         accountnumber = readAccount();




    }

    printClientcard(Clint);
    amount = homanyamountdeposit();

    DepositBalancetoClientByAccountNumber(vClient, accountnumber, amount);


}
void   showWithdraw()
{
    cout << "----------------------------------------------------" << endl;
    cout << "\t     Withdraw   Screen  " << endl;
    cout << "----------------------------------------------------" << endl;
    infooacount Clint;
    vector < infooacount  >   vClient;
    vClient = loaddatefromfile(namefile);
    string accountnumber = readAccount();
    double  amount = 0;

    while (!FindClintbyAccountnumber(accountnumber, Clint, vClient))
    {

        cout << "Client with [" << accountnumber << "] does not exist ." << endl;
        accountnumber = readAccount();

    }
    printClientcard(Clint);

    amount = homanyamountWithdraw();
    while (amount > Clint.accountbalance)
    {
        cout << "Amount Exceeds the balance ,  you  can Withdraw   up to :" << Clint.accountbalance << endl;

        amount = homanyamountWithdraw();


    }
    DepositBalancetoClientByAccountNumber(vClient, accountnumber, amount * -1);
}
void perfromainoptiontransction(enTransactioOptions  stcase)
{

    switch (stcase)
    {
    case enTransactioOptions::Deposit:
        system("cls");
        showdeposit();
        gobacktomenuetransction();
        break;
    case enTransactioOptions::Withdraw:
        system("cls");
        showWithdraw();
        gobacktomenuetransction();
        break;
    case  enTransactioOptions::TotalBalances:
        system("cls");
        showtotalBalances();
        gobacktomenuetransction();
        break;
    case  enTransactioOptions::MainMenue:
        system("cls");
        mainmenue();
        gobacktomenue();
        break;


    }

}

void  ShowTransaction()
{

    cout << "\n----------------------------------------------------\n" << endl;
    cout << "\t  Transaction Menue  Screen  " << endl;
    cout << "\n----------------------------------------------------\n" << endl;
    cout << "\t [1] Deposit . " << endl;
    cout << "\t [2] Withdraw." << endl;
    cout << "\t [3] Total Balances ." << endl;
    cout << "\t [4] Main Menue . " << endl;
    perfromainoptiontransction(enTransactioOptions(ReadMainMenuetransction()));
}     
bool  IsPermissions(enisPermissions  Permission)
{

    if (dateUsers.Permissions == enisPermissions::all)
        return true;

    if ((Permission & dateUsers.Permissions) == Permission)
        return true;
    else
        return false;
}

bool  FindUserByUsername(vector < currinusers  >  vdate, string nameusers, currinusers& dateusers)
{


    for (currinusers& date : vdate)
    {
        if (date.nameusers == nameusers)
        {

            dateusers = date;
            return   true;


        }



    }



    return  false;
}
void  printusers(currinusers  users)
{

    cout << "The following are the clint drtails :" << endl;
    cout << "\n----------------------------------------------------\n" << endl;
    cout << "Usersname         : " << users.nameusers << endl;
    cout << "Password          : " << users.passwoord << endl;
    cout << "Permissions       : " << users.Permissions << endl;
    cout << "\n----------------------------------------------------\n" << endl;





}
bool  MarkClintforDeleteByUsersname(string nameaccount, vector  < currinusers>& vClient)
{
    for (currinusers& date : vClient)
    {
        if (date.nameusers == nameaccount)
        {
            date.markfordelte = true;
            return  true;
        }
    }

    return  false;
}
vector  < currinusers >  saveusersRecord(string namefile, vector < currinusers >  vdate)
{

    fstream  myfile;

    string   line;
    myfile.open(namefile, ios::out);
    if (myfile.is_open())
    {
        for (currinusers& date : vdate)
        {
            if (date.markfordelte == false)
            {
                line = ConvertUserRecordToLine(date);
                myfile << line << endl;
            }
        }
        myfile.close();
    }

    return vdate;
}

bool  DeleteUserByUsername(vector < currinusers  >& vusers
    , string nameusers)
{
    if (nameusers == "Admin")
    {


        cout << "You cannot delete the Admin from the system. Press any key to continue..." << endl;


    }
    currinusers  users;

    char    deleteusers = 'n';
    if (FindUserByUsername(vusers, nameusers, users))
    {
        printusers(users);
        cout << "Are you sure you want delete this clinet  ? y/n ? ";
        cin >> deleteusers;
        while (deleteusers == 'Y' || deleteusers == 'y')
        {
            MarkClintforDeleteByUsersname(nameusers, vusers);
            saveusersRecord(filenameusersss, vusers);
            cout << "Users Deleted Successfully ." << endl;
            vusers = loaddateUsersfromfile(filenameusersss);
            return  true;
        }

    }
    else
    {

        cout << "users with usersname (" << nameusers << ") Not Found !" << endl;
        return  false;
    }  
    return  false;  
}
currinusers  ChangeUserRecord(string   nameusers )
{
    currinusers   info;
    info.nameusers = nameusers;  
    cout << endl << "Enter Password ?";
    cin >> info.passwoord;
    info.Permissions = ReadPermissions(); 

    return   info;
}
void  printuserslist(currinusers    date)
{
    cout << "|" << setw(12) << left << date.nameusers;
    cout << "|" << setw(40) << left << date.passwoord;
    cout << "|" << setw(25) << left << date.Permissions;
    cout << endl;
}
int ReadPermissions()
{
    int Permissions = 0; 
    char fullaccess = 'n';

    cout << endl << "Do you want to give full access  y/n ? " << endl;
    cin >> fullaccess;
    if (fullaccess == 'y' || fullaccess == 'Y')
    {
        Permissions = -1;
    }
    if (fullaccess == 'n' || fullaccess == 'N')
    {
        char shoe = 'y';
        cout << "show Clint List y/n" << endl;
        cin >> shoe;

        if (shoe == 'y' || shoe == 'Y')
        {
            Permissions += enisPermissions::showClintlists;
        }
        cout << "Add New Client  " << endl;
        cin >> shoe;
        if (shoe == 'y' || shoe == 'Y')
        {
            Permissions += enisPermissions::AddNewClient;
        }
        cout << "Delete Client" << endl;
        cin >> shoe;
        if (shoe == 'y' || shoe == 'Y')
        {
            Permissions += enisPermissions::DeleteClient;
        }
        cout << "Update Client info " << endl;
        cin >> shoe;
        if (shoe == 'y' || shoe == 'Y')
        {
            Permissions += enisPermissions::UpdateClient;
        }
        cout << "Find Client " << endl;
        cin >> shoe;
        if (shoe == 'y' || shoe == 'Y')
        {

            Permissions += enisPermissions::FindClient;
        }
        cout << "Transactions" << endl;
        cin >> shoe;
        if (shoe == 'y' || shoe == 'Y')
        {

            Permissions += enisPermissions::Transactions;
        }
        cout << "Mange Users " << endl;
        cin >> shoe;
        if (shoe == 'y' || shoe == 'Y')
        {
            Permissions += enisPermissions::MangeUserss;
        }
    }
    return Permissions;  
}

currinusers  ReadUsers()
{
    currinusers   info;
    cout << endl << " Enter Username   " << endl;
    getline(cin >> ws, info.nameusers);

    while (UserExistsByUsername(info.nameusers))
    {
        cout << "Clint  With [" << info.nameusers << "] already  exists   , enter anther Users  Nmae";
        cin >> info.nameusers;
    }
    cout << endl << "Enter Password ?";
    cin >> info.passwoord;
    info.Permissions = ReadPermissions(); 
       return   info;
}
string readusersname()
{
    string nameusers;
    cout << "place Enter  users   name  ";
    cin >> nameusers;
    cout << endl;
    return nameusers;
}

bool  FindUserByUsernameAndPassword(string nameusers, short password   , currinusers& dateusers )
{
    vector < currinusers  >  vdate;
    vdate = loaddateUsersfromfile(filenameusersss);
    for (currinusers& date : vdate)
    {
        if (date.nameusers == nameusers && date.passwoord == password)
        {
            dateusers = date; 
            return   true;



        }



    }

    return  false;
}
bool  LoadUserInfo( string nameusers, short password  , currinusers& dateusers )
{
    if (FindUserByUsernameAndPassword( nameusers, password   , dateusers ))
    {

          
        return   true;  


    }

    else
    {

        return   false; 
    }




}
string  readnameysers()
{


    string nameusers;
    cout << "Enter User name " << endl;
    getline(cin >> ws, nameusers);



    return nameusers;
}
short readpassword()
{

    short passwpord;
    cout << "Enter password  " << endl;
    cin >> passwpord;


    return  passwpord;
    


}         
void AddNewUser()
{
    currinusers date;   
    date  = ReadUsers();
    
    AddDataLineToFile(filenameusersss, ConvertUserRecordToLine(date));





}
void AddNewUsers()
{


    char  addmore = 'n'; 
    do
    {
        cout << "Adding New User:\n\n";
        AddNewUser(); 
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> addmore;



    } while (toupper(addmore == 'Y'));





}
void showFindUsers()
{
    cout << "\n----------------------------------------------------\n" << endl;
    cout << "Find Users " << endl;
    cout << "\n----------------------------------------------------\n" << endl;
    string  usersname = readusersname();
    vector < currinusers  >   vusers;
    vusers = loaddateUsersfromfile(filenameusersss);
    currinusers   users;

    if (FindUserByUsername(vusers, usersname, users))
    {


        printusers(users);




    }
    else
    {



        cout << "users with usersname (" << usersname << ") Not Found !" << endl;


    }





}

bool  UpdateUserByUsername(vector < currinusers  >& vusers, string   usersname)
{  
    currinusers dateusers;  
    char deleteusers = 'n';
    if (FindUserByUsername(vusers, usersname, dateusers))
    {
        printusers(dateusers);
        cout << "Are you sure you want update users  ? y/n ? ";
        cin >> deleteusers;
        while (deleteusers == 'Y' || deleteusers == 'y')
        {
            for (currinusers& date : vusers)
            {

                if (date.nameusers == usersname)
                {
                    date = ChangeUserRecord(usersname);  
                    break;
                }
            }
            saveusersRecord(filenameusersss, vusers);

            cout << "Users update Successfully ." << endl;
            return  true;
        }
    }
    else
    {

        cout << "users with usersname (" << usersname << ") Not Found !" << endl;
        return   false;
    } 
    return  false;  
}

void  showupdateUsers()
{
    cout << "\n----------------------------------------------------\n" << endl;
    cout << "Update  Users  " << endl;
    cout << "\n----------------------------------------------------\n" << endl;

    string  usersname = readusersname();
    vector < currinusers  >   vClient;
    vClient = loaddateUsersfromfile(filenameusersss);

    UpdateUserByUsername(vClient, usersname);
}

void  showDeleteusers()
{
    cout << "\n----------------------------------------------------\n" << endl;
    cout << "Delete Users  Screen " << endl;
    cout << "\n----------------------------------------------------\n" << endl;
    string  usersname = readusersname();

    vector < currinusers  >   vClient;
    vClient = loaddateUsersfromfile(filenameusersss); 
        DeleteUserByUsername(vClient, usersname);

   
}

void  ShowAddNewUserScreen()
{
    cout << "\n----------------------------------------------------\n" << endl;
    cout << "Add Users " << endl;
    cout << "\n----------------------------------------------------\n" << endl;
    char addmore = 'n'; 

    AddNewUsers();
}

void login()
{
    cout << "\n----------------------------------------------------\n" << endl;
    cout << "\t Login Screen " << endl;
    cout << "\n----------------------------------------------------\n" << endl;

    string nameusers; 
    short password; 
    bool  Login = false;
    do
    {
        if (Login)
        {
            system("cls");

            cout << "Invalid Username / Password ! " << endl;
        }  

        nameusers = readnameysers();
        password = readpassword();
        Login = !LoadUserInfo( nameusers, password, dateUsers);  

    } while (Login); 
    system("cls");

    mainmenue();


} 
void  Userslist()
{

    vector < currinusers  >   vClient;
    vClient = loaddateUsersfromfile(filenameusersss);
    int  sum = 0;
    cout << "\n\t\t\t   Users  list ( " << vClient.size() << ") Users (s) ." << endl;
    cout << endl << "-------------------------------------------------------------------------";
    cout << "----------------" << endl;
    cout << "|" << left << setw(12) << "User   Name ";
    cout << "|" << left << setw(40) << "Password  ";
    cout << "|" << left << setw(25) << "Permissions";
    cout << endl << "-------------------------------------------------------------------------";
    cout << "----------------" << endl;
    if (vClient.size() == 0)
    {
        cout << "\t\t\t No Client Available in the system ! ";
    }
    else
    {


        for (currinusers& date : vClient)
        {
            printuserslist(date);

        }
        cout << "-------------------------------------------------------------------------";
        cout << "----------------" << endl;
    }
}

void   perfomanceUser(enmangeusers  useroption)
{

    switch (useroption)
    {

    case enmangeusers::listusers:
        system("cls");
        Userslist();
        gobacktomenueMangeUsers();
        break;
    case enmangeusers::addNewUsers:
        system("cls");
        ShowAddNewUserScreen();
        gobacktomenueMangeUsers();
        break;
    case  enmangeusers::DeleteUsers:
        system("cls");
        showDeleteusers();
        gobacktomenueMangeUsers();
        break;
    case enmangeusers::updateUsers:
        system("cls");
        showupdateUsers();
        gobacktomenueMangeUsers();
        break;
    case  enmangeusers::FindUsers:
        system("cls");
        showFindUsers();
        gobacktomenueMangeUsers();
        break;
    case enmangeusers::manimenue:
        system("cls");
        mainmenue();
        gobacktomenueMangeUsers();

        break;
    }
}
void showMangeUsersMenueScreen()
{

    cout << "----------------------------------------------------" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "\t Mange Users Menue Screen " << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "\t [1]  List Users . " << endl;
    cout << "\t [2]  Add New Users.  " << endl;
    cout << "\t [3]  Delete Users. " << endl;
    cout << "\t [4]  Update Users ." << endl;
    cout << "\t [5]  Find Users. " << endl;
    cout << "\t [6]  Main Menue." << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "----------------------------------------------------" << endl;
    perfomanceUser(enmangeusers(ReadMainMenueOption()));
}

int main()
{
    login();     
    system("pause>0");
    return 0; 
}

