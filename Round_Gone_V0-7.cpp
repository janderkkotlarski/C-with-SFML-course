#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <random>


enum Rank {Blank, Joker, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

enum Color {Blanc, Jocer, Heart, Club, Diamond, Spade};




std::string rank_to_string(const Rank kard_appear)
noexcept
{
	
	switch (kard_appear)
	{
		
		case Blank:
			return "#";
		
		case Joker:
			return "$";
				
		case Ace:
			return "A";
			
		case Two:
			return "2";
	
		case Three:
			return "3";
			
		case Four:
			return "4";
		
		case Five:
			return "5";
		
		case Six:
			return "6";
			
		case Seven:
			return "7";
			
		case Eight:
			return "8";
			
		case Nine:
			return "9";
			
		case Ten:
			return "T";
			
		case Jack:
			return "J";
			
		case Queen:
			return "Q";
			
		case King:
			return "K";

	}
	
	return "#";
	
}



std::string color_to_string(const Color kard_color)
noexcept
{
	
	switch (kard_color)
	{
		
		case Blank:
			return "#";
			
		case Joker:
			return "$";	
				
		case Heart:
			return "♥";
			
		case Club:
			return "♣";
	
		case Diamond:
			return "♦";
			
		case Spade:
			return "♠";		

	}
	
	return "#";
	
}



int rank_to_value(const Rank kard_appear)
noexcept
{
	
	switch (kard_appear)
	{
		
		case Blank:
			return -10;
		
		case Joker:
			return 0;
				
		case Ace:
			return 1;
			
		case Two:
			return 2;
	
		case Three:
			return 3;
			
		case Four:
			return 4;
		
		case Five:
			return 5;
		
		case Six:
			return 6;
			
		case Seven:
			return 7;
			
		case Eight:
			return 8;
			
		case Nine:
			return 9;
			
		case Ten:
			return 10;
			
		case Jack:
			return -1;
			
		case Queen:
			return -2;
			
		case King:
			return -3;

	}
	
	return -10;
	
}







class Card
{
	
	Rank card_rank = Blank, card_appear = card_rank;
	
	Color card_color = Blanc;
	
	int card_value = 0;
	
	void ranc_to_value();
	
	public:
	
	void set_blank_card();
	
	void set_card(const Rank kard_rank, const Color kard_color);
	
		
	
	Card();
	
	Card(const Rank kard_rank, const Color kard_color);
	
	~Card();
	
	
	
	std::string card_to_string()
	{
		
		return "[" + rank_to_string(card_rank) + "~" + color_to_string(card_color) + "]" + "\n";
		
	}
	
};



void Card::ranc_to_value()
// noexcept
{
	
	card_value = rank_to_value(card_appear);
	
}




void Card::set_blank_card()
// noexcept
{
	
	card_rank = Blank;
	
	card_appear = card_rank;
	
	card_color = Blanc;
	
	ranc_to_value();
	
}




void Card::set_card(const Rank kard_rank, const Color kard_color)
// noexcept
{
	
	card_rank = kard_rank;
	
	card_appear = card_rank;
	
	card_color = kard_color;
	
	ranc_to_value();
	
}




Card::Card()
// noexcept
{
	
	set_blank_card();
		
}



Card::Card(const Rank kard_rank, const Color kard_color)
// noexcept
{
	
	set_card(kard_rank, kard_color);
	
}



Card::~Card()
// noexcept
{
	
	
	
}


Card place_card(const Rank kard_rank, const Color kard_color)
noexcept
{
	
	
	Card kard(kard_rank, kard_color);
	
	return kard;
	
	
}


Color colorize(const int place)
noexcept
{
	
	switch (place)
	{
	
		case -10:
			return Blanc;
	
		case 0:
			return Jocer;
			
		case 1:
			return Heart;
			
		case 2:
			return Club;
			
		case 3:
			return Diamond;
			
		case 4:
			return Spade;
						
	}
	
	return Blanc;
		
}




Rank rankize(const int place)
noexcept
{
	
	switch (place)
	{
	
		case -10:
			return Blank;
	
		case 0:
			return Joker;
			
		case 1:
			return Ace;
			
		case 2:
			return Two;
			
		case 3:
			return Three;
			
		case 4:
			return Four;
			
		case 5:
			return Five;
			
		case 6:
			return Six;
			
		case 7:
			return Seven;
			
		case 8:
			return Eight;
			
		case 9:
			return Nine;
			
		case 10:
			return Ten;
			
		case 11:
			return Jack;
			
		case 12:
			return Queen;
			
		case 13:
			return King;
		
	}
	
	return Blank;
		
}


std::vector<Card> invert_deck_order(const std::vector<Card> decc_list)
noexcept
{
	
	int decc_pos = decc_list.size() - 1;
	
	std::vector<Card> invert_decc_list;
	
	while (decc_pos >= 0)
	{
		
		if (decc_pos >= 0)
		{
			
			invert_decc_list.push_back(decc_list[decc_pos]);
			
		}		
		
		--decc_pos;	
		
	}
	
	return invert_decc_list;
	
}


void mash_shuffle(std::vector<Card> &decc_list)
{
	
	std::random_device randumb;
	
	const double min_ran = randumb.min(), max_ran = randumb.max();
	
	std::cout << max_ran << "\n";
	
	const int devi = 3;
	const double duvi = 2*devi;
	
	double cur_ran = randumb();
	
	
	
	const int decc_size = decc_list.size();
	
	const int half_decider = decc_size%2;
	
	const int half_size = decc_size/2 + half_decider - devi + trunc(duvi*cur_ran/max_ran),
			  inv_half_size = decc_size - half_size;
	
	cur_ran = randumb();
	
	const int quart_size = decc_size/4 - devi + trunc(duvi*cur_ran/max_ran),
			  inv_quart_size = decc_size - quart_size;
	
	std::vector<Card> quart_list_one, quart_list_two;
	
	int intendo;
	
	for (int a_sub = 0; a_sub < quart_size; ++a_sub)
	{
		
		quart_list_one.push_back(decc_list[a_sub]);
			
	}
	
	intendo = quart_list_one.size();
	
	assert(intendo = quart_size);	
	
	
	
	for (int a_sub = quart_size; a_sub < decc_size; ++a_sub)
	{
		
		quart_list_two.push_back(decc_list[a_sub]);	
		
	}
	
	intendo = quart_list_two.size();
	
	assert(intendo = inv_quart_size);
	
	
	std::cout << decc_size << ":" << quart_size << ":" << inv_quart_size << "\n";
	
	
	
	for (int a_sub = 0; a_sub < (inv_quart_size); ++a_sub)
	{
		
		decc_list[a_sub] = quart_list_two[a_sub];		
		
	}
	
	
	
	
	for (int a_sub = inv_quart_size; a_sub < decc_size; ++a_sub)
	{
		
		decc_list[a_sub] = quart_list_one[a_sub - decc_size + quart_size];
		
	}
	
	
	
	std::vector<Card> half_list_one, half_list_two;
	
	for (int a_sub = 0; a_sub < half_size; ++a_sub)
	{
		
		half_list_one.push_back(decc_list[a_sub]);
			
	}
	
	intendo = half_list_one.size();
	
	assert(intendo = half_size);	
	
	
	
	for (int a_sub = half_size; a_sub < decc_size; ++a_sub)
	{
		
		half_list_two.push_back(decc_list[a_sub]);	
		
	}
	
	intendo = half_list_two.size();
	
	assert(intendo = inv_half_size);
	
	bool first_half = true;
	
	for (int a_sub = 0; a_sub < decc_size; ++a_sub)
	{
		
		if (first_half)
		{
			
			
			
		}
		else
		{
			
			
			
		}
		
	}
	
	
	
	
	
	
}




std::vector<Color> make_color_list(const int kolor_amount)
noexcept
{
	
	std::vector<Color> kolor_list;
	
	if (kolor_amount == 4)
	{
	
		for (int a_sub = 0; a_sub <= kolor_amount; ++a_sub)
		{
			
			kolor_list.push_back(colorize(a_sub));
			
		}
		
	}
	
	return kolor_list;
	
}



std::vector<Rank> make_rank_list(const int ranc_amount)
noexcept
{
	
	std::vector<Rank> ranc_list;
	
	if (ranc_amount == 14)
	{
		
		for (int a_sub = 0; a_sub < ranc_amount; ++a_sub)
		{
			
			ranc_list.push_back(rankize(a_sub));
			
		}
		
	}
	
	return ranc_list;
	
}



std::vector<Card> make_deck_list(const std::vector<Rank> ranc_list, const int ranc_amount,
							const std::vector<Color> kolor_list, const int kolor_amount)
{
	
	std::vector<Card> decc_list;
	
	
	if ((ranc_amount == 14) && (kolor_amount == 4))	
	{
		
		for (int b_sub = 1; b_sub <= kolor_amount; ++b_sub)
		{
					
			decc_list.push_back(place_card(ranc_list[0], kolor_list[0]));
			
			for (int a_sub = 1; a_sub < ranc_amount; ++a_sub)
			{
				
				decc_list.push_back(place_card(ranc_list[a_sub], kolor_list[b_sub]));
				
			}
			
		}	
		
	}
	else
	{
		
		std::cout << "Meganekko!"<< "\n";
		
	}
		
	return decc_list;
	
}


int main()
{
	
	const std::string Enter = "\n";	
	
	assert(Enter == "\n");
	
	

	const std::string program_name = "Round Gone V0.7" + Enter;
	
	assert(program_name > "Round Gone V");
	
	

	const int color_amount = 4;
	
	assert(color_amount == 4);
	
	
	
	const int rank_amount = 14;
	
	assert(rank_amount == 14);
	
	
	
	// int temp_int = 0;


	std::cout << program_name;
	
	std::cout << Enter;
	
	
	
	std::vector<Color> color_list = make_color_list(color_amount);
	
	if (color_list.size() == 0)
	{
		
		std::cout << "color_list has no size!" << Enter;
		
		
		return -1;
		
	}
	
	for (int a_sub = 0; a_sub <= color_amount; ++a_sub)
	{
		
		std::cout << a_sub << "\n";		
		
	}
	
	
	
		
	
	std::cout << Enter;	
	
	std::vector<Rank> rank_list = make_rank_list(rank_amount);
	
	for (int a_sub = 0; a_sub < rank_amount; ++a_sub)
	{
		
		std::cout << a_sub << "\n";		
		
	}
	
	if (rank_list.size() == 0)
	{
		
		std::cout << "rank_list has no size!" << Enter;
		
		return -2;
		
	}
	
	std::cout << Enter;	
	
	

	std::vector<Card> deck_list = make_deck_list(rank_list, rank_amount,
												color_list, color_amount);

	
	for (int a_sub = 0; a_sub < color_amount*rank_amount; ++a_sub)
	{
		
		std::cout << a_sub << " ~ " << deck_list[a_sub].card_to_string();
		
	}
	
	
	std::cout << Enter;	
	
	
	
	std::vector<Card> invert_deck_list = invert_deck_order(deck_list);
	
	for (int a_sub = 0; a_sub < color_amount*rank_amount; ++a_sub)
	{
		
		std::cout << a_sub << " ~ " << invert_deck_list[a_sub].card_to_string();
		
	}
	
	std::vector<Card> void_list;
	
	std::vector<Card> invoid_list = invert_deck_order(void_list);
	
	std::cout << void_list.size() << ":" << invoid_list.size() << Enter;
	
	std::cout << Enter;
	
	mash_shuffle(deck_list);
	
	std::cout << ":::::::::" << Enter;
	
	for (int a_sub = 0; a_sub < color_amount*rank_amount; ++a_sub)
	{
		
		std::cout << a_sub << " ~ " << deck_list[a_sub].card_to_string();
		
	}	
	
	
	
	
	return 0;
	
} 
