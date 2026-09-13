
#include <iostream>
#include <vector> 
#include  <string> 
#include <iomanip> 
#include  <fstream>  
using namespace std;     
string  namefile = "myfile.txt"; 
void minu();

enum   enMainMenueOption {
    showclint = 1, addnewclint = 2, Deleteclint = 3, Updateclint = 4, findclint = 5, Exit = 6







};
struct   infooacount
{

    string  accountnumber;
    string  pincode;
    string name;
    string  iphone;
    int  accountbalance;
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
    short pos = 0;
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
    stinffoo.accountbalance = stoi(vstring[4]); // cast string to 






    return   stinffoo;





}

bool sarchaccount( string accountnumber)
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

infooacount  readaddclint( )
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
    system("cls");

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
void   savetofile(string  namefile, string   linecline)
{
    fstream   myfile;
    infooacount  date;

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



    savetofile(namefile, convortstrct(clint)); 


}
void  addclints( )
{
    char Addmore = 'y'; 
    do
    {
        addclint();  




        cout << " Add Clint successsfuly  ,   Do you want to add more? y/n ";
        cin >> Addmore;  





    } while (toupper(Addmore) == 'Y'); 














}
bool FindClintbyAccountnumber(string  user, infooacount& date  , vector   < infooacount  >  &  vClient 
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
bool  MarkClintforDeleteByAccountnumber(string nameaccount, vector  < infooacount> &vClient)
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
    myfile.open(namefile, ios::out ); 

    if (myfile.is_open())
    {

        for (infooacount& date : vdate)
        {

            if (date.markfordelte == false)
            {

                 line   =  convortstrct(date); 

                 myfile << line << endl;    
            }

        }

        myfile.close(); 


  }

    return vdate; 


}
bool  DeleteClint(vector < infooacount >& vClient,   string accontnumber )
{
    infooacount date;   
    char    deleteclint = 'n';  
 if  ( FindClintbyAccountnumber(accontnumber, date, vClient))
    {


     printClientcard(date);  

     cout << "Are you sure you want delete this clinet  ? y/n ? ";
     cin >> deleteclint;  

     while (deleteclint == 'y', deleteclint = 'Y')
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
            infooacount  updeteclint  = ChangClientRecord(accountnumber);


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








} 
void   showAddNewClint()
{
    cout << "----------------------------------------------------" << endl;
    cout << " \t Add  New  Clint " << endl;
    cout << "----------------------------------------------------" << endl;



    addclints(); 






} 

void   showDeleteClint()
{
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
void  showEndscreen()
{
    system("cls");
    cout << "\n----------------------------------------------------\n" << endl;
    cout << "\t Program Ends  :-) " << endl;
    cout << "\n----------------------------------------------------\n" << endl;




}

void  gobacktomenue()
{


    cout << "press any key to go back to main menue " << endl;

    system("pause>0");
    system("cls  ");
    minu();




}
void perfromainoption(enMainMenueOption  enoption)
{

    switch (enoption)
    {

    case enMainMenueOption::showclint :  
        system("cls"); 
        showClintlist(); 
        gobacktomenue(); 
        break;  
    case  enMainMenueOption ::addnewclint : 
        system("cls");
        showAddNewClint();  
        gobacktomenue();
        break; 
    case  enMainMenueOption ::Deleteclint : 
        system("cls");
        showDeleteClint();  
        gobacktomenue();
        break; 
    case  enMainMenueOption ::Updateclint :  
        system("cls");
        showupdateClint(); 
        gobacktomenue();
        break;
    case enMainMenueOption ::findclint : 
        system("cls");
        showfindClint();  
        gobacktomenue();
        break;
    case enMainMenueOption  ::Exit:
        system("cls");
        showEndscreen(); 
        break;
    }

}
void minu()
{

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
    cout << "\t [6]  Exit." << endl; 
    cout << "----------------------------------------------------" << endl;
    cout << "----------------------------------------------------" << endl;



    perfromainoption(enMainMenueOption(ReadMainMenueOption())); 

}
int main()
{


     
    minu();
}

