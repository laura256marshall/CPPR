/*********************************************
* Laura Spence
* Classes for CPPR/Final Project EE210
* Created on: 1/11/2024
* Last updated: 1/11/2024
*********************************************/


class paddles()
{
private:
int speed = 0;
int positionX = 0;
int positionY = 0;
int angle = 0;
int score = 0;

public:
paddles(int posX, int posY)
{
    this.positionX = posX;
    this.positionY = posY;
}

int getSpeed(){}
void setSpeed(){}

int getPosX()
{
    return positionX;
}
void setPosX(int addToPos)
{
    positionX = positionX + addToPos;
}

int getPosY()
{
    return positionY;
}

void setPosY(int addToPos)
{
    positionY = positionY + addToPos;
}

int getAngle()
{
    return angle;
}
void setAngle(){}

int getAngleSpeed()
{
}
void setAngleSpeed(){}

int getScore(){}
void setScore(int numScore)
{
    score = numScore;
}

void addToScore()
{
    score = score + addToScore;
}

}




