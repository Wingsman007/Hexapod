void IK_Kanan1(float pos[3]) {
  float sudut, x0, x, y, z;
  float hasil;
  float theta_f1, theta_f2, theta_t;
  float a, tmp, tmp1, tmp2;
  float hasil1, hasily, hasilx;

  x = pos[0]; y = pos[1]; z = pos[2];
  sudut = atan2(y, x);            //theta_c
  angle_kanan[0] = sudut * ksudut;

  hasil = x * x + y * y;
  x0 = sqrt(hasil);
  hasil = x0 - L_Coxa;
  theta_f1 = atan2(z, hasil);


  tmp1 = (x0 - L_Coxa) * (x0 - L_Coxa);
  tmp = z * z + tmp1;
  a = sqrt(tmp);
  tmp = L_Femur * L_Femur;
  tmp1 = a * a;
  tmp2 = L_Tibia * L_Tibia;
  hasily = tmp + tmp1 - tmp2;
  hasilx = 2 * a * L_Femur;
  hasil = hasily / hasilx;
  theta_f2 = acos(hasil);

  angle_kanan[1] = (theta_f1 + theta_f2) * ksudut; // theta_f

  hasily = tmp + tmp2 - tmp1;
  hasilx = 2 * L_Femur * L_Tibia;
  hasil = hasily / hasilx;

  theta_t = acos(hasil);
  angle_kanan[2] = (theta_t * ksudut) - 90; //theta_t


}

void IK_Kanan2(float pos[3]) {
  float sudut, x0, x, y, z;
  float hasil;
  float theta_f1, theta_f2, theta_t;
  float a, tmp, tmp1, tmp2;
  float hasil1, hasily, hasilx;

  x = pos[0]; y = pos[1]; z = pos[2];
  sudut = atan2(y, x);            //theta_c
  angle_kanan[3] = sudut * ksudut;

  hasil = x * x + y * y;
  x0 = sqrt(hasil);
  hasil = x0 - L_Coxa;
  theta_f1 = atan2(z, hasil);


  tmp1 = (x0 - L_Coxa) * (x0 - L_Coxa);
  tmp = z * z + tmp1;
  a = sqrt(tmp);
  tmp = L_Femur * L_Femur;
  tmp1 = a * a;
  tmp2 = L_Tibia * L_Tibia;
  hasily = tmp + tmp1 - tmp2;
  hasilx = 2 * a * L_Femur;
  hasil = hasily / hasilx;
  theta_f2 = acos(hasil);

  angle_kanan[4] = (theta_f1 + theta_f2) * ksudut; // theta_f

  hasily = tmp + tmp2 - tmp1;
  hasilx = 2 * L_Femur * L_Tibia;
  hasil = hasily / hasilx;

  theta_t = acos(hasil);
  angle_kanan[5] = (theta_t * ksudut) - 90; //theta_t
}

void IK_Kanan3(float pos[3]) {
  float sudut, x0, x, y, z;
  float hasil;
  float theta_f1, theta_f2, theta_t;
  float a, tmp, tmp1, tmp2;
  float hasil1, hasily, hasilx;

  x = pos[0]; y = pos[1]; z = pos[2];
  sudut = atan2(y, x);            //theta_c
  angle_kanan[6] = sudut * ksudut;

  hasil = x * x + y * y;
  x0 = sqrt(hasil);
  hasil = x0 - L_Coxa;
  theta_f1 = atan2(z, hasil);


  tmp1 = (x0 - L_Coxa) * (x0 - L_Coxa);
  tmp = z * z + tmp1;
  a = sqrt(tmp);
  tmp = L_Femur * L_Femur;
  tmp1 = a * a;
  tmp2 = L_Tibia * L_Tibia;
  hasily = tmp + tmp1 - tmp2;
  hasilx = 2 * a * L_Femur;
  hasil = hasily / hasilx;
  theta_f2 = acos(hasil);

  angle_kanan[7] = (theta_f1 + theta_f2) * ksudut; // theta_f

  hasily = tmp + tmp2 - tmp1;
  hasilx = 2 * L_Femur * L_Tibia;
  hasil = hasily / hasilx;

  theta_t = acos(hasil);
  angle_kanan[8] = (theta_t * ksudut) - 90; //theta_t
}
