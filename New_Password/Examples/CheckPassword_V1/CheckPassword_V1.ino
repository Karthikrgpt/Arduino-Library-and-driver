#include <NewPassword.h>

NewPassword Mypass;
int Case;
char data;

char pass[4][5] = {
  "1234","5678","abcd","1235"};
char User[4][10] = { 
  "Andy", "Joe", "me","test"};
  
void setup()
{
  Serial.begin(9600);
  Mypass.Init(4,5,4); // "Number of passwords, lenght of password, Number of users"
  
  Mypass.SetPassword(*pass);
  Mypass.SetUser(*User);

  delay(1000);
  Mypass.Check("1234"); // good
  Serial.print(Mypass.CheckUser());
  Serial.println();
  
  delay(1000);
  Mypass.Check("0000"); // fail
  Serial.print(Mypass.CheckUser());
  Serial.println();
  
  delay(1000);
  Mypass.Check("abcd"); // good
  Serial.print(Mypass.CheckUser());
  Serial.println();
  
  delay(1000);
  Mypass.Check("1235"); // good
  Serial.print(Mypass.CheckUser());
  Serial.println();
  
  Mypass.AddPassword("8520","New Guy");
  Mypass.AddPassword("ABCD","Andrew");
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
