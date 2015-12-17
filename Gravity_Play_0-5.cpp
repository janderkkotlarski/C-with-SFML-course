#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

struct planet
{
	
	const double mass{1};
	
	const double radius{1};
	
	sf::Vector2f posit{0, 0};
	
	sf::Vector2f speed{0, 0};
	
	sf::Vector2f accel{0, 0};
	
	sf::CircleShape circle;
	
	sf::Color color;
	
	planet(const double mazz, const double radiuz,
			const sf::Vector2f& pozit,
			const sf::Vector2f& zpeed,
			const sf::Color& kolor);
	
	~planet();
	
};

planet::planet(const double mazz, const double radiuz,
			const sf::Vector2f& pozit,
			const sf::Vector2f& zpeed,
			const sf::Color& kolor)
	:mass(mazz), radius(radiuz),
	posit(pozit), speed(zpeed),
	accel(), circle(), color(kolor)
{
	
	assert(mass > 0);
	
	assert(radius > 0);
	
	circle.setRadius(radius);
	
	circle.setPosition(pozit);
	
}

planet::~planet()
{
		
}

void posit_planet(planet& blanet)
{

	blanet.circle.setPosition(blanet.posit);
	
}

void color_planet(planet& blanet)
{
	
	blanet.circle.setFillColor(blanet.color);
	
}

void update_planet(planet& blanet)
{
	
	posit_planet(blanet);
	color_planet(blanet);
	
}

double orbiting_speed(const double mass, const double orbit, const double grav)
{
	
	return sqrt(grav*mass/orbit);
			
}

double calc_distance(const planet& planet_a, const planet& planet_b)
{
	
	assert((planet_a.posit.x != planet_b.posit.x) ||
			(planet_a.posit.y != planet_b.posit.y));
	
	
	return sqrt((planet_a.posit.x - planet_b.posit.x)*(planet_a.posit.x - planet_b.posit.x) +
				(planet_a.posit.y - planet_b.posit.y)*(planet_a.posit.y - planet_b.posit.y));
	
}



void add_accel(planet& planet_a, planet& planet_b, const double grav)
{
	
	const double distance{calc_distance(planet_a, planet_b)};
	assert(distance > 0);
	
	const double grav_factor{grav/(distance*distance*distance)};
	
	planet_a.accel.x += grav_factor*(planet_b.posit.x - planet_a.posit.x)*planet_b.mass;
	planet_a.accel.y += grav_factor*(planet_b.posit.y - planet_a.posit.y)*planet_b.mass;
	
	planet_b.accel.x += grav_factor*(planet_a.posit.x - planet_b.posit.x)*planet_a.mass;
	planet_b.accel.y += grav_factor*(planet_a.posit.y - planet_b.posit.y)*planet_a.mass;					
	
}

void clean_accel(std::vector <planet>& planetz)
{
	
	const int planet_amount{static_cast<int>(planetz.size())};
	assert(planet_amount > 0);
	
	int count_a{0};
	
	while(count_a < planet_amount)
	{
		
		planetz[count_a].accel.x = 0;
		planetz[count_a].accel.y = 0;
		
		++count_a;
		
	}
	
}

void total_accel(std::vector <planet>& planetz, const double grav)
{
	
	assert(grav > 0);
	
	const int planet_amount{static_cast<int>(planetz.size())};
	assert(planet_amount > 0);
	
	int count_a{0};
	assert(count_a == 0);
			
	while (count_a < planet_amount - 1)
	{
		
		int count_b{count_a + 1};
		assert(count_b == count_a + 1);
		
		while (count_b < planet_amount)
		{
			
			assert(count_a != count_b);
			
			add_accel(planetz[count_a], planetz[count_b], grav);
			
			++count_b;
			
		}
		
		++count_a;
		
	}	
	
}

void add_speed(planet& planet_a, const double delta_time)
{
	
	assert(delta_time > 0);
		
	planet_a.speed.x += delta_time*planet_a.accel.x;
	planet_a.speed.y += delta_time*planet_a.accel.y;
		
}

void total_speed(std::vector <planet>& planetz, const double delta_time)
{
	
	assert(delta_time > 0);
	
	const int planet_amount{static_cast<int>(planetz.size())};
	assert(planet_amount > 0);
	
	int count_a{0};
	assert(count_a == 0);
			
	while(count_a < planet_amount)
	{
		
		add_speed(planetz[count_a], delta_time);

		++count_a;
		
	}	
	
}

void add_posit(planet& planet_a, const double delta_time)
{
	
	assert(delta_time > 0);
		
	planet_a.posit.x += delta_time*planet_a.speed.x;
	planet_a.posit.y += delta_time*planet_a.speed.y;
		
}

void total_posit(std::vector <planet>& planetz, const double delta_time)
{
	
	assert(delta_time > 0);
	
	const int planet_amount{static_cast<int>(planetz.size())};
	assert(planet_amount > 0);
	
	int count_a{0};
	assert(count_a == 0);
			
	while(count_a < planet_amount)
	{
		
		add_posit(planetz[count_a], delta_time);

		++count_a;
		
	}	
	
}

void total_circle_posit(std::vector <planet>& planetz)
{
	
	const int planet_amount{static_cast<int>(planetz.size())};
	assert(planet_amount > 0);
	
	int count_a{0};
	assert(count_a == 0);
			
	while(count_a < planet_amount)
	{
		
		posit_planet(planetz[count_a]);

		++count_a;
		
	}
	
}

void change_planets(std::vector <planet>& planetz,
					const double delta_time,
					const double grav)
{
	
	assert(delta_time > 0);
	assert(grav > 0);
	
	clean_accel(planetz);
	
	total_accel(planetz, grav);
	
	total_speed(planetz, delta_time);
	
	total_posit(planetz, delta_time);
	
	total_circle_posit(planetz);
	
}	

int main()
{
		
	const int delaz{50};
	assert(delaz > 0);
	
	const std::chrono::milliseconds delay(delaz);
	
	const int delta_amount{100};
	assert(delta_amount > 0);
	
	const double delta_time{(1.0*delaz)/(1.0*delta_amount)};
	
	const double window_x{640};
	assert(window_x > 0);
	
	const double half_window_x{window_x/2};
	
	const double window_y{640};
	assert(window_y > 0);
	
	const double half_window_y{window_y/2};
	
	const sf::Color white{sf::Color(255, 255, 255)};	
	const sf::Color black{sf::Color(0, 0, 0)};	
	const sf::Color orange{sf::Color(255, 127, 0)};	
	const sf::Color purple{sf::Color(127, 0, 255)};	
	const sf::Color cyan{sf::Color(127, 255, 255)};
	const sf::Color yellow{sf::Color(255, 255, 127)};
	
	const std::string program_name{"Gravity Play 0.5"};
	assert(program_name != "");
	
	const double delta_speed{0.01};
	
	const sf::Vector2f delta_speed_right(delta_speed, 0);
	const sf::Vector2f delta_speed_down(0, delta_speed);
	const sf::Vector2f delta_speed_left{-delta_speed_right};
	const sf::Vector2f delta_speed_up{-delta_speed_down};
	
	const double grav{1};
	
	const double orbit{200};	
	const double proto_mass{1};	
	const double proto_radius{10};
	
	const sf::Vector2f proto_posit(half_window_x, half_window_y);	
	const sf::Vector2f proto_speed(0, 0);
		
	const planet proto_planet(proto_mass, proto_radius, proto_posit,
								proto_speed, white);
	
	const int proto_planet_amount{3};	
	const int planet_amount{4};
	
	const sf::Vector2f orbit_posit(orbit, 0);	
	const sf::Vector2f orbit_speed(0, orbiting_speed(proto_mass, orbit, grav));
	
	std::vector <planet> planets(proto_planet_amount, proto_planet);
	
	planets[1].posit += orbit_posit;
	planets[2].posit -= orbit_posit;
	
	planets[1].speed = orbit_speed;
	planets[2].speed = -orbit_speed;
	
	planets[0].color = yellow;
	planets[1].color = orange;
	planets[2].color = purple;
	
	int count{0};
	
	while (count < proto_planet_amount)
	{
		
		update_planet(planets[count]);
		
		++count;
		
	}
								
	const double vehicle_orbit{50};	
	const double vehicle_mass{0.01};	
	const double vehicle_radius{2};
	
	const sf::Vector2f vehicle_pos(0, vehicle_orbit);	
	const sf::Vector2f vehicle_posit{proto_posit + vehicle_pos};
	
	const sf::Vector2f vehicle_speed(orbiting_speed(proto_mass, vehicle_orbit, grav), 0);
	
	const planet vehicle_planet(vehicle_mass, vehicle_radius, vehicle_posit,
								vehicle_speed, cyan);
	
	planets.push_back(vehicle_planet);
	
	
	
	sf::RenderWindow window(sf::VideoMode(window_x, window_y), program_name, sf::Style::Default);
	
	while (window.isOpen())
	{
		
		sf::Event event;
		
		window.clear(black);
		
		count = 0;
		
		while (count < planet_amount)
		{
			
			window.draw(planets[count].circle);
			
			++count;
			
		}	
		
		window.display();		
		
		count = 0;
		
		while (count < delta_amount)
		{
			
			change_planets(planets, delta_time, grav);
			
			++count;
			
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			
			planets[3].speed += delta_speed_right;
					
		}	
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			
			planets[3].speed += delta_speed_left;
					
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			
			planets[3].speed += delta_speed_up;
					
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			
			planets[3].speed += delta_speed_down;
					
		}
		
		std::this_thread::sleep_for(delay);
		
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			
			window.close();
					
			return 1;
					
		}				
		
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
            {
				
				window.close();
				
				return 2;
				
			}
		
		}
		
	}
	
	return 0;
	
}
