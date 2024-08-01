void IK_Kiri1(float pos[3]) {
  float sudut, x0, x, y, z;
  float hasil;
  float theta_f1, theta_f2, theta_t;
  float a, tmp, tmp1, tmp2;
  float hasil1, hasily, hasilx;

  x = pos[0]; y = pos[1]; z = pos[2];
  sudut = atan2(y, x);            
  angle_kiri[0] = sudut * ksudut;     // THETA_C

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

  angle_kiri[1] = (theta_f1 + theta_f2) * ksudut;     // THETA_F

  hasily = tmp + tmp2 - tmp1;
  hasilx = 2 * L_Femur * L_Tibia;
  hasil = hasily / hasilx;

  theta_t = acos(hasil);
  angle_kiri[2] = (theta_t * ksudut) - 90;      // THETA_T


}

void IK_Kiri2(float pos[3]) {
  float sudut, x0, x, y, z;
  float hasil;
  float theta_f1, theta_f2, theta_t;
  float a, tmp, tmp1, tmp2;
  float hasil1, hasily, hasilx;

  x = pos[0]; y = pos[1]; z = pos[2];
  sudut = atan2(y, x);            
  angle_kiri[3] = sudut * ksudut;     // THETA_C

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

  angle_kiri[4] = (theta_f1 + theta_f2) * ksudut;     // THETA_F

  hasily = tmp + tmp2 - tmp1;
  hasilx = 2 * L_Femur * L_Tibia;
  hasil = hasily / hasilx;

  theta_t = acos(hasil);
  angle_kiri[5] = (theta_t * ksudut) - 90;      // THETA_T
}

void IK_Kiri3(float pos[3]) {
  float sudut, x0, x, y, z;
  float hasil;
  float theta_f1, theta_f2, theta_t;
  float a, tmp, tmp1, tmp2;
  float hasil1, hasily, hasilx;

  x = pos[0]; y = pos[1]; z = pos[2];
  sudut = atan2(y, x);            
  angle_kiri[6] = sudut * ksudut;     // THETA_C

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

  angle_kiri[7] = (theta_f1 + theta_f2) * ksudut;     // THETA_F

  hasily = tmp + tmp2 - tmp1;
  hasilx = 2 * L_Femur * L_Tibia;
  hasil = hasily / hasilx;

  theta_t = acos(hasil);
  angle_kiri[8] = (theta_t * ksudut) - 90;      // THETA_T
}
