#ifndef PACKET_H
#include <iostream>
#include <cstring>
using namespace std;
const int PACKET_SIZE = 5; // Number of characters in a packet
struct Packet
{
	int position; // Packet’s position within the message
	char body[PACKET_SIZE + 1]; // Characters contained in the packet including NULL terminator
};
#endif // !PACKET_H
