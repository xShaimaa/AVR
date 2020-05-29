/*
 * LCD + keypad.c
 *
 * Created: 03-Apr-20 2:09:50 AM
 * Author : shimo
 */ 

#include <avr/io.h>
#include "lcd_drive.h"
#include "keypad.h"

// functions prototype
// #define LCD_begin
// #define pass_enter
// #define pass_check
// #define pass_wrong

// variables
int counter = 0;				//counter to check the password
char password[5] ="1234";		//the system password
char lock = 0 ;					//the state of the system lock
char key [5];					//the entered pass

//start of the system
void LCD_begin (){
	Lcd_Out(1, 1, "welcome to the");
	Lcd_Out(2, 1, "system...");
	_delay_ms(200);
	send_command (_LCD_CLEAR);
	_delay_ms(10);
	Lcd_Out(1,1,"press any key");
}

//to enter the password and store it in a array
void pass_enter (){
	int i = 0;
	Lcd_Out(1, 1, "enter pass");
	for (i=0; i<=4; i++){
		key [i] = keypad_getkey();
		Lcd_Out(2, i+1, "*");				//replace the pass with ***
		_delay_ms (500);
		if (key [i] == 'C'){				//backspace when on/c is pressed
			Lcd_Out (2, i, "  ");
			i -= 2;
		}
	}
}

//check the entered pass
void pass_check(){
	int i = 0;
	for (i=0; i<=4; i++){					
		if (key [i] == password [i]) counter ++;		//for every correct num. counter ++ 
		if (counter == 4) lock = 1;						//when counter reaches 4 that mean the pass is correct
	}
}

//there are 3 chances to enter a wrong pass
void pass_wrong () {
	int i =0;
	for (i=0; i<3; i++){
		send_command(_LCD_CLEAR);
		_delay_ms(10);
		Lcd_Out (1, 1, "try again!");
		send_command(_LCD_CLEAR);
		_delay_ms(10);
		pass_enter ();
		pass_check ();
	}
		while (1) {}			//don't allow any trials after th third wrong time
	}

int main(void)
{
	Lcd_Init();
	keypad_init();
	LCD_begin();
		while (1)
		{
			if (keypad_getkey()){
			send_command(_LCD_CLEAR);
			_delay_ms(10);
			pass_enter ();
			pass_check ();
			if (lock == 1) {			//check th lock value, 1 mean correct pass and 0 means wrong
				 send_command(_LCD_CLEAR);
				 _delay_ms(10);
				 Lcd_Out(1, 1, "welcome");
			}
			if (lock == 0){
				pass_wrong();
			}
		}
	}
}

