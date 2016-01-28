#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

//terminate program
void terminateProgram()
{
	cout << "type any character and <ENTER> to continue" << endl;
	char chAnyChar;
	cin >> chAnyChar;
	return;
}

//global variable
const double Threshold = 0.0;

//Neuron
class Neuron
{
public:
	//connectionweight
	double getconnectionweight(int x){ return connectionweights[x]; }
	void setconnectionweight(double Wij){ connectionweights.push_back(Wij);}

	//iState
	int getState(){ return iState; }
	void updateState(vector<Neuron> Allneurons)
	{
		double state = 0.0;
		for (int i = 0; i < connectionweights.size(); ++i)
		{
			state += connectionweights[i] * Allneurons[i].getState();
		}
		if (state >= Threshold) { iState = 1; }
		else { iState = -1; }
	}
	void setState(int state){ iState = state; }
	void initState() { int x = rand() % 2; if (x == 1) { iState = x; } else { iState = -1; } }
	void flipState() {if (iState == 1) { iState = -1; } else { iState = 1; }}
private:
	int iState;
	vector<double> connectionweights;
};
void learnHerbianRule(vector<vector<int>> patterns, int Capacity, vector<Neuron> &AllNeurons)
{
	double Wij;
	for (int i = 0; i != AllNeurons.size(); ++i)
	{
		for (int j = 0; j != AllNeurons.size(); ++j)
		{
			double dSum = 0.0;
			for (int k = 0; k != Capacity; ++k)
			{
				dSum += (patterns[k][i] * patterns[k][j]);
				if (i == j) { dSum = 0.0; }
			}
			Wij = (1.0 / Capacity) * dSum;
			AllNeurons[i].setconnectionweight(Wij);
		}
	}
}
void printHerbianRule(vector<Neuron> AllNeurons)
{
	//print connect weight
	cout << "connection weight matrix" << endl;
	for (int i = 0; i != AllNeurons.size(); ++i)
	{
		for (int j = 0; j != AllNeurons.size(); ++j)
		{
			printf ("%5.1f", AllNeurons[i].getconnectionweight(j));
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void createRandomPattern(int TotNeurons, vector<vector<int>> &patterns, int capacity)
{
	for (int j = 0; j != capacity; ++j)
	{
		vector<int> pattern;
		for (int i = 0; i < TotNeurons; ++i)
		{
			const int x = (rand() % 2);
			if (x == 1){ pattern.push_back(x); }
			else{ pattern.push_back(-1); }
		}
		patterns.push_back(pattern);
	}
}
void setpseudoRandomStartPattern(vector<vector<int>> patterns, vector<Neuron> &Allneurons, int error)
{
	int x = rand() % patterns.size();
	cout << "picked pattern " << x << " to alter" << endl;
	for (int i = 0; i < patterns[x].size(); ++i)

	{
		Allneurons[i].setState(patterns[x][i]);
	}
	int errorrate = (patterns[x].size() / 100.0)*error;
	for (int i = 0; i < errorrate; ++i)
	{
		int y = rand() % patterns[x].size();
		Allneurons[y].flipState();
		cout << "cell " << y << " have been altered" << endl;
	}
}
double calculateEnergy(vector<Neuron> &AllNeurons)
{
	double dSum = 0.0;
	double Energy;
	for (int i = 0; i < AllNeurons.size(); ++i)
	{
		for (int j = 0; j < AllNeurons.size(); ++j)
		{
			if (i == j) continue;
			dSum += AllNeurons[i].getconnectionweight(j) * (AllNeurons[i].getState()*AllNeurons[j].getState());
		}
	}

	Energy = -0.5 * dSum;
	return Energy;
}

int main()
{
	//reseeding rand()
	srand(unsigned int(time(NULL)));

	//opening output file
	ofstream Outputfile ("HopfieldEnergyLandscape.csv");

	//setting the amount of neurons. minimum is 8 neurons due to capacity of network
	cout << "This is a hopfield neuronal network." << endl;
	cout << "how many neurons do you want to learn somthing (minimum 8): ";
	int TotalNeurons;
	cin >> TotalNeurons;
	cout << endl;

	//amount of patterns the network can learn.  per 8 neurons 1 pattern
	int networkCapacity = static_cast<int>(TotalNeurons*0.138f);
	cout << "the network can remember " << networkCapacity << " patterns" << endl;

	//make list of Neurons
	vector<Neuron> AllNeurons(TotalNeurons);

	//pattern to be learned
	vector<vector<int>> patterns;
	createRandomPattern(TotalNeurons, patterns, networkCapacity);
	learnHerbianRule(patterns, networkCapacity, AllNeurons);
	printHerbianRule(AllNeurons);

	//from goto statment
	RECALLIBRATE: 

	//print learned pattern
	cout << "learned patterns" << endl;
	for (int j = 0; j < networkCapacity; ++j)
	{
		cout << j << ": ";
		for (int i = 0; i < TotalNeurons; ++i){ printf("%2d", patterns[j][i]);}
		cout << endl;
	}
	cout << endl;

	//initializing starting state states;
	cout << "do you want to pick a starting state yourself (y), completly random (r) , or pseudo random(p) starting state? (y/r/p) ";
	char chChoice;
	cin >> chChoice;
	if (chChoice == 'r')
	{ 
		for (int i = 0; i < TotalNeurons; ++i)
		{ 
			AllNeurons[i].initState(); 
		} 
	}
	else if (chChoice == 'y')
	{
		cout << "type " << TotalNeurons << " zero's and ones" << endl;
		int x;
		for (int i = 0; i < TotalNeurons; ++i)
		{
			cin >> x;
			if (x == 0){ x = -1; }
			AllNeurons[i].setState(x);
		}
	}
	else
	{
		// give error percentage for starting state
		int errorpercentage;
		cout << "pseudo random pattern is created from altering a learned pattern, by picking an percentage of difference" << endl;
		cout << "how different do you want the starting pattern be from the learned patterns:" << endl << "choose a number between 10 and 100" << endl;
		cin >> errorpercentage;
		setpseudoRandomStartPattern(patterns, AllNeurons, errorpercentage); 
	}
	
	//printing starting pattern
	cout << "starting pattern ";
	for (int i = 0; i < AllNeurons.size(); ++i) { printf("%2d", AllNeurons[i].getState());}
	cout << endl;

	Outputfile << "loop" << ";" << "Energy" << endl;
	// updating until pattern and neurons are the same.
	bool notdone = true;
	int loopcntr = 0;
	int falseminimumcheckup = 0;
	while (notdone)
	{
		//update random cell with all other cells
		int x = rand() % TotalNeurons;
		for (int i = 0; i < AllNeurons.size(); ++i)
		{
			AllNeurons[x].updateState(AllNeurons);
		}

		//print newly updated state
		printf("updated cell: %2d : current pattern " , x);
		Outputfile << loopcntr << ";";
		for (int i = 0; i < AllNeurons.size(); ++i) {printf("%2d", AllNeurons[i].getState());}
		cout << " : Energy: " << calculateEnergy(AllNeurons) << endl;
		Outputfile << calculateEnergy(AllNeurons) << endl;

		// stop if learned patern and current patern are the same
		int countertarget = 0;
		for (int j = 0; j < networkCapacity; ++j)
		{
			for (int i = 0; i < AllNeurons.size(); ++i)
			{
				//checking if they are the same with learned pattern up
				if (AllNeurons[i].getState() == patterns[j][i]) { countertarget += 1; }
			}
			// if counter reaches 8 (meaning they are the same) stop, otherwise cntr = 0
			if (countertarget == AllNeurons.size())
			{ 
				cout << "you reached learned pattern "<< j << " after " << loopcntr << " loops"; notdone = false; 
			}
			else
			{ 
				countertarget = 0;
			}
		}

		//checking for false minimum
		if (loopcntr == falseminimumcheckup)
		{	
			// make temp state
			int falseMinimumCounter = 0;
			vector<int> tempState;
			for (int i = 0; i < AllNeurons.size(); ++i)
			{
				tempState.push_back(AllNeurons[i].getState());
			}

			//updating all cells systematicly to possibly change something
			for (int i = 0; i < AllNeurons.size(); ++i)
			{
				for (int j = 0; j < AllNeurons.size(); ++j)
				{
					AllNeurons[i].updateState(AllNeurons);
				}
			}
			//compare the current state and the possibly chaged state 
			for (int i = 0; i < AllNeurons.size(); ++i)
			{
				if (AllNeurons[i].getState() == tempState[i]) { falseMinimumCounter += 1; }
			}
			//if the same stop it is a false minimum
			if (falseMinimumCounter == AllNeurons.size()){ cout << "you reached a False Minimum after " << loopcntr << " loops" << endl; notdone = false; }
			//otherwise reset all the States to current state and counter is reset
			else
			{
				for (int i = 0; i < AllNeurons.size(); ++i)
				{
					AllNeurons[i].setState(tempState[i]);
				}
				falseMinimumCounter = 0;
			}

			falseminimumcheckup += 50;
		}
	
		//adding to loopcntr
		loopcntr += 1;
		if (loopcntr > 500){ cout << "results after " << loopcntr << " loops"; notdone = false; }
	}
	cout << endl;

	//reset
	cout << "do you want to rerun with a different starting pattern? (y/n) ";
	cin >> chChoice;
	if (chChoice == 'y'){ goto RECALLIBRATE; }

	//closing
	Outputfile.close();

	//terminating program
	terminateProgram();
	return 0;
}
