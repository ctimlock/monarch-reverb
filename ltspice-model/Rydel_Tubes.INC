
******************
.SUBCKT 6V6GT 1 2 3 4
* Anode G2 G1 Cathode
X1 1 2 3 4 TETRO1 G=.747m MU=494 MU12=8.86 k1=43 k4=5.6 k5=97.8 k6=43.4 K7=50U K8=2 K=0.015m
X2 3 4 Igrid ALPHA=.1m BETA=1U
C1 1 4 7.5p
C2 3 1 .7p
C3 3 4 9p
RF1 1 4 200MEG
RF2 3 4 50MEG
RF3 2 4 100MEG
.ENDS

******************
.SUBCKT 12AT7 1 2 3
* ANODE G CAT
X1 1 2 3 TRIO3 G=1.766m MU=45.3 B=3.92 C=.88 Vc=24.6
X2 2 3 Igrid ALPHA=.04m BETA=.1U
C1 1 2 1.6p
C2 2 3 2.5p
C3 1 3 .45p
RF1 1 3 200MEG
RF2 2 3 50MEG
.ENDS

******************
.SUBCKT 12AU7 1 2 3
* ANODE G CAT
X1 1 2 3 TRIO1 G=.524m MU=15.2 B=49.7 Vc=9.93
X2 2 3 Igrid ALPHA=.04m BETA=.1U
C1 1 2 1.6p
C2 2 3 2.5p
C3 1 3 .45p
RF1 1 3 200MEG
RF2 2 3 50MEG
.ENDS

******************
.SUBCKT 12AX7 1 2 3
* ANODE G CAT
X1 1 2 3 TRIO2 G=1.02m MU=90.6 B=18 Vc=50.7 k=5
X2 2 3 Igrid ALPHA=.01m BETA=.1U
C1 1 2 1.7p
C2 2 3 1.6p
C3 1 3 .46p
RF1 1 3 200MEG
RF2 2 3 50MEG
.ENDS

******************
.SUBCKT GZ34 1 2 3
* A1 A2 C
X1 1 2 3 VALVE1 G=3.924m
.ENDS

**********************
**MODELLI MATEMATICI**
**********************

******************
.SUBCKT TRIO1 A G C
B1 A C I={G}*(1+V(G,C)/({B}-(V(G,C)/1000)))*(V(G,C)+((V(A,C)+{Vc})/{MU}))**1.5
.ENDS

******************
.SUBCKT TRIO2 A G C
B1 A C I={G}*((1+V(G,C)/{B})*(V(G,C)+((V(A,C)+{Vc})/{MU}))**1.5)*(V(A,C)/(V(A,C)+{k}))
.ENDS

******************
.SUBCKT TRIO3 A G C
B1 A C I={G}*(1+(V(G,C)/({B}-(V(G,C)/{C}))))*(V(G,C)+((V(A,C)+{Vc})/{MU}))**1.5
.ENDS

******************
.SUBCKT TETRO1 A G2 G1 C

* Terme d'ecran
B1 10 0 V=IF(V(A,C)>0,(V(G2,C)/{MU12})*(V(A,C)/((V(G2,C)/{k1})+V(A,C))),0)

* Total
B2 11 0 V={G}*(V(G1,C)+V(10,0)+(V(A,C)/{MU}))**1.5

* Rajout de la caracteristique de saturation a faible tension
B3 A C I=IF(({K7}*(V(A,C)**{K8}))>V(11,0),V(11,0),IF(V(A,C)>0,({K7}*(V(A,C)**{K8})),0))

* Calcul du courant d'ecran
B6 12 0 V=IF(V(G2,C)>0,(V(G1,C)+(V(G2,C)/{k4})),0)
B7 G2 C I={K}*(V(12,0)**1.5)*((V(A,C)+{k5})/(V(A,C)+{k6}))**3
.ENDS

******************
.SUBCKT TETRO2 A G2 G1 C

* Terme d'ecran
B1 10 0 V=IF(V(A,C)>0,(V(G2,C)/{MU12})*(V(A,C)-({k3}*V(G1,C)))/((V(G2,C)/{k1})+V(A,C)),0)

* Total
B2 11 0 V={G}*((V(G1,C)+V(10,0))+(V(A,C)/({MU}*(1-(V(G1,C)/{k2})))))**1.5

* Rajout de la caracteristique de saturation a faible tension
B3 A C I=IF(({K7}*(V(A,C)**{K8}))>V(11,0),V(11,0),IF(V(A,C)>0,({K7}*(V(A,C)**{K8})),0))

* Calcul du courant d'ecran
B6 12 0 V=IF(V(G2,C)>0,(V(G1,C)+(V(G2,C)/{k4})),0)
B7 G2 C I={K}*(V(12,0)**1.5)*((V(A,C)+{k5})/(V(A,C)+{k6}))**3
.ENDS

******************
.SUBCKT PENTH1 A G2 G1 C

* Terme d'ecran
B1 10 0 V=IF(V(A,C)>0,(V(G2,C)/{MU12})*(V(A,C)-({k3}*V(G1,C)))/((V(G2,C)/{k1})+V(A,C)),0)

* Total
B2 A C I={G}*((V(G1,C)+V(10,0))+(V(A,C)/({MU}*(1-(V(G1,C)/{k2})))))**1.5

* Calcul du courant d'ecran
B6 12 0 V=IF(V(G2,C)>0,(V(G1,C)+(V(G2,C)/{k4})),0)
B7 G2 C I={K}*(V(12,0)**1.5)*((V(A,C)+{k5})/(V(A,C)+{k6}))**3
.ENDS

******************

.SUBCKT Heater F1 F2
.param VNOM=6.3 INOM=300m
Grms  1  0  VALUE={1E-3*(V(f2,f1))*(V(f2,f1))/(VNOM*VNOM)}
Rt    1  0  1k
Ct    1  0  9.94m
Gf   f2 f1  VALUE={V(f2,f1)*1.16*INOM/(VNOM*(PWR(V(1),0.3)+0.16))}
.ENDS Heater

******************
.SUBCKT Igrid G1 C
* Courant grille
B4 6 0 V=IF(V(G1,C)>0,{ALPHA}*V(G1,C)**1.5,{BETA}/-(V(G1,C)-.1))
B5 G1 C I=V(6,0)
.ENDS

******************
.SUBCKT VALVE1 A1 A2 C
B1 1 0 V=IF(V(A1,C)>0,{G}*(V(A1,C)),0)
B2 2 0 V=IF(V(A2,C)>0,{G}*(V(A2,C)),0)
B3 A1 C I=V(1,0)**1.5
B4 A2 C I=V(2,0)**1.5
R1 C 0 1MEG
.ENDS
