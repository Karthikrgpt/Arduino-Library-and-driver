#include <NewPassword.h>

NewPassword Mypass;

int Case;
char data;
char * password;
void setup(){
  Serial.begin(9600);
  Mypass.Init(0,5,0);
  Mypass.AddPassword("1234","Andy");
  Mypass.AddPassword("abcd","Joe");
  Mypass.AddPassword("ASDF","John");
  Mypass.AddPassword("8520","Sam");
}

void loop() {
  if(Serial.available() > 0 ){
    data = Serial.read();
    password = Mypass.EnterData( data );

    Case = Mypass.Check( password );

    switch(Case){
    case 1:
      Serial.print("Password was found: ");
      Serial.print(Mypass.CheckUser());
      Serial.println(); 
      break;

    case 0:
      Serial.print("Password was not found \n");
      EnterNewPassword();
      break;
    }
  }
}

void EnterNewPassword()
{
  Serial.print("Do you want to store this new password? ");
  while(1)
  {
    char Name[5]= {
      NULL    };
    if(Serial.available() > 0 ){
      char choice = Serial.read();
      if(choice == 'y' || choice == 'Y')
      {
        Serial.println(choice);
        Serial.println("Enter the person's name.");
        int cnt = 0;
        while(1)
        {
          if(Serial.available() > 0 )
          {
            char name = Serial.read(); 
            if(name == '.') break;
            else {
              Name[cnt] = name;
              cnt++;
            }
          }
        }
        Newpassword(password, Name);
        break;
      }
      else{
       Serial.println(choice); 
        break;
      }
    }
  }
}

void Newpassword(char * New_Password, char *New_User)
{
  Mypass.AddPassword(New_Password, New_User);
  Serial.println("New Password was added");
}


