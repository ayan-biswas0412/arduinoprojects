int BLACK = 1;
int WHITE = 0;

int S_A = 10;  //speed motor a
int M_A1 = 2; //motor a = +
int M_A2 = 3; //motor a = -
int M_B1 = 4; //motor b = -
int M_B2 = 5; //motor b = +
int S_B = 9;  //speed motor b

int R_S = A0; //sensor R
int S_S = A1; //sensor S
int L_S = A2; //sensor L

void setup() 
{
pinMode(M_B1, OUTPUT);
pinMode(M_B2, OUTPUT);
pinMode(M_A1, OUTPUT);
pinMode(M_A2, OUTPUT);
pinMode(S_B, OUTPUT);
pinMode(S_A, OUTPUT);

pinMode(L_S, INPUT);
pinMode(S_S, INPUT);
pinMode(R_S, INPUT);

analogWrite(S_A, 230); 
analogWrite(S_B, 230); 
delay(200);
}

void forword(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, HIGH);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW);  
}

void backward()
{
digitalWrite(M_A1, HIGH);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, HIGH);  
}

void turnRight(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW);  
}

void turnLeft(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, HIGH);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
}

void Stop(){
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
}

void loop()
{  
if ((digitalRead(L_S) == WHITE)&&(digitalRead(S_S) == BLACK)&&(digitalRead(R_S) == WHITE)){forword();}
else if((digitalRead(S_S) == BLACK)){forword();}

if ((digitalRead(L_S) == BLACK)&&(digitalRead(S_S) == BLACK)&&(digitalRead(R_S) == WHITE)){turnLeft();}
if ((digitalRead(L_S) == BLACK)&&(digitalRead(S_S) ==WHITE)&&(digitalRead(R_S) == WHITE)) {turnLeft();}

if ((digitalRead(L_S) == WHITE)&&(digitalRead(S_S) == BLACK)&&(digitalRead(R_S) == BLACK)){turnRight();}
if ((digitalRead(L_S) == WHITE)&&(digitalRead(S_S) == WHITE)&&(digitalRead(R_S) == BLACK)){turnRight();}

if ((digitalRead(L_S) == BLACK)&&(digitalRead(S_S) == BLACK)&&(digitalRead(R_S) == BLACK)){Stop();}

if ((digitalRead(L_S) == WHITE)&&(digitalRead(S_S) == WHITE)&&(digitalRead(R_S) == WHITE)){Stop();}
}
