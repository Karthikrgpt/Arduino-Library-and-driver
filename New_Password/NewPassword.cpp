//Passwords

//SetPassword() <<< set password array in form of "1234...", "5678..."
//SetUser() <<< set user array "Andy", "Joe", "Mike"...

//Check() <<< input password to be checked >>> return true or false
//CheckUser() <<< input password to be checked >>> return the user assigned to password

#include "NewPassword.h"

//=====================DO NOT CHANGE THESE VALUES=========================
bool checkFlag = false;
unsigned int i = 0, count = 0, cnt = 0, d = 0, NOP_Inc = 0, User_Inc = 0;
int user = -1, Checked = -1, isGood = -1;
char nt[Max_Lenght_of_Passwords] = { NULL };
//========================================================================


void NewPassword::Init(unsigned int NOP, unsigned int LOP, unsigned int NOU) 
{
 Number_of_Passwords = NOP; // default 0
 Lenght_of_Passwords = LOP; // default 5 VALUE STILL NEEDED TO WORK CORRECTLY
 Num_of_Users = NOU;        // default 0
 nt[Lenght_of_Passwords];
//LCD 
//Keypad
}

// SetPassword and SetUser are technically not needed functions, because AddPassword takes care of both passwords and users
void NewPassword::SetPassword(char * password)
{
  for(int i = 0; i < (Number_of_Passwords + NOP_Inc) * Lenght_of_Passwords; i+= Lenght_of_Passwords)
  {
    for(int j = 0; j < Lenght_of_Passwords; j++)
    {
      passTemp[(i % ((Number_of_Passwords + NOP_Inc) * Lenght_of_Passwords)) / Lenght_of_Passwords][j] = (password+i)[j];
    }
  }
}

void NewPassword::SetUser(char *User)
{
  for(int i = 0;i < (( Num_of_Users + User_Inc) * Max_Lenght_of_username); i+= Max_Lenght_of_username)
  {
    for(int j = 0; j < ( Num_of_Users + User_Inc); j++)
    {
      userTemp[(i % (( Num_of_Users + User_Inc) * Max_Lenght_of_username))/Max_Users][j] = (User+i)[j];
    }
  } 
}


int NewPassword::Check(char *input) {
   i = 0;
   user = -1;
   Checked = -1;
 
   while(1){
    if(!strcmp(input, passTemp[i]))
    {
	  user++;
	  Checked = 1;
      break;
    }
    else {
      i++;
      user++;
    }
	if(user > (( Num_of_Users ?  Num_of_Users - 1 : 0) + User_Inc))
      {
	   user = -1;
	   Checked = 0;
       break;
      }
   }
    if(checkFlag == true)
    {
     checkFlag = false;
     return Checked;
    }
	else return -1;
}

char * NewPassword::CheckUser() {
  return (user != -1)? userTemp[user] : NULL ; 
  user = -1;
}

char * NewPassword::EnterData(char data)
{
  if(data != NULL)
  { 
    if(data > 0)
    {	
      nt[cnt] = data;
      cnt++;
    }
    if(cnt == Lenght_of_Passwords - 1)
    {
      cnt = 0;
	  checkFlag = true;
	  return nt;
    }
  }
}

void NewPassword::AddPassword(char * NewPass, char * NewUser)
{ 
  NOP_Inc++;
  User_Inc++;
  if(( Num_of_Users + User_Inc) < Max_Users)
  {
    for(int j = 0; j < Lenght_of_Passwords; j++)
    {
      passTemp[((Number_of_Passwords != 0) ? Number_of_Passwords : 0) + NOP_Inc][j] = NewPass[j];
    }
	for(int i = 0; i < 10; i++){
      userTemp[((Num_of_Users != 0) ? Num_of_Users : 0)+ User_Inc][i] = NewUser[i];
    }
  }
  else {
    //Serial.println("Exceeded Maximum number of users");	
    User_Inc -= 1;
  }
}

//=============LCD+Keypad==========================
// In working process
