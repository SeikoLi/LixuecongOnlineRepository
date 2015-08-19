////////////////////////////////////////////////////////////////////////
///名称：AutoTrader
///版本：v1.0.2
///日期：20140701
///说明：基于上期CTP技术  6.2.0_20131205_tradeapi_windows
///版本：ctp 6.2.0_20131205   
///作者：小平常心
///  QQ：1396144618
///共享给大家，你可以打造完全属于自己的自动交易所系统了
/////////////////////////////////////////////////////////////////////////
// AutoTrader.cpp : 定义控制台应用程序的入口点。
//
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>

#include <stdlib.h>
using namespace std;

#include "..\ThostTraderApi\ThostFtdcTraderApi.h"
#include "..\ThostTraderApi\ThostFtdcMdApi.h"
#include "..\ThostTraderApi\ThostFtdcUserApiDataType.h"
#include "..\ThostTraderApi\ThostFtdcUserApiStruct.h"

#include "MdSpi.h"
#include "Common.h"


#pragma warning(disable : 4996)

// UserApi对象
CThostFtdcTraderApi *pUserApi;
// MdApi对象
CThostFtdcMdApi *pMdApi;

int		RunMode = 1;		//运行模式选择，0=本地测试，1=实盘运行 ，提示Common.h：设置InstrumentID_En=0，实盘在线仿真模式，InstrumentID_En=1，实盘在线交易模式，

// 配置参数
char  FRONT_ADDR_1A[] = "tcp://180.168.146.181:10000";		// 前置地址1交易:实盘
char  FRONT_ADDR_1B[] = "tcp://180.168.146.181:10100";		// 前置地址1行情:实盘
char  FRONT_ADDR_2A[] = "tcp://180.168.212.52:41205";		// 前置地址2交易:实盘
char  FRONT_ADDR_2B[] = "tcp://180.168.212.53:41213";		// 前置地址2行情:实盘
char  FRONT_ADDR_3A[] = "tcp://180.168.212.53:41205";		// 前置地址3交易:实盘 盘后
char  FRONT_ADDR_3B[] = "tcp://180.168.212.53:41213";		// 前置地址3行情:实盘 盘后

char  FRONT_ADDR_6A[] = "tcp://180.168.146.181:10000";	// 前置地址6行情:仿真 17:00开始
char  FRONT_ADDR_6B[] = "tcp://180.168.146.181:10100";		// 前置地址6行情:仿真 17:00开始

//TThostFtdcBrokerIDType	BROKER_ID = "0047";								// 经纪公司代码
//TThostFtdcInvestorIDType INVESTOR_ID = "023932";						// 投资者代码
//TThostFtdcPasswordType  PASSWORD = "123456";							// 用户密码
TThostFtdcBrokerIDType	BROKER_ID = "2030";							// 经纪公司代码:仿真
TThostFtdcInvestorIDType INVESTOR_ID = "00069";						// 投资者代码:仿真"00069","00092"
TThostFtdcPasswordType  PASSWORD = "888888";							// 用户密码:仿真

//char *ppInstrumentID[] = {"rb1410"};									// 行情订阅列表
//int iInstrumentID = 1;												// 行情订阅数量
//							0		1			2		  3			4		 5			6		   7		8			9		10		11		12		13		14		15		  16		17	   18		 19
char *ppInstrumentID[] = {  "i1509", "jm1509", "j1509", "rb1510","rb1509"};//行情订阅列表
//char *ppInstrumentID[] = {  "ag1412"};//行情订阅列表
int iInstrumentID = 1;													// 行情订阅数量

// User行情数据

// 声明会话参数

// 声明外部函数



void main(void)
{
	//void Erasefiles();                                              
	//bool ReadMdConfiguration();	
	bool ReadTradeConfiguration();	
	void _record0(char *txt);
	void Sniffer();
	void Trading();
	void test();
	void SendOrder(TThostFtdcInstrumentIDType FuturesId,int BuySell,int OpenClose,int i);


	JustRun = true;													//正在启动标志
	Erasefiles();
	Sleep(2000);

	cerr << "--->>> " << "Welcom MyAutoTrader System!" << endl;
	cerr << "--->>> " << "Version 1.0.3!" << endl;

	//ReadMdConfiguration();
	Sleep(8000);
	
	
	

	// 初始化MdApi
	Sleep(8000);
	pMdApi = CThostFtdcMdApi::CreateFtdcMdApi("./thostmduserapi.dll");					// 创建MdApi//"./thostmduserapi.dll"
	CThostFtdcMdSpi* pMdSpi = new CMdSpi();
	pMdApi->RegisterSpi(pMdSpi);									// 注册事件类
	pMdApi->RegisterFront(FRONT_ADDR_1B);							// connect
	//pMdApi->RegisterFront(FRONT_ADDR_2B);							// connect

	if (RunMode)
	{
		pMdApi->Init();
		cerr << "--->>> " << "Initialing MdApi" << endl;
	}
	else
	{
		cerr << "--->>> " << "Test Mode!" << endl;
	}
	
	//pMdApi->Join();
	//pMdApi->Release();
	
	Sleep(10000);	
	//ReadTradeConfiguration();
	Sleep(1000);
	cerr << "--->>> " << "初始化完成!" << endl;

	while(RunMode)	//实盘
	{
		//Sniffer();
		//Trading();
		Sleep(050);
	}

	while(!RunMode)	//本地测试
	{
		Sleep(050);
	}

}