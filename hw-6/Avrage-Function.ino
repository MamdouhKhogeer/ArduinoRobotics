void setup() {
  Serial.begin(9600);
}

void loop() {
  //define the numbers to take the avrage from
  int x1 = 15;
  int x2 = 30;
  int x3 = 60;

  // define avrage with three arguments insde ()
  int avg = avrage(x1, x2, x3);

  // print the avrage
  Serial.println(avg);
  delay(1000);
}

// the avrage function replacing its three arguments with integers to calculate
long avrage(int x, int y, int z) {
  int answer;
  answer = (x + y + z) / 3;
  return answer;
}
