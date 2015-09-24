#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cassert>
#include <chrono>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


int main()
{
	
	const std::string ENTER = "\n", program_name = "Trackerwave v0.8";
	
	
	

	
	assert(ENTER == "\n");
	
	assert(program_name > "Trackerwave");
		
	const double half_note_step = pow(2.0, 1.0/12.0), perfect_lowest_a = 13.75;
	
	assert((half_note_step > 1) && (half_note_step < 1.1));
	
	assert((perfect_lowest_a > 10) && (perfect_lowest_a < 20));
	
	const int octave_number = 12, white_note_number = 7;
	
	assert(octave_number > 0);
	
	std::vector<double> note_a{perfect_lowest_a},
	note_ais{half_note_step*note_a[0]},
	note_b{half_note_step*note_ais[0]},
	note_c{half_note_step*note_b[0]},
	note_cis{half_note_step*note_c[0]},
	note_d{half_note_step*note_cis[0]},
	note_dis{half_note_step*note_d[0]},
	note_e{half_note_step*note_dis[0]},
	note_f{half_note_step*note_e[0]},
	note_fis{half_note_step*note_f[0]},
	note_g{half_note_step*note_fis[0]},
	note_gis{half_note_step*note_g[0]};
	
	for (int a_sub = 1; a_sub < octave_number; ++a_sub)
	{
						
		note_a.resize(a_sub + 1);
		note_ais.resize(a_sub + 1);
		note_b.resize(a_sub + 1);
		note_c.resize(a_sub + 1);
		note_cis.resize(a_sub + 1);
		note_d.resize(a_sub + 1);
		note_dis.resize(a_sub + 1);
		note_e.resize(a_sub + 1);
		note_f.resize(a_sub + 1);
		note_fis.resize(a_sub + 1);
		note_g.resize(a_sub + 1);
		note_gis.resize(a_sub + 1);
		
		note_a[a_sub] = 2*note_a[a_sub - 1];
		note_ais[a_sub] = 2*note_ais[a_sub - 1];
		note_b[a_sub] = 2*note_b[a_sub - 1];
		note_c[a_sub] = 2*note_c[a_sub - 1];
		note_cis[a_sub] = 2*note_cis[a_sub - 1];
		note_d[a_sub] = 2*note_d[a_sub - 1];
		note_dis[a_sub] = 2*note_dis[a_sub - 1];
		note_e[a_sub] = 2*note_e[a_sub - 1];
		note_f[a_sub] = 2*note_f[a_sub - 1];
		note_fis[a_sub] = 2*note_fis[a_sub - 1];
		note_g[a_sub] = 2*note_g[a_sub - 1];
		note_gis[a_sub] = 2*note_gis[a_sub - 1];
		
	}
	
	std::vector <std::vector <double> > white_note(white_note_number, std::vector <double>(octave_number, 1));
	
	white_note[0][0] = note_a[0];
	white_note[1][0] = note_b[0];
	white_note[2][0] = note_c[0];
	white_note[3][0] = note_d[0];
	white_note[4][0] = note_e[0];
	white_note[5][0] = note_f[0];
	white_note[6][0] = note_g[0];
	
	for (int a_sub = 0; a_sub < white_note_number; ++a_sub)
	{
		
		
		for (int b_sub = 1; b_sub < octave_number; ++b_sub)
		{
		
		
			white_note[a_sub][b_sub] = 2.0*white_note[a_sub][b_sub - 1];
			
			
		}
		
		
	}
	
	for (int a_sub = 0; a_sub < white_note_number; ++a_sub)
	{
		
		
		for (int b_sub = 0; b_sub < octave_number; ++b_sub)
		{
		
		
			
			
			std::cout << white_note[a_sub][b_sub] << " ";
			
			if (b_sub == octave_number -1)
			{
				
				std::cout << ENTER;
				
			}
			
			
		}
		
		
	}
	
	
	
	
	
	
	const int sample_amount = 3;
	
	assert(sample_amount > 0);
	
	std::vector <std::string> sample_name(1);	
	
	std::vector <sf::SoundBuffer> sample_buffer(1);
	
	std::vector <sf::Sound> sample_sound(1);
	
	if (sample_amount > 1)
	{
		
		for (int a_sub = 2; a_sub <= sample_amount; ++a_sub)
		{
			
			
			sample_name.resize(a_sub);
			
			sample_buffer.resize(a_sub);
			
			sample_sound.resize(a_sub);
			
			
		}
		
		
	}
	
	
	
	sample_name[0] = "Bass_Drum.wav";
	
	sample_name[1] = "Square_Wave.wav";
	
	sample_name[2] = "Koto.wav";
	
	
	
	
	for (int a_sub = 0; a_sub < sample_amount; ++a_sub)
	{
		
		assert(sample_name[a_sub] > "");
		
		if (!sample_buffer[a_sub].loadFromFile(sample_name[a_sub]))
		{
			
			std::cout <<  program_name << " could not find " << sample_name[a_sub] << ENTER;
			
			return -1;
			
		}
		
		sample_sound[a_sub].setBuffer(sample_buffer[a_sub]);
		
		
	}
	
	
	sample_sound[1].setVolume(50);
	
	sample_sound[2].setVolume(40);

    
	
	const int track_amount = 3, track_length = 32;
	
	assert((track_amount > 0) && (track_length > 0));
	
	std::vector <std::vector <double> > note_track(track_amount, std::vector <double>(track_length, -1));
	
	for (int a_sub = 0; a_sub < track_length; ++a_sub)
	{
		
		if ((a_sub % 4) == 0)
		{
			
			note_track[0][a_sub] = white_note[0][3]/white_note[0][4];
			
			note_track[1][a_sub] = -10;
			
		}
		
		if ((a_sub % 4) == 2)
		{
			
			note_track[1][a_sub] = white_note[0][3]/white_note[0][4];
			
			if (a_sub >= 16)
			{
				
				note_track[1][a_sub] = white_note[4][2]/white_note[0][4];
				
			}
			
			if (a_sub >= 24)
			{
				
				note_track[1][a_sub] = white_note[2][3]/white_note[0][4];
				
			}
			
		}
		
		if ((a_sub % 2) == 1)
		{
			
			note_track[2][a_sub] = -10;
			
		}
		
		if ((a_sub % 32) == 0)
		{
			
			note_track[2][a_sub] = white_note[0][3]/white_note[0][4];
			
			note_track[2][a_sub + 2] = white_note[3][3]/white_note[0][4];
			
			note_track[2][a_sub + 4] = white_note[2][3]/white_note[0][4];
			
			note_track[2][a_sub + 6] = white_note[4][3]/white_note[0][4];
			
			note_track[2][a_sub + 8] = white_note[1][3]/white_note[0][4];
			
			note_track[2][a_sub + 10] = white_note[6][3]/white_note[0][4];
			
			note_track[2][a_sub + 12] = white_note[4][3]/white_note[0][4];
			
			note_track[2][a_sub + 14] = white_note[5][3]/white_note[0][4];
			
			note_track[2][a_sub + 16] = white_note[6][2]/white_note[0][4];
			
			note_track[2][a_sub + 18] = white_note[2][3]/white_note[0][4];
			
			note_track[2][a_sub + 20] = white_note[1][3]/white_note[0][4];
			
			note_track[2][a_sub + 22] = white_note[3][3]/white_note[0][4];
			
			note_track[2][a_sub + 24] = white_note[4][3]/white_note[0][4];
			
			note_track[2][a_sub + 26] = white_note[0][4]/white_note[0][4];
			
			note_track[2][a_sub + 28] = white_note[5][3]/white_note[0][4];
			
			note_track[2][a_sub + 30] = white_note[2][4]/white_note[0][4];
			
		}
			
		
	}
	
	int current_notes = 0;
	
	
	const int window_x = 100, window_y = 100;
	
	assert((window_x > 0) && (window_y > 0));
	
	sf::RenderWindow window(sf::VideoMode(window_x, window_y), program_name, sf::Style::Default);
	
	
	
	const int minute = 60, beat_division = 4;
	
	assert((minute == 60) && (beat_division > 0));
	
	const float bpm = 120.0, period = minute/bpm, interval = period/beat_division;
	
	assert(bpm > 0);
	
	// bool quart_note_trigger = true, octa_note_trigger = true;
	
	bool note_counter = false;
	
	
	
	sf::Time time = sf::seconds(0.0f), interval_time = sf::seconds(interval);
	
	sf::Clock clock;
	
	float seconds = time.asSeconds();
	
	
	// sample_sound[0].play();
	
	while (window.isOpen())
    {
		
		time = clock.getElapsedTime();
		
		
		
		if (time >= interval_time)
		{
			
			for (int a_sub = 0; a_sub < track_amount; ++a_sub)
			{
				
				if (note_track[a_sub][current_notes] < -2)
				{
				
					sample_sound[a_sub].stop();
					
				}
				
				if (note_track[a_sub][current_notes] > 0)
				{
					
					sample_sound[a_sub].stop();
					
					sample_sound[a_sub].setPitch(note_track[a_sub][current_notes]);
			
					sample_sound[a_sub].play();
					
					std::cout << "[" << a_sub << "][" << current_notes << "]" << ENTER;
					
				}
				
			}
						
			clock.restart();
			
			++current_notes;
			current_notes = current_notes % track_length;		
			
		}
		

		
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
		
			std::cout <<  program_name << " manually terminated!" << ENTER;
			
			window.close();
					
			return 0;
						
		}		
		
		
	}
}
