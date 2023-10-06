import processing.serial.*;

Serial myPort;
String val;

Ball ball;
Paddle playerOne;
Paddle playerTwo;

int playerOneValue;
int playerTwoValue;
int playerOneSwitchValue;
int playerTwoSwitchValue;

int playerOneScore = 0;
int playerTwoScore = 0;

boolean isStarted = false;
boolean winner = false;

void setup () {
  size(1024, 512);
  myPort = new Serial(this, "COM4", 9600);
  myPort.bufferUntil('\n'); 
  
  ball = new Ball();
  playerOne = new Paddle(true);
  playerTwo = new Paddle(false);
  
}

void draw () {
  myPort.write(playerOneScore);
  myPort.write(playerTwoScore);
  
  if(isStarted == false){
    background(0);
    textSize(100);
    textAlign(CENTER);
    text("PONG", width/2, height/2);
    textAlign(CENTER);
    textSize(20);
    text("Press Player1/Player2 key on the Controller", width/2, height/2+50);
  }
  
  if(playerOneSwitchValue == 0 && playerTwoSwitchValue == 0){
    isStarted = !isStarted;
  }
  
  if(isStarted == true) {
    background(0, 0, 0);
    
    ball.checkPaddleLeft(playerOne);
    ball.checkPaddleRight(playerTwo);
    
    ball.show();
    playerOne.show();
    playerTwo.show();
    
    playerOne.move(playerOneValue);
    playerTwo.move(playerTwoValue);
    ball.update();
    ball.edges();
    
    fill(255, 255, 255);
    textSize(32);
    text(playerOneScore, 30, 40);
    text(playerTwoScore, width - 60, 40);
  }
  
  if (playerOneScore > 9){
  background(0);
  textSize(100);
  textAlign(CENTER);
  text("Winner", width/2, height/2);
  textAlign(CENTER);
  textSize(20);
  text("Player 1", width/2, height/2+50);
  text("Wait", width/2, height/2+100);
  winner = true;
  playerOneScore = 0;
  playerTwoScore = 0;
  }
  
  if (playerTwoScore > 9){
  background(0);
  textSize(100);
  textAlign(CENTER);
  text("Winner", width/2, height/2);
  textAlign(CENTER);
  textSize(20);
  text("Player 2", width/2, height/2+50);
  text("Wait", width/2, height/2+100);
  winner = true;
  playerOneScore = 0;
  playerTwoScore = 0;
  }
  
  if(winner == true) {
    winner = false;
    isStarted = false;
  }
}

void serialEvent(Serial myPort) {
  val = myPort.readStringUntil('\n');
  val = trim(val);
  int[] vals = int(splitTokens(val, ","));
  playerOneValue = vals[0];
  playerTwoValue = vals[1];
  playerOneSwitchValue = vals[2];
  playerTwoSwitchValue = vals[3];
}

class Ball {
  float x = width/2;
  float y = height/2;
  float xSpeed;
  float ySpeed;
  float r = 10;
  
  Ball() {
    reset();
  }
  void show() {
    fill(255, 255, 255);
    circle(x, y, r*2);
  }
  void update() {
    x += xSpeed;
    y += ySpeed;
  }
  void reset() {
    x = width/2;
    y = height/2;
    float angle = 90*random(-PI/4, PI/4);
    xSpeed = 7 * cos(radians(angle));
    ySpeed = 7 * sin(radians(angle));
    
    if(random(1) < 0.5)
      xSpeed *= -1;
  }
  void edges() {
    if(y < 0 || y > height)
      ySpeed *= -1;
    if(x + r < 0) {
      playerTwoScore++;
      reset();
    }
    if(x - r > width) {
      playerOneScore++;
      reset();
    }
  }
  
  void checkPaddleLeft(Paddle p) {
    if(y < p.y + p.h/2 && y > p.y - p.h/2 && x - r < p.x + p.w/2)
      if(x > p.x) {
        //float diff = y - (p.y - p.y/2);
        //float angle = map(diff, 0, p.h, -radians(45), radians(45));
        //xSpeed = 7 * cos(angle);
        //ySpeed = 7 * sin(angle);
        //x = p.x + p.w/2 + r;
        xSpeed *= -1; 
      } 
  }
  void checkPaddleRight(Paddle p) {
    if(y < p.y + p.h/2 && y > p.y - p.h/2 && x + r > p.x - p.w/2)
      if(x < p.x) {
        //float diff = y - (p.y - p.y/2);
        //float angle = map(diff, 0, p.h, -radians(135), radians(135));
        //xSpeed = 7 * cos(angle);
        //ySpeed = 7 * sin(angle);
        //x = p.x - p.w/2 - r;
        xSpeed *= -1; 
      } 
  }
}

class Paddle {
  float x;
  float y = height/2;
  float w = 20;
  float h = 100;
  
  Paddle(boolean left) {
    if(left)
      x = w;
    else 
      x = width - w;
  }
  void show() {
    fill(255, 255, 255);
    rectMode(CENTER);
    rect(x, y, w, h);
  }
  void move(float steps) {
    //y = steps;
    y = constrain(steps, h/2, height - h/2);
  }
}
