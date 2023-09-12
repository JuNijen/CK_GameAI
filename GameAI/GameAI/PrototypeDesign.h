//#pragma once
//#include <string>
//#include <map>
//using namespace std;
//
//enum CANTYPE
//{
//	COKE,
//	SPRITE
//};
//
//struct Can
//{
//	virtual Can* clone() = 0;
//	virtual void draw() = 0;
//};
//
//class SpriteCan : public Can
//{
//	string m_name;
//public:
//	SpriteCan(string n) : m_name(n) { }
//	~SpriteCan() {}
//	Can* clone()
//	{
//		return new SpriteCan(*this);
//	}
//	void draw() {
//		cout << m_name << endl;
//	}
//};
//
//class CokeCan : public Can
//{
//	string m_name;
//	int m_price;
//
//public:
//	CokeCan(string n, int p) :
//		m_name(n), m_price(p) { }
//	~CokeCan() {}
//
//	Can* clone()
//	{
//		return new CokeCan(*this);
//	}
//	void draw() {
//		cout << m_name << endl;
//		cout << m_price << endl;
//	}
//	}
//};
//
//
//class CanFactory
//{
//	unordered_map<CANTYPE, Can*> m_cans;
//public:
//	CanFactory()
//	{
//		m_cans[COKE] = new CokeCan("Coke", 3000);
//		m_cans[SPRITE] = new SpriteCan("Sprite");
//	}
//	~CanFactory() {}
//
//	Can* createClone(CANTYPE ct)
//	{
//		return m_cans[ct]->clone();
//	}
//};
//}