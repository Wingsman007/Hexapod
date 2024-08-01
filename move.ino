void maju(){

  if (check_initial_maju == 1) {
    xx = pos_homecoxamajumundur;
    yy = pos_homefemurmajumundur;
    zz = pos_hometibiamajumundur;

    goto_kakikananmaju();
    goto_kakikananmaju_2();
    goto_kakikirimaju();
    goto_kakikirimaju_2();
    

    goto_servo_home_majumundur(xx, yy, zz);

    check_initial_maju = -1;

    delay(500);
  }
  while (l < 21)
  {
    
    xx = pos_degcoxamaju[l];
    yy = pos_degfemurmaju[l];
    zz = pos_degtibiamaju[l];

    xx_2 = pos_degcoxamaju_2[l];
    yy_2 = pos_degfemurmaju_2[l];
    zz_2 = pos_degtibiamaju_2[l];

    goto_servo_kananmaju(xx, yy, zz);
    goto_servo_kirimaju(xx_2, yy_2, zz_2);
    l++;
    delay(5);
  }
  while (p < 21)
  {
    xx = pos_degcoxamaju[p];
    yy = pos_degfemurmaju[p];
    zz = pos_degtibiamaju[p];

    xx_2 = pos_degcoxamaju_2[p];
    yy_2 = pos_degfemurmaju_2[p];
    zz_2 = pos_degtibiamaju_2[p];

    goto_servo_kananmaju(xx_2, yy_2, zz_2);
    goto_servo_kirimaju(xx, yy, zz);
    p++;
    delay(5);
  }
  l = 0;
  p = 0;
}

void belok_kanan() {
  if (check_initial_belokkanan == 1) {
    goto_kakikananbkanan();
    goto_kakikananbkanan_2();
    goto_kakikiribkanan();
    goto_kakikiribkanan_2();

    xx = pos_homecoxabelok;
    yy = pos_homefemurbelok;
    zz = pos_hometibiabelok;
    

    goto_servo_home_belok(xx, yy, zz);

    check_initial_belokkanan = -1;
    delay(500);
  }
  while (l < 21)
  {
    xx = pos_degcoxabkanan[l];
    yy = pos_degfemurbkanan[l];
    zz = pos_degtibiabkanan[l];

    goto_servo_kananbkanan(xx, yy, zz);
    l++;
    delay(15);
  }
  while (p < 21)
  {
    xx = pos_degcoxakiribkanan[p];
    yy = pos_degfemurkiribkanan[p];
    zz = pos_degtibiakiribkanan[p];

    goto_servo_kiribkanan(xx, yy, zz);
    p++;
    delay(15);
  }
  while (k < 21)
  {
    xx = pos_degcoxabkanan_2[k];
    yy = pos_degfemurbkanan_2[k];
    zz = pos_degtibiabkanan_2[k];

    xx_2 = pos_degcoxakiribkanan_2[k];
    yy_2 = pos_degfemurkiribkanan_2[k];
    zz_2 = pos_degtibiakiribkanan_2[k];

    goto_servo_kiribkanan(xx_2, yy_2, zz_2);
    goto_servo_kananbkanan(xx, yy, zz);
    k++;
    delay(15);
  }
  l = 0;
  p = 0;
  k = 0;
}

void belok_kiri() {
  if (check_initial_belokkiri == 1) {
    goto_kakikananbkiri();
    goto_kakikananbkiri_2();
    goto_kakikiribkiri();
    goto_kakikiribkiri_2();
    

    xx = pos_homecoxabelok;
    yy = pos_homefemurbelok;
    zz = pos_hometibiabelok;

    goto_servo_home_belok(xx, yy, zz);

    check_initial_belokkiri = -1;
    delay(500);
  }
  while (l < 21)
  {
    xx = pos_degcoxabkiri[l];
    yy = pos_degfemurbkiri[l];
    zz = pos_degtibiabkiri[l];

    goto_servo_kananbkiri(xx, yy, zz);
    l++;
    delay(15);
  }
  while (p < 21)
  {
    xx = pos_degcoxakiribkiri[p];
    yy = pos_degfemurkiribkiri[p];
    zz = pos_degtibiakiribkiri[p];

    goto_servo_kiribkiri(xx, yy, zz);
    p++;
    delay(15);
  }
  while (o < 21)
  {
    xx = pos_degcoxakiribkiri_2[o];
    yy = pos_degfemurkiribkiri_2[o];
    zz = pos_degtibiakiribkiri_2[o];

    xx_2 = pos_degcoxabkiri_2[o];
    yy_2 = pos_degfemurbkiri_2[o];
    zz_2 = pos_degtibiabkiri_2[o];

    goto_servo_kananbkiri(xx_2, yy_2, zz_2);
    goto_servo_kiribkiri(xx, yy, zz);
    o++;
    delay(15);
  }
  o = 0;
  l = 0;
  p = 0;
}

void mundur() {
  if (check_initial_mundur == 1) {
    xx = pos_homecoxamajumundur;
    yy = pos_homefemurmajumundur;
    zz = pos_hometibiamajumundur;
    goto_kakikananmundur();
    goto_kakikirimundur();

    goto_kakikananmaju();
    goto_kakikananmaju_2();
    goto_kakikirimaju();
    goto_kakikirimaju_2();
    

    goto_servo_home_majumundur(xx, yy, zz);

    check_initial_mundur = -1;
    delay(500);
  }


  while (l < 21)
  {
    xx = pos_degcoxamundur[l];
    yy = pos_degfemurmundur[l];
    zz = pos_degtibiamundur[l];

    xx_2 = pos_degcoxamundur_2[l];
    yy_2 = pos_degfemurmundur_2[l];
    zz_2 = pos_degtibiamundur_2[l];

    goto_servo_kananmundur(xx, yy, zz);
    goto_servo_kirimundur(xx_2, yy_2, zz_2);
    l++;
    delay(5);
  }
  while (p < 21)
  {
    xx = pos_degcoxamundur[p];
    yy = pos_degfemurmundur[p];
    zz = pos_degtibiamundur[p];

    xx_2 = pos_degcoxamundur_2[p];
    yy_2 = pos_degfemurmundur_2[p];
    zz_2 = pos_degtibiamundur_2[p];

    goto_servo_kananmundur(xx_2, yy_2, zz_2);
    goto_servo_kirimundur(xx, yy, zz);
    p++;
    delay(5);
  }
  l = 0;
  p = 0;
}
