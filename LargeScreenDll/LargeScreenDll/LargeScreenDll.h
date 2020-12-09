// LargeScreenDll.h : LargeScreenDll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


//http json
#include "HttpClient.h"
#include "json.h"
#include <sstream>

#pragma warning(disable:4996)


#define			PURCHASE_NUM			500				//�б�����
#define			TEXT_LENGTH				1024*2			//���³���
#define			RULE_NUM				5				//���³���

struct Purchase
{
	char eName[100];			//����
	//int fPurchasedate;			//����
	char fPurchasedate[15];
	int num;					//����
	bool urgent;

	Purchase()
	{
		memset(eName, 0, sizeof(eName));
		memset(fPurchasedate, 0, sizeof(fPurchasedate));
		//fPurchasedate = 0;
		num = 0;
		urgent = false;
	}
};

//���  ����  ����
struct MouseFlow
{
	int totalCount;
	Purchase purchase[PURCHASE_NUM];

	MouseFlow()
	{
		totalCount = 0;
	}
};

struct Rule
{
	bool enable;
	char text[TEXT_LENGTH];

	Rule()
	{
		enable = false;
		memset(text, 0, sizeof(text));
	}
};

struct RuleList
{
	int totalCount;
	Rule rule[RULE_NUM];

	RuleList()
	{
		totalCount = 0;
	}
};

struct Title
{
	int size;
	char words[50];

	Title()
	{
		size = 0;
		memset(words, 0, sizeof(words));
	}
};

string g_Http_IP;
string g_Http_Port;
//char g_TmpViedoPath[500];

std::string Utf8ToString(const char* pbuf, int bufsize);

int getWelcomeConfig(MouseFlow &monthin, MouseFlow &monthout, MouseFlow &monthscrape, RuleList &rulelist, Title &title, char *videopath);
//Json
int getWelcomeConfig_json(MouseFlow &monthin, MouseFlow &monthout, MouseFlow &monthscrape, RuleList &rulelist, Title &title, char *videopath);                      /* �õ����� */

extern "C" __declspec(dllexport) int my_lg_init();                                  /* ��ʼ�� */
extern "C" __declspec(dllexport) int my_lg_getWelcomeConfig(MouseFlow &monthin, MouseFlow &monthout, MouseFlow &monthscrape, RuleList &rulelist, Title &title, char *videopath);                      /* �õ����� */
extern "C" __declspec(dllexport) int my_lg_release();     /* �ͷ� */


bool HttpDownFile(                          /*���� */
	const CString & strFileURLInServer,     /* �������ļ���URL */
	const CString & strFileLocalFullPath);  /* ��ŵ����ص�·�� */
