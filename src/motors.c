# include <stdlib.h>
# include <stdio.h>

double motor_a8[] = {2,8,12,10,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
double motor_b6[] = {2,8,12,10,7,5,5,5,5,5,0,0,0,0,0,0,0,0,0,0};
double motor_c6[] = {2,8,13,10,8,7,5,5,5,5,5,5,5,5,5,5,5,5,5,5};

char motor_list[] = "\
AeroTech_D10,        AeroTech_D21,      AeroTech_E15_1\n\
AeroTech_E15,        AeroTech_E20,      AeroTech_E30\n\
AeroTech_E6,         AeroTech_F10,      AeroTech_F20\n\
AeroTech_F32,        AeroTech_G125,     AeroTech_G142\n\
AeroTech_G78_1,      AeroTech_G78,      AeroTech_G79\n\
AeroTech_G80_1,      AeroTech_G80_2,    AeroTech_G80_3\n\
AeroTech_G80,        AeroTech_H115,     AeroTech_H125\n\
AeroTech_H135,       AeroTech_H195,     AeroTech_H45\n\
AeroTech_H550,       AeroTech_H55,      AeroTech_H70\n\
AeroTech_I132,       AeroTech_I500,     AeroTech_I65\n\
AeroTech_J125,       AeroTech_K1050,    AeroTech_K250\n\
AeroTech_M1350,      Cesaroni_O25000,   Estes_A8\n\
Estes_B6,            Estes_E12,         Estes_E16\n\
Estes_E30,           Estes_E9,          Estes_F15_1\n\
Estes_F15,           Estes_F5,          Estes_G40_1\n\
Estes_G40,           PML_F50,           PML_G40\n\
PML_G80,             Quest_A3,          Quest_A8\n\
Quest_B4,            Quest_C6,          Quest_D5_1\n\
Quest_D5_2,          Quest_D5,          Quest_D8\n\
Quest_Micro_Maxx_1,  Quest_Micro_Maxx,  RV_E15\n\
RV_F72,              RV_G55";
