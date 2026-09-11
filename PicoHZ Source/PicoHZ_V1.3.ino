//   ____  _____   ______   _    _     _______   _                 ____  ____  ________  
//  |_   \|_   _|.' ____ \ | |  | |   |_   __ \ (_)               |_   ||   _||  __   _| 
//    |   \ | |  | |____\_|| |__| |_    | |__) |__   .---.   .--.   | |__| |  |_/  / /   
//    | |\ \| |  | '____`'.|____   _|   |  ___/[  | / /'`\]/ .'`\ \ |  __  |     .'.' _  
//   _| |_\   |_ | (____) |    _| |_   _| |_    | | | \__. | \__. |_| |  | |_  _/ /__/ | 
//  |_____|\____|'.______.'   |_____| |_____|  [___]'.___.' '.__.'|____||____||________| 


#define RST_IN 26
#define CPU_112 2
#define CPU_116 3
#define LED_15 4 //CLK 1.5X
#define LED_20 5 //CLK 2.0x
int clockstate = 0; //variable for clock state

void setup()
  {
  pinMode(RST_IN, INPUT);
  pinMode(CPU_112, OUTPUT);
  pinMode(CPU_116, OUTPUT);
  pinMode(LED_15, OUTPUT);
  pinMode(LED_20, OUTPUT);

  //set stock clock for boot.
  digitalWrite(CPU_112, HIGH);
  digitalWrite(CPU_116, LOW);
  digitalWrite(LED_15, HIGH);
  }

void loop()
{
    int RST_SW = analogRead(RST_IN);

    if (RST_SW <= 50)
    {
        delay(800);

        RST_SW = analogRead(RST_IN);

        if (RST_SW <= 50)
        {
            if (clockstate == 0)
            {
                clockstate = 1;

                digitalWrite(CPU_112, LOW);
                digitalWrite(CPU_116, HIGH);
                digitalWrite(LED_15, LOW);
                digitalWrite(LED_20, HIGH);
            }
            else
            {
                clockstate = 0;

                digitalWrite(CPU_112, HIGH);
                digitalWrite(CPU_116, LOW);
                digitalWrite(LED_15, HIGH);
                digitalWrite(LED_20, LOW);
            }

            delay(100);
        }
    }
}