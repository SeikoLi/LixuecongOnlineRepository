////////////////////////////////////////////////////////////////////////
///���ƣ�AutoTrader
///�汾��v1.0.2
///���ڣ�20140701
///˵������������CTP����  6.2.0_20131205_tradeapi_windows
///�汾��ctp 6.2.0_20131205   
///���ߣ�Сƽ����
///  QQ��1396144618
///�������ң�����Դ�����ȫ�����Լ����Զ�������ϵͳ��
/////////////////////////////////////////////////////////////////////////
// AutoTrader.cpp : �������̨Ӧ�ó������ڵ㡣
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

// UserApi����
CThostFtdcTraderApi *pUserApi;
// MdApi����
CThostFtdcMdApi *pMdApi;

int		RunMode = 1;		//����ģʽѡ��0=���ز��ԣ�1=ʵ������ ����ʾCommon.h������InstrumentID_En=0��ʵ�����߷���ģʽ��InstrumentID_En=1��ʵ�����߽���ģʽ��

// ���ò���
char  FRONT_ADDR_1A[] = "tcp://180.168.146.181:10000";		// ǰ�õ�ַ1����:ʵ��
char  FRONT_ADDR_1B[] = "tcp://180.168.146.181:10100";		// ǰ�õ�ַ1����:ʵ��
char  FRONT_ADDR_2A[] = "tcp://180.168.212.52:41205";		// ǰ�õ�ַ2����:ʵ��
char  FRONT_ADDR_2B[] = "tcp://180.168.212.53:41213";		// ǰ�õ�ַ2����:ʵ��
char  FRONT_ADDR_3A[] = "tcp://180.168.212.53:41205";		// ǰ�õ�ַ3����:ʵ�� �̺�
char  FRONT_ADDR_3B[] = "tcp://180.168.212.53:41213";		// ǰ�õ�ַ3����:ʵ�� �̺�

char  FRONT_ADDR_6A[] = "tcp://180.168.146.181:10000";	// ǰ�õ�ַ6����:���� 17:00��ʼ
char  FRONT_ADDR_6B[] = "tcp://180.168.146.181:10100";		// ǰ�õ�ַ6����:���� 17:00��ʼ

//TThostFtdcBrokerIDType	BROKER_ID = "0047";								// ���͹�˾����
//TThostFtdcInvestorIDType INVESTOR_ID = "023932";						// Ͷ���ߴ���
//TThostFtdcPasswordType  PASSWORD = "123456";							// �û�����
TThostFtdcBrokerIDType	BROKER_ID = "2030";							// ���͹�˾����:����
TThostFtdcInvestorIDType INVESTOR_ID = "00069";						// Ͷ���ߴ���:����"00069","00092"
TThostFtdcPasswordType  PASSWORD = "888888";							// �û�����:����

//char *ppInstrumentID[] = {"rb1410"};									// ���鶩���б�
//int iInstrumentID = 1;												// ���鶩������
//							0		1			2		  3			4		 5			6		   7		8			9		10		11		12		13		14		15		  16		17	   18		 19
char *ppInstrumentID[] = {  "i1509", "jm1509", "j1509", "rb1510","rb1509"};//���鶩���б�
//char *ppInstrumentID[] = {  "ag1412"};//���鶩���б�
int iInstrumentID = 1;													// ���鶩������

// User��������

// �����Ự����

// �����ⲿ����



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


	JustRun = true;													//����������־
	Erasefiles();
	Sleep(2000);

	cerr << "--->>> " << "Welcom MyAutoTrader System!" << endl;
	cerr << "--->>> " << "Version 1.0.3!" << endl;

	//ReadMdConfiguration();
	Sleep(8000);
	
	
	

	// ��ʼ��MdApi
	Sleep(8000);
	pMdApi = CThostFtdcMdApi::CreateFtdcMdApi("./thostmduserapi.dll");					// ����MdApi//"./thostmduserapi.dll"
	CThostFtdcMdSpi* pMdSpi = new CMdSpi();
	pMdApi->RegisterSpi(pMdSpi);									// ע���¼���
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
	cerr << "--->>> " << "��ʼ�����!" << endl;

	while(RunMode)	//ʵ��
	{
		//Sniffer();
		//Trading();
		Sleep(050);
	}

	while(!RunMode)	//���ز���
	{
		Sleep(050);
	}

}