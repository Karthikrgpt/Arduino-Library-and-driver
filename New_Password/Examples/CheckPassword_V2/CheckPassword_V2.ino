#include <NewPassword.h>

NewPassword Mypass;

int Case;
char data;

void setup(){
  Serial.begin(9600);
  Mypass.Init(0,5,0);// "Number of passwords, lenght of password, Number of users"
  
  Mypass.AddPassword("1234","Andy");
  Mypass.AddPassword("abcd","Joe");
  Mypass.AddPassword("ASDF","John");
  Mypass.AddPassword("8520","Sam");
}

void loop() {
  if(Serial.available() > 0 ){
    data = Serial.read();

    Case = Mypass.Check( Mypass.EnterData(data));

    switch(Case){
    case 1:
      Serial.print("Password was found: ");
      Serial.print(Mypass.CheckUser());
      Serial.println(); 
      break;

    case 0:
      Serial.print("Password was not found \n");
      break;
    }
  }
}

