#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver driver1 = Adafruit_PWMServoDriver();
Adafruit_PWMServoDriver driver2 = Adafruit_PWMServoDriver(0x41);
const int SERVOMIN = 100; // Minimum PWM pulse length count (us)
const int SERVOMAX = 600; // Maximum PWM pulse length count (us)

#define ksudut 57.2958

String receivedData;
int baca_sensor = 0;

bool btn;
long depan;
float kanan;
float kiri;


float angle_kanan[9] {
  0, 0, 0, 0, 0, 0, 0, 0, 0
};

float angle_kiri[9] {
  0, 0, 0, 0, 0, 0, 0, 0, 0
};

float koordinat[3] {
  0, 0, 0
};

float koordinat2[3] {
  0, 0, 0
};

//HOME
float pos_degcoxahome[21];
float pos_degfemurhome[21];
float pos_degtibiahome[21];

float pos_degcoxahome_2[21];
float pos_degfemurhome_2[21];
float pos_degtibiahome_2[21];


//MAJU
float pos_degcoxamaju[21];
float pos_degfemurmaju[21];
float pos_degtibiamaju[21];

float pos_degcoxamaju_2[21];
float pos_degfemurmaju_2[21];
float pos_degtibiamaju_2[21];

float posxmaju[21];
float posymaju[21];
float poszmaju[21];

float posxmaju_2[21];
float posymaju_2[21];
float poszmaju_2[21];

//MUNDUR
float pos_degcoxamundur[21];
float pos_degfemurmundur[21];
float pos_degtibiamundur[21];

float pos_degcoxamundur_2[21];
float pos_degfemurmundur_2[21];
float pos_degtibiamundur_2[21];

float posxmundur[21];
float posymundur[21];
float poszmundur[21];

float posxmundur_2[21];
float posymundur_2[21];
float poszmundur_2[21];

//BELOK KANAN
float pos_degcoxabkanan[21];
float pos_degfemurbkanan[21];
float pos_degtibiabkanan[21];

float pos_degcoxabkanan_2[21];
float pos_degfemurbkanan_2[21];
float pos_degtibiabkanan_2[21];

float posxbkanan[21];
float posybkanan[21];
float poszbkanan[21];

float posxbkanan_2[21];
float posybkanan_2[21];
float poszbkanan_2[21];

float pos_degcoxakiribkanan[21];
float pos_degfemurkiribkanan[21];
float pos_degtibiakiribkanan[21];

float pos_degcoxakiribkanan_2[21];
float pos_degfemurkiribkanan_2[21];
float pos_degtibiakiribkanan_2[21];

float posxkiribkanan[21];
float posykiribkanan[21];
float poszkiribkanan[21];

float posxkiribkanan_2[21];
float posykiribkanan_2[21];
float poszkiribkanan_2[21];

//BELOK KIIR
float pos_degcoxabkiri[21];
float pos_degfemurbkiri[21];
float pos_degtibiabkiri[21];

float pos_degcoxabkiri_2[21];
float pos_degfemurbkiri_2[21];
float pos_degtibiabkiri_2[21];

float posxbkiri[21];
float posybkiri[21];
float poszbkiri[21];

float posxbkiri_2[21];
float posybkiri_2[21];
float poszbkiri_2[21];

float pos_degcoxakiribkiri[21];
float pos_degfemurkiribkiri[21];
float pos_degtibiakiribkiri[21];

float pos_degcoxakiribkiri_2[21];
float pos_degfemurkiribkiri_2[21];
float pos_degtibiakiribkiri_2[21];

float posxkiribkiri[21];
float posykiribkiri[21];
float poszkiribkiri[21];

float posxkiribkiri_2[21];
float posykiribkiri_2[21];
float poszkiribkiri_2[21];

//HOME MAJU MUNDUR
float x_home = 6.01;
float y_home = 0;
float z_home = -8;

float pos_homecoxamajumundur;
float pos_homefemurmajumundur;
float pos_hometibiamajumundur;

//HOME BELOK
float pos_homecoxabelok;
float pos_homefemurbelok;
float pos_hometibiabelok;


float legR1[3] {0, 0, 0};
float legR2[3] {0, 0, 0};
float legR3[3] {0, 0, 0};
float legL1[3] {0, 0, 0};
float legL2[3] {0, 0, 0};
float legL3[3] {0, 0, 0};

int l = 0, p = 0, k = 0, o = 0;
float xx, yy, zz;
float xx_2, yy_2, zz_2;

float L_Coxa = 1.2;
float L_Femur = 4.81;
float L_Tibia = 7.82;

char check_initial_maju = 1, check_initial_mundur = 1;
char check_initial_belokkiri = 1, check_initial_belokkanan = 1;

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);

  driver1.begin();
  driver1.setPWMFreq(60);  // Analog servos run at ~60 Hz
  driver2.begin();
  driver2.setPWMFreq(60);  // Analog servos run at ~60 Hz

  //MAJU
  float x_maju[4] {
    6.01, 6.01, 6.01, 6.01
  };
  float y_maju[4] {
    -2, -1, 1, 2
  };
  float z_maju[4] {
    -8, -4.82, -4.82, -8
  };

  //MUNDUR
  float x_mundur[4] {
    6.01, 6.01, 6.01, 6.01
  };
  float y_mundur[4] {
    2, 1, -1, -2
  };
  float z_mundur[4] {
    -8, -4.82, -4.82, -8
  };

  //BELOK KANAN
  float x_kiribkanan[4] {
    5.204, 5.805, 6.01, 5.805
  };
  float y_kiribkanan[4] {
    -3.006, 0, 1.293, 3.006
  };
  float z_kiribkanan[4] {
    -8, -5.82, -5.82, -8
  };
  float x_bkanan[4] {
    5.204, 5.805, 6.01, 5.805
  };
  float y_bkanan[4] {
    3.006, 0, -1.293, -3.006
  };
  float z_bkanan[4] {
    -8, -5.82, -5.82, -8
  };

  //BELOK KIRI
  float x_bkiri[4] {
    5.204, 5.805, 6.01, 5.805
  };
  float y_bkiri[4] {
    -3.006, -1.293, 0,  3.006
  };
  float z_bkiri[4] {
    -8, -5.82, -5.82, -8
  };
  float x_kiribkiri[4] {
    5.805, 6.01, 5.805, 5.204
  };
  float y_kiribkiri[4] {
    3.006, 0, -1.293, -3.006
  };
  float z_kiribkiri[4] {
    -8, -5.82, -5.82, -8
  };

  // Isi data posx, posy, posz
  float a, b, c, d, t, k;
  t = 0.05;

  for (int i = 0; i < 21; i++) {
    k = (i * t);
    a = 1 - k;
    b = a;
    c = b;
    a = pow(a, 3);
    b = (3 * k) * pow(b, 2);

    c = (1 - k) * pow(k , 2);
    c = 3 * c;
    d = pow(k, 3);

    //MAJU
    posxmaju[i] = (a * x_maju[0]) + (b * x_maju[1]) + (c * x_maju[2]) + (d * x_maju[3]);
    posymaju[i] = (a * y_maju[0]) + (b * y_maju[1]) + (c * y_maju[2]) + (d * y_maju[3]);
    poszmaju[i] = (a * z_maju[0]) + (b * z_maju[1]) + (c * z_maju[2]) + (d * z_maju[3]);

    posxmaju_2[i] = (a * x_maju[0]) + (b * x_maju[1]) + (c * x_maju[2]) + (d * x_maju[3]);
    posymaju_2[i] = (a * y_maju[3]) + (b * y_maju[2]) + (c * y_maju[1]) + (d * y_maju[0]);
    poszmaju_2[i] = (a * z_maju[0]) + (b * z_maju[0]) + (c * z_maju[0]) + (d * z_maju[0]);

    //MUNDUR
    posxmundur[i] = (a * x_mundur[0]) + (b * x_mundur[1]) + (c * x_mundur[2]) + (d * x_mundur[3]);
    posymundur[i] = (a * y_mundur[0]) + (b * y_mundur[1]) + (c * y_mundur[2]) + (d * y_mundur[3]);
    poszmundur[i] = (a * z_mundur[0]) + (b * z_mundur[1]) + (c * z_mundur[2]) + (d * z_mundur[3]);

    posxmundur_2[i] = (a * x_mundur[0]) + (b * x_mundur[1]) + (c * x_mundur[2]) + (d * x_mundur[3]);
    posymundur_2[i] = (a * y_mundur[3]) + (b * y_mundur[2]) + (c * y_mundur[1]) + (d * y_mundur[0]);
    poszmundur_2[i] = (a * z_mundur[0]) + (b * z_mundur[0]) + (c * z_mundur[0]) + (d * z_mundur[0]);

    //BELOK KANAN
    posxbkanan[i] = (a * x_bkanan[0]) + (b * x_bkanan[1]) + (c * x_bkanan[2]) + (d * x_bkanan[3]);
    posybkanan[i] = (a * y_bkanan[0]) + (b * y_bkanan[1]) + (c * y_bkanan[2]) + (d * y_bkanan[3]);
    poszbkanan[i] = (a * z_bkanan[0]) + (b * z_bkanan[1]) + (c * z_bkanan[2]) + (d * z_bkanan[3]);

    posxbkanan_2[i] = (a * x_bkanan[3]) + (b * x_bkanan[2]) + (c * x_bkanan[1]) + (d * x_bkanan[0]);
    posybkanan_2[i] = (a * y_bkanan[3]) + (b * y_bkanan[2]) + (c * y_bkanan[1]) + (d * y_bkanan[0]);
    poszbkanan_2[i] = (a * z_bkanan[0]) + (b * z_bkanan[0]) + (c * z_bkanan[0]) + (d * z_bkanan[0]);

    posxkiribkanan[i] = (a * x_kiribkanan[0]) + (b * x_kiribkanan[1]) + (c * x_kiribkanan[2]) + (d * x_kiribkanan[3]);
    posykiribkanan[i] = (a * y_kiribkanan[0]) + (b * y_kiribkanan[1]) + (c * y_kiribkanan[2]) + (d * y_kiribkanan[3]);
    poszkiribkanan[i] = (a * z_kiribkanan[0]) + (b * z_kiribkanan[1]) + (c * z_kiribkanan[2]) + (d * z_kiribkanan[3]);

    posxkiribkanan_2[i] = (a * x_kiribkanan[3]) + (b * x_kiribkanan[2]) + (c * x_kiribkanan[1]) + (d * x_kiribkanan[0]);
    posykiribkanan_2[i] = (a * y_kiribkanan[3]) + (b * y_kiribkanan[2]) + (c * y_kiribkanan[1]) + (d * y_kiribkanan[0]);
    poszkiribkanan_2[i] = (a * z_kiribkanan[0]) + (b * z_kiribkanan[0]) + (c * z_kiribkanan[0]) + (d * z_kiribkanan[0]);

    //BELOK KIRI
    posxbkiri[i] = (a * x_bkiri[0]) + (b * x_bkiri[1]) + (c * x_bkiri[2]) + (d * x_bkiri[3]);
    posybkiri[i] = (a * y_bkiri[0]) + (b * y_bkiri[1]) + (c * y_bkiri[2]) + (d * y_bkiri[3]);
    poszbkiri[i] = (a * z_bkiri[0]) + (b * z_bkiri[1]) + (c * z_bkiri[2]) + (d * z_bkiri[3]);

    posxbkiri_2[i] = (a * x_bkiri[3]) + (b * x_bkanan[2]) + (c * x_bkiri[1]) + (d * x_bkiri[0]);
    posybkiri_2[i] = (a * y_bkiri[3]) + (b * y_bkiri[2]) + (c * y_bkiri[1]) + (d * y_bkiri[0]);
    poszbkiri_2[i] = (a * z_bkiri[0]) + (b * z_bkiri[0]) + (c * z_bkiri[0]) + (d * z_bkiri[0]);

    posxkiribkiri[i] = (a * x_kiribkiri[0]) + (b * x_kiribkiri[1]) + (c * x_kiribkiri[2]) + (d * x_kiribkiri[3]);
    posykiribkiri[i] = (a * y_kiribkiri[0]) + (b * y_kiribkiri[1]) + (c * y_kiribkiri[2]) + (d * y_kiribkiri[3]);
    poszkiribkiri[i] = (a * z_kiribkiri[0]) + (b * z_kiribkiri[1]) + (c * z_kiribkiri[2]) + (d * z_kiribkiri[3]);

    posxkiribkiri_2[i] = (a * x_kiribkiri[3]) + (b * x_kiribkiri[2]) + (c * x_kiribkiri[1]) + (d * x_kiribkiri[0]);
    posykiribkiri_2[i] = (a * y_kiribkiri[3]) + (b * y_kiribkiri[2]) + (c * y_kiribkiri[1]) + (d * y_kiribkiri[0]);
    poszkiribkiri_2[i] = (a * z_kiribkiri[0]) + (b * z_kiribkiri[0]) + (c * z_kiribkiri[0]) + (d * z_kiribkiri[0]);
  }

}


void loop() {
  //
  //if (baca_sensor == 5) {
  if (Serial2.available() > 0) {
    receivedData = Serial2.readStringUntil('\n');

    int firstCommaIndex = receivedData.indexOf(',');
    int secondCommaIndex = receivedData.indexOf(',', firstCommaIndex + 1);
    int thirdCommaIndex = receivedData.indexOf(',', secondCommaIndex + 1);

    btn = receivedData.substring(0, firstCommaIndex).toInt();
    depan = receivedData.substring(firstCommaIndex + 1, secondCommaIndex).toInt();
    kanan = receivedData.substring(secondCommaIndex + 1, thirdCommaIndex).toInt();
    kiri = receivedData.substring(thirdCommaIndex + 1).toInt();

    Serial.print("depan: ");
    Serial.print(depan);
    Serial.print(", kanan: ");
    Serial.print(kanan);
    Serial.print(", kiri: ");
    Serial.println(kiri);
  }


  if (btn == 1 && depan > 30) {
    if (Serial2.available()) {
      receivedData = Serial2.readStringUntil('\n');

      // Split the received data by commas
      int firstCommaIndex = receivedData.indexOf(',');
      int secondCommaIndex = receivedData.indexOf(',', firstCommaIndex + 1);
      int thirdCommaIndex = receivedData.indexOf(',', secondCommaIndex + 1);

      btn = receivedData.substring(0, firstCommaIndex).toInt();
      depan = receivedData.substring(firstCommaIndex + 1, secondCommaIndex).toInt();
      kanan = receivedData.substring(secondCommaIndex + 1, thirdCommaIndex).toInt();
      kiri = receivedData.substring(thirdCommaIndex + 1).toInt();

    }
    maju();
    //    Serial.print("maju");
  }
  else if (btn == 1 && depan < 30 && depan > 10 && kiri < 30) {
    if (Serial2.available()) {
      receivedData = Serial2.readStringUntil('\n');

      // Split the received data by commas
      int firstCommaIndex = receivedData.indexOf(',');
      int secondCommaIndex = receivedData.indexOf(',', firstCommaIndex + 1);
      int thirdCommaIndex = receivedData.indexOf(',', secondCommaIndex + 1);

      btn = receivedData.substring(0, firstCommaIndex).toInt();
      depan = receivedData.substring(firstCommaIndex + 1, secondCommaIndex).toInt();
      kanan = receivedData.substring(secondCommaIndex + 1, thirdCommaIndex).toInt();
      kiri = receivedData.substring(thirdCommaIndex + 1).toInt();

    }
    belok_kanan();
  }
  else if (btn == 1 && depan < 30 && depan > 10 && kiri > 30 && kanan > 30) {
    if (Serial2.available()) {
      receivedData = Serial2.readStringUntil('\n');

      // Split the received data by commas
      int firstCommaIndex = receivedData.indexOf(',');
      int secondCommaIndex = receivedData.indexOf(',', firstCommaIndex + 1);
      int thirdCommaIndex = receivedData.indexOf(',', secondCommaIndex + 1);

      btn = receivedData.substring(0, firstCommaIndex).toInt();
      depan = receivedData.substring(firstCommaIndex + 1, secondCommaIndex).toInt();
      kanan = receivedData.substring(secondCommaIndex + 1, thirdCommaIndex).toInt();
      kiri = receivedData.substring(thirdCommaIndex + 1).toInt();

    }
    belok_kanan();
  }
  else if (btn == 1 && depan < 30 && depan > 10 && kanan < 30) {
    if (Serial2.available()) {
      receivedData = Serial2.readStringUntil('\n');

      // Split the received data by commas
      int firstCommaIndex = receivedData.indexOf(',');
      int secondCommaIndex = receivedData.indexOf(',', firstCommaIndex + 1);
      int thirdCommaIndex = receivedData.indexOf(',', secondCommaIndex + 1);

      btn = receivedData.substring(0, firstCommaIndex).toInt();
      depan = receivedData.substring(firstCommaIndex + 1, secondCommaIndex).toInt();
      kanan = receivedData.substring(secondCommaIndex + 1, thirdCommaIndex).toInt();
      kiri = receivedData.substring(thirdCommaIndex + 1).toInt();

    }
    belok_kiri();
  }
  else if (btn == 1 && depan < 10) {
    if (Serial2.available()) {
      receivedData = Serial2.readStringUntil('\n');

      // Split the received data by commas
      int firstCommaIndex = receivedData.indexOf(',');
      int secondCommaIndex = receivedData.indexOf(',', firstCommaIndex + 1);
      int thirdCommaIndex = receivedData.indexOf(',', secondCommaIndex + 1);

      btn = receivedData.substring(0, firstCommaIndex).toInt();
      depan = receivedData.substring(firstCommaIndex + 1, secondCommaIndex).toInt();
      kanan = receivedData.substring(secondCommaIndex + 1, thirdCommaIndex).toInt();
      kiri = receivedData.substring(thirdCommaIndex + 1).toInt();

    }
    mundur();
  }
  else if (btn == 0) {
    if (Serial2.available()) {
      receivedData = Serial2.readStringUntil('\n');

      // Split the received data by commas
      int firstCommaIndex = receivedData.indexOf(',');
      int secondCommaIndex = receivedData.indexOf(',', firstCommaIndex + 1);
      int thirdCommaIndex = receivedData.indexOf(',', secondCommaIndex + 1);

      btn = receivedData.substring(0, firstCommaIndex).toInt();
      depan = receivedData.substring(firstCommaIndex + 1, secondCommaIndex).toInt();
      kanan = receivedData.substring(secondCommaIndex + 1, thirdCommaIndex).toInt();
      kiri = receivedData.substring(thirdCommaIndex + 1).toInt();

    }
    xx = pos_homecoxabelok;
    yy = pos_homefemurbelok;
    zz = pos_hometibiabelok;

    goto_servo_home_belok(xx, yy, zz);
  }

}
