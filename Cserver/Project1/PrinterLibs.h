#ifndef _PRINTERLIBS_H_
#define _PRINTERLIBS_H_

#define CSNPRINTERLLIBS_EXPORTS
#ifdef CSNPRINTERLLIBS_EXPORTS
#define CSNPRINTERLLIBS __declspec(dllexport)
#else
#define CSNPRINTERLLIBS __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

	/****************************************�˿ڲ�������*****************************************/
	// ö�ٴ���
	// buffer
	//     ��������˿��б�Ļ�����
	// length
	//     �������ֽ���
	// prequired
	//     ��Ҫ�Ļ������ֽ���
	// return
	//     ö�ٵ��Ķ˿�����
	CSNPRINTERLLIBS size_t Port_EnumCOM(char *buffer, size_t length);
	// ö��USB
	//  buffer
	//      ��������˿��б�Ļ�����
	//  length
	//      �������ֽ���
	//  prequired
	//      ��Ҫ�Ļ������ֽ���
	//  return
	//      ö�ٵ��Ķ˿�����
	CSNPRINTERLLIBS size_t Port_EnumUSB(char *buffer, size_t length);
	// ö�ٲ���
	// buffer
	//     ��������˿��б�Ļ�����
	// length
	//     �������ֽ���
	// prequired
	//     ��Ҫ�Ļ������ֽ���
	// return
	//     ö�ٵ��Ķ˿�����
	CSNPRINTERLLIBS size_t Port_EnumLPT(char *buffer, size_t length);
	// ö�ٱ��ش�ӡ����
	//  buffer
	//      ��������˿��б�Ļ�����
	//  length
	//      �������ֽ���
	//  prequired
	//      ��Ҫ�Ļ������ֽ���
	//  return
	//      ö�ٵ��Ķ˿�����
	CSNPRINTERLLIBS size_t Port_EnumPRN(char *buffer, size_t length);

	// �򿪴���
	// name 
	//      �˿����ƣ�������EnumCOM()��ȡ
	//      ���磺COM1��COM2��COM3��...COM11...
	// baudrate 
	//      ������
	//      һ��ȡ 9600,19200,38400,57600,115200.
	//		Ĭ��ֵ 9600
	//      ��Ҫ�ʹ�ӡ�������ʱ���һ�£�����ʹ�ø߲������Ի�ýϺõĴ�ӡ�ٶ�
	// flowcontrol
	//      �����ƣ���ֵ�������£���Ĭ��ֵΪ0��
	//      ֵ    ����
	//      0     ������
	//      1     DsrDtr
	//      2     CtsRts
	//		3	  Xon/Xoff
	// parity 
	//      У��λ����ֵ�������£���Ĭ��ֵΪ0��
	//      ֵ    ����
	//      0     ��У��
	//      1     ��У��
	//      2     żУ��
	//      3     ���У��
	//      4     �հ�У��
	// databits
	//      ����λ����Χ[4,8]��Ĭ��ֵΪ8��
	// stopbits 
	//      ֹͣλ����ֵ�������£���Ĭ��ֵΪ0��
	//      ֵ    ����
	//      0     1λֹͣλ
	//      1     1.5λֹͣλ
	//      2     2λֹͣλ
	//
	// return 
	//      ���ش򿪵Ķ˿ھ���������ʾ�򿪳ɹ������ʾ��ʧ�ܡ�
	//
	// remarks
	//      ������ڱ�ռ�ã��򿪴��ڻ�ʧ�ܡ�
	//      ��������ʺʹ�ӡ�������ʲ�ƥ�䣬���޷���ӡ��
	CSNPRINTERLLIBS void * Port_OpenCOMIO(const char *name, unsigned int baudrate = 9600, const int flowcontrol = 0, const int parity = 0, const int databis = 8, const int stopbits = 0);
	// ��USB
	// name 
	//      �˿����ƣ�����EnumUSB���
	// return 
	//      ���ش򿪵Ķ˿ھ���������ʾ�򿪳ɹ������ʾ��ʧ�ܡ�
	// remarks
	//      USB ��ӡ���ӵ������ϣ�����豸�������г�����"USB Printing Support"����"USB��ӡ֧��"�������ʹ�øú����򿪡�
	CSNPRINTERLLIBS void * Port_OpenUSBIO(const char *name);
	// ��LPT
	// name 
	//      �˿����ƣ�����EnumLPT���
	//		���磺LPT1,LPT2,LPT3...
	// return 
	//      ���ش򿪵Ķ˿ھ���������ʾ�򿪳ɹ������ʾ��ʧ�ܡ�
	// remarks
	//      ����ֻ�е���ͨѶ��ֻ��д���ɶ���
	//      һ�в�ѯ״̬�ĺ������Բ�����˵������Ч�ġ�
	CSNPRINTERLLIBS void * Port_OpenLPTIO(const char *name);
	// �򿪴�ӡ��
	// name
	//      ��ӡ�����ƣ�����EnumPRN��ã�
	//      ���磺POS58 Printer
	// return 
	//      ���ش򿪵Ķ˿ھ���������ʾ�򿪳ɹ������ʾ��ʧ�ܡ�
	// remarks
	//      �󲿷�������֧�ֵ���ͨѶ����ʱ�����ѯ��������Ч
	CSNPRINTERLLIBS void * Port_OpenPRNIO(const char *name);
	// ������
	// ip 
	//      ��ַ������
	//      ���磺192.168.1.87 
	// port 
	//      �˿ں�
	//      �̶�ֵ��9100
	// return 
	//      ���ش򿪵Ķ˿ھ���������ʾ�򿪳ɹ������ʾ��ʧ�ܡ�
	// remarks
	//      PC�ʹ�ӡ����Ҫͬ���εĲſ�������
	CSNPRINTERLLIBS void * Port_OpenTCPIO(const char *ip, const unsigned short port);
	// ���ô�ӡ��ͨѶ�˿�
	// handle 
	//      ͨ��OpenXXX()����ȡ�Ķ˿ھ��
	// return 
	//      ����true�������óɹ���false��������ʧ�ܡ�
	CSNPRINTERLLIBS bool Port_SetPort(void *handle);
	// �رմ�ӡ��ͨѶ�˿�
	// handle 
	//      ͨ��OpenXXX()����ȡ�Ķ˿ھ��
	// return 
	//      
	CSNPRINTERLLIBS void Port_ClosePort(void *handle);
	/****************************************�˿ڲ�������*****************************************/
	// ���ô�ӡ��
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	CSNPRINTERLLIBS bool Pos_Reset();
	// ��ӡ����ҳ
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	CSNPRINTERLLIBS bool Pos_SelfTest();
	// ��ֽһ��
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	CSNPRINTERLLIBS bool Pos_FeedLine();
	// �����ȵ�����ֽ(һ����0.125mm)
	// n
	//		��Ҫ��ֽ�ĵ���
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	CSNPRINTERLLIBS bool Pos_FeedHot(int n);
	// ��������ֽ
	// n
	//		��Ҫ��ֽ��������
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	CSNPRINTERLLIBS bool Pos_Feed_N_Line(int n);
	// ��ֽ����һ����ǩ��
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	// remarks
	//      ��APIֻ��ԷǱ�׼��ǩָ��Ĵ�ӡ������ִ��ESC/POS��ָ��ı�ǩ�������ͺţ�LPM-261
	CSNPRINTERLLIBS bool Pos_FeedNextLable();
	// ��ֽ����һ���ڱ괦
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	// remarks
	//      ��APIֻ����кڱ깦�ܵĴ�ӡ����
	CSNPRINTERLLIBS bool Pos_BlackMark();
	// ���ö��뷽ʽ
	// value
	//      ���ö��뷽ʽ����ֵ�������£�
	//      ֵ    ����
	//      0     �����
	//      1     ���ж���
	//      2     �Ҷ���
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	// remarks
	//      ��API�����ڶ���ָ�����������Ҫ�����API�����ڲ��䡣
	CSNPRINTERLLIBS bool Pos_Align(int value);
	// �����и�
	// value
	//      �����иߵ���(һ����0.125mm)����Χ[0,255]
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	CSNPRINTERLLIBS bool Pos_SetLineHeight(int value);
	// ��ӡ�ı�
	// prnText
	//		��Ҫ��ӡ���ı�
	// nLan
	//		��ӡ���ı��������ͣ���ֵ�������£�
	//      ֵ    ����
	//      0     GBK
	//      1     UTF-8
	//      3     BIG-5
	//		4	  SHIFT-JIS
	//		5	  EUC-KR
	// nOrgx
	//		��ӡ���ı�λ�ã���ֵ�������£�
	//      ֵ    ����
	//      -1    �����
	//      -2    ���ж���
	//      -3    �Ҷ���
	//		>=0	  �ڵ�n��λ�ÿ�ʼ��ӡ
	// nWidthTimes
	//		�ַ��Ŵ�ı�������Χ[0,7]
	// nHeightTimes
	//		�ַ��Ŵ�ı�������Χ[0,7]
	// FontType
	//		��ӡ���������ͣ���ֵ�������£�
	//      ֵ    ����
	//      0	  12*24
	//		1	  9*17
	// nFontStyle
	//		��ӡ���������ͣ���ֵ�������£�
	//      ֵ		����
	//      0x00	����
	//		0x08	�Ӵ�
	//		0x80    1���»���
	//		0x100   2���»���
	//		0x200	���ô�ӡ
	//		0x400	���ԡ��ڵװ���
	//		0x1000	ÿ���ַ�˳ʱ����ת 90 ��
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	// remarks
	//      nFontStyle��ֵ�ǿ���ͨ�� | ������ʵ�ֶ��ַ��ͬʱ���ֵġ�
	CSNPRINTERLLIBS bool Pos_Text(const wchar_t *prnText, int nLan, int nOrgx, int nWidthTimes, int nHeightTimes, int FontType, int nFontStyle);

	// ����������
	// nBeepCount
	//      ���д���
	// nMillis
	//      ��������ʱ�䣬ȡֵ��Χ[100,900]��ȡ�����ٺ��롣
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	// remarks
	//      ��ȷ�ϴ�ӡ���Ƿ��з��������ܡ�
	CSNPRINTERLLIBS bool Pos_Beep(unsigned char nCount, unsigned char nMillis);
	// ��Ǯ��
	// nId
	//      ��Ǯ�䣬ֵ��Χ[0,1]
	// nHightTime
	//      �ߵ�ƽ����ʱ��
	// nLowTime 
	//      �͵�ƽ����ʱ��
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	// remarks
	//      ��ȷ�ϴ�ӡ���Ƿ��д�Ǯ�书�ܡ�
	CSNPRINTERLLIBS bool Pos_KiskOutDrawer(int nId, int nHightTime = 20, int nLowTime = 60);
	// ִ��ȫ��
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	// remarks
	//      ��ȷ�ϴ�ӡ���Ƿ���ȫ�й��ܡ�
	CSNPRINTERLLIBS bool Pos_FullCutPaper();
	// ִ�а���
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	// remarks
	//      ��ȷ�ϴ�ӡ���Ƿ���ȫ�й��ܡ�
	CSNPRINTERLLIBS bool Pos_HalfCutPaper();
	// ��ӡ����
	// BarcodeData
	//		��ӡ����������
	// nBarcodeType
	//		��ӡ���������ͣ���ֵ�������£�
	//      ֵ		 ����
	//      0x41     UPC-A
	//      0x42     UPC-E
	//      0x43     EAN13
	//      0x44     EAN8
	//      0x45     CODE39
	//      0x46     ITF
	//      0x47     CODABAR
	//      0x48     CODE93
	// nOrgx
	//		��ӡ������λ�ã���ֵ�������£�
	//      ֵ    ����
	//      -1    �����
	//      -2    ���ж���
	//      -3    �Ҷ���
	//		>=0	  �ڵ�n��λ�ÿ�ʼ��ӡ
	// nUnitWidth
	//		��ӡ�������ȣ�ֵ��Χ[1,6]
	// nUnitHeight
	//		��ӡ������߶ȣ�ֵ��Χ[1,255]
	// nFontStyle
	//		�ɶ��ַ���HRI�����������ͣ���ֵ�������£�
	//      ֵ    ����
	//      0     12*24
	//      1     9*17
	// FontPosition
	//		�ɶ��ַ���HRI���Ĵ�ӡλ�ã���ֵ�������£�
	//      ֵ    ����
	//      0     ����ӡ
	//      1     �����Ϸ�
	//      2     �����·�
	//		3	  �����Ϸ����·�
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	// remarks
	//      nUnitWidth���������ӡ�߽磬�򲻴�ӡ��
	CSNPRINTERLLIBS bool Pos_Barcode(const char * BarcodeData, int nBarcodeType, int nOrgx, int nUnitWidth, int nUnitHeight, int nFontStyle, int FontPosition);
	// ��ӡ��ά��
	// QrcodeData
	//		��ά�������
	// nWidth
	//		��ά��Ŀ��,ȡֵ��Χ[1,6]
	//		��ά�뵥Ԫ���Խ��,QR��Խ��
	// nVersion
	//		��ά��Ĺ��,ȡֵ��Χ[0,16],0��ʾ�Զ�����汾��
	//		��ά����汾Խ���ܱ�����ַ���Խ�࣬QR��ҲԽ��
	// nErrlevenl
	//		��ά�����ȼ�,ȡֵ[1,4]
	// return 
	//		����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	// remarks
	//		�����ӡ�Ķ�ά�볬����ӡ�߽磬�򲻴�ӡ��
	CSNPRINTERLLIBS bool Pos_Qrcode(const wchar_t *QrcodeData, int nWidth = 2, int nVersion = 0, int nErrlevenl = 4);
	// ESC/POS�汾��ά��
	// QrcodeData
	//      ��ά�����ݡ�
	// nWidth
	//		��ά��Ŀ��,ȡֵ��Χ[1,16]
	//		��ά�뵥Ԫ���Խ��,QR��Խ��
	// nErrlevenl
	//		��ά�����ȼ�,ȡֵ[1,4]��
	// return 
	//		����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	// remarks
	//		��ȷ�϶�ά���С,��Ϊ��API����Ҳ���ӡ,�ᵼ���޷�����ɨ�衣
	CSNPRINTERLLIBS bool Pos_EscQrcode(const wchar_t *QrcodeData, int nWidth = 4, int nErrlevenl = 4);
	// ��ӡ˫��ά��
	// QrcodeData1
	//      ��һ����ά������ݡ�
	// QR1Position
	//      ��һ����ά�뿪ʼ��ӡ��λ��
	// QR1Version
	//      ��һ����ά��Ĺ�񣬷�Χ[0��19]
	// QR1Ecc
	//      ��һ����ά��ľ���ȼ�����Χ[0,3]
	// QrcodeData2
	//      �ڶ�����ά������ݡ�
	// QR2Position
	//      �ڶ�����ά�뿪ʼ��ӡ��λ��
	// QR2Version
	//      �ڶ�����ά��Ĺ��[0,19]
	// QR2Ecc
	//      �ڶ�����ά��ľ���ȼ�,��Χ[0,3]
	// ModuleSize
	//      ��ά��ģ��Ĵ�С����Χ[1��8]
	// remarks
	//      �����ӡʧ�ܣ���ע����ڶ�����ά���ӡ��λ���Ƿ����һ���ص����ߴ�ӡ�󳬳���ӡ�߽硣
	CSNPRINTERLLIBS bool Pos_DoubleQrcode(const wchar_t *QrcodeData1,int QR1Position,int QR1Version, int QR1Ecc, const wchar_t *QrcodeData2, int QR2Position, int QR2Version, int QR2Ecc, int ModuleSize);

	// ��ӡͼƬ
	// FileName
	//		ͼƬ·����
	// nWidth
	//		ָ����ӡ����ӡ��ͼƬ�Ŀ��(����)
	//		2���ӡ�����ֵΪ384
	//		3���ӡ�����ֵΪ576
	// nBinaryAlgorithm
	//		ͼƬ�����ģʽ����ֵ�������£�
	//		ֵ    ����
	//		0     �����㷨		���㷨�Բ�ɫͼƬ��ӡЧ���Ϻ�
	//		1     ƽ����ֵ�㷨	���㷨�Դ�����ͼƬ��ӡЧ���Ϻ�
	// return 
	//		����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	CSNPRINTERLLIBS bool Pos_ImagePrint(const wchar_t *FileName, int nWidth = 384, int nBinaryAlgorithm = 0);
	// ��ӡԤ�ص�Logo
	// n
	//		��ӡ��n��Logo,��Χ[1,9]
	// nMode
	//		ָ����ӡLogo��ģʽ��ֵ�������£�
	//      ֵ    ����
	//      0     ��ͨ
	//      1     ����
	//      2     ����
	//		3	  ���� | ����
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	// remarks
	//      �����ӡ������Ԥ�ص�Logo�򲻴�ӡ�����ô�ӡ������Ԥ�ء�
	CSNPRINTERLLIBS bool Pos_PrintNVLogo(unsigned short nLogo, unsigned short nWidth = 0);

	/*******************************************��ѯģ��*********************************************/
	// ��ѯ��ӡ������
	// nTimeout
	//		��ʱ�ĺ�������
	// return
	//		���ش����ֵ����ֵ�Ķ���Ϊ��
	//      ֵ		����
	//      1		��ӡ������
	//      -1		��ӡ���ѻ�
	//      -2		��ӡ���ϸǴ�
	//      -3		��ӡ��ȱֽ
	//      -4		��ӡ���е��쳣
	//      -5		��ӡ��ͷƬ�¶ȹ���
	//      -6		��ѯʧ��
	// remarks
	//      ��API�޷�һ�η��ض���쳣״̬�������ȡ����쳣����ʹ��Pos_QueryStstus��������ʵ�֡������ڴ�ӡ�����в����ѯ������
	CSNPRINTERLLIBS int Pos_QueryPrinterErr(unsigned long nTimeout = 3000);

	// ��ѯ��ӡ������
	// rBuffer
	//		�����ӡ�����ص�״̬
	// type
	//		��ѯ�����ݱ�[1,4]��������뿴˵���ĵ���
	// nTimeout
	//		��ʱ�ĺ�������
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	// remarks
	//      ��API�޷�һ�η��ض���쳣״̬�������ȡ����쳣����ʹ��Pos_QueryStstus��������ʵ�֡�
	CSNPRINTERLLIBS bool Pos_QueryStstus(char *rBuffer, int type, unsigned long nTimeout);

	/*******************************************����ģ��*********************************************/
	// ���ô�ӡ��������
	// nBaudrate
	//		���ô�ӡ���Ĳ����ʡ�
	//		���磺9600 19200 38400 57600 115200
	// return 
	//      ����true�������óɹ���false��������ʧ�ܡ�
	// remarks
	//      ����ô�������ʱ�������겨���ʺ�������ִ��OpenCOM��
	CSNPRINTERLLIBS bool Pos_SetPrinterBaudrate(int nBaudrate);
	// ���ô�ӡ����������
	// nFontStyle
	//		����������,��ֵ�������£�
	//		ֵ      ����
	//		0		9*17
	//		1		12*24
	//		2		9*24
	//		3		16*18
	// nDensity
	//		����Ũ��,��ֵ�������£�
	//		ֵ      ����
	//		0		΢��
	//		1		����
	//		2		΢Ũ
	//		3		��Ũ��
	// nLine 
	//      ���ý�ֽģʽ,��ֵ�������£�
	//		ֵ      ģʽ
	//		0		0x0A
	//		1		0x0D
	// nBeep 
	//      �Ƿ����÷�����,��ֵ�������£�
	//		ֵ      ����
	//		0		�رշ�����
	//		1		����������
	// nCut 
	//      �Ƿ����÷�����,��ֵ�������£�
	//		ֵ      ����
	//		0		�ر��е�����
	//		1		�����е�����
	// remarks
	//      ����������÷�˫�ֽ��ı�,�������ĺ��ĵ������Ϊ24*24�޷��޸ġ�
	//		������������ȷ��ʹ�õĻ����Ƿ���з���������
	//		�е�������ȷ��ʹ�õĻ����Ƿ�����е�����
	CSNPRINTERLLIBS bool Pos_SetPrinterBasic(int nFontStyle, int nDensity, int nLine, int nBeep, int nCut);

	/*******************************************PAGEģ��*********************************************/
	// ѡ��ҳģʽ
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	// remarks
	//      ��ȷ�ϴ�ӡ���Ƿ���ҳģʽ����,ҳģʽ�²���ֱ�Ӵ�ӡ,��Ҫ�������������Page_PrintPage��
	CSNPRINTERLLIBS bool Page_SelectPageMode();
	// ��ӡҳģʽ�µ�����
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	// remarks
	//      ��ȷ�ϴ�ӡ���Ƿ���ҳģʽ����,ҳģʽ�²���ֱ�Ӵ�ӡ,��Ҫ�������������Page_PrintPage��
	CSNPRINTERLLIBS bool Page_PrintPage();
	// �˳�ҳģʽ
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	CSNPRINTERLLIBS bool Page_ExitPageMode();
	// ����������Դ�ӡλ��
	// nPosition
	//      ��ӡλ��
	//
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	CSNPRINTERLLIBS bool Page_SetVerticalAbsolutePrintPosition(unsigned short nPosition);
	// ���ú�����Դ�ӡλ��
	// nPosition
	//      ��ӡλ��
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	CSNPRINTERLLIBS bool Page_SetHorizontalAbsolutePrintPosition(unsigned short nPosition);
	// ����������Դ�ӡλ��
	// nPosition
	//      ��ӡλ��
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	CSNPRINTERLLIBS bool Page_SetVerticalRelativePrintPosition(unsigned short nPosition);
	// ���ú�����Դ�ӡλ��
	// nPosition
	//      ��ӡλ��
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	CSNPRINTERLLIBS bool Page_SetHorizontalRelativePrintPosition(unsigned short nPosition);
	// ҳģʽ�����ô�ӡ����
	// nDirection
	//      ��ӡ�����򣬸�ֵ�������£�
	//      0    ������
	//      1    ���µ���
	//      2    ���ҵ���
	//      3    ���ϵ���
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	CSNPRINTERLLIBS bool Page_SetPageModeDrawDirection(unsigned short nPosition);
	// ҳģʽ������ҳ����
	// x
	//      ������ʼλ��
	//
	// y
	//      ������ʼλ��
	//
	// w
	//      ��ӡ������
	//
	// h
	//      ��ӡ����߶�
	//
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	CSNPRINTERLLIBS bool Page_SetPageArea(unsigned short x, unsigned short y, unsigned short w, unsigned short h);
	// ҳģʽ��UNICODE�ı�
	// prnText
	//		��Ҫ��ӡ��UNICODE�ı�
	// nOrgx
	//		��ӡ���ı�λ�ã���ֵ�������£�
	//      ֵ    ����
	//      -1    �����
	//      -2    ���ж���
	//      -3    �Ҷ���
	//		>=0	  �ڵ�n��λ�ÿ�ʼ��ӡ
	// nWidthTimes
	//		�ַ��Ŵ�ı�������Χ[0,7]
	// nHeightTimes
	//		�ַ��Ŵ�ı�������Χ[0,7]
	// FontType
	//		��ӡ���������ͣ���ֵ�������£�
	//      ֵ    ����
	//      0	  12*24
	//		1	  9*17
	// nFontStyle
	//		��ӡ���������ͣ���ֵ�������£�
	//      ֵ		����
	//      0x00	����
	//		0x08	�Ӵ�
	//		0x80    1���»���
	//		0x100   2���»���
	//		0x200	���ô�ӡ
	//		0x400	���ԡ��ڵװ���
	//		0x1000	ÿ���ַ�˳ʱ����ת 90 ��
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	// remarks
	//      nFontStyle��ֵ�ǿ���ͨ��&������ʵ�ֶ��ַ��ͬʱ���ֵġ�
	CSNPRINTERLLIBS bool Page_UnicodeText(const char *prnText, int nOrgx, int nWidthTimes, int nHeightTimes, int FontType, int nFontStyle);
	// ҳģʽ�´�ӡ�ı�
	// prnText
	//		��Ҫ��ӡ���ı�
	// nLan
	//		��ӡ���ı��������ͣ���ֵ�������£�
	//      ֵ    ����
	//      0     GBK
	//      1     UTF-8
	//      3     BIG-5
	//		4	  SHIFT-JIS
	//		5	  EUC-KR
	// nOrgx
	//		��ӡ���ı�λ�ã���ֵ�������£�
	//      ֵ    ����
	//      -1    �����
	//      -2    ���ж���
	//      -3    �Ҷ���
	//		>=0	  �ڵ�n��λ�ÿ�ʼ��ӡ
	// nWidthTimes
	//		�ַ��Ŵ�ı�������Χ[0,7]
	// nHeightTimes
	//		�ַ��Ŵ�ı�������Χ[0,7]
	// FontType
	//		��ӡ���������ͣ���ֵ�������£�
	//      ֵ    ����
	//      0	  12*24
	//		1	  9*17
	// nFontStyle
	//		��ӡ���������ͣ���ֵ�������£�
	//      ֵ		����
	//      0x00	����
	//		0x08	�Ӵ�
	//		0x80    1���»���
	//		0x100   2���»���
	//		0x200	���ô�ӡ
	//		0x400	���ԡ��ڵװ���
	//		0x1000	ÿ���ַ�˳ʱ����ת 90 ��
	// return 
	//      ����true����д��ɹ���false����д��ʧ�ܡ�
	// remarks
	//      nFontStyle��ֵ�ǿ���ͨ��&������ʵ�ֶ��ַ��ͬʱ���ֵġ�
	CSNPRINTERLLIBS bool Page_Text(const wchar_t *prnText, int nLan, int nOrgx, int nWidthTimes, int nHeightTimes, int FontType, int nFontStyle);
	// ��ҳģʽ�´�ӡ����
	// BarcodeData
	//		��ӡ����������
	// nBarcodeType
	//		��ӡ���������ͣ���ֵ�������£�
	//      ֵ		 ����
	//      0x41     UPC-A
	//      0x42     UPC-E
	//      0x43     EAN13
	//      0x44     EAN8
	//      0x45     CODE39
	//      0x46     ITF
	//      0x47     CODABAR
	//      0x48     CODE93
	// nOrgx
	//		��ӡ������λ�ã���ֵ�������£�
	//      ֵ    ����
	//      -1    �����
	//      -2    ���ж���
	//      -3    �Ҷ���
	//		>=0	  �ڵ�n��λ�ÿ�ʼ��ӡ
	// nUnitWidth
	//		��ӡ�������ȣ�ֵ��Χ[1,6]
	// nUnitHeight
	//		��ӡ������߶ȣ�ֵ��Χ[1,255]
	// nFontStyle
	//		�ɶ��ַ���HRI�����������ͣ���ֵ�������£�
	//      ֵ    ����
	//      0     12*24
	//      1     9*17
	// FontPosition
	//		�ɶ��ַ���HRI���Ĵ�ӡλ�ã���ֵ�������£�
	//      ֵ    ����
	//      0     ����ӡ
	//      1     �����Ϸ�
	//      2     �����·�
	//		3	  �����Ϸ����·�
	// return 
	//      ����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	// remarks
	//      nUnitWidth���������ӡ�߽磬�򲻴�ӡ��
	CSNPRINTERLLIBS bool Page_Barcode(const char * BarcodeData, int nBarcodeType, int nOrgx, int nUnitWidth, int nUnitHeight, int nFontStyle, int FontPosition);
	// ��ҳģʽ�´�ӡ��ά��
	// QrcodeData
	//		��ά�����ݡ�
	// nWidth
	//		��ά��Ŀ��,ȡֵ��Χ[1,16]
	//		��ά�뵥Ԫ���Խ��,QR��Խ��
	// nErrlevenl
	//		��ά�����ȼ�,ȡֵ[1,4]��
	// return 
	//		����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	// remarks
	//		��ȷ�϶�ά���С,��Ϊ��API����Ҳ���ӡ,�ᵼ���޷�����ɨ�衣
	CSNPRINTERLLIBS bool Page_Qrcode(const wchar_t *QrcodeData, int nWidth = 4, int nErrlevenl = 4);
	// ��ҳģʽ�´�ӡͼƬ
	// FileName
	//		ͼƬ·����
	// nWidth
	//		ָ����ӡ����ӡ��ͼƬ�Ŀ��(����)
	//		2���ӡ�����ֵΪ384
	//		3���ӡ�����ֵΪ576
	// nBinaryAlgorithm
	//		ͼƬ�����ģʽ����ֵ�������£�
	//		ֵ    ����
	//		0     �����㷨		���㷨�Բ�ɫͼƬ��ӡЧ���Ϻ�
	//		1     ƽ����ֵ�㷨	���㷨�Դ�����ͼƬ��ӡЧ���Ϻ�
	// return 
	//		����ֵ��ָʾָ���Ƿ�д��ɹ�������true��ʾд��ɹ�������false��ʾд��ʧ�ܡ�
	CSNPRINTERLLIBS bool Page_ImagePrint(const wchar_t *FileName, int nWidth = 384, int nBinaryAlgorithm = 0);


#ifdef __cplusplus
}
#endif

#endif // !_PRINTERLIBS_H_
