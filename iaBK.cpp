#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Cell {
	public:
		int index, cellType, resources, myAnts, oppAnts;
		vector<int> neighbors;

		Cell(int index, int cellType, int resources, vector<int> neighbors, int myAnts = 0, int oppAnts = 0) {
			index = index;
			cellType = cellType;
			resources = resources;
			neighbors = neighbors;
			myAnts = myAnts;
			oppAnts = oppAnts;
		}
};

int main()
{
	vector<Cell> cells;
	vector<int> myBases, oppBases;
	int numberOfCells; // amount of hexagonal cells in this map
	cin >> numberOfCells; cin.ignore();
	for (int i = 0; i < numberOfCells; i++) {
		int type; // 0 for empty, 1 for eggs, 2 for crystal
		int initialResources; // the initial amount of eggs/crystals on this cell
		int neigh0; // the index of the neighbouring cell for each direction
		int neigh1;
		int neigh2;
		int neigh3;
		int neigh4;
		int neigh5;
		cin >> type >> initialResources >> neigh0 >> neigh1 >> neigh2 >> neigh3 >> neigh4 >> neigh5; cin.ignore();
		Cell cell(i, type, initialResources, {neigh0, neigh1, neigh2, neigh3, neigh4, neigh5}, 0, 0);
		cells.push_back(cell);
	}
	
	int numberOfBases;
	cin >> numberOfBases; cin.ignore();
	for (int i = 0; i < numberOfBases; i++) {
		int myBaseIndex;
		cin >> myBaseIndex; cin.ignore();
		myBases.push_back(myBaseIndex);
	}
	for (int i = 0; i < numberOfBases; i++) {
		int oppBaseIndex;
		cin >> oppBaseIndex; cin.ignore();
		oppBases.push_back(oppBaseIndex);
	}

	int current;
	// game loop
	while (1) {
		string actions = "WAIT";
		for (int i = 0; i < numberOfCells; i++) {
			int resources; // the current amount of eggs/crystals on this cell
			int myAnts; // the amount of your ants on this cell
			int oppAnts; // the amount of opponent ants on this cell
			cin >> resources >> myAnts >> oppAnts; cin.ignore();

			cells[i].resources = resources;
			cells[i].myAnts = myAnts;
			cells[i].oppAnts = oppAnts;
		}

		int test = 0;
		for (int i = 0; i < numberOfCells; i++)
			if (cells[i].resources > test)
				test = cells[i].resources;
		for (int i = 0; i < numberOfCells && !cells[current].resources; i++)
			if (cells[i].resources == test)
				current = i;

		
		cout << "LINE " << myBases[0] << ' ' << current << " 100" << endl;
		
		// cout << "LINE " << myBases[0] << ' ' << cells[current[0]].index << " 100" << endl;
		// cerr << "Current :" << current << " " << cells[current] << endl;
	}
}