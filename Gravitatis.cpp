#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <cmath>


struct position
{
	
	double posi_x = 0;
	double posi_y = 0;
	
	position();
	position(const double pozi_x, const double pozi_y);
	~position();
	
	void set_posi(const double pozi_x, const double pozi_y);
	
};

position::position()
{
	
}

position::position(const double pozi_x, const double pozi_y)
{
	
	posi_x = pozi_x;
	posi_y = pozi_y;
			
}

position::~position()
{
		
}

void position::set_posi(const double pozi_x, const double pozi_y)
{
	
	posi_x = pozi_x;
	posi_y = pozi_y;
	
}



struct velocity
{
	
	double velo_x = 0;
	double velo_y = 0;
	
	velocity();
	velocity(const double vero_x, const double vero_y);
	~velocity();
	
	void set_velo(const double vero_x, const double vero_y);	
	
		
};

velocity::velocity()
{
	
}

velocity::velocity(const double vero_x, const double vero_y)
{
	
	velo_x = vero_x;
	velo_y = vero_y;
			
}

velocity::~velocity()
{
		
}

void velocity::set_velo(const double vero_x, const double vero_y)
{
	
	velo_x = vero_x;
	velo_y = vero_y;
	
}

struct acceleration
{
	
	double accel_x = 0;
	double accel_y = 0;
	
	acceleration();
	acceleration(const double accer_x, const double accer_y);
	~acceleration();
	
	void set_accel(const double accer_x, const double accer_y);
	
};



acceleration::acceleration()
{
	
}

acceleration::acceleration(const double accer_x, const double accer_y)
{
	
	accel_x = accer_x;
	accel_y = accer_y;
			
}

acceleration::~acceleration()
{
		
}

void acceleration::set_accel(const double accer_x, const double accer_y)
{
	
	accel_x = accer_x;
	accel_y = accer_y;
	
}


struct planetoid
{
	
	double mass = 1;
	
	double radius = pow(mass, 1.0/3.0);
	
	position posixy;	
	velocity veloxy;
	acceleration accelxy;
	
	
	planetoid(const double mazz, const position &pozixy,
			  const velocity &veroxy)
	: posixy(), veloxy(), accelxy()
	{
	
		mass = mazz;	
		radius = pow(mass, 1.0/3.0);	
		posixy = pozixy;
		veloxy = veroxy;
		
		acceleration accerxy;
		
		accelxy = accerxy;
	
	}
	
	planetoid(const planetoid &plan_a, const planetoid &plan_b)
	: posixy(), veloxy(), accelxy()
	{
	
		mass = plan_a.mass + plan_b.mass;
		radius = pow(mass, 1.0/3.0);
		
		posixy.posi_x = (plan_b.mass*plan_a.posixy.posi_x + plan_a.mass*plan_b.posixy.posi_x)/(2.0*(plan_a.mass + plan_b.mass));
		posixy.posi_y = (plan_b.mass*plan_a.posixy.posi_y + plan_a.mass*plan_b.posixy.posi_y)/(2.0*(plan_a.mass + plan_b.mass));
		
		veloxy.velo_x = (plan_a.mass*plan_a.veloxy.velo_x + plan_b.mass*plan_b.veloxy.velo_x)/(2.0*(plan_a.mass + plan_b.mass));
		veloxy.velo_y = (plan_a.mass*plan_a.veloxy.velo_y + plan_b.mass*plan_b.veloxy.velo_y)/(2.0*(plan_a.mass + plan_b.mass));
		
		accelxy.accel_x = (plan_a.mass*plan_a.accelxy.accel_x + plan_b.mass*plan_b.accelxy.accel_x)/(2.0*(plan_a.mass + plan_b.mass));
		accelxy.accel_y = (plan_a.mass*plan_a.accelxy.accel_y + plan_b.mass*plan_b.accelxy.accel_y)/(2.0*(plan_a.mass + plan_b.mass));
	
	}
	
	~planetoid()
	{
		
	}
	
	void set_accel_zero()
	{
		
		accelxy.accel_x = 0;
		accelxy.accel_y = 0;
		
	}
	
	void cumul_accel(const planetoid &plan_a)
	{
		
		const double grav = 1.0;
		
		const double dist_x = plan_a.posixy.posi_x - posixy.posi_x;
		const double dist_y = plan_a.posixy.posi_y - posixy.posi_y;
		
		const double dist_sqr = dist_x*dist_x + dist_y*dist_y;
		const double dist = sqrt(dist_sqr);
		
		const double accel = grav*mass/dist;
		
		accelxy.accel_x += accel*dist_x/(dist*dist_sqr);
		accelxy.accel_y += accel*dist_y/(dist*dist_sqr);
		
	}	

	
};



void change_speed_and_place(planetoid &plan_a, const double delta_time)
{
	
	plan_a.veloxy.velo_x += plan_a.accelxy.accel_x*delta_time;	
	plan_a.veloxy.velo_y += plan_a.accelxy.accel_y*delta_time;
	
	plan_a.posixy.posi_x += plan_a.veloxy.velo_x*delta_time;	
	plan_a.posixy.posi_y += plan_a.veloxy.velo_y*delta_time;
	
}

planetoid two_become_one(planetoid &plan_a, planetoid &plan_b)
{
	
	planetoid plan_c(plan_a, plan_b);
	
	return plan_c;
	
}

void planet_fusion(std::vector < planetoid > &planets, int planet_1, int planet_2)
{
	
	assert(planet_1 >= 0);
	assert(planet_2 >= 0);
	assert(planet_1 != planet_2);
	
	
	const int planets_size = planets.size();
	
	assert(planet_1 < planets_size);
	assert(planet_2 < planets_size);
	
	if (planet_2 < planet_1)
	{
		
		const int planet_t = planet_1;
		
		planet_1 = planet_2;
		
		planet_2 = planet_t;
		
	}
		
	planets[planet_1] = two_become_one(planets[planet_1], planets[planet_2]);
	
	std::cout << "Doet het!\n";
	
	std::move(planets.begin() + planet_1, planets.begin() + planet_2, planets.begin() + planet_1 - 1);
	
	
	planets.pop_back();
	
}

void display_plan(const planetoid &plan)
{
	
	std::cout << "mass = " << plan.mass << ", ";
	
	std::cout << "radius = " << plan.radius << "\n";
	
	std::cout << "position = [" << plan.posixy.posi_x << ", " << plan.posixy.posi_y << "]\n";
	
	std::cout << "velocity = [" << plan.veloxy.velo_x << ", " << plan.veloxy.velo_y << "]\n";
	
	std::cout << "acceleration = [" << plan.accelxy.accel_x << ", " << plan.accelxy.accel_y << "]\n";
	
	std::cout << "\n";
	
}

int main()
{
	
	double mass0 = 0.0001;
	
	double mass1 = 0.0004;
	
	position pos0(0, 0);
	
	position pos1(10, 10);
	
	velocity velo0(3, 0);
	
	velocity velo1(0, 5);
	
	planetoid plan0(mass0, pos0, velo0);
	
	planetoid plan1(mass1, pos1, velo1);
	
	planetoid plan2(plan0, plan1);
	
	std::vector < planetoid > planets(2, plan0);
	
	planets[1] = plan1;
	
	display_plan(planets[0]);
	
	display_plan(planets[1]);
	
	planet_fusion(planets, 0, 1);
	
	display_plan(planets[0]);
	
	// display_plan(planets[1]);
	
	display_plan(plan0);
	
	display_plan(plan1);
	
	display_plan(plan2);
		
	std::cout << "Hug your family!\n";
	
	return 0;
	
}
