const int bouton = 1; // le bouton est connecté à la broche 1 de la carte Adruino
const int relais_pompe = 2; // // le relais est connecté à la broche 2 de la carte Adruino
int etatBouton;
void setup()
{
pinMode(bouton, INPUT);
pinMode(relais_pompe, OUTPUT);
}

void loop()
{
etatBouton = digitalRead(bouton);
if (etatBouton == 0) // We press the button
{
digitalWrite(relais_pompe, HIGH); // the water pump fills the bottle
}
else // we release the button
{
digitalWrite(relais_pompe, LOW); // the water pump stops
}
}
