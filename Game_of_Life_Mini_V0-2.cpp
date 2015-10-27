#include <iostream>
#include <string> 
#include <chrono> 
#include <thread>
#include <vector>
#include <cassert>

#include <random>
#include <SFML/Graphics.hpp> 


void initialize_grid(std::vector< std::vector< int > > & init_grid)
{

	
	const int y_size = init_grid.size();
	
	assert(y_size > 0);

	
	const int x_size = init_grid[0].size();
	
	assert(x_size > 0);
	
	
	
	std::random_device randumb;
			
	int cur_ran = 0;
	

	
	for (int x_pos = 0; x_pos < x_size; ++x_pos)
	{
		
		for (int y_pos = 0; y_pos < y_size; ++y_pos)
		{
			
			cur_ran = round(randumb());
			
			init_grid[x_pos][y_pos] = (cur_ran % 2);
						
		}
				
	}
	
}

void show_grid_term(const std::vector< std::vector< int > > & life_grid, const int cur_gen)
{
	
	assert(cur_gen >= 0);
	
	const int y_size = life_grid.size();
	
	assert(y_size > 0);
	
	
	const int x_size = life_grid[0].size();
	
	assert(x_size > 0);
	
	for (int line_count = 0; line_count < 100; ++line_count)
	{
		
		std::cout << "\n";
		
	}
			
	
	std::cout << "generation: " << cur_gen << "\n";
	
	
	for (int y_pos = 0; y_pos != y_size; ++y_pos)
	{
		
		for (int x_pos = 0; x_pos != x_size; ++x_pos)
		{
			
			if (life_grid[x_pos][y_pos] == 1)
			{
				
				std::cout << "[#]";
				
			}
			else
			{
				
				std::cout << "[ ]";
				
			}
			
			
		}
		
		std::cout << "\n";
		
		
	}
	
	std::cout << "\n";
	
}


void show_grid_sfml(const std::vector< std::vector< int > > & life_grid, sf::RenderWindow & window,
					sf::Sprite & life_dot_sprite, const int dot_size)
{
	
	assert(dot_size > 0);
	
	
	const int y_size = life_grid.size();
	
	assert(y_size > 0);
	
	
	const int x_size = life_grid[0].size();
	
	assert(x_size > 0);
	
	
	window.clear(sf::Color(0, 0, 0));

	
	for (int y_pos = 0; y_pos != y_size; ++y_pos)
	{
		
		for (int x_pos = 0; x_pos != x_size; ++x_pos)
		{
			
			if (life_grid[x_pos][y_pos] == 1)
			{
				
				life_dot_sprite.setPosition(x_pos*dot_size, y_pos*dot_size);
				
				window.draw(life_dot_sprite);
			
			}			
			
		}		
		
	}
	
	window.display();
	
}

int count_neighbours(const int x_pos, const int y_pos, const std::vector< std::vector< int > > & current_grid)
{
	
	const int current_y_size = current_grid.size();
	
	assert(current_y_size > 0);
	
	
	const int current_x_size = current_grid[0].size();
	
	assert(current_x_size > 0);
	
	
	int count_neighbours = 0;
	
	for (int x_neighbour = -1; x_neighbour <= 1; ++x_neighbour)
	{
		
		for (int y_neighbour = -1; y_neighbour <= 1; ++y_neighbour)
		{
		
			if (((x_neighbour != 0) || (y_neighbour != 0)) &&
		(current_grid[(current_x_size + x_pos + x_neighbour) % current_x_size][(current_y_size + y_pos + y_neighbour) % current_y_size] == 1))
			{
				
				++count_neighbours;
				
			}
		
		}
		
	}
	
	return count_neighbours;
	
	
}


void next_generation(const std::vector< std::vector< int > > & current_grid, std::vector< std::vector< int > > & next_grid)
{
	
	
	
	const int current_y_size = current_grid.size();
	// const int next_y_size = next_grid.size();
	
	assert(current_y_size > 0);
	assert(next_y_size > 0);
	assert(current_y_size == next_y_size);
	
	const int current_x_size = current_grid[0].size();
	// const int next_x_size = next_grid[0].size();
	
	assert(current_x_size > 0);
	assert(next_x_size > 0);
	assert(current_x_size == next_x_size);
	
	
	for (int x_pos = 0; x_pos < current_x_size; ++x_pos)
	{
		
		for (int y_pos = 0; y_pos < current_y_size; ++y_pos)
		{
			const int number_neighbours = count_neighbours(x_pos, y_pos, current_grid);
			
			
			
			
			if (current_grid[x_pos][y_pos] == 0) 
			{
				
				if (number_neighbours == 3)
				{
					
					next_grid[x_pos][y_pos] = 1;
					
				}
				else
				{
					
					next_grid[x_pos][y_pos] = 0;
					
				}
				
			}
			
			if (current_grid[x_pos][y_pos] == 1) 
			{
				
				if ((number_neighbours < 2) ||
					(number_neighbours > 3))
				{
					
					next_grid[x_pos][y_pos] = 0;
					
				}
				else
				{
					
					next_grid[x_pos][y_pos] = 1;
					
				}
				
			}				
						
		}

	}
	
}



int main()
{
	
	const std::string gol_name = "Game of Life Mini V0.2";
	
	
	const int delaz = 100;
	
	assert(delaz > 0);
	
	const std::chrono::milliseconds delay(delaz);
	
	const int x_size = 80, y_size = 80;
	
	const bool term = false, sfml = true;
	
	assert(x_size > 2);
	assert(x_size <= 100);
	
	assert(y_size > 2);
	assert(y_size <= 100);
	
	assert(generation_loop > 0);
	
	const int dot_size = 8;
	
	const int window_x = x_size*dot_size, window_y = y_size*dot_size;
	
	assert(x_size > 0);
	assert(y_size > 0);
	
	std::vector < std::vector<int>> life_grid(y_size, std::vector<int>(x_size, 0));
	
	std::vector < std::vector<int>> change_grid(y_size, std::vector<int>(x_size, 0));
	
	
	initialize_grid(life_grid);
	
	
	for (int pos = 0; pos < y_size; ++pos)
	{
	
		life_grid[pos][pos] = 1;
		
		life_grid[y_size - 1 - pos][pos] = 1;
	
	}
	
	
	const std::string life_dot_img = "Life_Dot.png";
	
	sf::Texture life_dot_tex;
	
	if (!life_dot_tex.loadFromFile(life_dot_img))
	{
			
		std::cout << life_dot_img << " not found!\n";
			
	}
	
	sf::Sprite life_dot_sprite;
	
	life_dot_sprite.setTexture(life_dot_tex);

	sf::RenderWindow window(sf::VideoMode(window_x, window_y), gol_name, sf::Style::Default);

	
	int cur_gen = 0;
	
	while (window.isOpen())
	{
		
		if (sfml)
		{
			
			show_grid_sfml(life_grid, window, life_dot_sprite, dot_size);
			
		}
		
		if (term)
		{			
			
			show_grid_term(life_grid, cur_gen);
		
		}
		
		next_generation(life_grid, change_grid);
		
		life_grid = change_grid;
		
		++cur_gen;
		
		
		std::this_thread::sleep_for(delay);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			
			window.close();
					
			return 1;
					
		}
		
	}
	
	
	return 0;
	
}
