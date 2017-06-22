#include <iostream>
#include <fstream>

#include <json/json.h>

using namespace std;

int main()
{
	//根结点
	Json::Value root;

	//根结点的属性
	root["name"] = Json::Value("czm");
	root["age"]  = Json::Value(23);
	root["sex_is_male"] = Json::Value(true);

	//子节点
	Json::Value partner;

	//子节点的属性
	partner["partner_name"] = Json::Value("czmczm");
	partner["partner_age"]  = Json::Value(3);
	partner["partner_sex_is_male"] = Json::Value(true);

	//将子节点挂载到根结点上
	root["partner"] = Json::Value(partner);

	//数组的形式
	root["achievement"].append("ach1");
	root["achievement"].append("ach2");
	root["achievement"].append("ach3");

	//两种输出的方式

	cout << "FastWriter: " << endl;
	Json::FastWriter fw;
	cout << fw.write(root) << endl << endl;

	cout << "StyledWriter: " << endl;
	Json::StyledWriter sw;
	cout << sw.write(root) << endl << endl;

	ofstream os;
	os.open("PersonInfo_file");
	os << sw.write(root);
	os.close();

	return 0;
}