---
bibliography:
- LiteraturVerzeichnis/Literatur.bib
---

Hochschule für Technik und Wirtschaft - Berlin **Fachbereich 2\
Ingenieurwissenschaften - Technik und Leben\
im Studiengang Ingenieurinformatik**

        

**Technische Dokumentation**\

        

Einrichtung von OPC UA mit open62541\
auf einem Raspberry Pi 4\

        

Dieses Dokument dient als Anhang einer Bachelor Arbeit,\
unterliegt allerdings nicht dessen Sperrvermerk

̄ **Thema:** Umsetzung der digitalen Durchgängigkeit\
im Product Lifecycle Management (PLM)\
mittels MBSE und OPC UA

̄ **Autor:** Klemens Körner

̄ **Version vom:** .2021

Einleitung {#sec:einleitung}
==========

Diese Technische Dokumentation dient als Anleitung zur Einrichtung eines
OPC UA Servers auf einem Raspberry Pi4. Als Basis dient hierbei die Open
Source-Variante von OPC UA open62541. Um das Verständnis dieser
Dokumentation zu erhöhen, wird emp-fohlen, die dazugehörige
Bachelor-Arbeit zu lesen. Dort werden sehr viele Informationen aus den
Übungen von https://opcua.rocks/ verarbeitet. Diese Seite bietet
ausführliche Informationen zu open62541 und den Arbeiten mit offiziellen
Informationsmodellen der OPC UA Fundation Als Grundvoraussetzung wird
folgendes gesetzt:

-   Raspberry Pi4 mit 2GB Ram

-   Unified Automation UA Expert
    (www.unified-automation.com/products/development-tools.html)

-   Unified Automation UA Modeler
    (www.unified-automation.com/products/development-tools.html)

-   FreeOpcUA Modeler (github.com/FreeOpcUa/opcua-modeler)

-   Raspberry Pi Imager (www.raspberrypi.org/software/)

-   Für Windows Putty als SSH Client (https://www.putty.org/)

-   Cyberduck, um Zugriff via SSH auf Datei-System zu bekommen
    (https://cyberduck.io/download/)

Einrichtung des Raspberry Pi {#sec:raspiEin}
============================

Als ersten Schritt wollen wir den Raspberry Pi einrichten. Hierfür wird
mit dem Raspberry Pi Imager das aktuelle Raspberry OS (nicht Lite oder
Full) auf die SD Karte geschrieben (). Wenn ein schon vorhandener
Raspberry benutzt wird, kann man im Kapitel 3 fortfahren. Da ab Kapitel
3 nur noch mit dem Terminal gearbeitet wird, kann man auch mit der OS
Lite Version ohne Desktop fortfahren.

![Raspberry Pi Imager](abb/RaspberryPiImager.png){#fig:raspberrypiimager
width="0.7\\linewidth"}

Danach kann man die SD Karte in den Raspberry Pi einsetzen und ihn an
einen Monitor, eine Tastatur, eine Maus anschließen und ihn schließlich
mittels eines USB C-Netzkabels mit Spannung versorgen.

Voreinstellungen
----------------

Nach dem Start wird man durch ein kleines Wizard geführt, um diverse
Einstellungen der Sprache und Lokalisierung, das Standard-Passwort des
Nutzers pi, Bildschirm und Wlan zu ändern. Falls es nach dem Wizard zu
einem Fehler kommt oder das Tastatur-Layout nicht stimmt, kann man dies
nach dem Neustart in den OS-Einstellungen ändern oder natürlich auch das
Wizard beenden und die Einstellungen manuell durchführen.

Update und Upgrade
------------------

Nun wechseln wir im OS in das Terminal und geben den Befehl

``` {.Bash language="Bash"}
sudo apt update  #die Quellen des Paketmanagers aktualisieren
sudo apt upgrade #installierte Pakete auf den aktuellen Stand setzen
#Gegebenenfalls muss man das Installieren der Pakete mit Y Enter bestätigen
```

OPC UA Nutzer und Hostname anpassen
-----------------------------------

Da es grundsätzlich nie ideal ist, auf einem bestehenden System bekannte
Nutzer für den Zugriff von außen zu haben, benötigen wir einen neuen
Benutzer. Außerdem wollen wir den hostname des Raspberry an unsere
Bedürfnisse anpassen, da dieser für das Auffin-den von Geräten im
Netzwerk nützlich ist. Hostname ändern:

``` {.Bash language="Bash"}
hostname #abrufen des aktuellen hostname
sudo hostname -b {neuerName} #ändern des hostname
hostname #prüfen, ob Änderung erfolgreich
sudo grep -lr „{alter hostname}” /etc/* #prüfen, ob der alte Host noch in anderen Konfiguratonsdateien verzeichnet ist

sudo nano /etc/{Dateiname}
#nach dem hostname suchen, ändern und mit ctrl x speichern, hier da-rauf achten, dass man keine Dateien ändern muss, wo in der Zeichenkette der hostname auftaucht(Bsp. raspi.list, hier findet man http.//archive.raspberrypi.org/debian/ das natürlich nicht ändern)
Außerdem muss man nicht die Keys von SSH ändern, diese erstellen wir gleich neu mit folgenden Befehlen

sudo rm /etc/ssh/ssh_host_* #alte Keys löschen
sudo dpkg-reconfigure openssh-server #neue Keys erstellen

sudo reboot #System-Neustart
```

Benutzer hinzufügen und Pi-Benutzer löschen:

``` {.Bash language="Bash"}
#Nutzer hinzufügen
sudo adduser {USERNAME}
#Nutzer-Rechte hinzufügen, am wichtigsten ist sudo
sudo usermod -a -G adm,dialout,cdrom,sudo,ssh,audio,video,plugdev,games,users,input,netdev,gpio,i2c,spi {USERNAME}
#Testen, ob man sich mit dem neuen User als Superuser einloggen kann
sudo su – {USERNAME}
#den pi-Nutzer löschen
sudo pkill -u pi
#Nicht wundern, da wir im Desktop als PI-Nutzer eingeloggt sind und diesen gerade löschten, werden wir abgemeldet und gefragt, ob wir uns als {USERNAME} Nutzer einloggen wollen
```

SSH
---

Damit wir einen Fernzugriff auf den Raspberry bekommen, benötigen wir
SSH. Dies können wir im Terminal mit folgenden Befehlen aktivieren.

``` {.Bash language="Bash"}
sudo systemctl start ssh #ssh starten
sudo systemctl enable ssh #ssh Autostart nach dem boot Vorgang

systemctl status ssh #Status abfragen
systemctl is-enabled ssh #abfragen, ob Autostart aktiviert

ifconfig #damit sieht man die Einstellungen der Netzwerk Adpater, um sich für später die IP-Adresse (inet) des wlan0-Adpaters zu merken.
```

Nun können wir mit einem SSH Client auf den Raspberry zugreifen mit

``` {.Bash language="Bash"}
ssh {NUTZERNAME}@{IPADRESSE}
```

Sicherheit
----------

Da davon ausgegangen wird, dass der Raspberry zunächst im lokalen Netz
betrieben wird und wir während des Prototypings noch keine erhöhte
Sicherheit benötigen, werden keine weiteren Sicherheitseinstellungen
vorgenommen. Da aber später möglicherweise eine erhöhte Sicherheit
benötigt wird, wird hiermit auf die offizielle Seite von mit einer
kleinen Guideline zu den Sicherheitseinstellungen, Firewall, SSH, Nutzer
usw. verwiesen.

Open62541 SDK am Raspberry kompilieren
======================================

Die folgenden benötigten Pakete müssen auf dem Raspberry installiert
werden. Einige Pakete sind bereits vorinstalliert.

``` {.Bash language="Bash"}
sudo apt install git build-essential gcc pkg-config cmake python

# Nützliche Extra-Pakete
sudo apt install cmake-curses-gui # ccmake UI
sudo apt install libmbedtls-dev # Verschlüsselungs-Optionen
sudo apt install check libsubunit-dev # unit tests
sudo apt install python-sphinx graphviz #für Dokumentationen
sudo apt install python-sphinx-rtd-theme # Dokumentstyle-Erweiterung
```

Download des Source Codes

``` {.Bash language="Bash"}
#Repository Clone
git clone https://github.com/open62541/open62541.git ~/open62541
#Gehen in den Ordner
cd ~/open62541 #Submodule Laden
git submodule update --init --recursive
```

Kompilierung vorbereiten mit CCmake

``` {.Bash language="Bash"}
#Pfad erstellen und in Pfad gehen
mkdir ~/open62541/build && cd ~/open62541/build
#Öffne ccmake UI aus den Informationen im unteren Pfad
ccmake ..
```

Nun öffnet sich die UI. In dieser betätigen wir zunächst die Taste „c",
um die Konfigurations-Seite zu öffnen. Wie in zu sehen, ändern wir den
CMAKE_BUILD_TYPE gegen RelWithDebInfo (Release Version mit
Debug-Informationen), das CMAKE_INSTALL_PREFIX gegen den
Installationspfad und den UA_NAMESPACE_ZERO gegen FULL (Volle „namespace
zero"-Erstellung von den offizellen XML-Definitionen.) . Nachdem wir
fertig sind, beenden wir die Einstellungen mit der Taste „c" und
erstellen ein make file mit der Taste „g". Danach bauen wir den Code mit
dem Befehl

``` {.Bash language="Bash"}
make -j #das kann einige Zeit dauern
make install #den Build ins vorher gesetzte Installationsverzeichnis verschieben
```

![ccmake-Einstellungen](abb/Build_Open62541.png){#fig:buildopen62541
width="0.6\\linewidth"}

Erster Server mit OPC UA als Test
---------------------------------

Nun wollen testen, ob alles funktioniert. Deshalb kopieren wir uns ein
Beispiel eines Ser-vers und erstellen daraus einen lauffähigen Server
auf dem Raspberry

``` {.Bash language="Bash"}
mkdir ~/firstTest-Server
cp ~/open62541/examples/tutorial_server_firststeps.c ~/firstTestServer/firstTestServer.c
cd ~/firstTestServer/

#Bauen des TestServers
gcc -std=c99 -flto=1 -I$HOME/install/include -L$HOME/install/lib firstTestServer.c -lopen62541 -lmbedtls -lmbedx509 -lmbedcrypto -o firstTestServer
```

Dies kann über eine Stunde dauern. Was wurde im gcc-Befehl gemacht:

-   std=c99 gcc benutzt den C99-Kompilierer

-   flto=1 limitiert die parallel ablaufenden Linking-Jobs auf 1

-   -IPFAD fügt den vorhin gebauten Include-Pfad hinzu

-   -LPFAD fügt den vorhin gebauten Library-Pfad hinzu

-   \$Home Verweis auf das home-Verzeichnis des aktuellen Nutzers
    ähnlich wie  / nur universeller einsetzbar.

-   firstTest-Server.c C-Datei, die gebaut werden soll

-   -lopen62541 open62541 Library

-   -lmbedtls -lmbedx509 -lmbedcrypto für Kryptographie

-   -o firstTestServer Ausgabe-Datei

Test-Server mit Client verbinden
--------------------------------

Nun können wir den Server testen, indem wir die gerade erstellte Datei
ausführen

``` {.Bash language="Bash"}
./firstTestServer
```

![Terminal-Ausgabe nach dem Start des OPC
UA-Servers](abb/TerminaNachServerStart.png){#fig:terminanachserverstart
width="1\\linewidth"}

In sieht man den Server, der sich gestartet hat sowie die Adresse mit
Port, unter der er erreichbar ist. Nun starten wir auf unserem Computer
die Software UA Expert und fügen, wie in zu sehen ist, den gerade
gestarteten Server hinzu.

![Erster Start UA Expert](abb/UA_ExpertClient.png){#fig:uaexpertclient
width="1\\linewidth"}

Danach sieht man in die Datenstruktur des erstellten Test-Servers wie in

![Daten-Struktur Test-Server in UA
Expert](abb/UA_Expert_Strukt.png){#fig:uaexpertstrukt
width="0.6\\linewidth"}

Informationsmodellierung eines OPC UA-Servers
=============================================

Nachdem jetzt die Grundlagen geschaffen sind, einen lauffähigen OPC
UA-Server zu erstellen, wird in diesem Kapitel erklärt, wie man mit
Hilfe des FreeOpcUa Modeler ein UANodeSet.xml für seine Server-Struktur
erstellt. Dies wird im nächsten Kapitel benö-tigt, um einen Server mit
einem eigenen Nodeset zu bauen. Eine detaillierte Erklärung zu
Informationsmodellen und auch noch andere Wege zur Erstellung seiner
Informationsmodelle findet man unter

FreeOpcUa Modeler
-----------------

Das Programm können wir entweder direkt auf dem Raspberry installieren
und ausführen oder auch auf dem Projekt-Rechner. Nachdem wir diesen
gestartet haben, läuft im Hintergrund auch schon automatisch ein OPC
UA-Server, mit dem man sich verbinden kann. Dieser Server läuft auf dem
Open Source Projekt FreeOPC UA. Es soll auch möglich sein, hier direkt
einen open62541-Server anzusprechen. Da wir dies in unserem Beispiel
nicht benötigten, wurde das nicht getestet. Ein Blick nach dem Start im
Terminal zeigt auch hier die generierte opc-Adresse mit Port, wie in zu
sehen. 0.0.0.0 bedeutet, dass dieser am local Host erreichbar ist. Um
sich also mit ihm über einen anderen Rechner im Netzwerk zu verbinden,
wird die IP-Adresse des Netzwerk-Adapters benötigt!

![Start FreeOpcUa Modeler](abb/FreeOPCUA.png){#fig:freeopcua
width="1\\linewidth"}

Nun beginnen wir mit der Modellierung eines einfachen Beispiels: Wir
haben einen Motor, der über das Datenmodell ansteuerbar sein und seinen
Status anzeigen soll. Es kann auch sein, dass noch ein Motor hinzukommt.
Als erstes benötigen wir einen Namespace, wo wir diese Typen, Objekte
später zuordnen. Wie in zu sehen, wurde der Namespace 1 mit
http.//motoren.test/UA/ er-stellt.

![Namespace erstellen](abb/AddNamespace.png){#fig:addnamespace
width="1\\linewidth"}

Da es also sein kann, dass wir mehrere Motoren benötigen, erstellen wir
als Erstes einen Motor-Typ, der ein Objekt eines Motors darstellt und
beliebig oft als Objekt wiederverwendet werden kann. In ist der Ablauf
einer Objekt-Typ-Erstellung zu sehen.

![Objekt-Typ anlegen](abb/ObjectTypAnlegen.png){#fig:objecttypanlegen
width="1\\linewidth"}

Nun werden dem Objekt-Typ die nötigen Informationen gegeben. Im Beispiel
wurden 3 Variablen erstellt, die der Nutzer nur lesen kann (Speed,
Running, Direction) und 2 Methoden Control mit Eingangs- und
Ausgangs-Variablen und Emergency Stop ohne Variablen, wie in zu sehen.

![Erweitern der Informationen des
Motor-Typs](abb/ERweitertMotorTy.png){#fig:erweitertmotorty
width="1\\linewidth"}

Im nächsten Schritt wird aus dem erstellten Typ ein Objekt erstellt ().

![Erstellen eines Objekts aus einem
Objekt-Typ](abb/AddObject.png){#fig:addobject width="1\\linewidth"}

Und schon kann im UA Expert Client die Struktur validiert werden, wie
zeigt.

![UA Expert Aufruf einer
Methode](abb/CallMethodeUAExpert.png){#fig:callmethodeuaexpert
width="1\\linewidth"}

Natürlich führt der Aufruf einer Methode, wie auch zu sehen ist, noch zu
einem Fehler, da noch keine Logik in den Methoden steckt. Nun wird das
Projekt noch abgespeichert, wodurch sich auch das benötigte UANodeSet
File als XML Datei generiert.()

![Auszug aus der gespeicherten xml](abb/NodesetXML.png){#fig:nodesetxml
width="0.8\\linewidth"}

Anmerkung: Es ist nicht nötig, hier schon Objekte anzulegen, denn diese
kann man auch später erstellen. Wenn man allerdings schon weiß, was man
braucht, ist es nützlich, diese gleich zu modellieren. Des Weiteren ist
es ebenso möglich, aus einem Typ Objekt-Varianten zu erstellen, wenn man
z.B. danach noch Variablen hinzufügt, um einzelne Objekte zu
spezialisieren.

Aus einem UANodeSet.xml den Source-Code erstellen
=================================================

Im Grunde ist dies recht einfach, da im Git Reprository von open62541
ein python skript hinterlegt ist, das die ganze Arbeit erledigt. Dies
kann man also auch direkt am Raspberry erledigen oder auch auf seinem
Projekt-Computer. Hierfür muss nun das Skript mit folgenden Zusätzen
ausgeführt werden.

``` {.Bash language="Bash"}
python ~/open62541/tools/nodeset_compiler/nodeset_compiler.py 
--types-array=UA_TYPES --existing ~/open62541/deps/ua-nodeset/Schema/Opc.Ua.NodeSet2.xml --xml MotorSteuerungNodeSet.xml MotorSteuerung
```

Kurze Erklärung zu den einzelnen Zusätzen

``` {.Bash language="Bash"}
# python skript, das ausgeführt werden muss
python ~/open62541/tools/nodeset_compiler/nodeset_compiler.py
# als was sollen die Typen exportiert werden
--types-array=UA_TYPES
# auf welchem Schema baut das Ganze auf
--existing ~/open62541/deps/ua-nodeset/Schema/Opc.Ua.NodeSet2.xml
#Pfad zum erstellten NodeSet2.xml
--xml MotorSteuerungNodeSet.xml
#Ausgabe-Name, aus diesem werden dann die benötigte c- und h-Datei erstellt
MotorSteuerung
```

Wenn das Ganze erfolgreich war, sollte es wie in aussehen. Im oberen
Teil sieht man die Ausgabe des Skripts, im unteren Teil die im Ordner
erstellten c- und h-Dateien.

![Erfolgreiche Erstellung des Source
Codes](abb/ErfolgSource.png){#fig:erfolgsource width="1\\linewidth"}

Erstellen der Main-Methode und erster Server -Test
==================================================

In dem vorhergehenden Kapitel wurde der Source Code aus einem
Informationsmodell erstellt. Nun wollen wir das Ganze durch das
Erstellen einer Main-Methode ergänzen, die als Startpunkt für den Server
dient. Dazu erstellen wir in einem beliebigen Editor mit fol-gendem
Inhalt eine main.c-Datei und speichern diese bei unserem Source Code ab.

``` {.Bash language="Bash"}
#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>
#include <open62541/server_config_default.h>
#include <signal.h>
#include <stdlib.h>
#include "MotorSteuerung.h"

UA_Boolean running = true;


static void stopHandler(int sign) {
	UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "received ctrl-c");
	running = false;
}

int main(int argc, char** argv) {
	signal(SIGINT, stopHandler);
	signal(SIGTERM, stopHandler);
	
	UA_Server *server = UA_Server_new();
	UA_ServerConfig_setDefault(UA_Server_getConfig(server));
	UA_StatusCode retval;
	/* create nodes from nodeset */
	if(MotorSteuerung(server) != UA_STATUSCODE_GOOD) {
		UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_SERVER,
		"Could not add the MotorSteuerung nodeset. "
		"Check previous output for any error.");
		retval = UA_STATUSCODE_BADUNEXPECTEDERROR;
	} else {
		// Do some additional stuff with the nodes
		// this will just get the namespace index,
		//since it is already added to the server
		UA_UInt16 nsIdx = UA_Server_addNamespace(server, "http://helloWorld.com/UA/");
		// UA_MOTOR1_RUNNING_BOOL = 2010
		UA_NodeId testInstanceId = UA_NODEID_NUMERIC(nsIdx, 2010);
		UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER,
		"Motor1 Bool Running is in ns=%d;id=%d",
		testInstanceId.namespaceIndex, testInstanceId.identifier.numeric);
		retval = UA_Server_run(server, &running);
	}
	UA_Server_delete(server);
	return retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE;
```

Wie man erkennen kann, wird in der Main-Methode ein Server-Objekt mit
den Standard- Einstellungen erstellt. Die Variable retval dient dazu,
nach dem Beenden den Staus-Code des Servers zurückzugeben, als ob der
Server wegen eines Fehlers beendet oder absicht-lich beendet wurde.
Danach fragen wir in einem If-Block ab, ob das Erstellen des neuen
MotorSteuerung No-deBlocks erfolgreich war. Wenn nicht, geben wir im Log
einen Fehler aus. Wenn das erfolgreich war, können wir entweder gleich
zur Zeile mit US_server_run übergehen, oder aber - wie in unserem Fall -
wollen wir prüfen, ob eine Node-ID korrekt abgerufen wird. Dies wird in
den Log File ausgegeben. Nun können wir wieder mit unserem leicht
abgeänderten gcc-Befehl den Server-Code bauen.

``` {.Bash language="Bash"}
gcc -std=c99 -flto=1 -I$HOME/install/include -L$HOME/install/lib main.c MotorSteuerung.c -lopen62541 -lmbedtls -lmbedx509 -lmbedcrypto -o MotorSteuerung
```

Augenmerk sollte hier auf das Hinzufügen der main.c und der
implementierten Klassen in diese MotorSteuerung.c gelegt werden. Nachdem
der Server erstellt wurde, können wir ihn nun mit

``` {.Bash language="Bash"}
./MotorSteuerung
```

starten und prüfen, ob im Log auch unsere Abfrage der Node-ID ausgegeben
wird. ())

![Log Ausgabe der abgefragten
Node-ID](abb/ServerRunMotor.png){#fig:serverrunmotor
width="1\\linewidth"}

Wenn ja, können wir noch prüfen, ob im UA Expert Client alles
erwartungsgemäß angezeigt wird

Methoden und Variable mit Logic verbinden
=========================================

Nachdem nun ein funktionierender Server-Code vorliegt, wird mit dem
Anlegen der Lo-gic für Variable und Methoden begonnen.

Ändern der Server-Laufzeit-Routine
----------------------------------

Derzeit wird der Server mit

``` {.Bash language="Bash"}
UA_Server_run(server, &running);
```

gestartet. Dieser Aufruf wird solange durchgeführt, bis die Variable
running auf false gesetzt wird. Aus diesem Grund konnten wir keine
Variablen während der Laufzeit schreiben. Dies ändern wir, indem wir
diese Zeile aus der main.c entfernen und den Code mit Folgendem
erweitern.

``` {.Bash language="Bash"}
retval = UA_Server_run_startup(server);
//https://open62541.org/doc/current/server.html#server-lifecycle
if(retval != UA_STATUSCODE_GOOD) {
	UA_Server_delete(server);
	return retval;
}
while(running == true)
{
	//Server Routine
	//https://open62541.org/doc/current/server.html#server-lifecycle
	UA_Server_run_iterate(server, true);
}

return retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE;
```

Hier sieht man, dass wir dem Server zunächst die Startup-Routine
durchlaufen lassen, prüfen, ob dies erfolgreich war und dann eine
while-Schleife starten, in der wir bei jedem Durchlauf einmal die
Server-Routine durchlaufen.

Variable
--------

Um nun z.B. in der while-Schleife jede Sekunde den speed um 1 zu erhöhen
und alle 5 Sekunden den Zustand des bool running zu ändern, ergänzen wir
den Code folgendermaßen. Wichtig: Hierfür muss noch \#include \<time.h\>
hinzugefügt werden.

``` {.Bash language="Bash"}
int timestampM1Running = time(0) + 2;
int timestampM1Speed = time(0) + 1;
//https://open62541.org/doc/current/types.html
UA_Boolean m1running = false;
UA_Int16 m1speed = 0;
while(running == true)
{
	//Server Routine https://open62541.org/doc/current/server.html#server-lifecycle
	UA_Server_run_iterate(server, true);
	
	//Multi Use Variables for Update
	int time_now = time(0);
	UA_Variant value;
	
	//Update Variable Running every 2s
	if(time_now > timestampM1Running)
	{
		timestampM1Running = time_now + 2;
		m1running = m1running ? false : true;
		//https://open62541.org/doc/current/plugin_log.html
		UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
		"New Motor 1 Running Bool: %s",m1running ? "True" : "False");
		//https://open62541.org/doc/current/types.html#generated-data-type-definitions
		//https://open62541.org/doc/current/types.html#variant
		UA_Variant_setScalar(&value, &m1running,&UA_TYPES[UA_TYPES_BOOLEAN]);
		
		//https://open62541.org/doc/current/server.html#reading-and-writing-node-attributes	
		UA_Server_writeValue(server, UA_NODEID_NUMERIC(nsIdx, 2010), val-ue);
	}
	
	//Update Variable Speed every 1s
	if(time_now > timestampM1Speed)
	{
		timestampM1Speed = time_now + 1;
		m1speed++;
		UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
		"New M1 Speed int: %d", m1speed);
		UA_Variant_setScalar(&value, &m1speed,  &UA_TYPES[UA_TYPES_INT16]);
		UA_Server_writeValue(server, UA_NODEID_NUMERIC(nsIdx, 2011), val-ue);
	}
}

return retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE;
```

Im Code sind auch die Verweise verzweigt, wo man dies in der
Dokumentation findet. Wichtig ist zu wissen, dass zum Schreiben einer
Variable das Erstellen einer Variante nötig ist. In dieser werden später
der gewünschte Wert und die Information des Datentyps temporär
abgespeichert und zwar mit der Function UA_Variant_setScalar. Diese
Variante kann man dann mit der Funktion UA_Server_writeValue schreiben,
die einen Pointer auf dem Server benötigt, die nötige Node-ID und die
soeben erstellte Variante.

Methoden
--------

Methoden benötigen eine Callback-Funktion. Wir erstellen diese vor der
Main-Methode exemplarisch für die Methode Control.

``` {.Bash language="Bash"}
static UA_StatusCode
ControlMethodCallback(UA_Server *server,
const UA_NodeId *sessionId, void *sessionHandle,
const UA_NodeId *methodId, void *methodContext,
const UA_NodeId *objectId, void *objectContext,
size_t inputSize, const UA_Variant *input,
size_t outputSize, UA_Variant *output) {
	//Handle Input
	UA_Int16 speed_in = *(UA_Int16*)input[0].data;
	UA_Int16 distance_in = *(UA_Int16*)input[1].data;
	UA_Boolean direction_in = *(UA_Boolean*)input[2].data;
	
	//Handle Direction and set for test the return Value to direction value
	UA_Boolean ret_val = direction_in;
	UA_Variant value;
	UA_Variant_setScalar(&value, &ret_val, &UA_TYPES[UA_TYPES_BOOLEAN]);
	UA_Server_writeValue(server, UA_NODEID_NUMERIC(nsIdx, 2012), value);
	
	//Return the Value to Methode Output
	UA_Variant_setScalarCopy(output, &ret_val, &UA_TYPES[UA_TYPES_BOOLEAN]);
	
	//End Methode
	UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Control was called");
	return UA_STATUSCODE_GOOD;
}
```

Um zu sehen, in welcher Reihenfolge die Input-Parameter abzurufen sind,
kann man ei-nen Blick in sein Modell werfen. Wie in Abbildung zu sehen,
kann man im Attributes Editor die Argumente unter Values identifizieren.

![Anzeige Reihenfolge
Input-Argumente](abb/InputArgumente.png){#fig:inputargumente
width="1\\linewidth"}

Damit kann man dann lokale Variable schreiben und seine Methoden Logic
durchführen. Wir schreiben in diesem Fall einfach nur den Input
Direction direkt in die Server Variable Direction und ändern damit auch
je nach dem die output-Variable mit UA_Variant_setScalarCopy.

Im nächsten Schritt müssen wir der Methode noch sagen, dass sie diesen
ein Callback aufrufen soll. Dies geschieht mit folgender Erweiterung in
der Main-Methode.

``` {.Bash language="Bash"}
//Set Callback for M1 Control https://open62541.org/doc/1.2/server.html#method-callbacks
UA_Server_setMethodNode_callback(server,
UA_NODEID_NUMERIC(nsIdx, 2013),
&ControlMethodCallback);
```

Diesen Code-Teil kann man nach dem Server-Startup implementieren.

Modifizierte main.c
-------------------

Hier findet man noch die gesamten Änderungen der main.c zusammengefasst.

``` {.Bash language="Bash"}
#include <open62541/plugin/log_stdout.h>
#include <open62541/server.h>
#include <open62541/server_config_default.h>
#include <signal.h>
#include <stdlib.h>
#include "MotorSteuerung.h"

#include <time.h>

UA_Boolean running = true;
UA_UInt16 nsIdx; //Namespace  "http://helloWorld.com/UA/"

static UA_StatusCode
ControlMethodCallback(UA_Server *server,
const UA_NodeId *sessionId, void *sessionHandle,
const UA_NodeId *methodId, void *methodContext,
const UA_NodeId *objectId, void *objectContext,
size_t inputSize, const UA_Variant *input,
size_t outputSize, UA_Variant *output) {
	//Handle Input
	UA_Int16 speed_in = *(UA_Int16*)input[0].data;
	UA_Int16 distance_in = *(UA_Int16*)input[1].data;
	UA_Boolean direction_in = *(UA_Boolean*)input[2].data;
	
	//Handle Direction and set for test the return Value to direction value
	UA_Boolean ret_val = direction_in;
	UA_Variant value;
	UA_Variant_setScalar(&value, &ret_val, &UA_TYPES[UA_TYPES_BOOLEAN]);
	UA_Server_writeValue(server, UA_NODEID_NUMERIC(nsIdx, 2012), value);
	
	//Return the Value to Methode Output
	UA_Variant_setScalarCopy(output, &ret_val, &UA_TYPES[UA_TYPES_BOOLEAN]);
	
	//End Methode
	UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Control was called");
	return UA_STATUSCODE_GOOD;
}

static void stopHandler(int sign) {
	UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "received ctrl-c");
	running = false;
}

int main(int argc, char** argv) {
	signal(SIGINT, stopHandler);
	signal(SIGTERM, stopHandler);
	
	UA_Server *server = UA_Server_new();
	UA_ServerConfig_setDefault(UA_Server_getConfig(server));
	UA_StatusCode retval;
	/* create nodes from nodeset */
	if(MotorSteuerung(server) != UA_STATUSCODE_GOOD) {
		UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Could not add the Motor-Steuerung nodeset. "
		"Check previous output for any error.");
		retval = UA_STATUSCODE_BADUNEXPECTEDERROR;
	} else {
		// Do some additional stuff with the nodes
		// this will just get the namespace index, since it is already added to the server
		nsIdx = UA_Server_addNamespace(server, "http://helloWorld.com/UA/");
		// UA_MOTOR1_RUNNING_BOOL = 2010
		UA_NodeId testInstanceId = UA_NODEID_NUMERIC(nsIdx, 2010);
		UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "Motor1 Bool Running is in ns=%d;id=%d",
		testInstanceId.namespaceIndex, testIn-stanceId.identifier.numeric);
		
	}
	//
	retval = UA_Server_run_startup(server);
	//Set Callback for M1 Control https://open62541.org/doc/1.2/server.html#method-callbacks
	UA_Server_setMethodNode_callback(server,
	UA_NODEID_NUMERIC(nsIdx, 2013),
	&ControlMethodCallback);
	
	//https://open62541.org/doc/current/server.html#server-lifecycle
	if(retval != UA_STATUSCODE_GOOD) {
		UA_Server_delete(server);
		return retval;
	}
	
	int timestampM1Running = time(0) + 2;
	int timestampM1Speed = time(0) + 1;
	//https://open62541.org/doc/current/types.html
	UA_Boolean m1running = false;
	UA_Int16 m1speed = 0;
	while(running == true)
	{
		//Server Routine https://open62541.org/doc/current/server.html#server-lifecycle
		UA_Server_run_iterate(server, true);
		
		//Multi Use Variables for Update
		int time_now = time(0);
		UA_Variant value;
		
		//Update Variable Running every 2s
		if(time_now > timestampM1Running) {
			timestampM1Running = time_now + 2;
			m1running = m1running ? false : true;
			//https://open62541.org/doc/current/plugin_log.html
			UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "New Motor 1 Running Bool: %s",
			m1running ? "True" : "False");
			//https://open62541.org/doc/current/types.html#generated-data-type-definitions
			//https://open62541.org/doc/current/types.html#variant
			UA_Variant_setScalar(&value, &m1running,  &UA_TYPES[UA_TYPES_BOOLEAN]);
			
			//https://open62541.org/doc/current/server.html#reading-and-writing-node-attributes
			UA_Server_writeValue(server, UA_NODEID_NUMERIC(nsIdx, 2010), value);
		}
		
		//Update Variable Speed every 1s
		if(time_now > timestampM1Speed) {
			timestampM1Speed = time_now + 1;
			m1speed++;
			UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "New M1 Speed int: %d",
			m1speed);
			UA_Variant_setScalar(&value, &m1speed,  &UA_TYPES[UA_TYPES_INT16]);
			UA_Server_writeValue(server, UA_NODEID_NUMERIC(nsIdx, 2011), value);
		}
	}
	
	return retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE;
}
```

Kompilieren und testen
----------------------

Nun kann der Code wie im Kapitel 6 kompiliert und getestet werden.

In UA Expert kann man sich die Variablen in das Data Access View-Fenster
ziehen und beobachten, wie sich der Wert ändert. Die Methode kann mit
einem rechten Mausklick aufgerufen werden, danach kann man die
Input-Parameter setzen und mit Call den Abruf erledigen. Hier sind nun
die Änderungen der Direction und Success zu beobachten. In sieht man
einen erfolgreichen Methoden-Aufruf.

![Abruf von Methoden](abb/AbrufMethode.png){#fig:abrufmethode
width="1\\linewidth"}

Methoden mit Multithreading
===========================

Browse
======

Callback für vor oder nach dem Schreiben von Variablen Einrichten
=================================================================

Custom Cmake File
=================

Git Repository
==============
