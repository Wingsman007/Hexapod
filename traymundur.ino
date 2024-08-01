void goto_kakikananmundur() {
  float tmp_pos[3];
  for (int i = 0; i < 21; i++ ) {
    tmp_pos[0] = posxmundur[i];
    tmp_pos[1] = posymundur[i];
    tmp_pos[2] = poszmundur[i];

    IK_Kanan1(tmp_pos);
    //IK_Kanan2(tmp_pos);
    pos_degcoxamundur[i] = angle_kanan[0];
    pos_degfemurmundur[i] = angle_kanan[1];
    pos_degtibiamundur[i] = angle_kanan[2];
    

//    Serial.print("C = "); Serial.print(angle_kanan[0]);
//    Serial.print(", F = "); Serial.print(angle_kanan[1]);
//    Serial.print(", T = "); Serial.println(angle_kanan[2]);

  }

}

void goto_kakikirimundur() {
  float tmp_pos[3];
  for (int i = 0; i < 21; i++ ) {
    tmp_pos[0] = posxmundur_2[i];
    tmp_pos[1] = posymundur_2[i];
    tmp_pos[2] = poszmundur_2[i];

    IK_Kiri1(tmp_pos);
    //IK_Kanan2(tmp_pos);
    pos_degcoxamundur_2[i] = angle_kiri[0];
    pos_degfemurmundur_2[i] = angle_kiri[1];
    pos_degtibiamundur_2[i] = angle_kiri[2];
    

//    Serial.print("C = "); Serial.print(angle_kiri[0]);
//    Serial.print(", F = "); Serial.print(angle_kiri[1]);
//    Serial.print(", T = "); Serial.println(angle_kiri[2]);

  }

}
void goto_servo_kananmundur(float servo_c, float servo_f, float servo_t) {

  float pwmrc1, realsudutrc1;
  float pwmrf1, realsudutrf1; // Kanan depan
  float pwmrt1, realsudutrt1;

  float pwmrc3, realsudutrc3;
  float pwmrf3, realsudutrf3; // Kanan belakang
  float pwmrt3, realsudutrt3;

  float pwmlc2, realsudutlc2;
  float pwmlf2, realsudutlf2; // Kiri Tengah
  float pwmlt2, realsudutlt2;

  realsudutrc1 = (servo_c - 129) / (-0.9);
  pwmrc1 = (2.78 * realsudutrc1) + 100;

  realsudutrf1 = (90 - servo_f) / 0.9;
  pwmrf1 = 2.78 * (realsudutrf1 + 36);       // Kanan Depan

  realsudutrt1 = servo_t + 90;
  pwmrt1 = 2.78 * (realsudutrt1 + 36);
  

  realsudutrc3 = (36 - servo_c)/0.9;
  pwmrc3 = 2.78 * (realsudutrc3 + 36);

  realsudutrf3 = (90 - servo_f) / 0.9;
  pwmrf3 = 2.78 * (realsudutrf3 + 36);        // Kanan Belakang

  realsudutrt3 = (80.52 + servo_t) / 0.947;
  pwmrt3 = 2.78 * (realsudutrt3 + 35.9090);
  

  realsudutlc2 = 90 + servo_c;
  pwmlc2 = 2.78 * (realsudutlc2 + 36);

  realsudutlf2 = (90 + servo_f)/1.022;
  pwmlf2 = 2.78 * (realsudutlf2 + 36.3934);       // Kiri Tengah

  realsudutlt2 = (90 - servo_t)/0.937;
  pwmlt2 = 2.78 * (realsudutlt2 + 35.955);
  

  driver1.setPWM(0, 0, pwmrc1);
  driver1.setPWM(2, 0, pwmrf1);
  driver1.setPWM(4, 0, pwmrt1);

  driver1.setPWM(12, 0, pwmrc3);
  driver1.setPWM(14, 0, pwmrf3);
  driver1.setPWM(15, 0, pwmrt3);

  driver2.setPWM(9, 0, pwmlc2);
  driver2.setPWM(7, 0, pwmlf2);
  driver2.setPWM(5, 0, pwmlt2);
  delay(2);

}
void goto_servo_kirimundur(float servo_c, float servo_f, float servo_t) {

  float pwmrc2, realsudutrc2;
  float pwmrf2, realsudutrf2; // Kanan Tengah
  float pwmrt2, realsudutrt2;

  float pwmlc1, realsudutlc1;
  float pwmlf1, realsudutlf1; // Kiri depan
  float pwmlt1, realsudutlt1;

  float pwmlc3, realsudutlc3;
  float pwmlf3, realsudutlf3; // Kiri belakang
  float pwmlt3, realsudutlt3;


  realsudutlc1 = (46 + servo_c) / 0.9;
  pwmlc1 = 2.78 * (realsudutlc1 + 35.899);

  realsudutlf1 = (61.401 + servo_f)/0.841;
  pwmlf1 = 2.78 * (realsudutlf1 + 36.1616);       // Kiri Depan

  realsudutlt1 = (90 - servo_t)/1.125;
  pwmlt1 = 2.78 * (realsudutlt1 + 34.482);
  

  realsudutrc2 = 90 - servo_c;
  pwmrc2 = 2.78 * (realsudutrc2 + 36);

  realsudutrf2 = (96 - servo_f) / 1.022 ;
  pwmrf2 = 2.78 * (realsudutrf2 + 36);        // Kanan Tengah

  realsudutrt2 = 90 + servo_t;
  pwmrt2 = 2.78 * (realsudutrt2 + 36);


  realsudutlc3 = (121 + servo_c)/ 0.9;
  pwmlc3 = 2.78 * (realsudutlc3 + 35.899);

  realsudutlf3 = (80.52 + servo_f)/0.947;
  pwmlf3 = 2.78 * (realsudutlf3 + 35.9090);       // Kiri Belakang

  realsudutlt3 = (90 - servo_t)/1.0465;
  pwmlt3 =  2.78 * (realsudutlt3 + 35.9832);


  driver2.setPWM(15, 0, pwmlc1);
  driver2.setPWM(13, 0, pwmlf1);
  driver2.setPWM(11, 0, pwmlt1);

  driver1.setPWM(6, 0, pwmrc2);
  driver1.setPWM(8, 0, pwmrf2);
  driver1.setPWM(10, 0, pwmrt2);

  driver2.setPWM(3, 0, pwmlc3);
  driver2.setPWM(1, 0, pwmlf3);
  driver2.setPWM(0, 0, pwmlt3);
  delay(2);

}
