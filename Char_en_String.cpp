 #include <iostream>
 #include <fstream>
 #include <string>
 
 int main()
 {
	 
	 const char karak{'a'};	 
	 const char ter{'e'};	 
	 const char karakter{karak + ter};	 
	 
	 const std::string str{"Dit is"};	 
	 const std::string eng{"een zin."};	 
	 const std::string streng{str + eng};
	 
	 std::cout << karak << " + " << ter << " = " << karakter << '\n';
	 std::cout << str << " + " << eng << " = " << streng << "\n";
	 
	 const std::string uitvoer_naam{"uitvoer_bestand.txt"};
	 
	 std::ofstream mijn_bestand;
	 mijn_bestand.open(uitvoer_naam);
	 mijn_bestand << streng << '\n';
	 mijn_bestand.close();
	 
	 
	 return 0;
	 
 }
