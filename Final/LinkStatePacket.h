#pragma once
#include <string>
class LinkStatePacket
{
public:
	LinkStatePacket();

	LinkStatePacket(int a_routerId, int a_sequenceNum);
	~LinkStatePacket();


	void SetSequenceNumber(int a_seqNum)
	{
		m_sequenceNumber = a_seqNum;
	}

	void DecrementTTL()
	{
		m_TTL = m_TTL--;
	}
private:

	void SetRouterId(int a_routerId)
	{
		m_routerId = a_routerId;
	}

	//pointer to RouterList?
	int m_routerId;
	int m_sequenceNumber;
	int m_TTL;
	
};

