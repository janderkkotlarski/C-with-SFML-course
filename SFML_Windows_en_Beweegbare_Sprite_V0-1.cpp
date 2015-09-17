/// J. D. Kotlarski 2015

/// Cursus spel maken met C++ en SFML onder GNU\Linux.



/// Lees het onderstaande goed door, het gaat je een helebult dommigheden en frustraties
/// besparen, maar skip het gerust als je direct aan de slag wilt en goede
/// kans op falen wilt hebben.
/// Dit is andere Kapitein Koek dan Gamemaker.

/// Dit is een beginnerscursus spel maken met C++ en SFML onder GNU\Linux als
/// besturingssysteem.
/// Als vereiste is er dat je goede ervaring met Gamemaker hebt of met Arduino programmeren
/// en willens om voor een goed gedeelte op eigen houtje te leren programmeren.

/// Maak je geen illusies, na deze beginnerscursus zul je vast nog geen Mariokloon of
/// 2D Minecraft hebben, ook niet mijn eigen doolhofspel, maar dat is ook niet erg.
/// Het gaat erom dat je spelenderwijs leert hoe je C++ en in het algemeen
/// programmeren onder de knie krijgt en de grafische mogelijkheden van SFML leert te
/// beheersen.

/// Als inspiratiebronnen heb ik een aantal van mijn eigen folders en bestanden erbij gezet.
/// Als je die vernaggelt, boeit niks, ik zet geregeld de oorspronkelijke versies terug.
/// Als je je eigen programma/spel gebaseerd op dit bestand of de anderen wilt maken,
/// sla dit bestand onder een andere naam met .cpp als bestandseinde in je eigen folder op.
/// Dat voorkomt een bult verlies en verdriet als ik weer eens de ooorspronkelijke versies herstel.

/// Blijf regelmatig je bestanden opslaan, aan te raden valt om regelmatig een nieuwe
/// namen te gebruiken, waarbij ik zelf meestal met versies werk.
/// Zoals Spelkern_V0-1.cpp, Spelkern_V0-2.cpp, Spelkern_V0-3.cpp, Spelkern_V0-4.cpp, etc.
/// dat maakt het werken makkelijker en als je iets verprutst in een latere versie,
/// kun je altijd weer teruggaan naar een eerdere versie.

/// Daarnaast is het aan te raden om je bestanden niet alleen maar op te slaan op de
/// computers op de Jonge Onderzoekers en de synchronisatieopslag, maar het juist ook mee
/// naar huis te nemen.
/// Dat kan doordat je het op een USB-stick zet, het op een opslagplaat op het internet zet
/// of naar jezelf mailt.
/// Meestal betekent het dat je of een folder met bestanden of bestanden zo in een zip-bestand
/// zet en op die manier handiger als een bestand kunt hanteren.

/// Nog een handige tip is om veel van dit soort aantekeningen, a.k.a. annotaties, te maken.
/// Heel handig om achter te komen wat er waar fout ging en dat sneller op te lossen.
/// Zelf ben ik veelal nogal lui daarin, wat me weleens erg duur kwa tijd en mogelijkheden
/// komt te staan.
/// Leer van het negatieve voorbeeld en doe het anders dan ik het pleeg te doen.

/// Als je programma raar reageert of uberhaupt niet werkt, dan ligt het meestal aan een bug.
/// Een bug is een fout(je) in het programma wat voor vreemd programmagedrag zorgt of dat het
/// geheel niet werkt.

/// Wat de compiler betreft, als die merkt dat er kwa grammatika (syntax) iets mis is in
/// het programma of er anderzins een fout in de programmering zit, dan geeft die dat aan
/// en gaat ie het programma niet builden.
/// Meestal zijn de fouten eenvoudig te verhelpen, maar in het geval je na enigzins proberen
/// er nog niet uit komt, vraag me gerust om hulp.

/// De twee grote sites om zelf raad te kunnen plegen en dingen op te zoeken zijn:
/// http://www.cplusplus.com/doc/tutorial/
/// http://www.sfml-dev.org/tutorials/2.3/
/// Zelf heb ik daar heel veel op kunnen vinden en voordat je mij vraagt,
/// prbeer zelf eerst maar dingen uit te vogelen.
/// Je kunt meer zelf oplossen dan je denkt en je kunt elkaar ook vragen en helpen.
/// Vraag mij gerust voor de echt moeilijkere dingen of waar je echt niet uit komt.



/// Als er nog geen C++, SFML en/of Geanie op de PC onder Linux zitten, vraag mij om het erop te zetten.



// Dit heb je nodig in Geany, een andere teksteditor of de terminal
// om je programma via g++ te compileren.
/// g++ Spelkern.cpp -std=c++11 -o "%e" "%f" -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system



// Voor invoer en uitvoer
#include <iostream>

// Voor character-reeksen
#include <string> 

// Voor hogere wiskunde
#include <cmath> 

// Voor tijdperiodes afwachten
#include <chrono> 

// Voor het laten wachten van het programma.
#include <thread>

// Voor je grafische mogelijkheden
#include <SFML/Graphics.hpp> 


// Start van het programma
int main()
{
	
	// De wachttijd voor het programma/spel in milliseconden.
	// Het aantal Hertz is 1000 gedeeld door de wachttijd.
	int wachttijt = 20;
	
	// Overzetten van gehele getallen naar de daadwerkelijke tijdseenheden.
	std::chrono::milliseconds wachttijd(wachttijt);
	
	
	
	// Stel de grootte van de helf tvan de window voor horizontaal (x) en vertikaal (y) in.
	int halve_window_x = 300, halve_window_y = 300;
		
	// Nu de daadwerkelijke afmetingen van je window
	int volle_window_x = 2*halve_window_x, volle_window_y = 2*halve_window_y;
	
	/// Zie ook: 
	
	// Naam van het programma voor op de window, zodat iedereen die het gebruikt het weet.
	std::string programmanaam = "Spelkern V0.1";
	
	/// std hoort voor dingen als strings en cout en bepaalde andere zaken.
	/// Spelkern is de string binnen "Spelkern".
	/// programmanaam is de string die de computer onthoudt en
	/// via de declaratie std::string maak je programmanaam.
	/// In programmmanaam gooi je string Spelkern via =
	/// om die te onthouden en later weer weer te geven.
	/// ; is er om een instructie af te sluiten.
	
	/// Je kunt later een andere string in programmanaam gooien of er eentje bij doen.
	/// Bijvoorbeeld: programmanaam = "Aardkern";
	/// Of: programmanaam = programmanaam + "gracht";
	/// Probeer het gerust uit, gewoon dit bestand onder een andere naam opslaan,
	/// dan veranderen, dan weer opslaan, dan builden.	
	
	
	
	// Wat is de naam van je afbeelding?
	std::string sprite_naam = "Bit_Mask_40c.png";
	
	/// http://www.sfml-dev.org/tutorials/2.3/graphics-sprite.php
	
	
	// Nieuw patroon maken.
	sf::Texture sprite_tex;
	
	// Checken of je afbeelding echt bestaat en deze dan in het patroon laden.
	if (!sprite_tex.loadFromFile(sprite_naam))
	{
		
		// Hij heeft de afbeelding niet gevonden.
		// Alleen te zien op de terminal.
		std::cout << sprite_naam << " not found!" << "\n";
								
		// Een -1 uitspugen, main() uitgaan en zo het programma afsluiten.
		// Alleen te zien op de terminal.
		return -1;
		
	}
	
	
	
	// De sprite aanmaken.
	sf::Sprite sprite_beeld;
	
	// Patroon in de sprite laden.
	sprite_beeld.setTexture(sprite_tex);
	
	// Ankerpunt voor het tekenen van de sprite bepalen.
	// Voor het gemak in het midden zetten, maakt handelbaarheid makkelijker.
	sprite_beeld.setOrigin(sf::Vector2f(20, 20));
	
	// Waar op het tekenvlak wil je de sprite plaatsen.
	// Doe je dat buiten de window, ga je de sprite niet zien.
	sprite_beeld.setPosition(sf::Vector2f(halve_window_x, halve_window_y));
	
	
	
	double sprite_verplaats = 1;
	
	// Beginwaarden voor veranderende regenboogkleuren.
	int regenboog_rood = 192, regenboog_groen = 64, regenboog_blauw = 64;
	
	// Grenswaarden voor maximum en minimum en stapwaarde.
	int regenboog_max = 192, regenboog_min = 64, regenboog_stap = 1;
	
	
	// Nieuwe window maken met afmeting volle_window_x keer volle_window_y en als opschrift programmanaam.
	// sf::Style::Default is een standardstijl.
	sf::RenderWindow window(sf::VideoMode(volle_window_x, volle_window_y), programmanaam, sf::Style::Default);
	
	/// Zie voor meer over windows beheren ook: http://www.sfml-dev.org/tutorials/2.3/window-window.php
	
	
	
	//Open window en terwijl die open is: Doorloop de lus.
	while (window.isOpen())
    {
		
		
		/// De volgende code is een handige manier om veranderende regenboogkleuren aan je window of sprite
		/// toe te voegen.
		
		// Als rood is gelijk aan het maximum en groen is groter dan de minimum, dan groen verminderen.
		if ((regenboog_rood == regenboog_max) && (regenboog_groen > regenboog_min))
		{
				
			// Groen met stap verminderen.
			regenboog_groen = regenboog_groen - regenboog_stap;
			
			// Als groen kleiner dan het minimum is...
			if (regenboog_groen < regenboog_min)
			{
				
				// Dan wordt groen gelijk aan het minimum.
				regenboog_groen = regenboog_min;
				
			}
				
		}
		
		// Als rood is gelijk aan het maximum en groen is gelijk aan het minimum en blauw is kleiner dan het maximum,
		// dan blauw verhogen.	
		if ((regenboog_rood == regenboog_max) && (regenboog_groen == regenboog_min) && (regenboog_blauw < regenboog_max))
		{
			
			// Blauw met stap vermeerderen.
			regenboog_blauw = regenboog_blauw + regenboog_stap;
			
			// Als blauw groter dan het maximum is...
			if (regenboog_blauw > regenboog_max)
			{
				
				// Dan wordt blauw gelijk aan het maximum.
				regenboog_blauw = regenboog_max;
				
			}
		
		}
		
		// Als blauw is gelijk aan het maximum en rood is groter dan de minimum, dan groen verminderen.
		if ((regenboog_blauw == regenboog_max) && (regenboog_rood > regenboog_min))
		{
			
			// Rood met stap verminderen.	
			regenboog_rood = regenboog_rood - regenboog_stap;
			
			// Als rood kleiner dan het minimum is...
			if (regenboog_rood < regenboog_min)
			{
				
				// Dan wordt rood gelijk aan het minimum.
				regenboog_rood = regenboog_min;
				
			}
				
		}
		
		// Als blauw is gelijk aan het maximum en rood is gelijk aan het minimum en groen is kleiner dan het maximum,
		// dan blauw verhogen.	
		if ((regenboog_blauw == regenboog_max) && (regenboog_rood == regenboog_min) && (regenboog_groen < regenboog_max))
		{
			
			// Groen met stap vermeerderen.
			regenboog_groen = regenboog_groen + regenboog_stap;
			
			// Als groen groter dan het maximum is...
			if (regenboog_groen > regenboog_max)
			{
				
				// Dan wordt groen gelijk aan het maximum.
				regenboog_groen = regenboog_max;
				
			}
				
		}
		
		// Als groen is gelijk aan het maximum en blauw is groter dan de minimum, dan blauw verminderen.
		if ((regenboog_groen == regenboog_max) && (regenboog_blauw > regenboog_min))
		{
			
			// Blauw met stap verminderen.	
			regenboog_blauw = regenboog_blauw - regenboog_stap;
			
			// Als blauw kleiner dan het minimum is...
			if (regenboog_blauw < regenboog_min)
			{
				
				// Dan wordt blauw gelijk aan het minimum.
				regenboog_blauw = regenboog_min;
				
			}
				
		}
		
		// Als groen is gelijk aan het maximum en blauw is gelijk aan het minimum en rood is kleiner dan het maximum,
		// dan blauw verhogen.	
		if ((regenboog_groen == regenboog_max) && (regenboog_blauw == regenboog_min) && (regenboog_rood < regenboog_max))
		{
				
			// Rood met stap vermeerderen.
			regenboog_rood = regenboog_rood + regenboog_stap;
			
			// Als rood groter dan het maximum is...
			if (regenboog_rood > regenboog_max)
			{
				
				// Dan wordt rood gelijk aan het maximum.
				regenboog_rood = regenboog_max;
				
			}
					
		}
		
		/// Hier houdt deze veranderende regenboogkleurencode op.
		
		// Wis de window schoon met wit.
		// Window.clear(sf::Color::White);
		// window.clear(sf::Color(255, 255, 255));
		
		
		// Wis de window schoon met de veranderende regenboogkleur.
		window.clear(sf::Color(regenboog_rood, regenboog_groen, regenboog_blauw));
		
		/// Eerste waarde is van 0 tot 255 en is voor het rode kanaal.
		/// Tweede waarde is van 0 tot 255 en is voor het groene kanaal.
		/// Derde waarde is van 0 tot 255 en is voor het blauwe kanaal.
		/// Daarmee kun je zelf kleuren samenstellen.
		/// Maar wat simpele kleuren zijn ook te selecteren via standaardwoorden.
		/// Zelf kan ik het gebruik van de getallen aanraden, veel meer controle over de kleur.
		
				
		
		// Teken de sprite in de window.
		window.draw(sprite_beeld);	
		
		// Geef de window daadwerkelijk weer.
		window.display();
		
		
		
		// Als de [Esc] knop ingedrukt wordt eindig main() en zo het programma.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			
			/// http://www.sfml-dev.org/tutorials/2.3/window-inputs.php
			
			
			// Alleen te zien op de terminal.
			std::cout <<  programmanaam << " manually terminated!" << "\n";
			
			// sluit de window.
			window.close();
					
			// Een 1 uitspugen, main() uitgaan en zo het programma verlaten.
			return 0;
						
		}	
		
		// Als pijltje naar boven ingedrukt wordt, verplaats de sprite
		// met sprite_verplaats pixels naar boven.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			
			// Sprite wordt met sprite_verplaats pixels naar boven verplaatst.
			sprite_beeld.move(sf::Vector2f(0, -sprite_verplaats));
			
			/// Let op dat het eerste getal in sf::Vector2f een 0 is
			/// en een horizontale beweging weergeeft.
			/// Het tweede getal geeft een verticale beweging aan.
			/// Positieve getallen bewegen naar beneden.
			/// Negatieve getallen bewegen naar boven.
						
		}
		
		
		
		// Als pijltje naar boven ingedrukt wordt, verplaats de sprite
		// met sprite_verplaats pixels naar beneden.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			
			// Sprite wordt met sprite_verplaats pixels naar beneden verplaatst.
			sprite_beeld.move(sf::Vector2f(0, sprite_verplaats));
			
			/// Let op dat het eerste getal in sf::Vector2f een 0 is
			/// en een horizontale beweging weergeeft.
			/// Het tweede getal geeft een verticale beweging aan.
			/// Positieve getallen bewegen naar beneden.
			/// Negatieve getallen bewegen naar boven.
						
		}
		
		
		
		// Als pijltje naar boven ingedrukt wordt, verplaats de sprite
		// met sprite_verplaats pixels naar rechts.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			
			// Sprite wordt met sprite_verplaats pixels naar rechts verplaatst.
			sprite_beeld.move(sf::Vector2f(sprite_verplaats, 0));
			
			/// Let op dat het tweede getal in sf::Vector2f een 0 is
			/// en een verticale beweging weergeeft.
			/// Het eerste getal geeft een horizontale beweging aan.
			/// Positieve getallen bewegen naar rechts.
			/// Negatieve getallen bewegen naar links.
						
		}
		
		
		
		// Als pijltje naar boven ingedrukt wordt, verplaats de sprite
		// met sprite_verplaats pixels naar links.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			
			// Sprite wordt met sprite_verplaats pixels naar links verplaatst.
			sprite_beeld.move(sf::Vector2f(-sprite_verplaats, 0));
			
			/// Let op dat het tweede getal in sf::Vector2f een 0 is
			/// en een verticale beweging weergeeft.
			/// Het eerste getal geeft een horizontale beweging aan.
			/// Positieve getallen bewegen naar rechts.
			/// Negatieve getallen bewegen naar links.
						
		}
		
		
		
		// Programma wacht wachttijd milliseconden af voor het verdergaat.
		std::this_thread::sleep_for(wachttijd);
		
		// Einde lus.		
	}
	
	// Een 0 uitspugen, main() verlaten en dus programma einde.	
	// Alleen te zien op de terminal.
	return 0;
	
	/// Dit kan momdat je programma een functie is met de naam main en die een integer
	/// dus een geheel getal als uitvoer geeft als ie afgelopen is en die je middels return aangeeft.
	/// In dit geval is dat een 0.
	/// Dit hoeft niet perse, maar het is netter en zo controleer je de werking van je programma beter.
		
	
	// Einde programma.	
}
