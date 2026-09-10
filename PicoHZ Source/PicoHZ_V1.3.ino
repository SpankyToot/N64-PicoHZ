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
  //If RST low = check clockstate, if 0 change clock/led to 2x and set clockstate 1, else if 1 change clock/led to 1.5x and set clockstate 0
  // 112 LOW + 116 LOW = 1.0; 112 HIGH + 116 LOW = 1.5 (stock); 112 LOW + 116 HIGH = 2.0; 112 HIGH + 116 HIGH = 3.0
  int RST_SW = analogRead(RST_IN);
  if (RST_SW <= 50)
      {
        //wait to check if RST held or pressed
      delay(800);
      int RST_SW = analogRead(RST_IN);
      if (RST_SW <= 50)  
      //RST held, change clock
        {if (clockstate == 0)
          {
          clockstate = (clockstate +1);
          delay(100);
          //set multiplier 2.0x
          digitalWrite (CPU_112, LOW);
          digitalWrite (CPU_116, HIGH);
          digitalWrite (LED_15, LOW);
          digitalWrite (LED_20, HIGH);
          }
    
          else if (clockstate == 1)
          {
          clockstate = (clockstate -1);
          delay(100);
          //set multiplier 1.5x
          digitalWrite (CPU_116, LOW);
          digitalWrite (CPU_112, HIGH);
          digitalWrite (LED_15, HIGH);
          digitalWrite (LED_20, LOW);
          }
      else
        {
        }
      }
    }
  else
    {
    }
  }
