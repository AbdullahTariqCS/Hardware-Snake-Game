#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

// pins
const int sipoClk = 0;
const int sipoOutput = 1;

const int pisoClkLeft = 2;
const int pisoClkRight = 3;
const int pisoMode = 4;
const int pisoInput = 5;

const int counterA0 = 6;
const int counterA1 = 7;
const int counterB0 = 8;
const int counterB1 = 9;
const int shiftClk = 10;

const int dirO0 = 11;
const int dirO1 = 12;

const int rightLeft = A0; // xpin
const int upDown = A1;    // ypin
const int speed = A2; 
// variables
long prev = 0;
int del = 500;
int direction = RIGHT;
int counterA = 0;
int counterB = 1;
int edgeCount = 0;

void setup()
{

  pinMode(sipoOutput, OUTPUT);
  pinMode(sipoClk, OUTPUT);

  pinMode(pisoClkLeft, OUTPUT);
  pinMode(pisoClkRight, OUTPUT);
  pinMode(pisoMode, OUTPUT);
  pinMode(pisoInput, INPUT);

  pinMode(counterA0, OUTPUT);
  pinMode(counterA1, OUTPUT);
  pinMode(counterB0, OUTPUT);
  pinMode(counterB1, OUTPUT);
  pinMode(shiftClk, OUTPUT);

  pinMode(rightLeft, INPUT);
  pinMode(upDown, INPUT);
  pinMode(speed, INPUT);

  digitalWrite(sipoClk, HIGH);

  digitalWrite(pisoClkLeft, HIGH);
  digitalWrite(pisoClkRight, HIGH);
  digitalWrite(pisoMode, HIGH);
  digitalWrite(sipoClk, HIGH);

  digitalWrite(counterA0, counterA % 2);
  digitalWrite(counterA1, counterA / 2);
  digitalWrite(counterB0, counterB % 2);
  digitalWrite(counterB1, counterB / 2);
}
void loop()
{
  int del = map(analogRead(speed), 0 , 1023, 500, 300);
  long current = millis();
  bool updated = false; 
  if (current - prev >= del - 50 && analogRead(speed) > 100);
  {
    digitalWrite(shiftClk, LOW);
    updated = true;
  }

  if (analogRead(rightLeft) < 30)
  {
    direction = RIGHT;
  }
  else if (analogRead(rightLeft) > 1000)
  {
    direction = LEFT;
  }
  else if (analogRead(upDown) < 30)
  {
    direction = UP;
  }
  else if (analogRead(upDown) > 1000)
  {
    direction = DOWN;
  }

  if (current - prev >= del && analogRead(speed) > 100 && updated)
  {
    prev = current;
    digitalWrite(shiftClk, HIGH);

    counterA = (counterA + 1) % 4;
    counterB = (counterB + 1) % 4;

    digitalWrite(counterA0, counterA % 2);
    digitalWrite(counterA1, counterA / 2);
    digitalWrite(counterB0, counterB % 2);
    digitalWrite(counterB1, counterB / 2);

    byte rawData[16]; //{x00, x01, x10, x11, y00, y01, y10, y11}
    int coords[4][2]; //{{x0, y0}, {x1, y1}, {x2, y2}, {x3, y3}}
    byte matrix[4][4] = {0};

    // Serially input data from shift registers
    digitalWrite(pisoClkLeft, LOW);
    delay(2);
    digitalWrite(pisoClkRight, LOW);
    delay(2);

    // changing mode to shift
    digitalWrite(pisoMode, LOW);
    delay(2);

    // resetting the right and left clocks
    digitalWrite(pisoClkRight, HIGH);
    delay(2);
    digitalWrite(pisoClkLeft, HIGH);
    delay(2);

    // shifting data serially
    for (int i = 15; i >= 0; i--)
    {

      rawData[i] = (int)digitalRead(pisoInput);
      delay(2);
      digitalWrite(pisoClkRight, LOW);
      delay(2);
      if (i == 0)
      {
        digitalWrite(pisoClkLeft, LOW);
        delay(2);
        digitalWrite(pisoMode, HIGH);
        delay(2);
        digitalWrite(pisoClkLeft, HIGH);
        delay(2);
      }
      digitalWrite(pisoClkRight, HIGH);
    }
    delay(2);
    
    // converting raw data to coordinates
    int rawCount = 0;
    for (int i = 0; i < 4; i++)
    {
      coords[i][0] = rawData[rawCount] + 2 * rawData[rawCount + 1];
      coords[i][1] = rawData[rawCount + 8] + 2 * rawData[rawCount + 9];
      rawCount += 2;
    }

    // converting coordinates to bit matrix
    for (int i = 0; i < 4; i++)
      matrix[coords[i][0]][coords[i][1]] = 1;

    // shifting to bit matrix

    for (int i = 3; i >= 0; i--)
    {
      for (int j = 3; j >= 0; j--)
      {
        digitalWrite(sipoOutput, matrix[i][j]);
        delay(2);
        digitalWrite(sipoClk, LOW);
        delay(2);
        digitalWrite(sipoClk, HIGH);
      }
    }
    delay(2);
  }
}
