#pragma once
#include <windows.h> //声明MultiByteToWideChar
#include "PrinterLibs.h"
#include <iostream>
#define DEFAULT_PRINTER "KPOS_58 Printer"

using namespace std;
class Printer {
public:
	Printer() {

	}

	// 开启打印机服务
	bool open_prn(const char* s) {
		this->handle = Port_OpenPRNIO(s);
		if (Port_SetPort(this->handle)) {
			this->status = 1;
			return true;
		}
		this->status = 0;
		return false;
	}

	// 关闭打印机服务,打印机是内嵌到计算机内的，暂时不支持关闭
	void close_prn() {
		//Port_ClosePort(this->handle);
	}

	// 查询计算机状态
	char* query_status() {
		char buffer[1024] = { 0 };
		Pos_QueryStstus(buffer, 1, 3);
		return buffer;
	}

	/*
		返回一个包含多个打印机设备驱动的字符串，由,分割
	*/
	char* query_driver_list() {
		char prnrbuf[1024] = { 0 };
		char res[1024] = { 0 };
		int prnsub = Port_EnumPRN(prnrbuf, 1024);
		char* s4 = prnrbuf;
		while (strlen(s4))
		{
			strcat(res, s4);
			strcat(res, ",");
			s4 += strlen(s4) + 1;
		}
		return res;
	}

	/*
		自定义打印
	*/
	void print_line(std::string text) {
		Pos_Reset();
		Pos_Text(this->c2w(text.c_str()), 0, -1, 0, 0, 0, 0x08);
		Pos_Feed_N_Line(5);   // 每次打印中间的间隔
		// 打印机不支持半切
		// Pos_HalfCutPaper();
	}

	// 根据模板打印
	void print(std::string store_name, std::string print_text) {
		Pos_Reset();

		// 打印标题和正文，标题和正文之间使用 ******* 分割
		Pos_Text(this->c2w(store_name.c_str()), 0, -2, 0, 0, 0, 0x08);
		Pos_Text(L"******************************************\n", 1, 1, 0, 0, 1, 0x08);
		Pos_Text(this->c2w(print_text.c_str()), 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"******************************************\n", 1, 1, 0, 0, 1, 0x08);

		/*Pos_Text(L"青春驿站\n", 0, -2, 0, 0, 0, 0x08);
		Pos_Text(L"******************************************\n", 1, 1, 0, 0, 1, 0x08);
		Pos_Text(L"支付场景：扫码支付\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"订单金额：1.11\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"  券抵扣：1.10\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"红包抵扣：0.00\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"实付金额：1.11\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"推广提成：1.10\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"  服务费：0.20\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"下单用户：18955756387\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"下单日期：2022-1-10 15:30:22\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"支付方式：微信支付\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"订单金额：1.10\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"******************************************\n", 1, 1, 0, 0, 1, 0x08);*/

		// 二维码
		//Pos_FeedLine();
		//Pos_Text(L"扫码查看支付详情\n", 0, -2, 0, 0, 0, 0x08);
		//Pos_Reset();
		//Pos_Align(1);
		//Pos_Qrcode(L"https://pay.cnqilian.com/dist/?name=success&ddh=163790480433574839", 1, 9);

		Pos_Feed_N_Line(5); // 每次打印中间的间隔
	}

private:
	// 打印机状态
	int status = 0;
	// 打印机句柄
	void* handle = 0;

	wchar_t* c2w(const char* str)
	{
		int length = strlen(str) + 1;
		wchar_t* t = (wchar_t*)malloc(sizeof(wchar_t) * length);
		if (t == 0)
			return t;
		memset(t, 0, length * sizeof(wchar_t));
		MultiByteToWideChar(CP_ACP, 0, str, strlen(str), t, length);
		return t;
	}
};