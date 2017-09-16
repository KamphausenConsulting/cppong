![GitHub Logo](/gfx/CPPong512.png)

# CPPong

## Stufe I

* General
  [x] Zeichenfläche 
  * zwei Rechtecke mit Koordinaten (25, 25) und (1450, 325)
  * Kreis in der Mitte des Bildschirms

* Bewegungen
  * Bewegung bei Anklicken des Startbuttons
    * Quadrate, 1x up, 1x dowm
    * Kreis bewegt sich von links nach rechts
    * Quadrate solange seiner Richtung, bis es sich um 500 Pixel von seinem jeweiligen Ausgangspunkt entfernt hat
    * Wird eine Entfernung von 500 Pixeln erreicht, so kehr sich die Bewegungsrichtung des jeweiligen Quadrates um.
    * Bewegung des Kreises setzt sich so lange fort, bis dieser ein Ende des Bildschirms erreicht. 
      Geschieht dies, so beginnt der Kreis seine Bewegung erneut von der Mitte des Bildschirms aus.
    * Geschwindigkeiten
      * 1. Quadrat vier Pixel pro Zeiteinheit 
      * 2- Quadrat acht Pixel pro Zeiteinheit  
      * Kreis sechzehn pro Zeiteinheit 

* Farben & Gestaltung
  * Farben rot, grün, blau
  * Umriss mit einer Linienstärke von drei Pixeln.
  * Buttoms
    * „Start“: setzt alles in Bewegung
    * „Stop“ stoppt alle drei Objekte
    * „Speichern“ speichert die aktuelle Situation 
    * Button „Laden“, Bewegungen werden an der selben Stelle wiederaufgenommen 
    * Gespeichert / geladen muss die gesamte Anwendung werden! 
    Es müssen also alle Objekte an der jeweils letzten Stelle wieder erscheinen und bei den Aufgabenstellungen II bis IV sich ergebende zusätzliche Eigenschaften der Quadrate wieder hergestellt werden.

## Stufe II

* Basisaufgabe wird realisiert wie oben. 
* Zusätzlich springen die Farben alle Objekte, also der Quadrate sowie des Kreises, von „Rot, Grün, Blau“ zu „Grün, Blau, Rot“ sobald sich der Kreis einem der Quadrate auf 100 Pixel annähert und wieder zurück zu „Rot, Grün, Blau“, sobald die Beiden sich wieder weiter als 100 Pixel voneinander entfernen.

## Stufe III

* Zusätzlich: Nähert sich der Kreis einem Quadrat soweit an, dass sie sich berühren würden, kehren diese Beiden ihre Bewegungsrichtung um, bewegen sich also wieder voneinander weg (bis sie wieder miteinander kollidieren).

## Stufe IV

* Der Kreis bewegt sich nichtmehr auf einer horizontalen Bahn über den Bildschirm, sondern ändert seine Laufbahn wenn er mit einem Quadrat kollidiert. Durch das Verwenden der Cosinusfunktion, (http://www.cplusplus.com/reference/cmath/cos/) wird ein Wert generiert, in dessen Winkeln sich der Kreis nun auch auf der Y-Achse durch das Bildschirmfeld bewegt. Erreicht der Kreis dabei den Rand des Bildschirms, so kehrt er seine Y-Bewegung im selben Winkel um. Dadurch kann eine Bewegung wie in der folgenden Skizze entstehen: