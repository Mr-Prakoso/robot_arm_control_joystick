#include <Servo.h>

Servo servoa, servob, servoc,servod;

int a0 = 503, a1 = 508, a2 = 515, a3 = 513;
int timer;
int posa = 90, posb = 45, posc = 90, posd = 10;

void setup() {
  Serial.begin(9600);

  servoa.attach(11);
  servob.attach(10);
  servoc.attach(9);
  servod.attach(5);

  servoa.write(posa);
  delay(200);
  servob.write(posb);
  delay(200);
  servoc.write(posc);
  delay(200);
  servod.write(posd);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() {
  delay(5);
  // Serial.print(analogRead(A0));
  // Serial.print("\t");
  // Serial.print(analogRead(A1));
  // Serial.print("\t");
  // Serial.print(analogRead(A2));
  // Serial.print("\t");
  // Serial.println(analogRead(A3));

  if(analogRead(A0) <= a0-5 or analogRead(A0) >= a0+5){
    if(analogRead(A0) > a0){
      timer = map(analogRead(A0), a0, 1023, 100, 10);
      if(millis()%timer > timer-10){posa--;}
      if(posa < 0){posa = 0;}
    }
    else if(analogRead(A0) < a0){
      timer = map(analogRead(A0), a0, 0, 100, 10);
      if(millis()%timer > timer-10){posa++;}
      if(posa > 180){posa = 180;}
    }
    servoa.write(posa);
  }

  if(analogRead(A1) <= a1-5 or analogRead(A1) >= a1+5){
    if(analogRead(A1) > a1){
      timer = map(analogRead(A1), a1, 1023, 100, 10);
      if(millis()%timer > timer-10){posb--;}
      if(posb < 0){posb = 0;}
    }
    else if(analogRead(A1) < a1){
      timer = map(analogRead(A1), a1, 0, 100, 10);
      if(millis()%timer > timer-10){posb++;}
      if(posb > 180){posb = 180;}
    }
    servob.write(posb);
  }

  if(analogRead(A2) <= a2-10 or analogRead(A2) >= a2+10){
    if(analogRead(A2) > a2){
      timer = map(analogRead(A2), a2, 1023, 100, 10);
      if(millis()%timer > timer-10){posc--;}
      if(posc < 0){posc = 0;}
    }
    else if(analogRead(A2) < a2){
      timer = map(analogRead(A2), a2, 0, 100, 10);
      if(millis()%timer > timer-10){posc++;}
      if(posc > 180){posc = 180;}
    }
    servoc.write(posc);
  }
    
  if(analogRead(A3) <= a3-5 or analogRead(A3) >= a3+5){
    if(analogRead(A3) > a3){
      timer = map(analogRead(A3), a3, 1023, 100, 10);
      if(millis()%timer > timer-10){posd--;}
      if(posd < 0){posd = 0;}
    }
    else if(analogRead(A3) < a3){
      timer = map(analogRead(A3), a3, 0, 100, 10);
      if(millis()%timer > timer-10){posd++;}
      if(posd > 180){posd = 180;}
    }
    servod.write(posd);
  }
}