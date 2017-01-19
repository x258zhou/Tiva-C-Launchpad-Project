void oledInit()
{
  OrbitOledInit();
  OrbitOledClear();
  OrbitOledClearBuffer();
}
//Oled screen initial.

void welcomeScreen1()
{
  OrbitOledSetCursor(3,0);
  OrbitOledPutString("Super Mario");
  delay(WAIT);
  OrbitOledSetCursor(4,1);
  OrbitOledPutString("D A S H !");
  delay(WAIT);
  OrbitOledSetCursor(4,2);
  OrbitOledPutString("D A S H !");
  delay(WAIT);
  OrbitOledSetCursor(4,3);
  OrbitOledPutString("D A S H !");
  delay(WAIT);
  
  for(int i=1; i<=3; i++)
  {
    OrbitOledSetCursor(3,0);
    OrbitOledPutString("Super Mario");
    OrbitOledSetCursor(4,1);
    OrbitOledPutString("               ");
    OrbitOledSetCursor(4,2);
    OrbitOledPutString("               ");  
    OrbitOledSetCursor(4,3);
    OrbitOledPutString("               ");
    delay(WAIT);
    OrbitOledSetCursor(4,1);
    
    //Dash for three times
    OrbitOledPutString("D A S H !");
    OrbitOledSetCursor(4,2);
    OrbitOledPutString("D A S H !");  
    OrbitOledSetCursor(4,3);
    OrbitOledPutString("D A S H !");
    delay(WAIT);
  }
}

void welcomeScreen2()
{
  oledInit();
  delay(WAIT);
  OrbitOledSetCursor(3,0);
  OrbitOledPutString("Super Mario");
  OrbitOledSetCursor(1,1);
  OrbitOledPutString("DASH DASH DASH!");
  delay(WAIT);
  OrbitOledSetCursor(0,3);
  OrbitOledPutString("Press Any button");
  
}

void welcomeScreen()
{
  welcomeScreen1();
  delay(2*WAIT);
  welcomeScreen2();
  
}
//The Welcome Screen.

void waitForButton()
{
  while(1)
  {
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    if(buttonState1==HIGH || buttonState2==HIGH)
    {
      break;
    }
    
  }
  oledInit();
  delay(50);
  
}
//Wait until one of the two buttons on the boosterpack is pressed.

void loading()
{
  OrbitOledSetCursor(0,2);
  OrbitOledPutString("Press Any Button");
  OrbitOledSetCursor(4,3);
  OrbitOledPutString("to Jump");
  
  for(int i=0; i<8; i++)
  {
  OrbitOledSetCursor(2,1);
  OrbitOledPutString("Loading....-");
  delay(100);
  OrbitOledSetCursor(2,1);
  OrbitOledPutString("Loading....\\");
  delay(100);
  OrbitOledSetCursor(2,1);
  OrbitOledPutString("Loading....|");
  delay(100);
  OrbitOledSetCursor(2,1);
  OrbitOledPutString("Loading..../");
  delay(100);
  }
  
  OrbitOledSetCursor(2,1);
  OrbitOledPutString("Loading.... ");
  delay(100);
  OrbitOledSetCursor(0,2);
  OrbitOledPutString("    Success     ");
  delay(100);
  OrbitOledSetCursor(0,3);
  OrbitOledPutString("Press Any Button");
}
//Pretend that we have a loading process :)


void gameOver(int score)
{
  oledInit();
  delay(WAIT/2);
  OrbitOledSetCursor(4,0);
  OrbitOledPutString("Game Over");
  String temp1 = String(score,DEC);
  char temp2[10];
  temp1.toCharArray(temp2, 5);
  delay(WAIT/2);
  OrbitOledSetCursor(4,1);
  OrbitOledPutString("Score:");
  OrbitOledPutString(temp2);
  delay(WAIT);
  OrbitOledSetCursor(2,2);
  OrbitOledPutString("Play Again??");
  OrbitOledSetCursor(0,3);
  OrbitOledPutString("Press any button");
}
//Display your score and go back to the beginning of the game.

