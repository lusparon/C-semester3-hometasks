#ifndef Parser_h
#define Parser_h 
#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <map>
#include <sstream>
#include <fstream>
using namespace std;

struct ParserData;


template<typename C>
string to_string(C const & c)
{
	string res = "";
	for (auto x : c)
	{
		res += (string)*(x);
	}
	return res;
}

class Token
{
public:
	virtual void update(ParserData & pd) = 0;
	virtual operator string() = 0;

	void unwindOpsWithHigherPrecedence(ParserData & pd, int precedence)
	{
		while (!pd.token_stack.empty())
		{
			Token * t = pd.token_stack.top();
			pd.token_stack.pop();

			if (t != new LeftPar() && t != new RightPar())
			{
				if (pd.precedence_map[(string)*(t)] >= precedence)
					pd.postfix.push_back(t);
				else break;
			}
			else break;
		}

	}

	virtual void unwindUntillLeftPar(ParserData & pd)
	{
		Token * t = pd.token_stack.top();
		pd.token_stack.pop();
		pd.postfix.push_back(t);
		unwindUntillLeftPar(pd);
	}
};

class Number : public Token
{
	int x;
public:
	Number(int _x) : x(_x) {}

	operator std::string() override
	{
		return to_string(x);
	}

	void update(ParserData & pd) override 
	{
		pd.postfix.push_back(this);
	}

};

class Op : public Token
{
	string s;
public:
	Op(string _s) : s(_s) { }

	operator std::string() override
	{
		return s;
	}

	void update(ParserData & pd) override 
	{
		unwindOpsWithHigherPrecedence(pd , pd.precedence_map[s]);
		pd.token_stack.push(this);
	}

};

class LeftPar : public Token
{
public:
	operator std::string() override
	{
		return "(";
	}

	void update(ParserData & pd) override 
	{
		pd.token_stack.push(new LeftPar());
	}

	void unwindUntillLeftPar(ParserData & pd) override
	{
		delete pd.token_stack.top();
		pd.token_stack.pop();
	}
};

class RightPar : public Token
{
public:
	operator std::string() override
	{
		return ")";
	}

	void update(ParserData & pd) override 
	{
		unwindUntillLeftPar(pd);
	}
};

struct ParserData
{
	string input; // входна€(разбираема€) строка
	stack<Token*> token_stack; // стек прочитанных токенов,
	list<Token *> postfix; // результирующий список токенов в постфиксной форме
	map<string, int> precedence_map; // отображение, задающее приоритет операций.
};

class Parser
{
	ParserData data;
	int currentPos; // текуща€ позици€ при разборе входной строки.
public:
	Parser(string filename)
	{
		currentPos = 0;
		ifstream ifs(filename);
		if (!ifs)
			throw runtime_error("runtime error");
		else 
			while (!ifs.eof())
			{
				string str;
				int n;
				ifs >> str;
				ifs >> n;
				data.precedence_map[str] = n;
			}
	}

	string parse(string const & input)
	{
		data.input = input;
		data.token_stack.push(new LeftPar());
		data.input += " )";
		while (!data.token_stack.empty())
		{
			Token * t = nextToken();
			t->update(data);
		}

		string result = to_string(data.postfix);
		clear_token();
		return result;
	}

private:
	void clear_token()
	{
		while (!data.token_stack.empty())
		{
			delete data.token_stack.top();
			data.token_stack.pop;
		}
		for (auto x : data.postfix)
			delete x;
		data.postfix.clear;
	}

	bool is_op(const string &s)
	{
		bool f = false;
		for (auto i : data.precedence_map)
			if (s == i.first) f = true;
		return f;
	}

	Token * nextToken()
	{
		string curTok = "";
		while (data.input[this->currentPos] == ' ')
		{
			currentPos++;
		}

		while (data.input[this->currentPos] != ' ')
		{
			if (isalpha(data.input[this->currentPos]))
				throw runtime_error("¬ведена буква");
			curTok += data.input[currentPos];
			currentPos++;
		}

		if (isdigit(curTok[0]))
		{
			string numStr = curTok;
			istringstream iss(numStr);
			int n;
			iss >> n;
			return new Number(n);
		}
		else
			if (curTok == "(")
				return new LeftPar();
			else
				if (curTok == ")")
					return new RightPar();
				else
					if (is_op(curTok))
						return new Op(curTok);
					else throw runtime_error("");
					
	}

};



#endif Parser_h


