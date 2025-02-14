#Pershkrimi i kodit
Ky kod është një program që menaxhon dizajnerët dhe projektet që ata realizojnë, duke përdorur struktura dhe enumeracione për të ruajtur të dhënat dhe statuset e projekteve. Ja përshkrimi i funksionimit të tij:

Struktura e Kodit:
Enumeracioni StatusiProjektit:

Ky enumeracion përdoret për të përfaqësuar statuset e mundshme të një projekti. Ka tre vlera:
I_Nisur (Projekti është nisur)
I_Perkryer (Projekti është përfunduar)
I_Penduar (Projekti është i pezulluar)

Struktura Dizajner:

Kjo strukturë përfaqëson një dizajner dhe ka tri atribute:
id: ID unike për dizajnerin.
emri: Emri i dizajnerit.
pozita: Pozita e dizajnerit (p.sh., Grafik, Web, Produkt).
projekte: Një vektor (listë) që përmban emrat e projekteve që ka realizuar dizajneri.

Funksionet e Programit:

merrStatusinSiTekst: Kjo funksion merr një status të projektit si argument dhe kthen emrin e tij si tekst (p.sh., "I Nisur", "I Perkryer", "I Penduar").
shtoDizajner: Ky funksion shton një dizajner të ri në vektorin dizajneret. Përdor tre parametra: ID-në, emrin dhe pozitat e dizajnerit.
shtoProjekt: Ky funksion shton një projekt për një dizajner të caktuar. Ai merr ID-në e dizajnerit dhe emrin e projektit dhe e shton projektin në listën e projekteve të dizajnerit përkatës.
shfaqDizajneret: Ky funksion shfaq të gjithë dizajnerët dhe projektet që ata kanë realizuar. Ai shfaq gjithashtu ID-në, emrin dhe pozitat e dizajnerëve.
ndryshoStatusinProjektit: Ky funksion ndryshon statusin e një projekti për një dizajner të caktuar. Ai merr ID-në e dizajnerit, emrin e projektit dhe statusin e ri (si I_Perkryer, I_Nisur, ose I_Penduar) dhe i jep informacionin përkatës.

Funksioni Kryesor (main):

Këtu inicializohen disa dizajnerë dhe projekte për ta testuar programin.
Shtohet disa dizajnerë dhe projekte përkatëse dhe më pas shfaqet lista e dizajnerëve me projektet e tyre.
Programi pastaj ndryshon statusin e një projekti të një dizajneri dhe e shfaq përsëri listën e dizajnerëve për të parë ndryshimet.
