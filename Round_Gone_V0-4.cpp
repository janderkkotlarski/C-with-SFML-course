#include <iostream>
#include <string>
#include <vector>
#include <cassert>

std::string Enter()
{
	
	return "\n";	
	
}


std::string program_name()
{
	
	return "Round Gone V0.4" + Enter();
	
}



int color_amount()
{
	
	return 5;
	
}



int rank_amount()
{
	
	return 14;
	
}



enum Rank {Blank, Joker, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

enum Color {Blanc, Jocer, Heart, Club, Diamond, Spade};




std::string rank_to_string(Rank kard_appear)
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



std::string color_to_string(Color kard_color)
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



int rank_to_value(Rank kard_appear)
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
	
	void set_card(Rank kard_rank, Color kard_color);
	
		
	
	Card();
	
	Card(Rank kard_rank, Color kard_color);
	
	~Card();
	
	
	
	std::string card_to_string()
	{
		
		return "[" + rank_to_string(card_rank) + "~" + color_to_string(card_color) + "]" + Enter();
		
	}
	
};



void Card::ranc_to_value()
{
	
	card_value = rank_to_value(card_appear);
	
}




void Card::set_blank_card()
{
	
	card_rank = Blank;
	
	card_appear = card_rank;
	
	card_color = Blanc;
	
	ranc_to_value();
	
}




void Card::set_card(Rank kard_rank, Color kard_color)
{
	
	card_rank = kard_rank;
	
	card_appear = card_rank;
	
	card_color = kard_color;
	
	ranc_to_value();
	
}




Card::Card()
{
	
	set_blank_card();
		
}



Card::Card(Rank kard_rank, Color kard_color)
{
	
	set_card(kard_rank, kard_color);
	
}



Card::~Card()
{
	
	
	
}


Card place_card(Rank kard_rank, Color kard_color)
{
	
	
	Card kard(kard_rank, kard_color);
	
	return kard;
	
	
}


Color colorize(int place)
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




Rank rankize(int place)
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






int main()
{
	
	assert(Enter() == "\n");
	
	assert(program_name() > "Round Gone V");
	
	assert(color_amount() == 5);
	
	assert(rank_amount() == 14);
	
	int temp_int = 0;


	std::cout << program_name();
	
	
	std::vector<Color> color_list;
	
	for (int a_sub = 0; a_sub < color_amount(); ++a_sub)
	{
		
		color_list.push_back(colorize(a_sub));
		std::cout << a_sub << Enter();	
		
	}
	
	
	std::cout << Enter();	
	
	
	std::vector<Rank> rank_list;
	
	for (int a_sub = 0; a_sub < rank_amount(); ++a_sub)
	{
		
		rank_list.push_back(rankize(a_sub));
		
		std::cout << a_sub << Enter();		
		
	}
	
	
	std::cout << Enter();	

	
	std::vector<Card> deck_list;
	
	
	for (int b_sub = 1; b_sub < color_amount(); ++b_sub)
	{
		
		temp_int = (b_sub - 1)*rank_amount();
	
		deck_list.push_back(place_card(rank_list[0], color_list[0]));
		std::cout << temp_int << " ~ " << deck_list[temp_int].card_to_string();
		
		for (int a_sub = 1; a_sub < rank_amount(); ++a_sub)
		{
			
			deck_list.push_back(place_card(rank_list[a_sub], color_list[b_sub]));
			
			std::cout << (a_sub + temp_int) << " ~ " << deck_list[a_sub + temp_int].card_to_string();	
		}
		
	}

	
	return 0;
	
} 
