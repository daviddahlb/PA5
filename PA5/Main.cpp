#include "Actor.h"
#include "Movie.h"
#include "StringSplitter.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	StringSplitter ss;

	string parse_me;
	ifstream fin("basic.tsv");
	vector<vector<string>> parsed_data;

	if (fin.is_open()) {

		while (getline(fin, parse_me, '\n'))
		{
			//grabbed a full line of data up to newline (full actor's info)
			//parse the string again by tab to grab each piece of data needed
			cout << "parse_me: " << parse_me << endl;
			vector<string> data = ss.split(parse_me, "\t");
			vector<string> spliced_data;

			//create new vector only with elements we need and push into parsed_data]
			//put parsed data into vector<string> spliced_data
			//info needed from data: ID[0]
			spliced_data.push_back(data[0]);
			//					   NAME[1]
			spliced_data.push_back(data[1]);
			//					movieID[5]
			spliced_data.push_back(data[5]);

			//then put that data into the vector<vector<string>> parsed_data
			parsed_data.push_back(spliced_data);
		}
	}

	//TASK 3 - Output requested actor's information
	bool actor_name_found = false;
	do {

		string actor_id_input = "";

		cout << "Enter Actor ID: ";
		cin >> actor_id_input;

		for (auto actor : parsed_data)
		{
			if (actor[0] == actor_id_input)
			{
				actor_name_found = true;
				cout << "Actor Name: " << actor[0] << endl;
				cout << "Movie(s): " << actor[2] << endl;
				break;
			}
		}

	} while (actor_name_found == false);

	//now parsed_data should be full of actor's data (and movie data still in .csv form)
	//create graph and load with Actor's and Movies

	//parse string movieID by ',' (csv) to get each movieID



	//add actors and movies to graph
	return 0;
}