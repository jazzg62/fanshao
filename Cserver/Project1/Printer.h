#pragma once
#include <windows.h> //����MultiByteToWideChar
#include "PrinterLibs.h"
#include <iostream>
#define DEFAULT_PRINTER "KPOS_58 Printer"

using namespace std;
class Printer {
public:
	Printer() {

	}

	// ������ӡ������
	bool open_prn(const char* s) {
		this->handle = Port_OpenPRNIO(s);
		if (Port_SetPort(this->handle)) {
			this->status = 1;
			return true;
		}
		this->status = 0;
		return false;
	}

	// �رմ�ӡ������,��ӡ������Ƕ��������ڵģ���ʱ��֧�ֹر�
	void close_prn() {
		//Port_ClosePort(this->handle);
	}

	// ��ѯ�����״̬
	char* query_status() {
		char buffer[1024] = { 0 };
		Pos_QueryStstus(buffer, 1, 3);
		return buffer;
	}

	/*
		����һ�����������ӡ���豸�������ַ�������,�ָ�
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
		�Զ����ӡ
	*/
	void print_line(std::string text) {
		Pos_Reset();
		Pos_Text(this->c2w(text.c_str()), 0, -1, 0, 0, 0, 0x08);
		Pos_Feed_N_Line(5);   // ÿ�δ�ӡ�м�ļ��
		// ��ӡ����֧�ְ���
		// Pos_HalfCutPaper();
	}

	// ����ģ���ӡ
	void print(std::string store_name, std::string print_text) {
		Pos_Reset();

		// ��ӡ��������ģ����������֮��ʹ�� ******* �ָ�
		Pos_Text(this->c2w(store_name.c_str()), 0, -2, 0, 0, 0, 0x08);
		Pos_Text(L"******************************************\n", 1, 1, 0, 0, 1, 0x08);
		Pos_Text(this->c2w(print_text.c_str()), 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"******************************************\n", 1, 1, 0, 0, 1, 0x08);

		/*Pos_Text(L"�ഺ��վ\n", 0, -2, 0, 0, 0, 0x08);
		Pos_Text(L"******************************************\n", 1, 1, 0, 0, 1, 0x08);
		Pos_Text(L"֧��������ɨ��֧��\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"������1.11\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"  ȯ�ֿۣ�1.10\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"����ֿۣ�0.00\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"ʵ����1.11\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"�ƹ���ɣ�1.10\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"  ����ѣ�0.20\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"�µ��û���18955756387\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"�µ����ڣ�2022-1-10 15:30:22\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"֧����ʽ��΢��֧��\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"������1.10\n", 0, -1, 0, 0, 0, 0x08);
		Pos_Text(L"******************************************\n", 1, 1, 0, 0, 1, 0x08);*/

		// ��ά��
		//Pos_FeedLine();
		//Pos_Text(L"ɨ��鿴֧������\n", 0, -2, 0, 0, 0, 0x08);
		//Pos_Reset();
		//Pos_Align(1);
		//Pos_Qrcode(L"https://pay.cnqilian.com/dist/?name=success&ddh=163790480433574839", 1, 9);

		Pos_Feed_N_Line(5); // ÿ�δ�ӡ�м�ļ��
	}

private:
	// ��ӡ��״̬
	int status = 0;
	// ��ӡ�����
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