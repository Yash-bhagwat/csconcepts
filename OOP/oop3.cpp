#include <bits/stdc++.h>
using namespace std;

struct YTChannel{
	string Name;
	int Subcount;
	
	YTChannel(string name, int subcount){
		Name = name;
		Subcount = subcount;
	}
	
	bool operator==(const YTChannel& channel)const{
		return this->Name == channel.Name;
	}
};

//global function
ostream& operator<<(ostream& COUT, YTChannel& ytChannel){
	COUT << "Name: " << ytChannel.Name << endl;
	COUT << "Subcount: " << ytChannel.Subcount << endl;
	return COUT;
}

struct Coll{
	list<YTChannel> myChannels;
	
	//local function, member function
	void operator+=(YTChannel& channel){
		this->myChannels.push_back(channel);
	}
	
	void operator-=(YTChannel& channel){
		this->myChannels.remove(channel);
	}
};

ostream& operator <<(ostream& COUT, Coll& myCollection){
	for(YTChannel ytChannel : myCollection.myChannels)
	COUT << ytChannel << endl;
	return COUT;
}

int main(){
	YTChannel yt1 = YTChannel("ABC",75000);
	YTChannel yt2 = YTChannel("XYZ",1000000);
	//cout << yt1;
	//operator <<(cout,yt1);
	Coll myCollection;
	myCollection += yt1;
	myCollection += yt2;
	myCollection -= yt2;
	
	cout << myCollection;
}
