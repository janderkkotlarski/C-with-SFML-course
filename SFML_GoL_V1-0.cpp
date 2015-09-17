/// J. D. Kotlarski 2015

/// Fractal programma met C++ en SFML onder GNU\Linux.




// Dit heb je nodig in Geany, een andere teksteditor of de terminal
// om je programma via g++ te compileren.
/// g++ Spelkern.cpp -std=c++11 -o "%e" "%f" -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system



// Voor invoer en uitvoer
#include <iostream>

// Voor character-reeksen
#include <string> 

// Voor andersoortige parameter-reeksen
#include <vector>

// Voor hogere wiskunde
#include <cmath> 

// Voor tijdperiodes afwachten
#include <chrono> 

// Voor het laten wachten van het programma.
#include <thread>

// Voor je grafische mogelijkheden
#include <SFML/Graphics.hpp> 


void Fiboinit(std::vector<int> &fib_var, int max_var, int fractar)
{

	std::random_device generator;
	
	std::uniform_int_distribution<int> distribution(1, fractar);
	
	int	frac_var = distribution(generator);
	
	int ran_var = frac_var;
	
	if (ran_var <= 0)
	{
		
		ran_var = 1;
		
	}
	
	if (ran_var >= (fractar + 1))
	{
		
		ran_var = fractar;
		
	}
	
	fib_var[0] = ran_var;
	
	
	frac_var = distribution(generator);
	
	ran_var = frac_var;
	
	if (ran_var <= 0)
	{
		
		ran_var = 1;
		
	}
	
	if (ran_var >= (fractar + 1))
	{
		
		ran_var = fractar;
		
	}
	
	
	fib_var[1] = ran_var;
	fib_var[2] = 0;
		
}

void Fiborand(std::vector<int> &fib_var, int max_var, int fractar)
{

	fib_var[2] = fib_var[1];
	fib_var[1] = fib_var[1] + fib_var[0];
	fib_var[0] = fib_var[2];
						
	if (fib_var[1] >= max_var)
	{
							
		fib_var[1] = fib_var[1] - fractar - 1;
							
	}
	
}


// Start van het programma
int main()
{
	
	// De wachttijd voor het programma/spel in milliseconden.
	// Het aantal Hertz is 1000 gedeeld door de wachttijd.
	const int wachttijt = 20;
	
	// Overzetten van gehele getallen naar de daadwerkelijke tijdseenheden.
	const std::chrono::milliseconds wachttijd(wachttijt);
	
	
	
	// Stel de grootte van de heelf van de window voor horizontaal (x) en vertikaal (y) in.
	const int halve_window_x = 200, halve_window_y = 200;
		
	// Nu de daadwerkelijke afmetingen van je window
	const int volle_window_x = 2*halve_window_x + 1, volle_window_y = 2*halve_window_y + 1;
	
	const int pixel_div = 1;
	
	const int side_x = volle_window_x/pixel_div, side_y = volle_window_y/pixel_div;
	
	// De pixels voor het plaatje definiëren.
	sf::Uint8 *pixels = new sf::Uint8[side_x*side_y*4];
	
	// Variabelen voor de complexe getallen.
	double x_var, y_var, z_var, x_war, y_war, x_tar, y_tar, x_zar, y_zar;
	
	std::vector<int> current_cell(side_x*side_y), next_cell(side_x*side_y);
	
	int surrounding;
	
	int surro_x, surro_y;
	
	// Variabelen 
	double x_disp = 0, y_disp = 0;
	
	std::string x_disp_string = std::to_string(x_disp), y_disp_string  = std::to_string(y_disp), text_string; //= std::to_string(myDoubleVar);
	
	const double step_disp = 0.01;
	
	const double scale = 4.0/volle_window_x, bias = 10000;
	
	const int iter = 5;
	
	sf::Font font;
	
	if (!font.loadFromFile("Carlito-Regular.ttf"))
	{
		// error...
	}
	
	sf::Text text;

	// select the font
	text.setFont(font); // font is a sf::Font

	// set the character size
	text.setCharacterSize(10); // in pixels, not points!

	// set the color
	text.setColor(sf::Color::White);

	// set the text style
	text.setStyle(sf::Text::Bold);

	text_string = "R: " + x_disp_string + "\nI: " + y_disp_string;
			
	text.setString(text_string);
	
	
	
	/// std::vector<sf::Uint8> pyxels(volle_window_x * volle_window_y * 4);
	
	// Een 2D plaatje aanmaken en voorbereiden.
	sf::Texture plaatje;
	
	if (!plaatje.create(side_x, side_y))
	{
		
		return 1;
		
	}
	
	// Een sprite aanmaken.
    sf::Sprite sprite;
    
	std::vector<int> fib_val(3);
	const int max_val = 1000000000, fractal = (max_val - 2);
	
	const double max_div = 1.0/max_val;
	
	Fiboinit(fib_val, max_val, fractal);
	
	for (int b_sub = 0; b_sub < side_y; b_sub++)
	{		
		
		for (int a_sub = 0; a_sub < side_x; a_sub++)
		{
			
			Fiborand(fib_val, max_val, fractal);
			
			if (fib_val[0] > (max_val/2))
			{
			
				current_cell[a_sub + b_sub*side_x] = 1;
				
			}
			else
			{
				
				current_cell[a_sub + b_sub*side_x] = 0;
				
			}		
			
		}		
		
	}
	
	
	Fiborand(fib_val, max_val, fractal);
	
	
	
	/// Zie ook: 
	
	// Naam van het programma voor op de window, zodat iedereen die het gebruikt het weet.
	const std::string programmanaam = "Game of Life V1.0";
	
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
	// std::string sprite_naam = "Bit_Mask_40c.png";
	
	/// http://www.sfml-dev.org/tutorials/2.3/graphics-sprite.php
	
	
	
	
	
	
	
	// Beginwaarden voor veranderende regenboogkleuren.
	int regenboog_rood = 192, regenboog_groen = 64, regenboog_blauw = 64;
	
	// Grenswaarden voor maximum en minimum en stapwaarde.
	const int regenboog_max = 192, regenboog_min = 64, regenboog_stap = 1;
	
	
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
		
		
		
		for (int b_sub = 0; b_sub < side_y; b_sub++)
		{		
			
			for (int a_sub = 0; a_sub < side_x; a_sub++)
			{
				
				surrounding = 0;
				
				for (int d_sub = -1; d_sub <= 1; d_sub++)
				{
					
					surro_y = (b_sub + d_sub + side_y) % side_y;
					
					for (int c_sub = -1; c_sub <= 1; c_sub++)
					{
						
						surro_x = (a_sub + c_sub + side_x) % side_x;
						
						if ((c_sub != 0) || (d_sub != 0))
						{
							
							if (current_cell[surro_x + surro_y*side_x] == 1)
							{
								
								surrounding++;
								
							}
							
						}
						
					}
					
				}
			
				if (current_cell[a_sub + b_sub*side_x] == 1) 
				{
					
					if ((surrounding == 2) || (surrounding == 3))
					{
					
						next_cell[a_sub + b_sub*side_x] = 1;
						
					}
					else
					{
					
						next_cell[a_sub + b_sub*side_x] = 0;
						
					}
					
				}
						
				
				if (current_cell[a_sub + b_sub*side_x] == 0)
				{
					
					if (surrounding == 3)
					{
					
						next_cell[a_sub + b_sub*side_x] = 1;
						
					}
					else
					{
					
						next_cell[a_sub + b_sub*side_x] = 0;
						
					}
				
				}

			}		
			
		}
		
		for (int b_sub = 0; b_sub < side_y; b_sub++)
		{		
			
			for (int a_sub = 0; a_sub < side_x; a_sub++)
			{
				
				current_cell[a_sub + b_sub*side_x] = next_cell[a_sub + b_sub*side_x];
				
				if (current_cell[a_sub + b_sub*side_x] == 1)
				{
				
					pixels[4*(a_sub + b_sub*side_x)] = regenboog_rood;
					pixels[4*(a_sub + b_sub*volle_window_x) + 1] = regenboog_groen;
					pixels[4*(a_sub + b_sub*volle_window_x) + 2] = regenboog_blauw;
					
				}
				else
				{
				
					pixels[4*(a_sub + b_sub*side_x)] = 0;
					pixels[4*(a_sub + b_sub*volle_window_x) + 1] = 0;
					pixels[4*(a_sub + b_sub*volle_window_x) + 2] = 0;
					
				}			
				
				
				pixels[4*(a_sub + b_sub*volle_window_x) + 3] = 255;
				
			}
	
		}
		
		
		
		
		
		// std::cout << fib_val[0] << "\n";
		
		plaatje.update(pixels);
		
		sprite.setTexture(plaatje);
		
		
		// Wis de window schoon met de veranderende regenboogkleur.
		window.clear(sf::Color(0*regenboog_rood, 0*regenboog_groen, 0*regenboog_blauw));
		
		/// Eerste waarde is van 0 tot 255 en is voor het rode kanaal.
		/// Tweede waarde is van 0 tot 255 en is voor het groene kanaal.
		/// Derde waarde is van 0 tot 255 en is voor het blauwe kanaal.
		/// Daarmee kun je zelf kleuren samenstellen.
		/// Maar wat simpele kleuren zijn ook te selecteren via standaardwoorden.
		/// Zelf kan ik het gebruik van de getallen aanraden, veel meer controle over de kleur.
		
		
		window.draw(sprite);
		
		// inside the main loop, between window.clear() and window.display()
		// window.draw(text);
				
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
		
		
		
		
		/* if (sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))
		{
			
			x_disp = 0;
			y_disp = 0;
			
			x_disp_string = std::to_string(x_disp);
			y_disp_string = std::to_string(y_disp);
			
			text_string = "R: " + x_disp_string + "\nI: " + y_disp_string;
			
			text.setString(text_string);
			
		} */
		
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
