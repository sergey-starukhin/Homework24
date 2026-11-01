#include <iostream>
#include <windows.h>
#pragma once

using namespace std;

class Playlist
{
private:
	char* name;
	int* durations;
	int count;

public:
	explicit Playlist(const char* name) : name(nullptr), durations(nullptr), count(0)
	{
		setName(name);
		cout << "[+] Ранкова" << endl;
	}

	Playlist(const Playlist& other) : Playlist(other.getName())
	{
		if (other.getCount() != 0)
		{
			count = other.getCount();
			durations = new int[count];
			for (int i = 0; i < count; i++)
			{
				durations[i] = other.getDuration(i);
			}
		}
		cout << "[=] Ранкова" << endl;
	}
	
	~Playlist()
	{
		delete[] name;
		delete[] durations;
		cout << "[-] Ранкова" << endl;
	}

	static void printFormatedDuration(int duration);
	static void printSummary(const Playlist& playlist);
	static void printCopy(Playlist playlist);
	static const Playlist& longer(const Playlist& first, const Playlist& second);
	static Playlist combine(const Playlist& first, const Playlist& second);

	//getters
	const char* getName() const;
	int getCount() const;
	int getDuration(int index) const;
	int getTotalSeconds() const;
	int getLongest() const;
	
	//setters
	void setName(const char* name);
	void add(int seconds);
	
	void print() const;
};

inline const char* Playlist::getName() const {
	return name;
}

inline int Playlist::getCount() const {
	return count;
}

inline int Playlist::getDuration(int index) const{
	if (index < 0 || index > count - 1)
		return 0;
	return durations[index];
}


