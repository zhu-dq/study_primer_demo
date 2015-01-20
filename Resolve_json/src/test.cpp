#include <iostream>
#include <string>
#include<fstream>
#include "json\json.h"
using namespace std;

/*
	生成json
*/
string creat_json(string ID, vector<pair<string, string>> v)
{
	Json::Value json_object;
	Json::Value json_object1;
	Json::Value attribute1;
	for (vector<pair<string, string>>::iterator i = v.begin(); i != v.end(); i++)
	{
		attribute1["ATTRIBUTE"] = (*i).first;
		attribute1["VALUE"] = (*i).second;
		json_object["AVP_LIST"].append(attribute1);
	}

	json_object["ID"] = ID;
	return json_object.toStyledString();
}
/*
		解析json
*/
void Resolve_json(string strjson)
{
	cout << "解析的结果是：" << endl;
	Json::Reader reader;
	Json::Value json_object;
	Json::Value json_object1;
	Json::Value json_object2;
	reader.parse(strjson, json_object, false);
	string jsonID = json_object["ID"].toStyledString();
	cout << "ID:    " + jsonID + "" << endl;
	string json_attribute = json_object["AVP_LIST"].toStyledString();
	cout << "AVP_LIST:    " + json_attribute + "" << endl;
	json_object1 = json_object["AVP_LIST"];
	
	for (Json::Value::iterator i = json_object1.begin(); i != json_object1.end(); i++)
	{
		json_object2 = *i;
		string json_attibute1 = json_object2["ATTRIBUTE"].toStyledString();
		cout << "ATTRIBUTE:     " + json_attibute1 + "" << endl;
		string json_attibute2 = json_object2["VALUE"].toStyledString();
		cout << "VALUE:     " + json_attibute2 + "" << endl;
	}
}
int main()
{
	vector <pair<string, string>> test_vec;
	test_vec.push_back(make_pair("aaa", "111"));
	test_vec.push_back(make_pair("bbb", "222"));
	test_vec.push_back(make_pair("ccc", "333"));
	string json_str = creat_json("12306", test_vec);
	cout << json_str << endl;
	cout << "-------------------------" << endl;
	Resolve_json(json_str);
	int i;
	cin >> i;
	return 0;
}