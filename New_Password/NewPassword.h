//password.h

#ifndef NewPassword_h
#define NewPassword_h

#include <Arduino.h>

#define Max_Users 10
#define Max_Lenght_of_username 10
#define Max_Num_of_Passwords  10
#define Max_Lenght_of_Passwords 7

class NewPassword {

	public:

	    void Init( unsigned int NOP = 0, unsigned int LOP = 5, unsigned int NOU = 0);
		void SetPassword(char *password);
		void SetUser(char *User);
		int Check(char *input);
		char * CheckUser();
		//void Keypad_Data(char data);
		char * EnterData(char temp);
		void AddPassword(char * NewPass, char * NewUser);
	
	private:
			
		unsigned int Number_of_Passwords;
        unsigned int Lenght_of_Passwords;
        unsigned int Num_of_Users;
        char passTemp [Max_Num_of_Passwords][Max_Lenght_of_Passwords];
        char userTemp [Max_Users][Max_Lenght_of_username];
};


#endif