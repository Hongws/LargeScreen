#ifndef LARGESCREENDLL_H
#define LARGESCREENDLL_H

#define			PURCHASE_NUM			500				//列表数量
#define			TEXT_LENGTH				1024*2			//文章长度
#define			RULE_NUM				5				//文章长度

struct Purchase
{
    char eName[100];			//名称
    //int fPurchasedate;			//日期
    char fPurchasedate[15];
    int num;					//数量
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



extern "C" __declspec(dllexport) int my_lg_init();                                  /* 初始化 */
extern "C" __declspec(dllexport) int my_lg_getWelcomeConfig(MouseFlow &monthin, MouseFlow &monthout, MouseFlow &monthscrape, RuleList &rulelist, Title &title, char *videopath);                      /* 得到数据 */
extern "C" __declspec(dllexport) int my_lg_release();    /* 释放 */


#endif // LARGESCREENDLL_H
