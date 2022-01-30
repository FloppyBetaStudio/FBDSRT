#include "pch.h"
#include <EventAPI.h>
#include <LoggerAPI.h>
#include <MC/Level.hpp>
#include <MC/BlockInstance.hpp>
#include <MC/Block.hpp>
#include <MC/BlockSource.hpp>
#include <MC/Actor.hpp>
#include <MC/Player.hpp>
#include <MC/ItemStack.hpp>
#include <LLAPI.h>
#include <direct.h>
#include <shellapi.h>
#include "shlwapi.h"

#pragma comment(lib, "shlwapi.lib")

using namespace std;
using json = nlohmann::json;

//static_assert(false, "Please set your plugin's name below and delete this line");
Logger logger("FBDSRT");

string securityKey = "iruanp.com";
string srv_address;
int srv_port;
httplib::Server svr;

//事件反馈
map<string, int> apiTextBox;//目标的编辑框的句柄列表
//map<string, int> apiButton;//目标按钮的句柄列表//用编辑框内容被改变的事件代替
//记录需要用到回调的插件的列表
vector<string> callback_onPlayerJoin;//当玩家加入游戏时触发

//UTF8的string转换为unicode
wstring UTF8ToUnicode(const string& s)
{
	wstring result;

	// 获得缓冲区的宽字符个数
	int length = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, NULL, 0);

	wchar_t* buffer = new wchar_t[length];
	::MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, buffer, length);
	result = buffer;

	delete[] buffer;
	return result;
}
wstring string2wstring(string str)
{
	wstring result;
	//获取缓冲区大小，并申请空间，缓冲区大小按字符计算  
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	TCHAR* buffer = new TCHAR[len + 1];
	//多字节编码转换成宽字节编码  
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';             //添加字符串结尾  
	//删除缓冲区并返回值  
	result.append(buffer);
	delete[] buffer;
	return result;
}
string wstring2string(wstring wstr)
{
	string result;
	//获取缓冲区大小，并申请空间，缓冲区大小事按字节计算的  
	int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
	char* buffer = new char[len + 1];
	//宽字节编码转换成多字节编码  
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
	buffer[len] = '\0';
	//删除缓冲区并返回值  
	result.append(buffer);
	delete[] buffer;
	return result;
}

void internal_run_all_plugins(string path)
{
	WIN32_FIND_DATAW wfd;
	LPWSTR pszPath = (LPWSTR)(string2wstring(path+"\\plugins\\FBDSRT\\plugins\\*.fbdsplugin.exe").c_str());
	//TODO:在此定义欲枚举文件目录（C风格字符串）
	HANDLE hFind = FindFirstFileW(pszPath, &wfd);//开始枚举
	if (hFind == INVALID_HANDLE_VALUE)
	{
		//MessageBoxW(NULL, L"111", L"111", 0);
		//TODO:在此添加错误处理代码
		//cout << "fuck";
		cout << "Something went wrong\n";
		cout << GetLastError();
		return;
	}

	do
	{
		if (PathIsDirectoryW(wfd.cFileName) == (BOOL)FILE_ATTRIBUTE_DIRECTORY)
		{
			//TODO:在此处理枚举到的子目录，wfd.cFileName为目录名的C风格字符串
		}
		else
		{
			//TODO:在此处理枚举到的文件，wfd.cFileName为文件名的C风格字符串
			ShellExecuteA(NULL, NULL, (path + (string)"\\plugins\\FBDSRT\\plugins\\" + wstring2string((wstring)wfd.cFileName)).c_str(), NULL, (path + (string)"\\plugins\\FBDSRT\\plugins").c_str(), NULL);
			cout << "Start FBDSPlugin:" << path + (string)"\\plugins\\FBDSRT\\plugins\\" << wstring2string((wstring)wfd.cFileName) << "\n";
		}
	} while (FindNextFileW(hFind, &wfd));
	FindClose(hFind);

}



class webServerFun {
public:
	static bool safety_check(string key) {
		//安检，确认密钥正确（这代码看起来有点废，直接对比就好了，但是为了方便万一以后要搞什么花里胡哨的）
		if (key == securityKey) {
			return true;
		} else {
			return false;
		}
	}
	static bool runcmd(string yourCMD) {//执行命令的实现函数
		return Level::runcmd(yourCMD);
	}

	static bool pluginReg(string pluginName, int hwndTextBox) {
		if (apiTextBox.find(pluginName) != apiTextBox.end()) {
			return false;
		}
		//将句柄添加到列表
		apiTextBox.insert(pair<string, int>(pluginName, hwndTextBox));
		return true;
	}

	static void eventReg_onPlayerJoin(string pluginName) {
		vector<string>::iterator it = find(callback_onPlayerJoin.begin(), callback_onPlayerJoin.end(), pluginName);
		if (it != callback_onPlayerJoin.end()) {//如果已经存在则直接返回
			return;
		}
		//将插件标识名称添加到对应的API事件列表
		callback_onPlayerJoin.push_back(pluginName);

	}

};

//web服务器的线程，为了防止web服务器阻塞主线程
void thread_webServer() {
	//配置各种功能的路径
	//运行命令 参数：
	//cmd 要执行的命令
	svr.Get("/runcmd", [](const httplib::Request& req, httplib::Response& res) {
		if (!webServerFun::safety_check(req.get_param_value("key"))) {
			res.set_content("Error: Need key", "text/plain");
			return;
		}

	//不出意外，返回结果变成文字的bool类型
		res.set_content(to_string(webServerFun::runcmd(req.get_param_value("cmd"))), "text/plain");
		});

	//注册插件
	//参数：name 插件名称; hwnd 编辑框句柄
	svr.Get("/pluginReg", [](const httplib::Request& req, httplib::Response& res) {
		if (!webServerFun::safety_check(req.get_param_value("key"))) {
			res.set_content("Error: Need key", "text/plain");
			return;
		}

		if (req.get_param_value("name") == "" or req.get_param_value("hwnd") == "") {
			res.set_content("Error: Need plugin name or text box hWnd", "text/plain");
			return;
		}

		if (webServerFun::pluginReg(req.get_param_value("name"), stoi(req.get_param_value("hwnd")))) {
			res.set_content("true", "text/plain");
		}
		else {
			res.set_content("false", "text/plain");
		}
		});

	//注册回调事件
	//在玩家加入游戏时触发事件 参数：
	//name 插件名称
	svr.Get("/eventReg_onPlayerJoin", [](const httplib::Request& req, httplib::Response& res) {
		if (!webServerFun::safety_check(req.get_param_value("key"))) {
			res.set_content("Error: Need key", "text/plain");
			return;
		}

		//不出意外，调用相关绑定方法
		if (req.get_param_value("name") == "") {
			res.set_content("Error: Need plugin name", "text/plain");
			return;
		}
		webServerFun::eventReg_onPlayerJoin(req.get_param_value("name"));
		//操作变量通常不会出意外，直接返回true
		res.set_content("true", "text/plain");

		});

	//完成配置，开始监听
	svr.listen(srv_address.c_str(), srv_port);
	logger.error((string)"Web Server thread aborted!Web server detail:address = " + srv_address + (string)"and port = " + to_string(srv_port));
}


//该死的插件入口
void PluginInit()
{
	//static_assert(false, "Please modify your plugin registration details and delete this line");
	LL::registerPlugin("FBDSRT", "A plugin make you can run other plugins with other languages by web API made by Floppy Beta Studio", LL::Version(1, 0, 0));
	logger.info("FBDSRT loading:web server");
	
	ifstream fileConfig(".\\plugins\\FBDSRT\\config.json");
	json jsonConfig;
	string fileConfigData;
	fileConfig >> fileConfigData;
	if (fileConfigData == "") {
		logger.warn("There is not an available config file, now create one automaticly");

		//创建默认配置文件
		jsonConfig["WebAPI"]["address"] = "0.0.0.0";
		jsonConfig["WebAPI"]["port"] = 1984;
		jsonConfig["Security"]["key"] = "iruanp.com";

		//写入默认配置文件
		try {
			system("mkdir .\\plugins\\FBDSRT");
			ofstream fileConfigWrite(".\\plugins\\FBDSRT\\config.json");
			fileConfigWrite << jsonConfig;
			logger.info("Config file has been written");
		}
		catch(exception ex){
			logger.error("Something went wrong when writing the config file");
		}
	}
	else {
		logger.info("Reading the config file");
		jsonConfig = json::parse(fileConfigData);
	}
	
	logger.info("Config file loaded successfully");
	svr.Get("/", [](const httplib::Request&, httplib::Response& res) {
		res.set_content("Welcome to FBDSRT default page!Visit iruanp.com for more detail", "text/plain");
		});
	try {
		srv_address = (string)jsonConfig["WebAPI"]["address"].get<string>();
		srv_port = jsonConfig["WebAPI"]["port"].get<int>();
		thread(thread_webServer).detach();

	}
	catch (exception ex) {
		logger.error((string)"Something went wrong when starting the web server:"+(string)(ex.what()));
		logger.error((string)"Detail:address = " + (string)jsonConfig["WebAPI"]["address"].get<string>() + (string)"and port = " + to_string(jsonConfig["WebAPI"]["port"].get<int>()));
	}



	//Web服务器就绪，开始注册事件
	//比较懒，事件就直接写在这里了
	Event::PlayerJoinEvent::subscribe([](const Event::PlayerJoinEvent& ev) {
		if (callback_onPlayerJoin.size() < 1) {
			//没有注册这个事件的，则直接返回
			return true;
		}

		//构建json
		json jsonOut;
		jsonOut["player"]["name"] = ev.mPlayer->getRealName();
		jsonOut["player"]["pos"] = ev.mPlayer->getPos().toString();
		jsonOut["player"]["dimension"] = to_string(ev.mPlayer->getDimensionId());
		jsonOut["player"]["ip"] = ev.mPlayer->getIP();
		jsonOut["player"]["xuid"] = ev.mPlayer->getXuid();
		jsonOut["player"]["uuid"] = ev.mPlayer->getUuid();
		jsonOut["event"]["type"] = "onPlayerJoin";

		string strJsonOut = jsonOut.dump();

		for (int i = 0; i < callback_onPlayerJoin.size(); i++) {
			//当前处理事件插件的名称：callback_onPlayerJoin[i]
			::SendMessageW((HWND)apiTextBox[callback_onPlayerJoin[i]], WM_SETTEXT, 0, (LPARAM)(LPCWSTR)UTF8ToUnicode(strJsonOut).c_str());
			//https://blog.csdn.net/Notzuonotdied/article/details/70788937 为了修复与易语言对接时编码错误导致世间万物皆乱码，全部采用Unicode

		}
		return true;
		});



	//启用插件
	internal_run_all_plugins(_getcwd(NULL, 0));
}