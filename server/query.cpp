/*

	SA:MP Multiplayer Modification
	Copyright 2004-2005 SA:MP Team

    Version: $Id: query.cpp,v 1.16 2006/05/08 13:28:46 kyeman Exp $

*/

#include "main.h"

bool bRconSocketReply = false;

SOCKET	cur_sock			= INVALID_SOCKET;
char*	cur_data			= NULL;
int		cur_datalen			= 0;
sockaddr_in to;

void RconSocketReply(char* szMessage)
{
	// IMPORTANT!
	// Don't use logprintf from here... You'll cause an infinite loop.
	if (bRconSocketReply)
	{
		int message_len = strlen(szMessage);
		char* newdata = (char*)malloc(message_len + cur_datalen + sizeof(WORD));
		if (newdata == NULL) return;
		char* keep_ptr = newdata;
		memcpy(newdata, cur_data, cur_datalen);
		newdata += cur_datalen;
		*(WORD*)newdata = (WORD)message_len;
		newdata += sizeof(WORD);
		memcpy(newdata, szMessage, message_len);
		newdata += message_len;
		sendto(cur_sock, keep_ptr, (newdata - keep_ptr), 0, (sockaddr*)&to, sizeof(to));
		free(keep_ptr);
	}
}

int ProcessQueryPacket(unsigned int binaryAddress, unsigned short port, char* data, int length, SOCKET s)
{
	// Expecting atleast 10 bytes long data, starting first 4 bytes with "SAMP"
	if (length >= 11 && *(unsigned int*)data == 0x504D4153) {

		// Tell the user someone sent a request, if "logqueries" enabled
		if (bQueryLogging) {
			in_addr in;
			in.s_addr = binaryAddress;
			logprintf("[query:%c] from %s:%d", data[10], inet_ntoa(in), port);
		}

		// Data was in fact query request 
		return 1;
	}
	return 0;
}
