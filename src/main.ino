//#include <LiquidCrystal_I2C.h>
#include <rgb_lcd.h>
//LiquidCrystal_I2C lcd(0x27, 16, 2);

rgb_lcd lcd;

int bp1 = 12;
int bp2 = 13;

boolean bt1 = 0;
boolean bt2 = 0;
//int bp = 13;
//int ledpin = 2;
//
//boolean bt = 0;
//boolean bt_old = 0;
//
#define Push_short 100
#define PushLong 100000

void setup()
{
	lcd.begin(16, 2);
	lcd.print("Hello World");


	//lcd.init();
	//lcd.backlight();
	//lcd.setCursor(0, 0);
	//lcd.print("Hello World");

	//pinMode(bp, INPUT);
	//pinMode(ledpin, OUTPUT);
	//Serial.begin(9600);
}
int i = 0;
void loop()
{

	unsigned long gauge1 = 0;
	unsigned long gauge2 = 0;

	while (digitalRead(bp1))
	{
		gauge1++;
	}
	
	while (digitalRead(bp2))
	{
		gauge2++;

	}

	if (gauge1 > Push_short)
	{
		i++;
		bt1 = !bt1;
	//	Serial.print(bt1);
	//	Serial.print(":");
	//	Serial.println(gauge1);
		lcd.clear();
		lcd.print("button"+ String(i));

	}
	if (gauge2 > Push_short)
	{
		i--;
		bt2 = !bt2;
		lcd.clear();
		lcd.print("button"+String(i));
	
	}
	else if (gauge1 > Push_short && gauge2 > Push_short)
	{
		bt1 = !bt1;
		lcd.clear();
		lcd.print("1 and 2 !!");
	}


	//boolean bt_now = digitalRead(bp);

	//if ( bt_now == 1 && bt_old == 0)
	//{
	//bt = !bt;
	//Serial.println(bt);
	//}
	//bt_old = bt_now;

	//digitalWrite(ledpin, bt);
	//delay(100);
}

