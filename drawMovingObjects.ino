struct coor
{
  int x;
  int y;
};
//The coordinates.

struct box{
  //random size of the boxes
  int boxLength = random(5, 12);
  //random distance between boxes
  int distance = random(30, 80);
  //coordinates used to draw the boxes
  struct coor coorTopLeft;
  struct coor coorBottomRight;
  struct coor coorDistance;
};

int drawBox(struct box boxes[],int state[],int jud[], int dis[], int score)
{
    int height = state[0];

    //First time box generation.
    if(score==0)    
    {
      dis[0] = boxes[0].distance+boxes[1].distance+boxes[2].distance+boxes[3].distance+boxes[4].distance+boxes[5].distance;
      boxes[0].coorTopLeft.x = 127;
      for(int j=1; j<6; j++)
      {
        boxes[j].coorTopLeft.x = boxes[j-1].coorTopLeft.x + boxes[j-1].distance;
        }
    }
    for(int i=0; i<6; i++)
    {
      printOneBox(boxes, i, height, jud, dis);
      }
    OrbitOledMoveTo(0,30);
    OrbitOledLineTo(127,30);
    
}
//Print boxes on screen.


void drawPlayer(int state[], int keep[])
{
  
  int h = state[0];
  //Serial.println(h);

  //Between jumps.
  if(keep[0]>=40)    
  {
    keep[0]=0;
  }
  else if(keep[0]>35 && keep[0]<40)
  {
    buttonState1=LOW;
    buttonState2=LOW;
  }
  else
  {
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
  }

  //Jump
  if(buttonState1==HIGH || buttonState2==HIGH)    
  {
    state[0]=14;
    keep[0]+=1;
  }

  //Keep jumping
  if(keep[0]>=1)  
  {
    keep[0]++;
  }
  if(keep[0]>=35)
  {
    state[0]=0;
  }
  OrbitOledMoveTo(10,30-h);
  OrbitOledLineTo(13,25-h);
  OrbitOledLineTo(16,30-h);
  OrbitOledMoveTo(13,22-h);
  OrbitOledLineTo(13,25-h);
}

int mainGame()
{
  struct box boxes[6];    //6 boxes
  boxes[5].coorDistance.x = 127;
  int state[1] = {0};    //The height of jumping.
  int keep[1] = {0};    //Decide the distance of jumping.
  int jud[1] = {0};    //Decide whether the game should be stopped.
  int dis[1] = {0};    //The total distance of the boxes
  int score = 0;    //The score, count the iteration.
 
  while(1)
  {
    drawBox(boxes, state, jud, dis, score);
    drawPlayer(state, keep);

    //Increasing difficulty.
    if(score/5 <200)    
    {delay(20);}
    else if (score/5>=200 && score/5<400)
    {
      delay(18);
    }
    else if (score/5>=400 && score/5<600)
    {
      delay(16);
    }
    else if (score/5>=600 && score/5<800)
    {
      delay(14);
    }
    else if (score/5>=800 && score/5<1000)
    {
      delay(12);
    }
    else
    {
      delay(10);
    }
    OrbitOledUpdate();
    OrbitOledClearBuffer();
    
    if (jud[0]>3)
    {
      return score/5;
    }
    score++;
  }
}

void printOneBox(struct box boxes[], int j, int height, int jud[], int dis[])
{
  boxes[j].coorBottomRight.y = 30;
  boxes[j].coorDistance.y = 30;
  boxes[j].coorTopLeft.y = 30-boxes[j].boxLength;
  boxes[j].coorDistance.x = boxes[j].coorTopLeft.x+boxes[j].distance;
  boxes[j].coorBottomRight.x = boxes[j].coorTopLeft.x+boxes[j].boxLength;
  OrbitOledMoveTo(boxes[j].coorTopLeft.x, boxes[j].coorTopLeft.y);
  OrbitOledDrawRect(boxes[j].coorBottomRight.x, boxes[j].coorBottomRight.y);
  boxes[j].coorTopLeft.x--;

  //Boundary tests
  if(13>=boxes[j].coorTopLeft.x && 13<=boxes[j].coorBottomRight.x && (30-height)>=boxes[j].coorTopLeft.y)    
  {
    jud[0]++;
  }

  //Regenerate boxes
  if((boxes[j].coorTopLeft.x+boxes[j].distance)<0)    
  {
    int oldBoxDistance = boxes[j].distance;
    dis[0]-=oldBoxDistance;
    boxes[j].coorTopLeft.x = dis[0];
    boxes[j].boxLength = random(5, 12);
    boxes[j].distance = random(30, 80);
    dis[0]+=boxes[j].distance;
  }
}

