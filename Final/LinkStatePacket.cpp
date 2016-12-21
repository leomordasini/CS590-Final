#include "LinkStatePacket.h"



LinkStatePacket::LinkStatePacket()
{
	
}

LinkStatePacket::LinkStatePacket(int a_routerId, int a_sequenceNum)
{
	SetRouterId(a_routerId);
	SetSequenceNumber(a_sequenceNum);
	m_TTL = 10;
}


LinkStatePacket::~LinkStatePacket()
{
}
