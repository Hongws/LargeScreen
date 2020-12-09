// LargeScreenDll.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "LargeScreenDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

std::string Utf8ToString(const char* pbuf, int bufsize)
{
	int nwLen = MultiByteToWideChar(CP_UTF8, 0, pbuf, -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//一定要加1，不然会出现尾巴  
	memset(pwBuf, 0, nwLen * 2 + 2);

	MultiByteToWideChar(CP_UTF8, 0, pbuf, bufsize, pwBuf, nwLen);

	int nLen = WideCharToMultiByte(CP_ACP, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];
	memset(pBuf, 0, nLen + 1);

	WideCharToMultiByte(CP_ACP, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr = std::string(pBuf, nLen + 1);

	delete[]pBuf;
	delete[]pwBuf;

	pBuf = NULL;
	pwBuf = NULL;

	return retStr;
}

int getWelcomeConfig(MouseFlow &monthin, MouseFlow &monthout, MouseFlow &monthscrape, RuleList &rulelist, Title &title, char *videopath)
{
	return iRet;
}

//Json 通过http接口来解析Json格式来获取内容
int getWelcomeConfig_json(MouseFlow &monthin, MouseFlow &monthout, MouseFlow &monthscrape, RuleList &rulelist, Title &title, char *videopath)                      /* 得到数据 */
{
	return iRet;
}

extern "C" __declspec(dllexport) int my_lg_init()                                  /* 初始化 */
{
	char app_path[MAX_PATH] = "";
	char set_path[MAX_PATH] = "";
	GetCurrentDirectory(MAX_PATH, app_path);
	sprintf(set_path, "%s\\%s", app_path, "NetSet.ini");

	char str[100] = "";
	GetPrivateProfileString("NetWork", "HTTP_IP", "", str, sizeof(str), set_path);
	g_Http_IP = str;

	GetPrivateProfileString("NetWork", "HTTP_PORT", "", str, sizeof(str), set_path);//端口
	g_Http_Port = str;

	
	return 0;
}


extern "C" __declspec(dllexport) int my_lg_getWelcomeConfig(MouseFlow &monthin, MouseFlow &monthout, MouseFlow &monthscrape, RuleList &rulelist, Title &title, char *videopath)                      /* 得到数据 */
{
	return getWelcomeConfig(monthin, monthout, monthscrape, rulelist, title, videopath);
}


extern "C" __declspec(dllexport) int my_lg_release()    /* 释放 */
{
	return 0;
}



bool HttpDownFile(const CString& strFileURLInServer, //待下载文件的URL 
	const CString & strFileLocalFullPath)//存放到本地的路径 
{
	return bReturn;
}
