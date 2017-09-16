![GitHub Logo](/gfx/CPPong128.png)

# CPPong

## Stufe I

- General
  - [x] Zeichenfläche 
  - [x] zwei Rechtecke mit Koordinaten (25, 25) und (1450, 325)
    - *Koordinaten leicht angepasst, Ansicht lässt sich zudem zoomen*
  - [x] Kreis in der Mitte des Bildschirms

- [x] Bewegungen
  - [x] Bewegung bei Anklicken des Startbuttons
    - [x] Quadrate, 1x up, 1x down
    - [x] Kreis bewegt sich von links nach rechts
    - [x] Quadrate solange seiner Richtung, bis es sich um 500 Pixel von seinem jeweiligen Ausgangspunkt entfernt hat
    - [x] Wird eine Entfernung von 500 Pixeln erreicht, so kehr sich die Bewegungsrichtung des jeweiligen Quadrates um.
      - *Anstelle einer Annäherung dient das Spielfeld-Objekt als Begrenzung. Alle Objekte prallen davon ab.*
    - [x] Bewegung des Kreises setzt sich so lange fort, bis dieser ein Ende des Bildschirms erreicht. 
      Geschieht dies, so beginnt der Kreis seine Bewegung erneut von der Mitte des Bildschirms aus.
    - [x] Geschwindigkeiten
      - [x] 1. Quadrat vier Pixel pro Zeiteinheit 
        - *Zeit angepasst*
      - [x] 2- Quadrat acht Pixel pro Zeiteinheit  
        - *Zeit angepasst*
      - [x] Kreis sechzehn pro Zeiteinheit 
        - *Zeit angepasst*

- [x] Farben & Gestaltung
  - [x] Farben rot, grün, blau
  - [x] Umriss mit einer Linienstärke von drei Pixeln.
    - *Pixel angepasst.*
  - [x] Buttoms
    - [x] „Start“: setzt alles in Bewegung
      - *„START“*
    - [x] „Stop“ stoppt alle drei Objekte
      - *„STOP“*
    - [x] „Speichern“ speichert die aktuelle Situation
      - *„SAVE“* 
    - [x] Button „Laden“, Bewegungen werden an der selben Stelle wiederaufgenommen 
      - *„LOAD“*
    - [x] Gespeichert / geladen muss die gesamte Anwendung werden! 
    Es müssen also alle Objekte an der jeweils letzten Stelle wieder erscheinen und bei den Aufgabenstellungen II bis IV sich ergebende zusätzliche Eigenschaften der Quadrate wieder hergestellt werden.
      - *Alle Einstellungen, sowie alle vorgenommenen Abweichungen von der Aufgabenstellung werden gespeichert und geladen. Die App nutzt den Desktop als Speicherort.*


## Stufe II

- [x] Basisaufgabe wird realisiert wie oben. 
- [x] Farben wechseln von „Rot, Grün, Blau“ zu „Grün, Blau, Rot“, wenn sich Kreis Quadrat auf 100px annähert 
- [x] Farben wechseln wieder zurück zu, sobald die Beiden sich wieder weiter als 100 Pixel voneinander entfernen.
  - *Farben wechseln jeweils beim Kollidieren des Balls mit einem der Rechtecke.*


## Stufe III

- [x] Stufe II wird realisiert wie oben.
- [x] Zusätzlich: Nähert sich der Kreis einem Quadrat soweit an, dass sie sich berühren würden, kehren diese Beiden ihre Bewegungsrichtung um, bewegen sich also wieder voneinander weg (bis sie wieder miteinander kollidieren).


## Stufe IV

- [x] Stufe III wird realisiert wie oben.
- [x] Der Kreis bewegt sich nichtmehr auf einer horizontalen Bahn über den Bildschirm, sondern ändert seine Laufbahn wenn er mit einem Quadrat kollidiert. 
  - *Der Kreis bewegt sich zunächst gerade und prallt beim ersten Kontakt in einem zufälligen Winkel vom entsprechenden Rechteck ab.*
- [ ] Durch das Verwenden der Cosinusfunktion, (http://www.cplusplus.com/reference/cmath/cos/) wird ein Wert generiert, in dessen Winkeln sich der Kreis nun auch auf der Y-Achse durch das Bildschirmfeld bewegt. 
- [x] Erreicht der Kreis dabei den Rand des Bildschirms, so kehrt er seine Y-Bewegung im selben Winkel um. 
- *Jeder Kontakt mit einem Rechteck oder dem oberen/unteren Spielfeldrand*




