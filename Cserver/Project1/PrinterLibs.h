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

	/****************************************端口操作函数*****************************************/
	// 枚举串口
	// buffer
	//     用来保存端口列表的缓冲区
	// length
	//     缓冲区字节数
	// prequired
	//     需要的缓冲区字节数
	// return
	//     枚举到的端口数量
	CSNPRINTERLLIBS size_t Port_EnumCOM(char *buffer, size_t length);
	// 枚举USB
	//  buffer
	//      用来保存端口列表的缓冲区
	//  length
	//      缓冲区字节数
	//  prequired
	//      需要的缓冲区字节数
	//  return
	//      枚举到的端口数量
	CSNPRINTERLLIBS size_t Port_EnumUSB(char *buffer, size_t length);
	// 枚举并口
	// buffer
	//     用来保存端口列表的缓冲区
	// length
	//     缓冲区字节数
	// prequired
	//     需要的缓冲区字节数
	// return
	//     枚举到的端口数量
	CSNPRINTERLLIBS size_t Port_EnumLPT(char *buffer, size_t length);
	// 枚举本地打印驱动
	//  buffer
	//      用来保存端口列表的缓冲区
	//  length
	//      缓冲区字节数
	//  prequired
	//      需要的缓冲区字节数
	//  return
	//      枚举到的端口数量
	CSNPRINTERLLIBS size_t Port_EnumPRN(char *buffer, size_t length);

	// 打开串口
	// name 
	//      端口名称，可以由EnumCOM()获取
	//      例如：COM1，COM2，COM3，...COM11...
	// baudrate 
	//      波特率
	//      一般取 9600,19200,38400,57600,115200.
	//		默认值 9600
	//      需要和打印机波特率保持一致，建议使用高波特率以获得较好的打印速度
	// flowcontrol
	//      流控制，各值定义如下：（默认值为0）
	//      值    定义
	//      0     无流控
	//      1     DsrDtr
	//      2     CtsRts
	//		3	  Xon/Xoff
	// parity 
	//      校验位，各值定义如下：（默认值为0）
	//      值    定义
	//      0     无校验
	//      1     奇校验
	//      2     偶校验
	//      3     标记校验
	//      4     空白校验
	// databits
	//      数据位，范围[4,8]（默认值为8）
	// stopbits 
	//      停止位，各值定义如下：（默认值为0）
	//      值    定义
	//      0     1位停止位
	//      1     1.5位停止位
	//      2     2位停止位
	//
	// return 
	//      返回打开的端口句柄。非零表示打开成功，零表示打开失败。
	//
	// remarks
	//      如果串口被占用，打开串口会失败。
	//      如果波特率和打印机波特率不匹配，则无法打印。
	CSNPRINTERLLIBS void * Port_OpenCOMIO(const char *name, unsigned int baudrate = 9600, const int flowcontrol = 0, const int parity = 0, const int databis = 8, const int stopbits = 0);
	// 打开USB
	// name 
	//      端口名称，可由EnumUSB获得
	// return 
	//      返回打开的端口句柄。非零表示打开成功，零表示打开失败。
	// remarks
	//      USB 打印机接到电脑上，如果设备管理器中出现了"USB Printing Support"或者"USB打印支持"，则可以使用该函数打开。
	CSNPRINTERLLIBS void * Port_OpenUSBIO(const char *name);
	// 打开LPT
	// name 
	//      端口名称，可由EnumLPT获得
	//		例如：LPT1,LPT2,LPT3...
	// return 
	//      返回打开的端口句柄。非零表示打开成功，零表示打开失败。
	// remarks
	//      并口只有单向通讯，只可写不可读。
	//      一切查询状态的函数，对并口来说均是无效的。
	CSNPRINTERLLIBS void * Port_OpenLPTIO(const char *name);
	// 打开打印机
	// name
	//      打印机名称（可由EnumPRN获得）
	//      例如：POS58 Printer
	// return 
	//      返回打开的端口句柄。非零表示打开成功，零表示打开失败。
	// remarks
	//      大部分驱动仅支持单向通讯，此时任意查询函数均无效
	CSNPRINTERLLIBS void * Port_OpenPRNIO(const char *name);
	// 打开网口
	// ip 
	//      地址或名称
	//      例如：192.168.1.87 
	// port 
	//      端口号
	//      固定值：9100
	// return 
	//      返回打开的端口句柄。非零表示打开成功，零表示打开失败。
	// remarks
	//      PC和打印机需要同网段的才可以连接
	CSNPRINTERLLIBS void * Port_OpenTCPIO(const char *ip, const unsigned short port);
	// 设置打印机通讯端口
	// handle 
	//      通过OpenXXX()所获取的端口句柄
	// return 
	//      返回true代表设置成功，false代表设置失败。
	CSNPRINTERLLIBS bool Port_SetPort(void *handle);
	// 关闭打印机通讯端口
	// handle 
	//      通过OpenXXX()所获取的端口句柄
	// return 
	//      
	CSNPRINTERLLIBS void Port_ClosePort(void *handle);
	/****************************************端口操作函数*****************************************/
	// 重置打印机
	// return 
	//      返回true代表写入成功，false代表写入失败。
	CSNPRINTERLLIBS bool Pos_Reset();
	// 打印测试页
	// return 
	//      返回true代表写入成功，false代表写入失败。
	CSNPRINTERLLIBS bool Pos_SelfTest();
	// 进纸一行
	// return 
	//      返回true代表写入成功，false代表写入失败。
	CSNPRINTERLLIBS bool Pos_FeedLine();
	// 按加热点数进纸(一个点0.125mm)
	// n
	//		需要进纸的点数
	// return 
	//      返回true代表写入成功，false代表写入失败。
	CSNPRINTERLLIBS bool Pos_FeedHot(int n);
	// 按行数进纸
	// n
	//		需要进纸的行数。
	// return 
	//      返回true代表写入成功，false代表写入失败。
	CSNPRINTERLLIBS bool Pos_Feed_N_Line(int n);
	// 进纸到下一个标签处
	// return 
	//      返回true代表写入成功，false代表写入失败。
	// remarks
	//      该API只针对非标准标签指令的打印机，即执行ESC/POS的指令的标签机。如型号：LPM-261
	CSNPRINTERLLIBS bool Pos_FeedNextLable();
	// 进纸到下一个黑标处
	// return 
	//      返回true代表写入成功，false代表写入失败。
	// remarks
	//      该API只针对有黑标功能的打印机。
	CSNPRINTERLLIBS bool Pos_BlackMark();
	// 设置对齐方式
	// value
	//      设置对齐方式，各值定义如下：
	//      值    定义
	//      0     左对齐
	//      1     居中对齐
	//      2     右对齐
	// return 
	//      返回true代表写入成功，false代表写入失败。
	// remarks
	//      该API仅用于对齐指令操作，又需要对齐的API，做于补充。
	CSNPRINTERLLIBS bool Pos_Align(int value);
	// 设置行高
	// value
	//      设置行高点数(一个点0.125mm)，范围[0,255]
	// return 
	//      返回true代表写入成功，false代表写入失败。
	CSNPRINTERLLIBS bool Pos_SetLineHeight(int value);
	// 打印文本
	// prnText
	//		需要打印的文本
	// nLan
	//		打印的文本编码类型，各值定义如下：
	//      值    定义
	//      0     GBK
	//      1     UTF-8
	//      3     BIG-5
	//		4	  SHIFT-JIS
	//		5	  EUC-KR
	// nOrgx
	//		打印的文本位置，各值定义如下：
	//      值    定义
	//      -1    左对齐
	//      -2    居中对齐
	//      -3    右对齐
	//		>=0	  在第n点位置开始打印
	// nWidthTimes
	//		字符放大的倍数，范围[0,7]
	// nHeightTimes
	//		字符放大的倍数，范围[0,7]
	// FontType
	//		打印的字体类型，各值定义如下：
	//      值    定义
	//      0	  12*24
	//		1	  9*17
	// nFontStyle
	//		打印的字体类型，各值定义如下：
	//      值		定义
	//      0x00	正常
	//		0x08	加粗
	//		0x80    1点下划线
	//		0x100   2点下划线
	//		0x200	倒置打印
	//		0x400	反显、黑底白字
	//		0x1000	每个字符顺时针旋转 90 度
	// return 
	//      返回true代表写入成功，false代表写入失败。
	// remarks
	//      nFontStyle数值是可以通过 | 操作来实现多种风格同时出现的。
	CSNPRINTERLLIBS bool Pos_Text(const wchar_t *prnText, int nLan, int nOrgx, int nWidthTimes, int nHeightTimes, int FontType, int nFontStyle);

	// 蜂鸣器鸣叫
	// nBeepCount
	//      鸣叫次数
	// nMillis
	//      蜂鸣毫秒时间，取值范围[100,900]。取整到百毫秒。
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	// remarks
	//      请确认打印机是否有蜂鸣器功能。
	CSNPRINTERLLIBS bool Pos_Beep(unsigned char nCount, unsigned char nMillis);
	// 打开钱箱
	// nId
	//      打开钱箱，值范围[0,1]
	// nHightTime
	//      高电平毫秒时间
	// nLowTime 
	//      低电平毫秒时间
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	// remarks
	//      请确认打印机是否有打开钱箱功能。
	CSNPRINTERLLIBS bool Pos_KiskOutDrawer(int nId, int nHightTime = 20, int nLowTime = 60);
	// 执行全切
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	// remarks
	//      请确认打印机是否有全切功能。
	CSNPRINTERLLIBS bool Pos_FullCutPaper();
	// 执行半切
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	// remarks
	//      请确认打印机是否有全切功能。
	CSNPRINTERLLIBS bool Pos_HalfCutPaper();
	// 打印条码
	// BarcodeData
	//		打印的条码内容
	// nBarcodeType
	//		打印的条码类型，各值定义如下：
	//      值		 类型
	//      0x41     UPC-A
	//      0x42     UPC-E
	//      0x43     EAN13
	//      0x44     EAN8
	//      0x45     CODE39
	//      0x46     ITF
	//      0x47     CODABAR
	//      0x48     CODE93
	// nOrgx
	//		打印的条码位置，各值定义如下：
	//      值    定义
	//      -1    左对齐
	//      -2    居中对齐
	//      -3    右对齐
	//		>=0	  在第n点位置开始打印
	// nUnitWidth
	//		打印的条码宽度，值范围[1,6]
	// nUnitHeight
	//		打印的条码高度，值范围[1,255]
	// nFontStyle
	//		可读字符（HRI）的字体类型，各值定义如下：
	//      值    定义
	//      0     12*24
	//      1     9*17
	// FontPosition
	//		可读字符（HRI）的打印位置，各值定义如下：
	//      值    定义
	//      0     不打印
	//      1     条码上方
	//      2     条码下方
	//		3	  条码上方和下方
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	// remarks
	//      nUnitWidth如果超出打印边界，则不打印。
	CSNPRINTERLLIBS bool Pos_Barcode(const char * BarcodeData, int nBarcodeType, int nOrgx, int nUnitWidth, int nUnitHeight, int nFontStyle, int FontPosition);
	// 打印二维码
	// QrcodeData
	//		二维码的内容
	// nWidth
	//		二维码的宽度,取值范围[1,6]
	//		二维码单元宽度越大,QR码越大。
	// nVersion
	//		二维码的规格,取值范围[0,16],0表示自动计算版本。
	//		二维码码版本越大，能编码的字符就越多，QR码也越大。
	// nErrlevenl
	//		二维码纠错等级,取值[1,4]
	// return 
	//		返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	// remarks
	//		如果打印的二维码超出打印边界，则不打印。
	CSNPRINTERLLIBS bool Pos_Qrcode(const wchar_t *QrcodeData, int nWidth = 2, int nVersion = 0, int nErrlevenl = 4);
	// ESC/POS版本二维码
	// QrcodeData
	//      二维码内容。
	// nWidth
	//		二维码的宽度,取值范围[1,16]
	//		二维码单元宽度越大,QR码越大。
	// nErrlevenl
	//		二维码纠错等级,取值[1,4]。
	// return 
	//		返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	// remarks
	//		请确认二维码大小,因为该API超出也会打印,会导致无法正常扫描。
	CSNPRINTERLLIBS bool Pos_EscQrcode(const wchar_t *QrcodeData, int nWidth = 4, int nErrlevenl = 4);
	// 打印双二维码
	// QrcodeData1
	//      第一个二维码的内容。
	// QR1Position
	//      第一个二维码开始打印的位置
	// QR1Version
	//      第一个二维码的规格，范围[0，19]
	// QR1Ecc
	//      第一个二维码的纠错等级，范围[0,3]
	// QrcodeData2
	//      第二个二维码的内容。
	// QR2Position
	//      第二个二维码开始打印的位置
	// QR2Version
	//      第二个二维码的规格。[0,19]
	// QR2Ecc
	//      第二个二维码的纠错等级,范围[0,3]
	// ModuleSize
	//      二维码模块的大小，范围[1，8]
	// remarks
	//      如果打印失败，请注意检查第二个二维码打印的位置是否与第一个重叠或者打印后超出打印边界。
	CSNPRINTERLLIBS bool Pos_DoubleQrcode(const wchar_t *QrcodeData1,int QR1Position,int QR1Version, int QR1Ecc, const wchar_t *QrcodeData2, int QR2Position, int QR2Version, int QR2Ecc, int ModuleSize);

	// 打印图片
	// FileName
	//		图片路径。
	// nWidth
	//		指定打印机打印该图片的宽度(像素)
	//		2寸打印机最大值为384
	//		3寸打印机最大值为576
	// nBinaryAlgorithm
	//		图片计算的模式，各值定义如下：
	//		值    定义
	//		0     抖动算法		该算法对彩色图片打印效果较好
	//		1     平均阈值算法	该算法对纯文字图片打印效果较好
	// return 
	//		返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	CSNPRINTERLLIBS bool Pos_ImagePrint(const wchar_t *FileName, int nWidth = 384, int nBinaryAlgorithm = 0);
	// 打印预载的Logo
	// n
	//		打印第n张Logo,范围[1,9]
	// nMode
	//		指定打印Logo的模式，值定义如下：
	//      值    定义
	//      0     普通
	//      1     倍宽
	//      2     倍高
	//		3	  倍宽 | 倍高
	// return 
	//      返回true代表写入成功，false代表写入失败。
	// remarks
	//      如果打印机中无预载的Logo则不打印。请用打印机工具预载。
	CSNPRINTERLLIBS bool Pos_PrintNVLogo(unsigned short nLogo, unsigned short nWidth = 0);

	/*******************************************查询模块*********************************************/
	// 查询打印机错误
	// nTimeout
	//		超时的毫秒数。
	// return
	//		返回错误的值，各值的定义为：
	//      值		类型
	//      1		打印机正常
	//      -1		打印机脱机
	//      -2		打印机上盖打开
	//      -3		打印机缺纸
	//      -4		打印机切刀异常
	//      -5		打印机头片温度过高
	//      -6		查询失败
	// remarks
	//      该API无法一次返回多个异常状态。如需获取多个异常，请使用Pos_QueryStstus函数自行实现。请勿在打印过程中插入查询操作。
	CSNPRINTERLLIBS int Pos_QueryPrinterErr(unsigned long nTimeout = 3000);

	// 查询打印机错误
	// rBuffer
	//		储存打印机返回的状态
	// type
	//		查询的数据表。[1,4]。具体表单请看说明文档。
	// nTimeout
	//		超时的毫秒数。
	// return 
	//      返回true代表写入成功，false代表写入失败。
	// remarks
	//      该API无法一次返回多个异常状态。如需获取多个异常，请使用Pos_QueryStstus函数自行实现。
	CSNPRINTERLLIBS bool Pos_QueryStstus(char *rBuffer, int type, unsigned long nTimeout);

	/*******************************************设置模块*********************************************/
	// 设置打印机波特率
	// nBaudrate
	//		设置打印机的波特率。
	//		例如：9600 19200 38400 57600 115200
	// return 
	//      返回true代表设置成功，false代表设置失败。
	// remarks
	//      如果用串口连接时，设置完波特率后，请重新执行OpenCOM。
	CSNPRINTERLLIBS bool Pos_SetPrinterBaudrate(int nBaudrate);
	// 设置打印机基本参数
	// nFontStyle
	//		设置字体规格,各值定义如下：
	//		值      字体
	//		0		9*17
	//		1		12*24
	//		2		9*24
	//		3		16*18
	// nDensity
	//		设置浓度,各值定义如下：
	//		值      字体
	//		0		微淡
	//		1		正常
	//		2		微浓
	//		3		高浓度
	// nLine 
	//      设置进纸模式,各值定义如下：
	//		值      模式
	//		0		0x0A
	//		1		0x0D
	// nBeep 
	//      是否启用蜂鸣器,各值定义如下：
	//		值      开关
	//		0		关闭蜂鸣器
	//		1		开启蜂鸣器
	// nCut 
	//      是否启用蜂鸣器,各值定义如下：
	//		值      开关
	//		0		关闭切刀功能
	//		1		开启切刀功能
	// remarks
	//      字体规格仅设置非双字节文本,中文日文韩文等字体均为24*24无法修改。
	//		蜂鸣器开关请确认使用的机型是否带有蜂鸣器功能
	//		切刀开关请确认使用的机型是否带有切刀功能
	CSNPRINTERLLIBS bool Pos_SetPrinterBasic(int nFontStyle, int nDensity, int nLine, int nBeep, int nCut);

	/*******************************************PAGE模块*********************************************/
	// 选择页模式
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	// remarks
	//      请确认打印机是否有页模式功能,页模式下不会直接打印,需要在数据填充后调用Page_PrintPage。
	CSNPRINTERLLIBS bool Page_SelectPageMode();
	// 打印页模式下的内容
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	// remarks
	//      请确认打印机是否有页模式功能,页模式下不会直接打印,需要在数据填充后调用Page_PrintPage。
	CSNPRINTERLLIBS bool Page_PrintPage();
	// 退出页模式
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	CSNPRINTERLLIBS bool Page_ExitPageMode();
	// 设置纵向绝对打印位置
	// nPosition
	//      打印位置
	//
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	CSNPRINTERLLIBS bool Page_SetVerticalAbsolutePrintPosition(unsigned short nPosition);
	// 设置横向绝对打印位置
	// nPosition
	//      打印位置
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	CSNPRINTERLLIBS bool Page_SetHorizontalAbsolutePrintPosition(unsigned short nPosition);
	// 设置纵向相对打印位置
	// nPosition
	//      打印位置
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	CSNPRINTERLLIBS bool Page_SetVerticalRelativePrintPosition(unsigned short nPosition);
	// 设置横向相对打印位置
	// nPosition
	//      打印位置
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	CSNPRINTERLLIBS bool Page_SetHorizontalRelativePrintPosition(unsigned short nPosition);
	// 页模式下设置打印方向
	// nDirection
	//      打印区域方向，各值定义如下：
	//      0    从左到右
	//      1    从下到上
	//      2    从右到左
	//      3    从上到下
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	CSNPRINTERLLIBS bool Page_SetPageModeDrawDirection(unsigned short nPosition);
	// 页模式下设置页区域
	// x
	//      横向起始位置
	//
	// y
	//      纵向起始位置
	//
	// w
	//      打印区域宽度
	//
	// h
	//      打印区域高度
	//
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	CSNPRINTERLLIBS bool Page_SetPageArea(unsigned short x, unsigned short y, unsigned short w, unsigned short h);
	// 页模式下UNICODE文本
	// prnText
	//		需要打印的UNICODE文本
	// nOrgx
	//		打印的文本位置，各值定义如下：
	//      值    定义
	//      -1    左对齐
	//      -2    居中对齐
	//      -3    右对齐
	//		>=0	  在第n点位置开始打印
	// nWidthTimes
	//		字符放大的倍数，范围[0,7]
	// nHeightTimes
	//		字符放大的倍数，范围[0,7]
	// FontType
	//		打印的字体类型，各值定义如下：
	//      值    定义
	//      0	  12*24
	//		1	  9*17
	// nFontStyle
	//		打印的字体类型，各值定义如下：
	//      值		定义
	//      0x00	正常
	//		0x08	加粗
	//		0x80    1点下划线
	//		0x100   2点下划线
	//		0x200	倒置打印
	//		0x400	反显、黑底白字
	//		0x1000	每个字符顺时针旋转 90 度
	// return 
	//      返回true代表写入成功，false代表写入失败。
	// remarks
	//      nFontStyle数值是可以通过&操作来实现多种风格同时出现的。
	CSNPRINTERLLIBS bool Page_UnicodeText(const char *prnText, int nOrgx, int nWidthTimes, int nHeightTimes, int FontType, int nFontStyle);
	// 页模式下打印文本
	// prnText
	//		需要打印的文本
	// nLan
	//		打印的文本编码类型，各值定义如下：
	//      值    定义
	//      0     GBK
	//      1     UTF-8
	//      3     BIG-5
	//		4	  SHIFT-JIS
	//		5	  EUC-KR
	// nOrgx
	//		打印的文本位置，各值定义如下：
	//      值    定义
	//      -1    左对齐
	//      -2    居中对齐
	//      -3    右对齐
	//		>=0	  在第n点位置开始打印
	// nWidthTimes
	//		字符放大的倍数，范围[0,7]
	// nHeightTimes
	//		字符放大的倍数，范围[0,7]
	// FontType
	//		打印的字体类型，各值定义如下：
	//      值    定义
	//      0	  12*24
	//		1	  9*17
	// nFontStyle
	//		打印的字体类型，各值定义如下：
	//      值		定义
	//      0x00	正常
	//		0x08	加粗
	//		0x80    1点下划线
	//		0x100   2点下划线
	//		0x200	倒置打印
	//		0x400	反显、黑底白字
	//		0x1000	每个字符顺时针旋转 90 度
	// return 
	//      返回true代表写入成功，false代表写入失败。
	// remarks
	//      nFontStyle数值是可以通过&操作来实现多种风格同时出现的。
	CSNPRINTERLLIBS bool Page_Text(const wchar_t *prnText, int nLan, int nOrgx, int nWidthTimes, int nHeightTimes, int FontType, int nFontStyle);
	// 在页模式下打印条码
	// BarcodeData
	//		打印的条码内容
	// nBarcodeType
	//		打印的条码类型，各值定义如下：
	//      值		 类型
	//      0x41     UPC-A
	//      0x42     UPC-E
	//      0x43     EAN13
	//      0x44     EAN8
	//      0x45     CODE39
	//      0x46     ITF
	//      0x47     CODABAR
	//      0x48     CODE93
	// nOrgx
	//		打印的条码位置，各值定义如下：
	//      值    定义
	//      -1    左对齐
	//      -2    居中对齐
	//      -3    右对齐
	//		>=0	  在第n点位置开始打印
	// nUnitWidth
	//		打印的条码宽度，值范围[1,6]
	// nUnitHeight
	//		打印的条码高度，值范围[1,255]
	// nFontStyle
	//		可读字符（HRI）的字体类型，各值定义如下：
	//      值    定义
	//      0     12*24
	//      1     9*17
	// FontPosition
	//		可读字符（HRI）的打印位置，各值定义如下：
	//      值    定义
	//      0     不打印
	//      1     条码上方
	//      2     条码下方
	//		3	  条码上方和下方
	// return 
	//      返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	// remarks
	//      nUnitWidth如果超出打印边界，则不打印。
	CSNPRINTERLLIBS bool Page_Barcode(const char * BarcodeData, int nBarcodeType, int nOrgx, int nUnitWidth, int nUnitHeight, int nFontStyle, int FontPosition);
	// 在页模式下打印二维码
	// QrcodeData
	//		二维码内容。
	// nWidth
	//		二维码的宽度,取值范围[1,16]
	//		二维码单元宽度越大,QR码越大。
	// nErrlevenl
	//		二维码纠错等级,取值[1,4]。
	// return 
	//		返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	// remarks
	//		请确认二维码大小,因为该API超出也会打印,会导致无法正常扫描。
	CSNPRINTERLLIBS bool Page_Qrcode(const wchar_t *QrcodeData, int nWidth = 4, int nErrlevenl = 4);
	// 在页模式下打印图片
	// FileName
	//		图片路径。
	// nWidth
	//		指定打印机打印该图片的宽度(像素)
	//		2寸打印机最大值为384
	//		3寸打印机最大值为576
	// nBinaryAlgorithm
	//		图片计算的模式，各值定义如下：
	//		值    定义
	//		0     抖动算法		该算法对彩色图片打印效果较好
	//		1     平均阈值算法	该算法对纯文字图片打印效果较好
	// return 
	//		返回值仅指示指令是否写入成功。返回true表示写入成功，返回false表示写入失败。
	CSNPRINTERLLIBS bool Page_ImagePrint(const wchar_t *FileName, int nWidth = 384, int nBinaryAlgorithm = 0);


#ifdef __cplusplus
}
#endif

#endif // !_PRINTERLIBS_H_
