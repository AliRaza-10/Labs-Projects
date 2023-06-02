#ifndef PACKETMANAGER_H
#include <iostream>
#include "Packet.h"
#include <cstring>
#include <fstream>
using namespace std;
class PacketManager
{
private:
	Packet* packets; // Array which will be used to store the packets read from the file
	int numPackets; // Number of packets in the above array
	char* message; // The message that was extracted from the packets
	int msgLength; // Length of the message
public:
	PacketManager(ifstream&);
	~PacketManager();
	void displayPackets() const;
	void sortPacketsBubbleSort();
	void sortPacketsSelectionSort();
	void extractMessage();
	void displayMessage() const;
};
#endif // !PACKETMANAGER_H
