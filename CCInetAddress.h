﻿#ifndef __CCNET_INETADDRESS_H__
#define __CCNET_INETADDRESS_H__

#include "cocos2d.h"
#include "CCNetMacros.h"
#include <string>

NS_CC_BEGIN

// dns parse
static std::string domainToIP(const char* pDomain)
{
	struct hostent* h = gethostbyname(pDomain);
	if( h != NULL ) 
	{
		unsigned char* p = (unsigned char *)(h->h_addr_list)[0];
		if( p != NULL )
		{
			char ip[16] = {0};
			sprintf(ip, "%u.%u.%u.%u", p[0], p[1], p[2], p[3]);
			return ip;
		}
	}
	return "";
}

/**
 * calss  : CCInetAddress
 * author : Jason lee
 * email  : jason.lee.c@foxmail.com
 * descpt : address define
 */
class CCInetAddress : public sockaddr_in
{
public:
	CCInetAddress();
	CCInetAddress(const char* ip, unsigned short port);
	CCInetAddress(const struct sockaddr* addr);
	virtual ~CCInetAddress(void);

public:
	operator struct sockaddr*();
	operator const struct sockaddr*() const;
	const char* getHostAddress() const;
	const char* getIp() const;
	unsigned short getPort() const;
	void setIp(const char* ip);
	void setIp(unsigned int ip);
	void setPort(unsigned short port);
	void setHost(const char* name);

public:
	int getLength();
};

NS_CC_END


#endif //__CCNET_INETADDRESS_H__