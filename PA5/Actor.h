#pragma once
#ifndef ACTOR_H
#define ACTOR_H

#include "Movie.h"
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Movie;
class Actor
{
private:
    unordered_map<string, Movie*> _movies;
    string _name;
    string _id;

public:
	void addMovie(Movie* movie);
	
	//setters
	void setId(string id);
    void setName(string name);
    
	//getters
	vector<Movie*> getMovies();
	string getName() const;
    string getId() const;
};

#endif