#include <iostream>
#include <fstream>

#include <json/json.h>

using namespace std;

/*{
    "name":"Tsybius",
    "age":23,
    "sex_is_male":true,
    "partner":
    {
        "partner_name":"Galatea",
        "partner_age":21,
        "partner_sex_is_male":false
    },
    "achievement":["ach1","ach2","ach3"]
}*/

int main()
{
	Json::Reader reader;
	Json::Value  root;

	//从文件中进行读取json文件

	ifstream is;
    //mark  这里文件名写错了parser() error!
	is.open("PersonalInfo.json",ios::binary);

    cout << "start parser!" << endl;
	if(reader.parse(is,root))
	{
        cout << "entry parser!" << endl;
		//读取根结点的信息
		string name = root["name"].asString();
		int age = root["age"].asInt();
		bool sex_is_male = root["sex_is_male"].asBool();

		cout << "My name is " << name << endl;
        cout << "I'm " << age << " years old" << endl;
        cout << "I'm a " << (sex_is_male ? "man" : "woman") << endl;

        //读取子结点的信息
        string partner_name = root["partner"]["partner_name"].asString();
        int    partner_age  = root["partner"]["partner_age"].asInt();
        bool   partner_sex_is_male = root["partner"]["partner_sex_is_male"].asBool();

        cout << "My partner's name is " << partner_name << endl;
        cout << (partner_sex_is_male ? "he" : "she") << " is "
             << partner_age << " years old" << endl;

        //读取数组中的信息
        cout << "Here is my achievement: " << endl;

        for(int i = 0; i < root["achievement"].size(); i++)
        {
        	string ach = root["achievement"][i].asString();
        	cout << ach << '\t';
        }

        cout << endl;


	}
    cout << "end parser!" << endl;
	return 0;
}