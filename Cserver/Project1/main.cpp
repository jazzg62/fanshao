#include <iostream>
#include <regex>
#include "httplib.h"
#include "printer.h"

using namespace httplib;
using namespace std;

int main()
{
	Printer printer;
	Server server;

	// 测试服务延迟
	server.Get("/test1567", [&](const auto& req, auto& res) {
		LARGE_INTEGER begain, end, frequency;

		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&begain);

		std::cout << req.body << std::endl;

		res.set_content("Server test", "text/plain");

		QueryPerformanceCounter(&end);
		std::cout << "post_time: " << (double)(end.QuadPart - begain.QuadPart) * 1000 / frequency.QuadPart << "ms" << std::endl;
		//std::cout << begain.QuadPart << std::endl;
		});

	server.Post("/printer/file", [&](const auto& req, auto& res) {
		int size = req.files.size();
		const auto& file = req.get_file_value("file");
		res.set_content(file.content, "text/plain");
		});

	server.Post("/printer/text", [&](const auto& req, auto& res) {
		cout << "text aa: " << req.get_param_value("aa") << endl;
		cout << "text bb：" << req.get_param_value("bb") << endl;
		});

	server.Post("/printer/test", [&](const auto& req, auto& res) {
		printer.print("这里显示商家名", "打印机测试");
		});

	server.Post("/printer/print", [&](const auto& req, auto& res) {
		cout << "store_name: " << req.get_param_value("store_name") << endl;
		cout << "print_text: " << req.get_param_value("print_text") << endl;
		printer.print(req.get_param_value("store_name"), req.get_param_value("print_text"));
		});

	// 启动打印机服务
	server.Post("/printer/start", [&](const auto& req, auto& res) {
		string s;
		const char* printer_name;
		// 如果有重启标识符，则先关闭打印机
		if (req.has_param("restart")) {
			printer.close_prn();
		}
		if (req.has_param("printer_name")) {
			s = req.get_param_value("printer_name");
			printer_name = s.data();
		}
		else {
			printer_name = DEFAULT_PRINTER;
		}
		if (printer.open_prn(printer_name)) {
			std::cout << "链接 " << printer_name << " 打印服务成功" << std::endl;
			res.set_content("1", "text/plain");
		}
		else {
			std::cout << "链接 " << printer_name << " 打印服务失败" << std::endl;
			res.set_content("0", "text/plain");
		}
		});

	// 关闭打印机服务
	server.Post("/printer/end", [&](const auto& req, auto& res) {
		printer.close_prn();
		});

	// 查询打印机状态 TODO
	server.Post("/printer/status", [&](const auto& req, auto& res) {
		res.set_content(printer.query_status(), "text/plain");
		});

	// 获取服务器打印机列表驱动 TODO
	server.Post("/printer/driver/list", [&](const auto& req, auto& res) {
		char* a = printer.query_driver_list();
		res.set_content(a, "text/plain");
		});

	// 打印单行字符串
	server.Post("/printer/print/str", [&](const auto& req, auto& res) {
		string s;
		cout << req.get_param_value("str") << endl;
		cout << req.get_param_value("aa") << endl;
		if (req.has_param("str")) {
			s = req.get_param_value("str");
			printer.print_line(s);
			res.set_content("1", "text/plain");
			return;
		}
		res.set_content("0", "text/plain");
		});

	// 根据模板来打印 TODO
	server.Post("/printer/print/template", [&](const auto& req, auto& res) {
		res.set_content("1", "text/plain");
		});

	const int port = 5826;
	server.listen("0.0.0.0", port);
}

