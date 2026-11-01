#include <iostream>
#include <cstring>
#include "Playlist.h"

using namespace std;

int Playlist::getTotalSeconds() const {
	int summ = 0;
	for (int i = 0; i < getCount(); i++)
	{
		summ += getDuration(i);
	}
	return summ;
}

int Playlist::getLongest() const {
	if (count == 0)
		return 0;

	int longest{};
	int index{};
	for (int i = 0; i < getCount(); i++)
	{
		if (getDuration(i) > longest)
		{
			longest = getDuration(i);
			index = i;
		}
	}
	return index;
}

void Playlist::setName(const char* name) {
	delete[] this->name;
	int length = strlen(name) + 1;
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}

void Playlist::add(int seconds) {
	if (seconds <= 0)
		return;

	int newCount = getCount() + 1;
	int* newDurations = new int[newCount];
	for (int i = 0; i < getCount(); i++)
	{
		newDurations[i] = getDuration(i);
	}
	newDurations[newCount - 1] = seconds;
	delete[] durations;
	durations = newDurations;
	count = newCount;
}

void Playlist::print() const{
	cout << getName() << endl;
	for (int i = 0; i < getCount(); i++)
	{
		printFormatedDuration(durations[i]);
		cout << endl;
	}
}

void Playlist::printFormatedDuration(int duration) {
	cout << duration / 60 << " : " << duration % 60;
}

void Playlist::printSummary(const Playlist& playlist){
	cout << playlist.getName() << endl;
	cout << playlist.getCount() << " songs" << endl;
	cout << "Total duration: ";
	playlist.printFormatedDuration(playlist.getTotalSeconds());
	cout << endl;
	cout << "Longest song: ";
	playlist.printFormatedDuration(playlist.getDuration(playlist.getLongest()));
	cout << endl;
}

void Playlist::printCopy(Playlist playlist) {
	playlist.add(60);
	playlist.print();
}

const Playlist& Playlist::longer(const Playlist& first, const Playlist& second) {
	if (first.getTotalSeconds() >= second.getTotalSeconds())
		return first;
	else
		return second;
}

Playlist Playlist::combine(const Playlist& first, const Playlist& second) {
	Playlist result = first;
	result.setName("Мікс");

	for (int i = 0; i < second.getCount(); i++)
	{
		result.add(second.getDuration(i));
	}
	return result;
}