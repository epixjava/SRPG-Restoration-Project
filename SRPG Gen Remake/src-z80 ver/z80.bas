Check A7036A9F
Auto 1

# Run-time Variables

Var y: Num = 13
Var a: Num = 1

# End Run-time Variables

   1 CLS
  10 LOAD ""SCREEN$
  20 PAUSE 0:
  30 GO TO 50
  50 LET d=0: CLS
  70 LET s=100
  80 LET m=50
  90 LET a=100: LET y=50
 100 CLS
 110 IF s<1 AND a>0 THEN GO TO 600
 120 IF s>0 AND a<1 THEN GO TO 700
 130 IF s<1 AND a<1 THEN GO TO 800
 140 PRINT "PV SONIC  :",s:
 150 PRINT "PM SONIC  :",m:
 160 PRINT "PV SHADOW :",a: PRINT "PM SHADOW :",y:
 170 PRINT "1-Attaquer": PRINT "2-Se defendre": PRINT "3-Spin Dash 20MP": PRINT "4-Soin ":
 180 INPUT "Quelle attaque veut-tu choisir";c:
 190 IF c=1 THEN GO TO 230
 200 IF c=2 THEN GO TO 310
 210 IF c=3 AND m>19 THEN GO TO 410
 220 IF c=4 AND m>9 THEN GO TO 500
 221 IF c>4 THEN GO TO 100: IF c<1 THEN GO TO 100
 230 CLS : PRINT "Vous avez choisi l'attaque": PRINT "": PRINT "Sonic attaque Shadow"
 240 LET a=a-10:
 250 PRINT "Shadow perd 10 PV"
 251 IF a>25 AND y<20 THEN GO TO 2000
 252 IF a<26 AND y>9 THEN GO TO 3000
 253 IF a>25 AND y>19 THEN GO TO 5000
 270 GO TO 100
 310 CLS : PRINT "Vous avez choisi la defense": PRINT "": PRINT "Shadow attaque Sonic":
 320 LET s=s-6:
 330 PRINT "Sonic perd 6 PV":
 340 LET m=m+10:
 350 PRINT "Sonic gagne 10 PM":
 360 INPUT "Appuyez sur 1 pour Continuer";d:
 370 GO TO 100
 410 CLS : PRINT "Vous avez choisi d'utiliser SPIN DASH": PRINT "": LET m=m-20: PRINT "Sonic utilise SPIN DASH contre Shadow"
 420 LET a=a-27:
 430 PRINT "Shadow perd 27 PV"
 440 IF a>25 AND y<20 THEN GO TO 2000
 441 IF a<26 AND y>9 THEN GO TO 3000
 442 IF a>25 AND y>19 THEN GO TO 5000
 450 INPUT "Appuyez sur 1 pour Continuer";d:
 460 GO TO 100
 500 CLS : PRINT "Vous avez choisi d'utiliser Soin": PRINT "": LET m=m-10: PRINT "Sonic utilise Soin"
 510 LET s=s+30:
 520 PRINT "Sonic guerit de 30 PV"
 521 IF a>25 AND y<20 THEN GO TO 2000
 522 IF a<26 AND y>9 THEN GO TO 3000
 523 IF a>25 AND y>19 THEN GO TO 5000
 540 INPUT "Appuyez sur 1 pour Continuer";d:
 550 GO TO 100
 600 CLS : PRINT "Shadow gagne la partie !"
 610 INPUT "Voulez-vous recommencer 1=Oui 2=Non";d:
 620 IF d=1 THEN GO TO 50: IF d=2 THEN GO TO 1
 630 GO TO 600
 700 CLS : PRINT "Sonic gagne la partie !"
 710 INPUT "Voulez-vous recommencer 1=Oui 2=Non";d:
 720 IF d=1 THEN GO TO 50: IF d=2 THEN GO TO 1
 730 GO TO 700
 800 CLS : PRINT "Egalite !"
 810 INPUT "Voulez-vous recommencer 1=Oui 2=Non";d:
 820 IF d=1 THEN GO TO 50: IF d=2 THEN GO TO 1
 830 GO TO 800
2000 PRINT "Shadow attaque Sonic"
2010 LET s=s-10:
2020 PRINT "Sonic perd 25 PV"
2030 PRINT "Appuyez sur Entrer pour Continuer": PAUSE 0: GO TO 100:
2040 GO TO 2000
3000 PRINT "Shadow utilise SOIN"
3010 LET a=a+30: LET y=y-10
3020 PRINT "Shadow recupere des PV"
3030 PRINT "Appuyez sur Entrer pour Continuer": PAUSE 0: GO TO 100:
3040 GO TO 3000
4000 PRINT "Shadow attaque Sonic"
4010 LET s=s-6:
4020 PRINT "Sonic perd 6 PV"
4030 PRINT "Appuyez sur Entrer pour Continuer": PAUSE 0: GO TO 100:
4040 GO TO 4000
5000 PRINT "Shadow utilise Chaos Control"
5010 LET s=s-25: LET y=y-20
5020 PRINT "Sonic perd 12 PV"
5030 PRINT "Appuyez sur Entrer pour Continuer": PAUSE 0: GO TO 100:
5040 GO TO 5000
