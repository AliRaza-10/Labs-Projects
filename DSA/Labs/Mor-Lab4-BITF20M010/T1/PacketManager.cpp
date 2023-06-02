//Muhammad Waqas Ud Din
//Bitf20m013
//IT-Morning
#include <iostream>
#include "PacketManager.h"
#include <fstream>
#include <cstring>
using namespace std;
PacketManager::PacketManager(ifstream& fin)
{
	fin >> numPackets;
	packets = new Packet[numPackets];
	for (int i = 0; i < numPackets; i++) {
		fin >> packets[i].position;
		fin.ignore();
		fin.getline(packets[i].body, PACKET_SIZE+1);
	}
	message = NULL;
	msgLength = 0;
}
PacketManager::~PacketManager()
{
	if (packets) {
		delete[]packets;
		packets = NULL;
	}
	if (message) {
		delete[]message;
		message = NULL;
	}
}
void PacketManager::displayPackets() const
{
	for (int i = 0; i < numPackets; i++) {
		cout << packets[i].position << "  " << packets[i].body << endl;
	}
}
void swap(Packet& p1, Packet& p2)
{
	Packet temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}
void PacketManager::sortPacketsBubbleSort()
{
	for (int i = numPackets - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (packets[j].position > packets[j + 1].position)
				swap(packets[j], packets[j + 1]);
		}
	}
}
void PacketManager::sortPacketsSelectionSort()
{
	for (int i = numPackets-1; i>=0; i--) {
		int maxIndex = i;
		for (int j = 0; j < i; j++) {
			if (packets[j].position > packets[maxIndex].position)
				maxIndex = j;
		}
		swap(packets[i], packets[maxIndex]);
	}
}
void PacketManager::extractMessage()
{
	char choice;
	cout << "\n\nWhich sorting algorithm you want to use?\n";
	cout << "\tEnter 'B' or 'b' for Bubble sort\n";
	cout << "\tEnter 'S' or 's' for Selection sort\n";
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 'B' || choice == 'b')
		sortPacketsBubbleSort();
	else if (choice == 'S' || choice == 's')
		sortPacketsSelectionSort();
	msgLength = PACKET_SIZE * numPackets;
	message = new char[msgLength + 1];
	strcpy(message, packets[0].body);
	for (int i = 1; i < numPackets; i++) {
		strcat(message, packets[i].body);
	}
}
void PacketManager::displayMessage() const
{
	if (message) {
		cout << "\nThe extracted message is : \n";
		cout << message << endl;
	}
	else
		cout << "Message has not been extracted yet.\n";
}