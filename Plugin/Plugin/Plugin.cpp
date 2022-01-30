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

//�¼�����
map<string, int> apiTextBox;//Ŀ��ı༭��ľ���б�
//map<string, int> apiButton;//Ŀ�갴ť�ľ���б�//�ñ༭�����ݱ��ı���¼�����
//��¼��Ҫ�õ��ص��Ĳ�����б�
vector<string> callback_onPlayerJoin;//����Ҽ�����Ϸʱ����

//UTF8��stringת��Ϊunicode
wstring UTF8ToUnicode(const string& s)
{
	wstring result;

	// ��û������Ŀ��ַ�����
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
	//��ȡ��������С��������ռ䣬��������С���ַ�����  
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	TCHAR* buffer = new TCHAR[len + 1];
	//���ֽڱ���ת���ɿ��ֽڱ���  
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';             //����ַ�����β  
	//ɾ��������������ֵ  
	result.append(buffer);
	delete[] buffer;
	return result;
}
string wstring2string(wstring wstr)
{
	string result;
	//��ȡ��������С��������ռ䣬��������С�°��ֽڼ����  
	int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
	char* buffer = new char[len + 1];
	//���ֽڱ���ת���ɶ��ֽڱ���  
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
	buffer[len] = '\0';
	//ɾ��������������ֵ  
	result.append(buffer);
	delete[] buffer;
	return result;
}

void internal_run_all_plugins(string path)
{
	WIN32_FIND_DATAW wfd;
	LPWSTR pszPath = (LPWSTR)(string2wstring(path+"\\plugins\\FBDSRT\\plugins\\*.fbdsplugin.exe").c_str());
	//TODO:�ڴ˶�����ö���ļ�Ŀ¼��C����ַ�����
	HANDLE hFind = FindFirstFileW(pszPath, &wfd);//��ʼö��
	if (hFind == INVALID_HANDLE_VALUE)
	{
		//MessageBoxW(NULL, L"111", L"111", 0);
		//TODO:�ڴ���Ӵ��������
		//cout << "fuck";
		cout << "Something went wrong\n";
		cout << GetLastError();
		return;
	}

	do
	{
		if (PathIsDirectoryW(wfd.cFileName) == (BOOL)FILE_ATTRIBUTE_DIRECTORY)
		{
			//TODO:�ڴ˴���ö�ٵ�����Ŀ¼��wfd.cFileNameΪĿ¼����C����ַ���
		}
		else
		{
			//TODO:�ڴ˴���ö�ٵ����ļ���wfd.cFileNameΪ�ļ�����C����ַ���
			ShellExecuteA(NULL, NULL, (path + (string)"\\plugins\\FBDSRT\\plugins\\" + wstring2string((wstring)wfd.cFileName)).c_str(), NULL, (path + (string)"\\plugins\\FBDSRT\\plugins").c_str(), NULL);
			cout << "Start FBDSPlugin:" << path + (string)"\\plugins\\FBDSRT\\plugins\\" << wstring2string((wstring)wfd.cFileName) << "\n";
		}
	} while (FindNextFileW(hFind, &wfd));
	FindClose(hFind);

}



class webServerFun {
public:
	static bool safety_check(string key) {
		//���죬ȷ����Կ��ȷ������뿴�����е�ϣ�ֱ�ӶԱȾͺ��ˣ�����Ϊ�˷�����һ�Ժ�Ҫ��ʲô������ڵģ�
		if (key == securityKey) {
			return true;
		} else {
			return false;
		}
	}
	static bool runcmd(string yourCMD) {//ִ�������ʵ�ֺ���
		return Level::runcmd(yourCMD);
	}

	static bool pluginReg(string pluginName, int hwndTextBox) {
		if (apiTextBox.find(pluginName) != apiTextBox.end()) {
			return false;
		}
		//�������ӵ��б�
		apiTextBox.insert(pair<string, int>(pluginName, hwndTextBox));
		return true;
	}

	static void eventReg_onPlayerJoin(string pluginName) {
		vector<string>::iterator it = find(callback_onPlayerJoin.begin(), callback_onPlayerJoin.end(), pluginName);
		if (it != callback_onPlayerJoin.end()) {//����Ѿ�������ֱ�ӷ���
			return;
		}
		//�������ʶ������ӵ���Ӧ��API�¼��б�
		callback_onPlayerJoin.push_back(pluginName);

	}

};

//web���������̣߳�Ϊ�˷�ֹweb�������������߳�
void thread_webServer() {
	//���ø��ֹ��ܵ�·��
	//�������� ������
	//cmd Ҫִ�е�����
	svr.Get("/runcmd", [](const httplib::Request& req, httplib::Response& res) {
		if (!webServerFun::safety_check(req.get_param_value("key"))) {
			res.set_content("Error: Need key", "text/plain");
			return;
		}

	//�������⣬���ؽ��������ֵ�bool����
		res.set_content(to_string(webServerFun::runcmd(req.get_param_value("cmd"))), "text/plain");
		});

	//ע����
	//������name �������; hwnd �༭����
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

	//ע��ص��¼�
	//����Ҽ�����Ϸʱ�����¼� ������
	//name �������
	svr.Get("/eventReg_onPlayerJoin", [](const httplib::Request& req, httplib::Response& res) {
		if (!webServerFun::safety_check(req.get_param_value("key"))) {
			res.set_content("Error: Need key", "text/plain");
			return;
		}

		//�������⣬������ذ󶨷���
		if (req.get_param_value("name") == "") {
			res.set_content("Error: Need plugin name", "text/plain");
			return;
		}
		webServerFun::eventReg_onPlayerJoin(req.get_param_value("name"));
		//��������ͨ����������⣬ֱ�ӷ���true
		res.set_content("true", "text/plain");

		});

	//������ã���ʼ����
	svr.listen(srv_address.c_str(), srv_port);
	logger.error((string)"Web Server thread aborted!Web server detail:address = " + srv_address + (string)"and port = " + to_string(srv_port));
}


//�����Ĳ�����
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

		//����Ĭ�������ļ�
		jsonConfig["WebAPI"]["address"] = "0.0.0.0";
		jsonConfig["WebAPI"]["port"] = 1984;
		jsonConfig["Security"]["key"] = "iruanp.com";

		//д��Ĭ�������ļ�
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



	//Web��������������ʼע���¼�
	//�Ƚ������¼���ֱ��д��������
	Event::PlayerJoinEvent::subscribe([](const Event::PlayerJoinEvent& ev) {
		if (callback_onPlayerJoin.size() < 1) {
			//û��ע������¼��ģ���ֱ�ӷ���
			return true;
		}

		//����json
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
			//��ǰ�����¼���������ƣ�callback_onPlayerJoin[i]
			::SendMessageW((HWND)apiTextBox[callback_onPlayerJoin[i]], WM_SETTEXT, 0, (LPARAM)(LPCWSTR)UTF8ToUnicode(strJsonOut).c_str());
			//https://blog.csdn.net/Notzuonotdied/article/details/70788937 Ϊ���޸��������ԶԽ�ʱ���������������������룬ȫ������Unicode

		}
		return true;
		});



	//���ò��
	internal_run_all_plugins(_getcwd(NULL, 0));
}